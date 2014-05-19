#include "../headers/namescreen.h"

extern double start_time;
extern double getCurrentTime();

NameScreen::NameScreen(DataController *theDataController) : Screen(theDataController) {


  textInBox.push_back("Player 1");
  textInBox.push_back("Player 2");
  textInBox.push_back("Player 3");

  for (int i=0; i < 3; i++) {
    isOverTextBox.push_back(false);
    textBoxIsClicked.push_back(false);
  }

  nameError = false;

  buttons.push_back(Button("", 230, 86, 946, 640, 0.098, 0.694, 0.173, 0.0, 0.2, 0.3));

}

void NameScreen::draw(bool shouldDrawButtons) {

  drawTexture(loadTexture("images/backgrounds/pam/namescreen.pam"), 0, 0, 1200, 750);

  drawTextBoxes(0);
  drawTextBoxes(1);
  drawTextBoxes(2);

  if (nameError) {
    drawLargestText("Error! Name entered is invalid.", 450, 680);
  }

  Screen::draw(true); // draws buttons

}

void NameScreen::nextTextBox() {

  for (int i=0; i < 3; i++) {
    if (textBoxIsClicked[i]) {
      int next = (i + 1) % 3;
      textBoxIsClicked[i] = false;
      textBoxIsClicked[next] = true;
      break;
    }
  }
}

void NameScreen::drawTextBoxes(int index) {

  // draw text box
  glColor3f(.25, .25, .25);  // dark gray
  // drawBox(positionX + 50, positionY + 50, width - 100, 50);
  drawBox(450, 300+ 100*index, 300, 50);
  if (nameError && (textInBox[index] == ""))
    if (isOverTextBox[index] || textBoxIsClicked[index])
      glColor3f(1,0.4,0.4); // red
    else
      glColor3f(1.0,0,0);
  else if (isOverTextBox[index] || textBoxIsClicked[index])
    glColor3f(1,1,1);  // light gray
  else
    glColor3f(.75, .75, .75);
  drawBox(455, 300 + 100*index + 5, 290, 40);
  glColor3f(0, 0, 0);  // black
  drawLargestText(textInBox[index], 460, 300 + 100*index + 30);

}

int NameScreen::didClickButton(int x, int y) {

  for (int i=0; i < 3; i++)
    textBoxIsClicked[i] = false;

  for (int i=0; i < 3; i++)
    if (isOverTextBox[i])
      textBoxIsClicked[i] = true;

  int buttonClicked = Screen::didClickButton(x, y);

  if (buttonClicked == 0) {
    if (!nameError) {
      dataController->setPlayerNames(textInBox);
      start_time = getCurrentTime();
      return 2;//return one cause want to advance to next screen in main class
    }
  }

  return -1;//else don't do anything, cause no buttons clicked
}

void NameScreen::isOnTextBoxes(int x, int y) {

  for (int i=0; i < 3; i++)
    isOverTextBox[i] = false;

  // check text boxes
  if (x >=450 && x <= 750) {
    if (y >= 300 && y <= 350)
      isOverTextBox[0] = true;
    else if (y >= 400 && y <= 450)
      isOverTextBox[1] = true;
    else if (y >= 500 && y <= 550)
      isOverTextBox[2] = true;
  }

}

void NameScreen::setTextBoxText(unsigned char theChar) {

  for (int i=0; i < 3; i++) {
    //only wanna change the text if the text box is clicked
    if (textBoxIsClicked[i]) {
      if ( '\b'==theChar || 127==theChar ) { // handle backspace
        if ( textInBox[i].length() > 0 ) {
          textInBox[i].erase(textInBox[i].end()-1);
          if (textInBox[i] == "") 
            nameError = true;
        }
      }
      else if ( theChar >= 32 && theChar <= 126 ) { // check for printable character
        // check that we don't overflow the box
        if ( textInBox[i].length() < 50 ) {
          textInBox[i] += theChar;
          if (nameError && !(textInBox[0] == "") && !(textInBox[1] == "") && !(textInBox[2] == ""))
            nameError = false;
        }
      }
      break;
    }
  }

}

void NameScreen::offButtons() {

  Screen::offButtons();

}
