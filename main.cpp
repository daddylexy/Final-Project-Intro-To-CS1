#include "character.h" //Including the Character class//
#include <ctime> //Using it for random number generation//
#include <cstdlib> //Has functions from the C standard library that I am using//
#include <iostream>
using namespace std;

// Global variables for scores
int MAX_SCORE = 0; // Maximum score among all games
int GAME_SCORE = 0; // Score for the current game

// Function to determine the winner and display the result
void winner(Character& c1, Character& c2) {
    if (c1.getHealth() > c2.getHealth()) {
        cout << "The winner is: " << c1.getName() << " with a Health of: " << c1.getHealth() << endl;
    } else {
        cout << "The winner is: " << c2.getName() << " with a Health of: " << c2.getHealth() << endl;
    }
}

// Challenge functions//
bool challenge1();
bool challenge2();
bool challenge3();

//Level functions//
void level1(Character& player, Character& oracle) {
    cout << "\n--- Level 1 ---" << endl;
    if (player.getHealth() < 10) {
        cout << "Player is too weak to continue Level 1!" << endl;
        return;
    }
    if (challenge1()) {
        oracle.updateHealth(player);  // Oracle's health is deducted
        player.updateDamage();        // Player's damage is increased
        GAME_SCORE += 10;             //Points earned per challenge win//
    } else {
        player.updateHealth(oracle);  // Player's health is deducted
        oracle.updateDamage();        // Oracle's damage is increased
    }
}

void level2(Character& player, Character& oracle) {
    cout << "\n--- Level 2 ---" << endl;
    if (player.getHealth() < 10) {
        cout << "Player is too weak to continue Level 2!" << endl;
        return;
    }
    if (challenge2()) {
        oracle.updateHealth(player);  // Oracle's health is deducted
        player.updateDamage();        // Player's damage is increased
        GAME_SCORE += 10;             //Points earned per challenge win//
    } else {
        player.updateHealth(oracle);  // Player's health is deducted
        oracle.updateDamage();        // Oracle's damage is increased
    }
}

void level3(Character& player, Character& oracle) {
    cout << "\n--- Level 3 ---" << endl;
    if (player.getHealth() < 10) {
        cout << "Player is too weak to continue Level 3!" << endl;
        return;
    }
    if (challenge3()) {
        oracle.updateHealth(player);  //Oracle's health is deducted//
        player.updateDamage();        //Player's damage is increased//
        GAME_SCORE += 10;             //Points earned per challenge win//
    } else {
        player.updateHealth(oracle);  //Player's health is deducted//
        oracle.updateDamage();        //Oracle's damage is increased//
    }
}

//Challenge functions//
bool challenge1() {
    cout << "Challenge 1: Guess a number (1-5): ";
    int guess;
    cin >> guess;
    int correct = rand() % 5 + 1; // Random number between 1 and 5//
    if (guess == correct) {
        cout << "You guessed correctly! You win this challenge!" << endl;
        return true;
    } else {
        cout << "Wrong guess. The correct number was " << correct << "." << endl;
        return false;
    }
}

bool challenge2() {
    cout << "Challenge 2: Solve a simple math problem. What is 5 + 3? ";
    int answer;
    cin >> answer;
    if (answer == 8) {
        cout << "Correct! You win this challenge!" << endl;
        return true;
    } else {
        cout << "Wrong answer. The correct answer is 8." << endl;
        return false;
    }
}

bool challenge3() {
    cout << "Challenge 3: Choose the correct key (A, B, or C): ";
    char choice;
    cin >> choice;
    char correct = 'A' + rand() % 3; // Randomly choose A, B, or C
    if (toupper(choice) == correct) {
        cout << "You chose correctly! You win this challenge!" << endl;
        return true;
    } else {
        cout << "Wrong choice. The correct key was " << correct << "." << endl;
        return false;
    }
}

int main() {
    srand(time(0)); //Seed random number generator for challenges//
    char restart;

    do {
        //Declaring string playerName, and asking user to enter their name//
        string playerName;
        cout << "Enter your character's name: ";
        cin >> playerName;
        
        //Create the player with the entered name//
        Character player(playerName);
        Character oracle("Oracle");

        //Reset game score at the start of each game//
        GAME_SCORE = 0;

        cout << "\nWelcome to the Text Adventure Game, " << player.getName() << "!" << endl;
        cout << "These Are Your Initial Stats:" << endl;
        player.print();
        cout << "This Is The Oracle's Initial Stats:" << endl;
        oracle.print();

        //Run the levels 1 through 3//
        level1(player, oracle);
        level2(player, oracle);
        level3(player, oracle);

        //Determine the winner and update MAX_SCORE//
        if (GAME_SCORE > MAX_SCORE) {
            MAX_SCORE = GAME_SCORE;
        }
        cout << "\nGame Over! Final Stats:" << endl;
        player.print();
        oracle.print();

        winner(player, oracle);

        //Ask if the user wants to restart//
        cout << "Do you want to restart the game? (y/n): ";
        cin >> restart;
    } while (restart == 'y' || restart == 'Y');
    
    cout << endl;
    
    cout << "\nThank you for playing!" << " Maximum Score: " << MAX_SCORE << endl;
}
