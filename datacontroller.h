#ifndef _DATACONTROLLER_
#define _DATACONTROLLER_

#include <string>
#include <vector>
#include <sstream>
// #include "professor.h"
// #include "building.h"
// #include "entertainmentbuilding.h"
// #include "foodbuilding.h"
// #include "academicbuilding.h"
// #include "sound.h"
#include "math.h"
// #include "people.h"
using namespace std;


class DataController {

  //scene and general user info
  string collegeName;
 //  SceneType sceneType;

 //  //user game information
 //  int userMoney;
 //  int userCapacity;//the capacity that the user sees
 //  int userPopulation;//the population that the user sees
 //  int backgroundCapacity;//the capacity that only the game knows
 //  int backgroundPopulation;//the population that only the game knows
 //  int tuition;//the tuition that the user has set
 //  StudentHappiness studentHappiness;
 //  double partialPopIncreaseUser;
 //  double partialPopIncreaseBackground;
  
 //  vector<Building*> buildings;
 //  //int totalAmountOfSavedGames;

 //  string errorMessage;
 //  string warningMessage;

 //  // FMOD::Sound *music;
 //  // bool musicPlaying;

 //  int studentsToDisplay;
 //  vector<People*> displayedStudents;

 // public: 
 //  vector<string> savedGames;
  

 public:

  DataController();
  ~DataController();

  //getter funtcions
 //  int getUserCapacity();
 //  int getUserPopulation();
 //  int getUserMoney();
 //  StudentHappiness getStudentHappiness();
 //  vector<Building*> getBuildings();
 //  int getTuition();
 //  string getCollegeName();
 //  SceneType getSceneType();
 //  string getErrorMessage();
 //  string getSavedGameName(int theIndexvector);
 //  string getWarningMessage();

 //  //setter functions
 //  void setCollegeName(string theCollegeName);
 //  void setInitialUserMoney(GameLevel theGameLevel);//this function only used to set the intial money based off the level screen
 //  void setSceneType(SceneType theSceneType);
 //  void setUserMoney(int theUserMoney);
 //  void setUserPopulation(int theUserPopulation);
 //  void setBackgroundCapacity(int theBackgroundCapacity);
 //  void setBackgroundPopulation(int theBackgroundPopulation);
 //  void setStudentHappiness(int theValue);
 //  void setTuition(int theTuition);
 //  // void setSoundtrack(FMOD::Sound *musicSetter);

 //  //adding functions
 //  bool addAcademicBuilding(BuildingSize theBuildingSize);
 //  bool addFoodBuilding(BuildingSize theBuildingSize);
 //  bool addEntertainmentBuilding(EntertainmentType theEntertainmentType);
 //  bool addProfessor(ProfessorLevel theProfessorLevel);

 //  //removing functions
 //  bool removeProfessor(ProfessorLevel theProfessorLevel, int theIndex);
 //  bool removeBuilding(int theIndex);

 //  //calculation functions
 //  void performTimeUpdate();

 //  //save and loading functions
 //  void saveGame(string gameName);
 //  void loadGame(int theIndex);
 //  void recordOfAllSavedGames();
 //  int getTotalAmountOfSavedGames();
 //  void getRecordOfAllSavedGames();
 //  void createBuildings(int buildingType, int buildingSize, int buildingPos);

 //  //music functions
 //  // void playMusic();
 //  // void turnOffMusic();
 //  // bool getMusicPlaying();

 //  //conversion
 //  int convertStringToInt(string theValue);

 //  //displayed students functions
 //  void calculateStudentsToDisplay();
 //  void setStartBuilding(int personNumber);
 //  void setEndBuilding(int personNumber);
 //  vector<People*> getPeople();
 //  void createPeople(int numberOfPeopleToCreate);
 //  void checkPositionOfDisplayedStudents();
 //  void movePeople();

 // private:

 //    int calculateChangeInMoney();
 //    double calculateBackgroundRatio();
 //    void calculateUserCapacity();
 //    int calculatePopulationIncreaseWithTuition(int populationIncrease);

};


#endif //_DATACONTROLLER_
