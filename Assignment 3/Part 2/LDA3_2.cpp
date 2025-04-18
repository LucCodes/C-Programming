#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// i made the computer slightly annoying to go against, haha
// didn't take long, determineWinner was tedious

// display the game menu
void displayMenu() {
    cout << "Game Menu" << endl;
    cout << "--------" << endl;
    cout << "1) Rock" << endl;
    cout << "2) Paper" << endl;
    cout << "3) Scissors" << endl;
    cout << "4) Quit" << endl;
}

// get the user choice
int getUserChoice() {
    int choice;
    bool validInput = false;
    
    while (!validInput) {
        cout << "Enter your choice: ";
        cin >> choice;
        
        if (choice >= 1 && choice <= 4) {
            validInput = true;
        } else {
            cout << "Error: Please enter a number between 1 and 4." << endl;
        }
    }
    
    return choice;
}

// generate the computer's choice
int getComputerChoice() {
    // random number between 1 and 3
    return (rand() % 3) + 1;
}

// convert choice number to string
string choiceToString(int choice) {
    switch (choice) {
        case 1: return "Rock";
        case 2: return "Paper";
        case 3: return "Scissors";
        default: return "Unknown";
    }
}

// determine the winner
void determineWinner(int userChoice, int computerChoice) {
    cout << "You selected: " << choiceToString(userChoice) << endl;
    cout << "Computer selected: " << choiceToString(computerChoice) << endl;
    
    if (userChoice == computerChoice) {
        cout << "Tie. Go again I'll beat you." << endl;
    } else if ((userChoice == 1 && computerChoice == 3) || // rock smashes scissors
               (userChoice == 3 && computerChoice == 2) || // scissors cuts paper
               (userChoice == 2 && computerChoice == 1)) { // paper wraps rock
        cout << "You Won? No way. ";
        
        if (userChoice == 1 && computerChoice == 3) {
            cout << "Rock smashes scissors." << endl;
        } else if (userChoice == 3 && computerChoice == 2) {
            cout << "Scissors cuts paper." << endl;
        } else {
            cout << "Paper wraps rock." << endl;
        }
    } else {
        cout << "I WON LOSER! ";
        
        if (computerChoice == 1 && userChoice == 3) {
            cout << "Rock smashes scissors." << endl;
        } else if (computerChoice == 3 && userChoice == 2) {
            cout << "Scissors cuts paper." << endl;
        } else {
            cout << "Paper wraps rock." << endl;
        }
    }
}

// main function
int main() {
    // seed the random number generator
    srand(time(0));
    
    int userChoice;
    
    do {
        // generate the computer's choice at the beginning (don't display it yet)
        int computerChoice = getComputerChoice();
        
        displayMenu();
        userChoice = getUserChoice();
        
        // exit the game if the user quits
        if (userChoice == 4) {
            cout << "If I won, thanks for playing! If not, ALT + F4." << endl;
            break;
        }
        
        // determine the winner (display the computer's choice)
        determineWinner(userChoice, computerChoice);
        
        cout << endl;
    } while (true);
    
    return 0;
}
