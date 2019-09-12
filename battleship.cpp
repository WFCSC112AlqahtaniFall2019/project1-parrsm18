#include <iostream>
#include <vector>
#include <ctime>
#include <string>
using namespace std;

int main() {
    //Specify number of rows and columns
    const int COL = 3;
    const int ROW = 3;

    bool hit = false;
    bool validColumn = false;
    bool validRow = false;

    //Create two-dimensional array
    vector<string> vec(COL, "!");
    vector<vector<string>> battlefield(ROW, vec);

    //Seed random number and create ship location
    srand(time(0));
    int randXCoordinate = rand() % COL;
    int randYCoordinate = rand() % ROW;

    //Following line is used for debugging purposes
    //cout << randXCoordinate + 1 << " " << randYCoordinate  + 1 << endl;

    //Initialize all other variables to be used
    char guessXCoordinate = 'A';
    char guessYCoordinate = 'A';
    char alphabet;

    int xCoordinate = 0;
    int yCoordinate = 0;

    int numGuesses = 0;

    //Begin game
    while (!hit) {
        //Print out board
        for (int i = 0; i < battlefield.size(); i++) {
            for (int j = 0; j < battlefield.at(i).size(); j++) {
                cout << battlefield.at(i).at(j) << " ";
            }
            cout << endl;
            for (int z = 0; z <= COL - 1; z++){
                cout << "~ ";
            }
            cout << endl;
        }

        //Asks user to guess column that ship is located in
        validColumn = false;
        while (!validColumn) {
            cout << "Enter guess for column of ship: (A for column 1, B for column 2, C for column 3 and so on...)" << endl;
            cin >> guessXCoordinate;
            if (guessXCoordinate >= 65 + COL || guessXCoordinate < 65) { // Checks to see if column entered is in the valid range
                cout << "Please enter a valid column" << endl;
            }
            else {
                validColumn = true;
            }
        }

        //between 65(A) and 90 (z)


        //Converts the character input of the user to the corresponding column with A -> Column 0, B -> Column 1, C -> Column 2 ...
        alphabet = 'A';
        for (int x = 0; x < COL; x++){
            if(guessXCoordinate == alphabet){
                xCoordinate = x;
                break;
            }
            alphabet += 1;
        }

        //Asks user to guess row that ship is located in
        validRow = false;
        while (!validRow) {
            cout << "Enter guess for row of ship: (A for row 1, B for row 2, C for row 3 and so on...)" << endl;
            cin >> guessYCoordinate;
            if (guessYCoordinate >= 65 + ROW || guessYCoordinate < 65) { // Checks to see if row entered is in the valid range
                cout << "Please enter a valid row" << endl;
            }
            else {
                validRow = true;
            }
        }

        // Resets the alphabet and converts the character input of the user to the corresponding row with A -> Row 0, B -> Row 1, C -> Row 2 ...
        alphabet = 'A';
        for (int y = 0; y < ROW; y++){
            if(guessYCoordinate == alphabet){
                yCoordinate = y;
                break;
            }
            alphabet += 1;
        }

        //This if statement executes if the user guesses the correct location and ends the program
        if (xCoordinate == randXCoordinate && yCoordinate == randYCoordinate) {
            numGuesses++;
            hit = true;
            battlefield.at(yCoordinate).at(xCoordinate) = "X";
            for (int i = 0; i < battlefield.size(); i++) {
                for (int j = 0; j < battlefield.at(i).size(); j++) {
                    cout << battlefield.at(i).at(j) << " ";
                }
                cout << endl;
                for (int z = 0; z <= COL - 1; z++){
                    cout << "~ ";
                }
                cout << endl;
            }
            cout << "Hit!!! You sunk my battleship in " << numGuesses << " guesses!" << endl;
        }

        //This else statement executes if the user guesses the wrong location and replaces that location with an O
        else {
            battlefield.at(yCoordinate).at(xCoordinate) = "O";
            numGuesses++;
            cout << "Miss!!!" << endl;
        }
    }
    return 0;
}