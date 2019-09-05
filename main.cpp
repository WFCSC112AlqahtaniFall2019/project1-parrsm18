#include <iostream>
#include <vector>
#include <ctime>
#include <string>
using namespace std;

int main() {
    const int COL = 3;
    const int ROW = 3;

    bool hit = false;

    vector<string> vec(COL, "!");
    vector<vector<string>> battlefield(ROW, vec);

    srand(time(0));
    int randXCoordinate = rand() % 3;
    int randYCoordinate = rand() % 3;
    //cout << randXCoordinate + 1 << " " << randYCoordinate  + 1<< endl;

    char guessXCoordinate;
    char guessYCoordinate;

    int xCoordinate = 0;
    int yCoordinate = 0;

    int numGuesses = 0;

    while (!hit) {
        for (int i = 0; i < battlefield.size(); i++) {
            for (int j = 0; j < battlefield.at(i).size(); j++) {
                cout << battlefield.at(i).at(j) << " ";
            }
            cout << endl;
            cout << "~~~~~~";
            cout << endl;
        }
        cout << "Enter guess for column of ship: (A for column 1, B for column 2, C for column 3)" << endl;
        cin >> guessXCoordinate;
        if (guessXCoordinate == 'A'){
            xCoordinate = 0;
        }
        else if (guessXCoordinate == 'B'){
            xCoordinate = 1;
        }
        else if (guessXCoordinate == 'C'){
            xCoordinate = 2;
        }
        cout << "Enter guess for row of ship: (A for row 1, B for row 2, C for row 3) " << endl;
        cin >> guessYCoordinate;
        if (guessYCoordinate == 'A'){
            yCoordinate = 0;
        }
        else if (guessYCoordinate == 'B'){
            yCoordinate = 1;
        }
        else if (guessYCoordinate == 'C'){
            yCoordinate = 2;
        }

        if (xCoordinate == randXCoordinate && yCoordinate == randYCoordinate) {
            numGuesses++;
            hit = true;
            battlefield.at(yCoordinate).at(xCoordinate) = "X";
            for (int i = 0; i < battlefield.size(); i++) {
                for (int j = 0; j < battlefield.at(i).size(); j++) {
                    cout << battlefield.at(i).at(j) << " ";
                }
                cout << endl;
                cout << "~~~~~~";
                cout << endl;
            }
            cout << "Hit!!! You sunk my battleship in " << numGuesses << " guesses!" << endl;
        }
        else {
            battlefield.at(yCoordinate).at(xCoordinate) = "O";
            numGuesses++;
            cout << "Miss!!!" << endl;
        }
    }
}