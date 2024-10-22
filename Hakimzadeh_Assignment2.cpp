//  Alex Hakimzadeh
//  CS2 Coding Project 2
//  3/9/22
//####################### 80 CHARACTERS########################################
#include <iostream>
#include <ctype.h>
using namespace std;

struct robot {
    int x = 0;
    int y = 0;
    char lastCommand = 'p';
    int speed = 1;
    int distance = 0;
    string name;
};

// Distances
// Parameters: List of robots, amount of robots
// Returns: none
// Side Effects: Uses bubble sorting algorithm to put distances in order
//              from least to greatest, then prints the distances
void distances (robot** roboList, int SIZE){
    for (int i = 0; i < SIZE; i++){
        for (int j = SIZE - 1; j > i; j--){
            if (roboList[j] -> distance > roboList[i] -> distance){
                robot* temp = roboList[i];
                roboList[i] = roboList[j];
                roboList[j] = temp;
            }
        }
    }
    // Print distances list:
    for (int k = 0; k < SIZE; k++){
        cout << roboList[k] -> name << "\t" << roboList[k] -> distance
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
        if (allBots[i]->name == ID){
            return i;
        }
    }
    return -1;
}

// Move Robot
// Parameters: robot struct
// Returns: n/a
// Side Effects: Changes position of chosen robot
void moveRobot (robot* r){
    
    // Option Choice Menu:
    cout << "Choose from the following:" << endl;
    cout << "\tU - Move up 1" << endl << "\tD - Move down 1" << endl
        << "\tR - Move right 1" << endl << "\tL - Move left 1"
        << endl << "\tQ - Back to main menu" << endl << endl;
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
        case 'u':
            r->y += r->speed;
            r->distance += r->speed;
            break;
        case 'D':
        case 'd':
            r->y -= r->speed;
            r->distance += r->speed;
            break;
        case 'R':
        case 'r':
            r->x += r->speed;
            r->distance += r->speed;
            break;
        case 'L':
        case 'l':
            r->x -= r->speed;
            r->distance += r->speed;
            break;
        case 'Q':
        case 'q':
            cout << "Redirecting..." << endl;
            return;
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

robot** makeBotList(int SIZE){
    robot** robotList = new robot*[SIZE];
    for (int i = 0; i < SIZE; i++){
       robotList[i] = new robot;
    }
    return robotList;
}

int main(int argc, const char * argv[]) {
    cout << "Welcome to MRG!" << endl;
    cout << "Enter amount of robots you'd like to track: " << endl;
    int numRobots;
    cin >> numRobots;
    robot** robotList = makeBotList(numRobots);
    cout << "Please enter a name for each of the " << numRobots
        << " robots: ";
    for (int i = 0; i < numRobots; i++){
        cin >> robotList[i]->name;
    }
    char menuChoice;
    string botName;
    int robotPlace;
    
    do {
        cout << "\nSelect from the following: \n";
        cout << "\tM-\tMove one robot.\n";
        cout << "\tD-\tPrint the distance each robot was moved.\n";
        cout << "\tQ-\tQuit the Program.\n";
        cin >> menuChoice;
        
        switch (menuChoice){
            case 'M':
            case 'm':
                cout << "Enter the robots name: ";
                cin >> botName;
                robotPlace = findRobot(robotList, numRobots, botName);
                if (robotPlace == -1){
                    cout << "The robot you named does not exist." << endl;
                }
                else {
                    moveRobot(robotList[robotPlace]);
                }
                break;
            case 'D':
            case 'd':
                cout << "\nDistances traveled by each robot:" << endl;
                distances(robotList, numRobots);
                break;
            case 'Q':
            case 'q':
                cout << "\nThanks for using MRG! Bye bye!" << endl;
                return 0;
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
