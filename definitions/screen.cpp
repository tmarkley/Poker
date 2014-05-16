#include "../headers/screen.h"

Screen::Screen(DataController *theDataController) {

  init(.35, .59, .999, theDataController);

}

Screen::Screen(double red, double green, double blue, DataController *theDataController) {

  init(red, green, blue, theDataController);

}

void Screen::init(double red, double green, double blue, DataController *theDataController) {

  // alertDialogShouldShow = false;
  // alertDialogMessage = "";
  // alertButtonIsAdded = false;

  // textBoxShouldShow = false;
  // textBoxMessage = "";
  // textInBox = "";
  // lastTextInBox = "";
  // textBoxButtonIsAdded = false;
  // isOverTextBox = false;
  
  dataController = theDataController;
  // hasTycoonLogo = hasTyLogo;

  backgroundColor.push_back(red);
  backgroundColor.push_back(green);
  backgroundColor.push_back(blue);
  
}

void Screen::draw(bool shouldDrawButtons) {

  //draw the background
  // glColor3f(backgroundColor[0], backgroundColor[1], backgroundColor[2]);
  // drawBox(0, 0, 850, 650);

  //if the screeen has the tycoon logo on it
  // if (hasTycoonLogo) {
  //   drawTexture(loadTexture("collegeTycoon.pam"), 100, 10, 650, 150);
  // }

  //draw the buttons on the screen
  if (shouldDrawButtons)
    drawButtons(0, buttons.size() - 1);

}

// void Screen::drawAlertDialog() {

//   int positionX = 75;
//   int positionY = 200;
//   int width = 700;
//   int height = 200;

//   if (alertDialogShouldShow) {

//     //drawTexture(loadTexture("darkalertbackground.pam"), 0,0,  850, 650, 1);

//     glColor3f(0, 0, 0);
//     drawBox(positionX - 5, positionY - 5, width + 10, height + 10);

//     glColor3f(1, 1, 1);
//     drawBox(positionX, positionY, width, height);

//     glColor3f(1, .9, 0);
//     drawTriangle(positionX + (width/2) - 75/2, positionY + 80, 75, 75);

//     glColor3f(1,1,1);
//     drawBox(positionX + (width/2) - (10/2) + 1, positionY + 20, 10, 45);
//     drawBox(positionX + (width/2) - (10/2) + 1, positionY + 67, 10, 10);

//     glColor3f(0,0,0);
//     int numPixelsOffset = 0;
//     for (int z = 0; z < alertDialogMessage.size(); z ++) {
//       numPixelsOffset += glutBitmapWidth(GLUT_BITMAP_HELVETICA_18, alertDialogMessage[z]);
//     }
//     drawText(alertDialogMessage, positionX + (width / 2) - (numPixelsOffset / 2), positionY + 125);

//     if (!alertButtonIsAdded) {
//       buttons.push_back(Button("Okay", 90, 45, positionX + (width/2) - 45, positionY + 145));
//       buttons[buttons.size() - 1].setColor(1, 0, 0);
//       buttons[buttons.size() - 1].setChangeColor(.7,0,0);
//       buttons[buttons.size() - 1].setClickedColor(.7,0,0);
//       alertButtonIsAdded = true;
//     }

//     drawButtons(buttons.size() - 1, buttons.size() - 1, 0);
//   }

// }

// void Screen::drawTextBox() {

//   int positionX = 75;
//   int positionY = 200;
//   int width = 700;
//   int height = 150;

//   if (textBoxShouldShow) {

//     glColor3f(0, 0, 0);
//     drawBox(positionX - 5, positionY - 5, width + 10, height + 10);

//     glColor3f(1, 1, 1);
//     drawBox(positionX, positionY, width, height);

//     //draw the message specified for the text box (centered in dialog box)
//     glColor3f(0,0,0);
//     int numPixelsOffset = getWidthOfString(textBoxMessage);
//     drawText(textBoxMessage, positionX + (width / 2) - (numPixelsOffset / 2), positionY + 30);
    
    
//     // draw text box
//     glColor3f(.25, .25, .25);  // dark gray
//     drawBox(positionX + 50, positionY + 50, width - 100, 50);
//     if (isOverTextBox)
//       glColor3f(1,1,1);  // light gray
//     else
//       glColor3f(.75, .75, .75);
//     drawBox(positionX + 55, positionY + 55, width - 110, 40);
//     glColor3f(0, 0, 0);  // black
//     drawText(textInBox, positionX + 60, positionY + 80);

//     if (!textBoxButtonIsAdded) {

//       buttons.push_back(Button("Okay", 90, 40, positionX + (width/2) - 45, positionY + 105));
//       buttons[buttons.size() - 1].setColor(1, 0, 0);
//       buttons[buttons.size() - 1].setChangeColor(.7,0,0);
//       buttons[buttons.size() - 1].setClickedColor(.7,0,0);
//       textBoxButtonIsAdded = true;

//     }

//     drawButtons(buttons.size() - 1, buttons.size() - 1, 0);

//   }

// }

// void Screen::setTextBoxText(unsigned char theChar) {
  
//   //only wanna change the text if the text box is highlighted
//   if (isOverTextBox) {
//     if ( '\b'==theChar || 127==theChar ) { // handle backspace
//       if ( textInBox.length() > 0 )
// 	textInBox.erase(textInBox.end()-1);
//     }
//     else if ( theChar >= 32 && theChar <= 126 ) { // check for printable character
//       // check that we don't overflow the box
//       if ( textInBox.length() < 50 )
// 	textInBox += theChar;
//     }
//   }

// }

void Screen::isOnButton(int x, int y) {
  
  for (int i = 0; i < buttons.size(); i ++) {//go through all of the buttons

    buttons[i].isOverButton(x, y);//check if the user is over one of the buttons
  }

}

int Screen::didClickButton(int x, int y) {
  
  // if (!alertButtonIsAdded && !textBoxButtonIsAdded) {//if the alert dialog isnt showing go through buttons like normal
  // cout << "number of buttons: " << buttons.size() << endl;
    for (int i = 0; i < buttons.size(); i ++) {//go through all the buttons for the class

      if (buttons[i].isClicked(x, y))//if a button was clicked
	     return i;//return the integer representing that button
    }

    return -1;//else if no button was clicked, return -1
 //  }
 //  else {//else if the alert dialog or text box is showing

 //    bool isTextBox = textBoxShouldShow;



 //    if (buttons[buttons.size() - 1].isClicked(x, y)) {

 //      if (textBoxShouldShow) {//should clear the text box so next time open blank, but save what was in it so can access it in sub class
	// lastTextInBox = textInBox;
	// textInBox = "";
 //      }

 //      alertDialogShouldShow = false;
 //      alertButtonIsAdded = false;
 //      textBoxButtonIsAdded = false;
 //      textBoxShouldShow = false;
 //      buttons.pop_back();


 //      if (isTextBox)//if text box want to return -3 cause only return -2 if its an alert dialog
 //      return -3;
 //    } 
    
 //    return -2;//return -2 because alert button was clicked, not text box
 //  }  

}

void Screen::offButtons() {

  for (int i = 0; i < buttons.size(); i ++) {//go through all of the buttons in the class

    buttons[i].offClick();//turn off the click color for each of them

  }

}

void Screen::drawButtons(int startIndex, int endIndex, int leftScreenX) {

  for (int i = startIndex; i <= endIndex; i ++) {//go through all of the buttons in the class

    buttons[i].draw(leftScreenX);//draw each button

  }

}

// string Screen::getLastTextInBox() {

//   string theText = lastTextInBox;
//   lastTextInBox = "";

//   return theText;

// }

// void Screen::setCurrentTime(double theCurrentTime) {

//   currentTime = theCurrentTime;

// }
