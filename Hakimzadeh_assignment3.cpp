//  Alex Hakimzadeh
//  CS2 Coding Project 3
//  4/6/2022
//####################### 80 CHARACTERS########################################
#include <iostream>
#include <ctype.h>
#include <string>
using namespace std;

class robot {
private:
    int x, y;
    char lastCommand = 'p';
    int speed = 1;
    int distance = 0;
    string name;
    
public:
    robot(){
        x = 0;
        y = 0;
    }
    bool stopped = false;
    int getDistance(){return distance;};
    string getName(){return name;};
    void setName(string n){name = n;}
    
    // Move Robot
    // Parameters: robots
    // Returns: n/a
    // Side Effects: Changes position of chosen robot
    void moveRobot (robot* r){
        
        // Option Choice Menu:
        cout << "Choose from the following:" << endl;
        cout << "\tU - Move up 1" << endl << "\tD - Move down 1" << endl
            << "\tR - Move right 1" << endl << "\tL - Move left 1"
            << endl << "\tS - Start or Stop" << endl
            << "\tQ - Back to main menu" << endl << endl;
            cout << "Select an option: ";
        char movementChoice;
        cin >> movementChoice;
        if(toupper(r->lastCommand) == toupper(movementChoice)){
            if(r->speed < 4){
                r->speed += 1;
            }
        }
        else {
            r->speed = 1;
        }
        
        switch (movementChoice){
            case 'U':
            case 'u':{
                if(r->stopped == true){
                    cout << "This robot cannot move.\n";
                }
                else {
                    r->y += r->speed;
                    r->distance += r->speed;
                }
                break;
            }
            case 'D':
            case 'd':{
                if(r->stopped == true){
                    cout << "This robot cannot move.\n";
                }
                else{
                    r->y -= r->speed;
                    r->distance += r->speed;
                }
                break;
            }
            case 'R':
            case 'r':{
                if(r->stopped == true){
                    cout << "This robot cannot move.\n";
                }
                else{
                    r->x += r->speed;
                    r->distance += r->speed;
                }
                break;
            }
            case 'L':
            case 'l':{
                if(r->stopped == true){
                    cout << "This robot cannot move.\n";
                }
                else{
                    r->x -= r->speed;
                    r->distance += r->speed;
                }
                break;
            }
            case 'S':
            case 's': {
                if (r->stopped == true) {
                    r->stopped = false;
                    cout << r->name << " has started moving\n";
                    r->speed = 1;
                }
                else {
                    r->stopped = true;
                    cout << r->name << " has stopped moving.\n";
                    r->speed = 0;
                }
                break;
            }
            case 'Q':
            case 'q':{
                cout << "Redirecting..." << endl;
                return;
            }
            default:
                cout << "Error! Invalid direction. Try again." << endl;
        }
        r->lastCommand = movementChoice;
        // Update Robot position:
        cout << r->name << "'s position: " << "(" << r->x
        << "," << r->y << ")\n";
        cout << "Last Command: " << r->lastCommand << endl;
        return;
    }
};

// Distances
// Parameters: List of robots, amount of robots
// Returns: none
// Side Effects: Uses bubble sorting algorithm to put distances in order
//              from least to greatest, then prints the distances
void distances (robot** roboList, int SIZE){
    for (int i = 0; i < SIZE; i++){
        for (int j = SIZE - 1; j > i; j--){
            if (roboList[j] -> getDistance() > roboList[i] -> getDistance()){
                robot* temp = roboList[i];
                roboList[i] = roboList[j];
                roboList[j] = temp;
            }
        }
    }
    // Print distances list:
    for (int k = 0; k < SIZE; k++){
        cout << roboList[k] -> getName() << "\t"
            << roboList[k] -> getDistance()
            << endl;
    }
}

// Find Robot
// Parameters: robot list, size of robot list, and name of each robot
// Returns -1 if robot name != ID and returns robot's position
// in array if name = ID
// Side effects: if -1 returned, bot not found, main prints error message
int findRobot (robot* allBots[], int SIZE, string ID){
    for (int i = 0; i < SIZE; i++){
        if (allBots[i]->getName() == ID){
            return i;
        }
    }
    return -1;
}

robot** makeBotList(int SIZE){
    robot** robotList = new robot*[SIZE];
    for (int i = 0; i < SIZE; i++){
       robotList[i] = new robot;
    }
    return robotList;
}

int main(int argc, const char * argv[]) {
    robot abc;
    cout << "Welcome to MRG!" << endl;
    cout << "Enter amount of robots you'd like to track: " << endl;
    int numRobots;
    cin >> numRobots;
    robot** robotList = makeBotList(numRobots);
    cout << "Please enter a name for each of the " << numRobots
        << " robots: ";
    string origName;
    for (int i = 0; i < numRobots; i++){
        cin >> origName;
        robotList[i]->setName(origName);
    }
    char menuChoice;
    string botName;
    int robotPlace;
    
    do {
        cout << "\nSelect from the following: \n";
        cout << "\tM-\tMove one robot.\n";
        cout << "\tD-\tPrint the distance each robot was moved.\n";
        cout << "\tR-\tRename a robot.\n";
        cout << "\tQ-\tQuit the Program.\n";
        cin >> menuChoice;
        
        switch (menuChoice){
            case 'M':
            case 'm':{
                cout << "Enter the robots name: ";
                cin >> botName;
                robotPlace = findRobot(robotList, numRobots, botName);
                if (robotPlace == -1){
                    cout << "The robot you named does not exist." << endl;
                }
                else {
                    abc.moveRobot(robotList[robotPlace]);
                }
                break;
            }
            case 'D':
            case 'd':{
                cout << "\nDistances traveled by each robot:" << endl;
                distances(robotList, numRobots);
                break;
            }
            case 'R':
            case 'r':{
                cout << "What robot do you want to change? ";
                cin >> botName;
                // Check to see if original name entered exists
                int roboIndex;
                roboIndex = findRobot(robotList, numRobots, botName);
                if (roboIndex == -1){
                    cout << "The robot you named does not exist." << endl;
                    break;
                }
                // Set new name
                else {
                    cout << "Enter " << botName << "'s new name: ";
                    string newName;
                    cin >> newName;
                    cout << botName << "'s name has changed to "
                        << newName <<  endl;
                    robotList[roboIndex]->setName(newName);
                break;
                }
            }
            case 'Q':
            case 'q':{
                cout << "\nThanks for using MRG! Bye bye!" << endl;
                return 0;
            }
            default: cout << "Error. Invalid choice. Do better next time.\n"
                    << endl;
        }
    }while (menuChoice != 'Q' || menuChoice != 'q');
    for (int i = 0; i < numRobots; i++){
        delete robotList[i];
    }
    delete robotList;
    return 0;
}
