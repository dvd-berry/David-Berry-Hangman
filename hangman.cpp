#include <iostream>
#include <string>
#include <set>
#include <ctime>

using namespace std;

class Hangman {
private:
    //Variables for all game types
    const set<string> wordList = {"DITHYRAMBIC", "OSTENSIBLE", "INFINITESIMAL", "ANACHRONISM",
                    "DEMAGOGUE", "COLONEL", "CONVALESCENT", "ICONOCLAST", 
                    "PUGNACIOUS", "PEDANTRY"};
    set<string> usedWords;
    string targetWord;
    string displayWord; // Shows what has been correctly guessed with blanks for unknowns
    set<char> guesses;
    int lettersCorrect; // When equal to the number of letters in targetWord, the game is won
    bool playAgain;
    bool correct;
    int guessesWrong;
    int guessesRight;


    void toUppercase(char& c) {
        // Checks for lowercase letter and capitalizes using ASCII
        if(97 <= c && c <= 122)
            c -= 32;
        else if (!(65 <= c && c <= 90)) //Throws exception if input is not in the alphabet
            throw runtime_error("That is not a valid letter. Try again: ");
    }
    void displayGuesses() {
        cout << "\nTotal guesses: " << guessesRight + guessesWrong << endl;
        cout << "Correct guesses: " << guessesRight << endl;
        cout << "Incorrect guesses: " << guessesWrong << endl;
        cout << "Incorrect Letters: " << endl << endl;
        int i = 0;
        bool allRight = true; // Checks if all letters guessed have been correct
        string incorrectLetters = "";
        for (char c : guesses) {
            if (targetWord.find(c) == string::npos) { // TRUE if the letter is not in the targetWord
                incorrectLetters += c;
                incorrectLetters += ", ";
                ++i;
                allRight = false;
            }
            if (i % 5 == 0 && i > 0) // formatting
                incorrectLetters += "\n";
        }
        
        if(!incorrectLetters.empty()) {
        incorrectLetters.pop_back(); //Removes the final comma
        incorrectLetters.pop_back();
        }
        cout << incorrectLetters;
        if(allRight)
            cout << "None";
        cout << endl;
    }

    void guessLetters() {
        while (true) {
            cout << displayWord << endl;
            char letter = 0;
            string input;
            cout << "Guess a letter: ";
            while(true) { //Repeats if input is invalid
                input.clear();
                cin >> input;
                if(input.size() > 1) {
                    cout << "Please enter one character at a time. Try again: ";
                    continue;
                }
                letter = input[0]; // guards against entering multiple letters

                try {
                    toUppercase(letter);
                    if (guesses.find(letter) != guesses.end()) {
                    cout << "You have already guessed that letter. Try again: ";
                    continue;
                }
                    guesses.insert(letter);
                    break;
                } // catches if character is not a letter and displays
                catch (runtime_error e) {
                    cout << e.what();
                }

            }

            correct = false;

            for(int i = 0; i < targetWord.length(); i++) { // Sets display word
                if(targetWord[i] == letter) {
                    displayWord[i*2] = letter;
                    correct = true;
                    lettersCorrect++;
                }
            }
            if(lettersCorrect == targetWord.length()) {
                guessesRight++;
                winGame();
                return;

            }

            if(correct) {
                cout << "Correct! " << letter << " is in the word." << endl;
                guessesRight++;
            }
            else {
                cout << "Incorrect. " << letter << " is not in the word. " << endl;
                guessesWrong++;
            }

            displayGuesses();
        }
        
    }
    void winGame() {
        cout << "You got it! The word was " << targetWord << "!" << endl;
        cout << "\nTotal guesses: " << guessesRight + guessesWrong << endl;
        cout << "Correct guesses: " << guessesRight << endl;
        cout << "Incorrect guesses: " << guessesWrong << endl << endl;
        string response;
        while (true) { // Guards for invalid input
            cout << "Would you like to play again? (yes/no) ";
            cin >> response;

            if(response != "yes" && response != "no") {
                cout << "\nThat wasn't one of the options!" << endl;
            }
            else
                break;

        }
        if (response == "no") {
            playAgain = false;
        }
        else {
            cout << "Have fun! " << endl << endl;
            playAgain = true;
        }
    }
    
    void reset() { // prepares data for a new game
    if(usedWords.size() == wordList.size())
        usedWords.clear();
    displayWord = "";
    guesses.clear();
    lettersCorrect = 0;
    guessesRight = 0;
    guessesWrong = 0;


    while(usedWords.find(targetWord) != usedWords.end()) { // makes sure the word hasn't been used yet
            targetWord = *next(wordList.begin(), rand() % wordList.size());
        }
        usedWords.insert(targetWord);

        for(int i = 0; i < targetWord.length(); ++i) {
            displayWord += "_ ";
        }
    }

public:
    Hangman() : lettersCorrect(0), playAgain(false), correct(false), guessesRight(0), guessesWrong(0) {
        //wordList = {"DITHYRAMBIC", "OSTENSIBLE", "INFINITESIMAL", "ANACHRONISM",
       //             "DEMAGOGUE", "COLONEL", "CONVALESCENT", "ICONOCLAST", 
       //             "PUGNACIOUS", "PEDANTRY"};
        srand(time(0));

        // randomly initializes targetWord from wordList that hasn't been used yet
        while(usedWords.find(targetWord) == usedWords.end()) {
            targetWord = *next(wordList.begin(), rand() % wordList.size());
            usedWords.insert(targetWord);
        }
        

        for(int i = 0; i < targetWord.length(); ++i) {
            displayWord += "_ ";
        }
    }

    void play() {
        /* for (string word : wordList)
            cout << word << " ";
        cout << endl;
        cout << targetWord << endl;
        cout << displayWord << endl; */ //check values

        while(true) {
            cout << "You are going to guess a word. The word has " << targetWord.length() << " letters." << endl;
            guessLetters();
            if(!playAgain){
                cout << "Thanks for playing!" << endl;
                return;
            }
            reset();
        }
    }

};