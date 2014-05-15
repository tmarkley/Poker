#include "datacontroller.h"
#include <ostream>
#include <iostream>
#include <fstream>
using namespace std;

DataController::DataController() {

  collegeName = "";
  // sceneType = BEACH_SCENE;

  // userMoney = 0;
  // userCapacity = 0;
  // userPopulation = 0;
  // backgroundCapacity = 0;
  // backgroundPopulation = 1;
  // tuition = 0;
  // studentHappiness = HAPPY;
  // musicPlaying = false;
  // partialPopIncreaseUser = 0;
  // partialPopIncreaseBackground = 0;

}

DataController::~DataController(){
  // for(int i = 0; i < buildings.size(); i++){
  //   delete buildings[i];
  // }
}

// int DataController::getUserCapacity() {


//   return userCapacity;


// }

// int DataController::getUserPopulation() {

//   return userPopulation;

// }

// int DataController::getUserMoney() {

//   return userMoney;

// }

// int DataController::getTuition() {

//   return tuition;

// }

// string DataController::getCollegeName() {

//   return collegeName;

// }

// SceneType DataController::getSceneType() {

//   return sceneType;

// }

// string DataController::getErrorMessage() {

//   return errorMessage;

// }

// StudentHappiness DataController::getStudentHappiness() {

//   return studentHappiness;
  
// }

// string DataController::getWarningMessage() {

//   return warningMessage;

// }

// vector<Building*> DataController::getBuildings() {

//   return buildings;

// }

// bool DataController::addEntertainmentBuilding(EntertainmentType theEntertainmentType) {

//   //check to make sure can afford building and if so, subtract the right amount of  money
//   bool didBuy = false;

//   if (theEntertainmentType == SPORTS) {
//     if (userMoney - SPORTS_BUILDING_COST >= 0) {
//       userMoney -= SPORTS_BUILDING_COST;
//       didBuy = true;
//      }
//   }
//   else if (theEntertainmentType == MUSIC) {
//     if (userMoney - MUSIC_BUILDING_COST >= 0) {
//       userMoney -= MUSIC_BUILDING_COST;
//       didBuy = true;
//     }
//   }
//   else if (theEntertainmentType == MOVIE_THEATER) {
//     if (userMoney - MOVIE_THEATER_BUILDING_COST >= 0) {
//       userMoney -= MOVIE_THEATER_BUILDING_COST;
//       didBuy = true;
//     }
//   }
//   else if (theEntertainmentType == BOWLING) {
//     if (userMoney - BOWLING_BUILDING_COST >= 0) {
//       userMoney -= BOWLING_BUILDING_COST;
//       didBuy = true;
//     }
//   }
//   else { //REC_CENTER
//     if (userMoney - REC_CENTER_BUILDING_COST >= 0) {
//       userMoney -= REC_CENTER_BUILDING_COST;
//       didBuy = true;
//     }
//   }
//   if (didBuy) {
//     //need to find what the position of the new building is going to be
//     int theNewPosition;
//     if (buildings.empty()) {//if array is empty, the building has a position of zero cause its the first building
//       theNewPosition = 0;
//     }
//     else {//calculate position based off position of last building
//       Building *theLastBuilding = buildings[buildings.size() - 1];
//       theNewPosition = theLastBuilding->getPositionX() + theLastBuilding->getWidth() + 20;
//     }
//     //need to actually create the correct type of building subclass with the new position
//     Building *buildingToAdd =  new EntertainmentBuilding(theEntertainmentType, theNewPosition);

//     //add the building to the vector of buildings
//     buildings.push_back(buildingToAdd);

//     return true;//return true because can afford the building and it was added
//   }

//   errorMessage = "You don't have enough funds to construct this building.";//set the message describing why the building couldn't be made

//   return false;//return false cause can't afford the building so wasn't added


// }

// bool DataController::addFoodBuilding(BuildingSize theBuildingSize) {

//   //check to make sure can afford building and if so, subtract the right amount of  money
//   bool didBuy = false;

//   if (theBuildingSize == SMALL_BUILDING) {
//     if (userMoney - SMALL_CAFETERIUM_COST >= 0) {
//       userMoney -= SMALL_CAFETERIUM_COST;
//       didBuy = true;
//      }
//   }
//   else if (theBuildingSize == MEDIUM_BUILDING) {
//     if (userMoney - MEDIUM_CAFETERIUM_COST >= 0) {
//       userMoney -= MEDIUM_CAFETERIUM_COST;
//       didBuy = true;
//     }
//   }
//   else {
//     if (userMoney - LARGE_CAFETERIUM_COST >= 0) {
//       userMoney -= LARGE_CAFETERIUM_COST;
//       didBuy = true;
//     }
//   }

//   if (didBuy) {
//     //need to find what the position of the new building is going to be
//     int theNewPosition;
//     if (buildings.empty()) {//if array is empty, the building has a position of zero cause its the first building
//       theNewPosition = 0;
//     }
//     else {//calculate position based off position of last building
//       Building *theLastBuilding = buildings[buildings.size() - 1];
//       theNewPosition = theLastBuilding->getPositionX() + theLastBuilding->getWidth() + 20;
//     }

//     //need to actually create the correct type of building subclass with the new position
//     Building *buildingToAdd =  new FoodBuilding(theBuildingSize, theNewPosition);

//     //add the building to the vector of buildings
//     buildings.push_back(buildingToAdd);

//     return true;//return true because can afford the building and it was added
//   }

//   errorMessage = "You don't have enough funds to construct this sized cafeteria.";//set the message describing why the building couldn't be made

//   return false;//return false cause can't afford the building so wasn't added


// }

// bool DataController::addAcademicBuilding(BuildingSize theBuildingSize) {

//   //check to make sure can afford building and if so, subtract the right amount of  money
//   bool didBuy = false;

//   if (theBuildingSize == SMALL_BUILDING) {
//     if (userMoney - SMALL_ACADEMIC_BUILDING_COST >= 0) {
//       userMoney -= SMALL_ACADEMIC_BUILDING_COST;
//       didBuy = true;
//      }
//   }
//   else if (theBuildingSize == MEDIUM_BUILDING) {
//     if (userMoney - MEDIUM_ACADEMIC_BUILDING_COST >= 0) {
//       userMoney -= MEDIUM_ACADEMIC_BUILDING_COST;
//       didBuy = true;
//     }
//   }
//   else {
//     if (userMoney - LARGE_ACADEMIC_BUILDING_COST >= 0) {
//       userMoney -= LARGE_ACADEMIC_BUILDING_COST;
//       didBuy = true;
//     }
//   }

//   if (didBuy) {
//     //need to find what the position of the new building is going to be
//     int theNewPosition;
//     if (buildings.empty()) {//if array is empty, the building has a position of zero cause its the first building
//       theNewPosition = 0;
//     }
//     else {//calculate position based off position of last building
//       Building *theLastBuilding = buildings[buildings.size() - 1];
//       theNewPosition = theLastBuilding->getPositionX() + theLastBuilding->getWidth() + 20;
//     }

//     //need to actually create the correct type of building subclass with the new position
//     Building *buildingToAdd =  new AcademicBuilding(theBuildingSize, theNewPosition);

//     //add the building to the vector of buildings
//     buildings.push_back(buildingToAdd);

//     return true;//return true because can afford the building and it was added
//   }

//   errorMessage = "You don't have enough funds to construct this building.";//set the message describing why the building couldn't be made

//   return false;//return false cause can't afford the building so wasn't added


// }

// bool DataController::addProfessor(ProfessorLevel theProfessorLevel) {

//   //check to make sure can afford professor and if so subtract the money
//   bool didBuy = false;
  
//   if (theProfessorLevel == WORST) {
//     if (userMoney - WORST_PROFESSOR_COST >= 0) {
//       userMoney -= WORST_PROFESSOR_COST;
//       didBuy = true;
//     }
//   }
//   else if (theProfessorLevel == MIDDLE) {
//     if (userMoney - MIDDLE_PROFESSOR_COST >= 0) {
//       userMoney -= MIDDLE_PROFESSOR_COST;
//       didBuy = true;
//     }
//   }
//   else {//the best professor
//     if (userMoney - BEST_PROFESSOR_COST >= 0) {
//       userMoney -= BEST_PROFESSOR_COST;
//       didBuy = true;
//     }
//   }
 
//   bool didAdd = false;
//   //if could afford the professor, try adding it to a building
//   if (didBuy) {
//     AcademicBuilding *theBuilding;
//     //go through all buildings and try to add a professor to them, if add successfully, then return true
//     for (int z = 0; z < buildings.size(); z ++) {
//       if (buildings[z]->getBuildingType() == ACADEMIC) {
// 	theBuilding = static_cast<AcademicBuilding *>(buildings[z]);
// 	if (theBuilding->addProfessor(theProfessorLevel)) {
// 	  didAdd = true;
// 	  break;
// 	}
//       }
//     }
//   }

//   if (didAdd) {//if successfully added to a building and could be afforded, return that the professor was added
//     return true;
//   }

//   errorMessage = "You don't have the funds required to hire that professor.";
  

//   //if dont add a professor successfuly the return false, and if did buy it then subtract the money added
//   if (didBuy) {

//     if (theProfessorLevel == WORST)
//       userMoney += WORST_PROFESSOR_COST;
//     else if (theProfessorLevel == MIDDLE)
//       userMoney += MIDDLE_PROFESSOR_COST;
//     else //the best professor
//       userMoney += BEST_PROFESSOR_COST;

//     //since could buy, but couldnt add, the problem must be capacity related
//     errorMessage = "All of your buildings are at full capacity. Buy a new building or fire a professor.";
//   }

//   return false;

// }

// void DataController::setInitialUserMoney(GameLevel theGameLevel) {

//   switch (theGameLevel) {

//   case EASY_LEVEL:
//     userMoney = STARTING_USER_MONEY_EASY;
//     break;
   
//   case MEDIUM_LEVEL:
//     userMoney = STARTING_USER_MONEY_MEDIUM;
//     break;

//   case HARD_LEVEL:
//     userMoney = STARTING_USER_MONEY_HARD;
//     break;

//   };

// }

// void DataController::setCollegeName(string theCollegeName) {

//   collegeName = theCollegeName;

// }

// void DataController::setSceneType(SceneType theSceneType) {

//   sceneType = theSceneType;

// }

// void DataController::setTuition(int theTuition) {

//   tuition = theTuition;

// }

// void DataController::setUserPopulation(int theUserPopulation){
//   userPopulation = theUserPopulation;
// }

// void DataController::setBackgroundCapacity(int theBackgroundCapacity){
//   backgroundCapacity = theBackgroundCapacity;
// }

// void DataController::setBackgroundPopulation(int theBackgroundPopulation){
//   backgroundPopulation = theBackgroundPopulation;
// }

// void DataController::setStudentHappiness(int theStudentHappinessVal){
//   if(theStudentHappinessVal == 0){
//     studentHappiness = HAPPY;
//   }
//   else if(theStudentHappinessVal == 1){
//     studentHappiness = NEUTRAL;
//   }
//   else studentHappiness = SAD;
// }

// void DataController::createBuildings(int buildingType, int buildingSize, int buildingPosition){
//   int width;
//   if(buildingType == 0){
//     EntertainmentType entertainmentTypeVal;
//     if(buildingSize == 0){
// 	entertainmentTypeVal = SPORTS;
//       }
//       else if (buildingSize == 1){
// 	entertainmentTypeVal = MUSIC;
//       }
//       else if (buildingSize == 2){
// 	entertainmentTypeVal = MOVIE_THEATER;
//       } 
//       else if (buildingSize == 3){
// 	entertainmentTypeVal = BOWLING;
//       }
//       else if (buildingSize == 4){
// 	entertainmentTypeVal = REC_CENTER;
//       }
//       addEntertainmentBuilding(entertainmentTypeVal);
//   }
//   else if (buildingType == 1){
//     BuildingSize buildingSizeVal;
//     if ( buildingSize == 0){
//       buildingSizeVal = SMALL_BUILDING;
//     }
//     else if (buildingSize == 1){
//       buildingSizeVal = MEDIUM_BUILDING;
//     }
//     else if (buildingSize == 2){
//       buildingSizeVal = LARGE_BUILDING;
//     }
//     addAcademicBuilding(buildingSizeVal);
//   }
//   else if (buildingType == 2){
//     BuildingSize buildingSizeVal;
//     if ( buildingSize == 0){
//       buildingSizeVal = SMALL_BUILDING;
//     }
//     else if (buildingSize == 1){
//       buildingSizeVal = MEDIUM_BUILDING;
//     }
//     else if (buildingSize == 2){
//       buildingSizeVal = LARGE_BUILDING;
//     }
//     addFoodBuilding(buildingSizeVal);
//   }
// }

// bool DataController::removeProfessor(ProfessorLevel theProfessorLevel, int theIndex) {

//    //for each professor, see if it is of the right level
//   AcademicBuilding *theAcademicBuilding = static_cast<AcademicBuilding *>(buildings[theIndex]);
 
//   return theAcademicBuilding->removeProfessor(theProfessorLevel);
// }

// bool DataController::removeBuilding(int theIndex) {

//   //need to get the width of the building before deleting it so can move all other buildings back the width of the building
//   int theWidth = buildings[theIndex]->getWidth();

//   //remove building and deallocate memory
//   delete buildings[theIndex];
//   buildings.erase(buildings.begin() + theIndex);

//   //for all buildings after the one deleted, go through and adjust the new position x by the width of the old building minus the 20 pixel space in between
//   for (int z = theIndex; z < buildings.size(); z ++) {

//     buildings[z]->setPositionX(buildings[z]->getPositionX() - theWidth - 20);
    
//   }

// }

// //all the calculational functions are down here

// void DataController::performTimeUpdate() {

//   calculateUserCapacity();
//   double backgroundRatio = calculateBackgroundRatio();
 
//   if (userPopulation == 0) {
//     warningMessage = "You don't have any students. Try constructing some buildings and hiring some professors to start your college  .";
//     studentHappiness = HAPPY;
//   }
//   //need to set the enum student happiness based on the returned background ratio
//   else if (backgroundRatio > .9)
//     studentHappiness = SAD;
//   else if (backgroundRatio >= .7)
//     studentHappiness = NEUTRAL;
//   else
//     studentHappiness = HAPPY;

//   //now that have the background ratio, need to find the population increases using our algorithm
//   int userPopulationIncrease;
//   int backgroundPopulationIncrease;
  
//   //need it to decrease at least a little bit
//   if (backgroundRatio >= 1) {
//     backgroundRatio = .99;
//   }

  
//   if (backgroundRatio > .9) {
//     if (warningMessage != "The students are feeling a little rumbly in the tumbly. Give them somewhere to eat  ." && userPopulation != 0)
//     warningMessage = "The students are complaining that the college is quite crowded. Try building some new buildings or adding more professors  .";
//     partialPopIncreaseUser = -(pow(backgroundRatio, 35) * userCapacity);
//     partialPopIncreaseBackground = -(pow(backgroundRatio, 35) * backgroundCapacity);
//   }
//   else if (backgroundRatio >= .7) {
//     if (warningMessage != "The students are feeling a little rumbly in the tumbly. Give them somewhere to eat  .")
//     warningMessage = "The students are starting to feel quite cramped for their style. Try adding some entertainment to lighten the mood  .";
//     partialPopIncreaseUser += (pow(1 -backgroundRatio, 4) * userCapacity);
//     partialPopIncreaseBackground += (pow(1 -backgroundRatio, 4) * backgroundCapacity);
//   }

//   else {//backgroundRatio <.7
//     //dont want it to immediately go up to full capacity, or go up to fast at all really
//     if (backgroundRatio < .3) {
//       backgroundRatio = .3;
//     }
//     if (warningMessage != "The students are feeling a little rumbly in the tumbly. Give them somewhere to eat  .")
//     warningMessage = "The student body approves of your buildilishessness. Keep up the great work  !";

//     partialPopIncreaseUser += (pow(1 -backgroundRatio, 5) * userCapacity);
//     partialPopIncreaseBackground += (pow(1 -backgroundRatio, 5) * backgroundCapacity);

//   }

//   if (userMoney < 0)
//     warningMessage = "You're bleeding money! Try increasing the tuition before you go bankrupt  !";

//   if (partialPopIncreaseUser < 1 && partialPopIncreaseUser > -1) {
//     userPopulationIncrease = 0;
//   }
//   else {
//     userPopulationIncrease = partialPopIncreaseUser;
//     partialPopIncreaseUser = 0;
//   }

//   if (partialPopIncreaseBackground < 1 && partialPopIncreaseBackground > -1) {
//     backgroundPopulationIncrease = 0;
//   }
//   else {
//     backgroundPopulationIncrease = partialPopIncreaseBackground;
//     partialPopIncreaseBackground = 0;
//   }

//   userPopulationIncrease = calculatePopulationIncreaseWithTuition(userPopulationIncrease);
//   backgroundPopulationIncrease = calculatePopulationIncreaseWithTuition(backgroundPopulationIncrease);

//   if ((userPopulation + userPopulationIncrease) > userCapacity)
//     userPopulation = userCapacity;
//   else if ((userPopulation + userPopulationIncrease) < 0)
//     userPopulation = 0;
//   else
//     userPopulation += userPopulationIncrease;
  
//   if ((backgroundPopulation + backgroundPopulationIncrease) > backgroundCapacity)
//     backgroundPopulation = backgroundCapacity;
//   else if ((backgroundPopulation + backgroundPopulationIncrease) < 0)
//     backgroundPopulation = 0;
//   else
//     backgroundPopulation += backgroundPopulationIncrease;
  
//   calculateChangeInMoney();

//   //calculate students to draw based off new population
//   if (buildings.size() != 0) {
//     calculateStudentsToDisplay();
//     createPeople(studentsToDisplay);
//   }
//   else {
//     createPeople(0);

//   }
// }

// int DataController::calculateChangeInMoney() {

//   int revenue = userPopulation * tuition;

//   int totalMaintenanceCost = 0;
//   for (int z = 0; z < buildings.size(); z++) {

//     totalMaintenanceCost += buildings[z]->getMaintenanceCost();

//   }

//   revenue -= totalMaintenanceCost;
  
//   userMoney += revenue;

// }

// void DataController::calculateUserCapacity() {

//   int totalUserCapacity = 0;

//   for (int z = 0; z < buildings.size(); z ++) {
//     //only want to add the capacities of academic building cause other ones dont count for user capacity
//     if ((buildings[z]->getBuildingType() == ACADEMIC)) 
//       totalUserCapacity += buildings[z]->getUserCapacity();
//   }

//   userCapacity = totalUserCapacity;

// }

// int DataController::calculatePopulationIncreaseWithTuition(int populationIncrease) {

//   double suggestedTuition = 80;
//   if (studentHappiness == HAPPY)
//     suggestedTuition = 80;
//   else if (studentHappiness == NEUTRAL)
//     suggestedTuition = 50;
//   else
//     suggestedTuition = 30;

//   if (tuition > suggestedTuition) {

//     double tuitionRatio = (suggestedTuition) / ((double) tuition);
    
//     //if less than or equal to .5, the tuition is double suggested tuition, so want population to decrease overall
//     if (tuitionRatio <= .5) {
//       warningMessage = "The students are complaining that their tuition is quite high. Consider lowering it  .";
//       populationIncrease = (double) (populationIncrease * (-(1-tuitionRatio)) - 1);
//       studentHappiness = NEUTRAL;//students should be sad cause they are leaving

//       if (populationIncrease > -1) {//if almost near capacity, should still  decrease a little bit each time if the tuition is too high, but decrease based off amount above tuition
// 	populationIncrease = -1;
//       }
//     }
//     else {
//       warningMessage = "The students are saying the college's tuition is rising fast. Be careful  .";
//       populationIncrease = populationIncrease * tuitionRatio;
//       studentHappiness = NEUTRAL;//students should be neutral since tuition is not high but it is not super low
//     }

//   }

//   return populationIncrease;
// }

// double DataController::calculateBackgroundRatio() {

//   int totalBackgroundCapacity = 0;
//   int totalCafeteriumCapacity = 0;
//   for (int z = 0; z < buildings.size(); z ++) {

//     //only want to add the capacities of academic and entertainment cause cafeteria capacity is treated differently
//     if ((buildings[z]->getBuildingType() == ACADEMIC) || (buildings[z]->getBuildingType()==ENTERTAINMENT)) 
//       totalBackgroundCapacity += buildings[z]->getBackgroundCapacity();
//     else//if it is a cafeterium
//       totalCafeteriumCapacity += buildings[z]->getBackgroundCapacity();
//   }
  
//   //if have more students than the cafeterias can handle, then should decrease capacity by the number that you are over
//   int amountToDecrease = 0;
//   if (userPopulation > totalCafeteriumCapacity) {
//     warningMessage = "The students are feeling a little rumbly in the tumbly. Give them somewhere to eat  .";
//     amountToDecrease = totalCafeteriumCapacity - userPopulation;
//   }
//   else {
//     warningMessage = "";
//   }

//   totalBackgroundCapacity += amountToDecrease;
//   if (totalBackgroundCapacity < 0)//dont want it to decrease less than zero though
//     totalBackgroundCapacity = 0;
//   backgroundCapacity = totalBackgroundCapacity;

//   double backgroundRatio = 0;
//   if (backgroundCapacity == 0) {
//     backgroundCapacity = 1;
//   }
//   backgroundRatio = ((double) backgroundPopulation / (double) backgroundCapacity);
  
//   return backgroundRatio;
    
// }


// //music stuff is down here
// // void DataController::setSoundtrack (FMOD::Sound *musicSetter) {

// //   music = musicSetter; 

// // }

// // void DataController::playMusic() {

// //   playSound(music, 0);
// //   musicPlaying = true;

// // }

// // void DataController::turnOffMusic(){
// //   setPaused(0,true);
// //   musicPlaying = false;
// // }

// // bool DataController::getMusicPlaying() {

// //   return musicPlaying;

// // }


// void DataController::setUserMoney(int theMoney){
//   userMoney = theMoney;
// }

// void DataController::loadGame(int theIndex){
//   string gameFile = savedGames[theIndex] + ".txt";
//   string fileName;
//   string collegeName;
//   string sceneTypeVal, userMoney, userPopulation, backgroundCapacity,backgroundPopulation, tuition, studentHappiness, blank, amountOfBuildings;
//   ifstream g(gameFile.c_str());
//   getline(g,fileName);
//   getline(g,collegeName);
//   getline(g,sceneTypeVal);
//   SceneType savedScene;
//   if(convertStringToInt(sceneTypeVal) == 0){
//     savedScene = BEACH_SCENE;
//   }
//   else if (convertStringToInt(sceneTypeVal) == 1 ){
//     savedScene = MOUNTAIN_SCENE;
//   }
//   else if (convertStringToInt(sceneTypeVal) == 2) {
//     savedScene = CITY_SCENE;
//   }
//   else {
//     savedScene = TOWN_SCENE;
//   }
//   setSceneType(savedScene);
//   getline(g,userMoney);
//   int startingVal = 1000000;
//   int userMoneyVal = convertStringToInt(userMoney);
//   setUserMoney(startingVal);
//   getline(g,userPopulation);
//   int userPopulationVal = convertStringToInt(userPopulation);
//   setUserPopulation(userPopulationVal);
//   getline(g,backgroundCapacity);
//   int backgroundCapacityVal = convertStringToInt(backgroundCapacity);
//   setBackgroundCapacity(backgroundCapacityVal);
//   getline(g,backgroundPopulation);
//   int backgroundPopulationVal = convertStringToInt(backgroundPopulation);
//   setBackgroundPopulation(backgroundPopulationVal);
//   getline(g,tuition);
//   int tuitionVal = convertStringToInt(tuition);
//   setTuition(tuitionVal);
//   getline(g,studentHappiness);
//   int studentHappinessVal = convertStringToInt(studentHappiness);
//   setStudentHappiness(studentHappinessVal);
//   getline(g,blank);
//   getline(g,blank);
//   getline(g,amountOfBuildings);
//   int amountOfBuildingsVal = convertStringToInt(amountOfBuildings);
//   string buildingName, buildingType, buildingSize, goodProfessors, middleProfessors, badProfessors, buildingPosition;
//     for(int x = 0; x < amountOfBuildingsVal; x++){
//       getline(g,buildingName);
//       getline(g,buildingType);
//       getline(g,buildingSize);
//       getline(g,buildingPosition);
//       int buildingTypeVal = convertStringToInt(buildingType);
//       int buildingSizeVal = convertStringToInt(buildingSize);
//       int buildingPositionVal = convertStringToInt(buildingPosition);
//       createBuildings(buildingTypeVal, buildingSizeVal, buildingPositionVal);
//       if(buildingTypeVal == 1){
// 	getline(g, badProfessors);
// 	getline(g, middleProfessors);
// 	getline(g, goodProfessors);
// 	int badProfessorsVal = convertStringToInt(badProfessors);
// 	for(int i = 0; i < badProfessorsVal; i++){
// 	  addProfessor(WORST);
// 	}
// 	int middleProfessorsVal = convertStringToInt(middleProfessors);
// 	for(int x = 0; x < middleProfessorsVal; x++){
// 	  addProfessor(MIDDLE);
// 	}
// 	int goodProfessorsVal = convertStringToInt(goodProfessors);
// 	for(int p = 0; p < goodProfessorsVal; p++){
// 	  addProfessor(BEST);
// 	}
//       }
//       getline(g, blank);
//     }
//   setUserMoney(userMoneyVal);
//   g.close();
// }

// void DataController::saveGame(string theGameTitle){
//   bool isSaved = false;
//   for(int z  = 0; z < savedGames.size(); z++) {
    
//     if (savedGames[z] == theGameTitle)
//       isSaved = true;

//   }
//   if (!isSaved)
//     savedGames.push_back(theGameTitle);
//   string theGameFile = theGameTitle + ".txt";
//   ofstream f(theGameFile.c_str());
//   f << theGameTitle << endl;
//   f << collegeName << endl;
//   f << sceneType << endl;
//   f << userMoney << endl;
//   f << userPopulation << endl;
//   f << backgroundCapacity << endl;
//   f << backgroundPopulation << endl;
//   f << tuition << endl;
//   f << studentHappiness << endl;
//   f << endl << "Amount of buildings" << endl;;
//   f << buildings.size();
//   for(int i = 0; i < buildings.size(); i++){
//     f << endl << "Building" << i + 1;
//     f << buildings[i]->getName() << endl;
//     f << buildings[i]->getBuildingType() << endl;
//     if ( buildings[i]->getBuildingType() == 0){
//       EntertainmentBuilding *theEntertainmentBuilding = static_cast<EntertainmentBuilding *>(buildings[i]);				        		     f <<  theEntertainmentBuilding->getEntertainmentType(*theEntertainmentBuilding) << endl;		        }
//     else if (buildings[i]->getBuildingType() == 1){
//       AcademicBuilding *theAcademicBuilding = static_cast<AcademicBuilding *>(buildings[i]);
//       f <<  theAcademicBuilding->getAcademicBuildingSize(*theAcademicBuilding) << endl;	
//     }
//     else {
//       FoodBuilding *theFoodBuilding = static_cast<FoodBuilding *>(buildings[i]);
//       f <<  theFoodBuilding->getFoodBuildingSize(*theFoodBuilding) << endl;	
//     }
//     f << buildings[i]->getPositionX() << endl; 
//     if ( buildings[i]->getBuildingType() == 1){
//       AcademicBuilding *theAcademicBuilding = static_cast<AcademicBuilding *>(buildings[i]);
//       f <<  theAcademicBuilding->getNumProfessor(WORST) << endl;
//       f <<  theAcademicBuilding->getNumProfessor(MIDDLE) << endl;
//       f <<  theAcademicBuilding->getNumProfessor(BEST) << endl;
//     }
//   }
//   f << endl  <<"end" << endl;
//   ofstream m("savedGames.txt");
//   m << savedGames.size() << endl;
//   for(int x = 0; x < savedGames.size(); x++){
//     m << savedGames[x] << endl;
//   }
//   m.close();
//   f.close();
// }

// int DataController::getTotalAmountOfSavedGames(){
//   int totalAmountOfSavedGames;
//   ifstream g("savedGames.txt");
//   if (g.good()){
//     g >> totalAmountOfSavedGames;
//   }
//   return totalAmountOfSavedGames;
// }


// void DataController::getRecordOfAllSavedGames(){
//   ifstream p("savedGames.txt");
//   string gameName;
//   getline(p,gameName);
//     for(int i = 0; i < getTotalAmountOfSavedGames();i++){
//       getline(p,gameName);
//       savedGames.push_back(gameName);
//   }
//   p.close();
// }

// string DataController::getSavedGameName(int theIndex){
//   return savedGames[theIndex];
// }

// int DataController::convertStringToInt(string toConvert){
//   istringstream convert(toConvert);
//   int convertedVal;
//   convert >> convertedVal;
//   return convertedVal;
// }

// void DataController::calculateStudentsToDisplay () {

//   studentsToDisplay = userPopulation;

// }

// void DataController::setStartBuilding (int personNumber) {
//   if (buildings.size() != 0) {
//     int buildingChosen = rand() % buildings.size();
//     displayedStudents[personNumber]->setStartingPositionX(buildings[buildingChosen]->getPositionX()+(buildings[buildingChosen]->getWidth()/2));
//     displayedStudents[personNumber]->setPositionX(buildings[buildingChosen]->getPositionX()+(buildings[buildingChosen]->getWidth()/2));
//   }

// }

// vector<People*> DataController::getPeople() {

//   return displayedStudents;

// }

// void DataController::setEndBuilding (int personNumber) {
//   if (buildings.size() != 0) {
//     int buildingChosen = rand() % buildings.size();
//     displayedStudents[personNumber]->setEndingPositionX(buildings[buildingChosen]->getPositionX()+(buildings[buildingChosen]->getWidth()/2));
//   }

// }

// void DataController::checkPositionOfDisplayedStudents() {

//   for (int i = 0; i < displayedStudents.size(); i++) {
//     if (displayedStudents[i]->getStartingPositionX() > displayedStudents[i]->getEndingPositionX()) {
//       if (displayedStudents[i]->getPositionX() <= displayedStudents[i]->getEndingPositionX()) {
// 	setStartBuilding(i);
// 	setEndBuilding(i);
//       }
//     }
//     else if (displayedStudents[i]->getStartingPositionX() < displayedStudents[i]->getEndingPositionX()) {
//       if (displayedStudents[i]->getPositionX() >= displayedStudents[i]->getEndingPositionX()) {
// 	setStartBuilding(i);
// 	setEndBuilding(i);
//       }
//     }
//     else {
//       setStartBuilding(i);
//       setEndBuilding(i);    

//     }
//   }
// }

// void DataController::createPeople(int numberOfPeopleToCreate) {
//   int currentStudentSize = displayedStudents.size();
//   if (numberOfPeopleToCreate < 0) {
//     for (int i = (currentStudentSize-1)+numberOfPeopleToCreate; i < currentStudentSize; i++) {
//       delete displayedStudents[i];
//       displayedStudents.pop_back();
//     }
//   }
//   else if (numberOfPeopleToCreate == 0) {

//     for (int i = currentStudentSize - 1; i >= 0; i--) {
//       delete displayedStudents[i];
//       displayedStudents.pop_back();
//     }
//   }
//   else {
//     if (displayedStudents.size() < numberOfPeopleToCreate) {
//       for (int i = 0; i < (numberOfPeopleToCreate-currentStudentSize); i++)
// 	{
// 	  People *personToAdd = new People(); 
// 	  displayedStudents.push_back(personToAdd);
// 	}
//     }
    
//     for (int i = currentStudentSize; i < displayedStudents.size(); i++) {
//       setStartBuilding(i);
//       setEndBuilding(i);
//     }
//   }
// }

// void DataController::movePeople() { 
//   for (int i = 0; i < displayedStudents.size(); i++)
//     displayedStudents[i]->movePosition();
//     }
