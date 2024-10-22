//  Alex Hakimzadeh
//  CS2 Coding Project 0
//  2/2/22
//####################### 80 CHARACTERS ########################################
#include <iostream>

using namespace std;

struct robot {
    int x = 0;
    int y = 0;
    char lastCommand = 'x';
};
robot pos;
char choice;
void moveRobot (robot pos, char choice){
    do {
        // Get user input
        cout << "Select an option: ";
        cin >> choice;
        pos.lastCommand = choice;
        switch (choice){
            case 'U':
            case 'u':
                pos.y += 1;
                break;
            case 'D':
            case 'd':
                pos.y -= 1;
                break;
            case 'R':
            case 'r':
                pos.x += 1;
                break;
            case 'L':
            case 'l':
                pos.x -= 1;
                break;
            case 'Q':
            case 'q':
                cout << "Terminating program..." << endl;
                return;
            default:
                cout << "Error! Invalid Input. Try again." << endl;
        }
        // Update Robot position:
        cout << "Robot position: " << "(" << pos.x << "," << pos.y << ")";
        cout << "\nLast command: " << pos.lastCommand;
        cout << endl << endl;
    }while (choice != 'q' || choice != 'Q');
}

int main(int argc, const char * argv[]) {
    cout << "Robot's position is 0,0" << endl;
    // Option Choice Menu:
    cout << "Please select:" << endl;
    cout << "\tU - Move up 1" << endl << "\tD - Move down 1" << endl
        << "\tR - Move right 1" << endl << "\tL - Move left 1"
        << endl << "\tQ - Quit the program" << endl << endl;
    moveRobot (pos, choice);
    return 0;
}
