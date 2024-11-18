#include <iostream>
#include "hangman.cpp"

using namespace std;

int main() {

    cout << "Welcome to Hangman! You're just in time for the execution!" << endl;

    string response;
    while(true) { // Guards against invalid input
        cout << "Would you like to play a game to save someone? (yes/no) ";
        cin >> response;

        if(response != "yes" && response != "no") {
            cout << "\nThat wasn't one of the options!" << endl;
        }
        else {
            break;
        }
    }

    if(response == "no") {
        cout << "\nHave a good day!";
        return 0;
    }

    Hangman hangman;
    hangman.play();
    
    return 0;
}