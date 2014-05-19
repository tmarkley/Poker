#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include "headers/welcomescreen.h"
#include "headers/mainscreen.h"
#include "headers/button.h"
#include <sys/time.h>
#include <cstdlib>

using namespace std;

// FOR TESTING PURPOSES ONLY ///////////////////////////////////////////////////
string s1 = "3_hearts.pam";
string s2 = "4_diamonds.pam";
string s3 = "4_spades.pam";
string s4 = "3_diamonds.pam";
string s5 = "5_clubs.pam";
Card card1(s1);
Card card2(s2);
Card card3(s3);
Card card4(s4);
Card card5(s5);
// FOR TESTING PURPOSES ONLY ///////////////////////////////////////////////////

bool mouseIsDragging = false;

bool fullscreen = false;

bool onLoad = true;

int WIDTH = 1200;  // width of the user window (640 + 80)
int HEIGHT = 750;  // height of the user window (480 + 60)
char programName[] = "Poker";

double pi = 3.14159265;

// double lastTime;
// // double lastTimeSound;
// double lastTimePeople;
// double lastTimeScrolling;
// // double elapsedTimeSound;
// double elapsedTimePeople;

//FMOD::Sound *soundtrack;

enum ScreenType {WELCOME_SCREEN, MAIN_SCREEN};
ScreenType currentScreen =  WELCOME_SCREEN; //holds the current screen that we are on - intializes to the welcome screen

//initializes the data controller that does the main handling of the program... all the innards
DataController dataController;

//instantiates all the screens
MainScreen mainscreen(&dataController);
WelcomeScreen welcomescreen(&dataController);
Screen *screens[2] = {&welcomescreen, &mainscreen};

int currentMousePosition[] = {0, 0};


void drawWindow()
{
  // clear the buffer
  glClear(GL_COLOR_BUFFER_BIT);

  // glColor3f(.35, .59, .999);
  // drawTexture(loadTexture("backgrounds/welcomescreen.pam"), 0, 0, glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
  // drawBox(0, 0, 850, 650);
  // drawTexture(loadTexture("cards/A_hearts.pam"), 0, 0, 200, 286, 1, pi/4);

  // draw stuff
  //draw the current screen that we are on
  screens[currentScreen]->draw();

  // tell the graphics card that we're done-- go ahead and draw!
  //   (technically, we are switching between two color buffers...)
  glutSwapBuffers();
}

// process keyboard events
void keyboard( unsigned char c, int x, int y )
{
  int win = glutGetWindow();
  // screens[currentScreen]->setTextBoxText(c);
    
  switch(c) {
    case 'F':
    case 'f':
      if (!fullscreen)  {
        glutFullScreen();
        fullscreen = true;
      }
      else {
        glutReshapeWindow(WIDTH,HEIGHT);
        fullscreen = false;
      }
      break;
    case 'q':
    case 'Q':
    case 27:
      // get rid of the window (as part of shutting down)
      glutDestroyWindow(win);
      exit(0);
      break;
    default:
      break;
  }
  glutPostRedisplay();
}

void mouseCoords(int &x, int&y, int w2, int h2)
{
  int w = glutGet(GLUT_WINDOW_WIDTH);
  int h = glutGet(GLUT_WINDOW_HEIGHT);
  float ratiox = (float)w/(float)w2;
  float ratioy = (float)h/(float)h2;
  x/=ratiox;
  y/=ratioy;
}

// the reshape function handles the case where the user changes the size
//   of the window.  We need to fix the coordinate
//   system, so that the drawing area is still the unit square.
void reshape(GLsizei w, GLsizei h)
{
  // double ratio = WIDTH/HEIGHT;
  glViewport(0, 0, (GLsizei) w, (GLsizei) h);
  // // WIDTH = w;  HEIGHT = h;
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0., WIDTH, HEIGHT, 0., -1.0, 1.0);

}

// the mouse function is called when a mouse button is pressed down or released
void mouse(int button, int state, int x, int y)
{
  mouseCoords(x, y, WIDTH, HEIGHT);
  // cout << "x: " << x << ", y: " << y << endl;
  if ( GLUT_LEFT_BUTTON == button ) {
    if ( GLUT_DOWN == state ) { // the user just pressed down on the mouse-- do something
      mouseIsDragging = true;
      int newScreen = screens[currentScreen]->didClickButton(x, y);
      if (currentScreen != MAIN_SCREEN) {//if not on the main screen, should use these buttons to advance through the screens, else they are on the main screen buttons
        if (currentScreen == WELCOME_SCREEN && newScreen == MAIN_SCREEN) {
          currentScreen = MAIN_SCREEN;
        }
      }
    }
    //       mainscreen.generateDetailButtonsForLoadGame();

    //       switch (newScreen) {
    //         case(LEVEL_SCREEN):
	   //          currentScreen = LEVEL_SCREEN;
	   //          break;
	   //        case(GENERAL_SCREEN):
	   //          currentScreen = GENERAL_SCREEN;
	   //          break;
	   //        case(MAIN_SCREEN):
	   //          currentScreen = MAIN_SCREEN;
	   //          break;
	   //      }
    //   } 
    else {
      // the user just let go the mouse-- do something
      screens[currentScreen]->offButtons();
      mouseIsDragging = false;
    } 
  }
  else if ( GLUT_RIGHT_BUTTON == button ) {
    //blah
  }
  glutPostRedisplay();
}

// the mouse_motion function is called when the mouse is being dragged,
//   and gives the current location of the mouse
void mouse_motion(int x,int y)  {
  // the mouse is moving....

  mouseCoords(x, y, WIDTH, HEIGHT);

  currentMousePosition[0] = x;
  currentMousePosition[1] = y;

  screens[currentScreen]->isOnButton(x, y);
  
  glutPostRedisplay();
}

// the init function sets up the graphics card to draw properly
void init(void)
{

  // enable transparency for TRANSPARENT buttons.. aww yeah.
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  // clear the window to black
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  // set up the coordinate system:  number of pixels along x and y
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0., WIDTH, HEIGHT, 0., -1.0, 1.0);

  // Set the clipping volume
  // gluPerspective(45, 0.75, 0.1, 1000);
  // glMatrixMode(GL_MODELVIEW);
  // glLoadIdentity();
  // gluLookAt(0, 1.75, 5, 0, 1.75, 6, 0.0f, 1.0f, 0.0f);

  // welcome message
  cout << "Welcome to " << programName << "." << endl;

  // dataController.loadTextures();
}

// function to return the current time, in seconds, since Jan 1, 1970.
//   depends on the sys/time.h library
double getCurrentTime()
{
  struct timeval tv = {0,0};
  struct timezone tz;
  gettimeofday(&tv, &tz);
  // cout << "tv is " << tv.tv_sec << " micro " << tv.tv_usec << endl;
  return tv.tv_sec + tv.tv_usec/(double)1000000.;
  // return tv.tv_sec + tv.tv_usec;
}

void idle() {

  //if on the right side of the screen want to call the hovering function if on main screen so the screen can be moved to the right when hovering even if the mouse doesnt move
  // if ((currentMousePosition[0] > 750 || currentMousePosition[0] < 100) && currentScreen == MAIN_SCREEN) {
  //   screens[currentScreen] -> isOnButton(currentMousePosition[0], currentMousePosition[1]);
  // }
  
  // screens[currentScreen]->setCurrentTime(getCurrentTime());//set it so the scrolling text can use it and stuff

 // figure out whether it is time to change the counter.
  //   we want the counter to change once every 5  seconds, so we want the
  //   elapsed time (since the beginning of the program) 5 times the 
  //   elapsedTime (rounded down), or elapsedTime / 5.
  // double elapsedTime = getCurrentTime() - lastTime;
  // if ( (elapsedTime)  > 5 ) {

  //     dataController.performTimeUpdate();

  //     lastTime = getCurrentTime();

  //     glutPostRedisplay();

  // }

  //need to make sure to redraw enough to make the scrolling of the warning text consistent - so this matches the scrolling text
  // double elapsedTimeScrolling = getCurrentTime() - lastTimeScrolling;
  // if (elapsedTimeScrolling > .5) {

  //   glutPostRedisplay();

  // }


  // elapsedTimeSound = getCurrentTime() - lastTimeSound;
  // if ( (int) (elapsedTimeSound) > 54 ) {
  //   if (dataController.getMusicPlaying()) {
  //     dataController.turnOffMusic();
  //     dataController.playMusic();
  //   }
  //   lastTimeSound = getCurrentTime();
  //   }

  //if (screens[currentScreen]->screenShouldRedraw)
  //glutPostRedisplay();

  // elapsedTimePeople = getCurrentTime() - lastTimePeople;
  // if ( elapsedTimePeople > .01 ) {
  //   if (currentScreen == MAIN_SCREEN) {
  //     dataController.movePeople();
  //     dataController.checkPositionOfDisplayedStudents();
  //     lastTimePeople = getCurrentTime();
  //   }
  // }
}


// init_gl_window is the function that starts the ball rolling, in
//  terms of getting everything set up and passing control over to the
//  glut library for event handling.  It needs to tell the glut library
//  about all the essential functions:  what function to call if the
//  window changes shape, what to do to redraw, handle the keyboard,
//  etc.
void init_gl_window()
{
  char *argv[] = {programName};
  int argc = sizeof(argv) / sizeof(argv[0]);
  glutInit(&argc, argv);
  glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE );
  glutInitWindowSize(WIDTH,HEIGHT);
  glutInitWindowPosition(100,100);
  glutCreateWindow(programName);
  init();
  glutDisplayFunc(drawWindow);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutMouseFunc(mouse);
  glutMotionFunc(mouse_motion);
  glutPassiveMotionFunc(mouse_motion);
  glutIdleFunc(idle);
  glutMainLoop();
}

int main()

{
  // lastTime = getCurrentTime();
  // srand(time(0));
  // lastTimeSound = getCurrentTime();
  // lastTimeScrolling = getCurrentTime();
  // lastTimePeople = getCurrentTime();
  // dataController.getRecordOfAllSavedGames();
  // init_sound_system();
  //soundtrack = loadSoundFile("Daydream.wav");
  //dataController.setSoundtrack(soundtrack);
  // dataController.playMusic();
  init_gl_window(); 
}
