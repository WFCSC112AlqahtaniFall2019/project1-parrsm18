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
    int randXCoordinate = rand() % 3 + 1;
    int randYCoordinate = rand() % 3 + 1;

    int guessXCoordinate;
    int guessYCoordinate;

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
        cout << "Enter guess for column of ship: " << endl;
        cin >> guessXCoordinate;
        guessXCoordinate -= 1;
        cout << "Enter guess for row of ship: " << endl;
        cin >> guessYCoordinate;
        guessYCoordinate -= 1;

        if (guessXCoordinate == randXCoordinate && guessYCoordinate == randYCoordinate) {
            hit = true;
            battlefield.at(guessYCoordinate).at(guessXCoordinate) = "X";
            for (int i = 0; i < battlefield.size(); i++) {
                for (int j = 0; j < battlefield.at(i).size(); j++) {
                    cout << battlefield.at(i).at(j) << " ";
                }
                cout << endl;
                cout << "~~~~~~";
                cout << endl;
            }
            cout << "Hit!!! You sunk my battleship in " << numGuesses << endl;
        }
        else {
            battlefield.at(guessYCoordinate).at(guessXCoordinate) = "O";
            numGuesses++;
            cout << "Miss!!!" << endl;
        }
    }
}