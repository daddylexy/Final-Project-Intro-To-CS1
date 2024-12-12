//preprocessor directives//
/*Checks if the header file CHARACTER_H has already been included in the program. 
If it hasn't, it proceeds with the inclusion*/
#ifndef CHARACTER_H
/*Defines the CHARACTER_H symbol to indicate that this header file has been included. 
This prevents the file from being included multiple times in the same program,
which could cause issues*/
#define CHARACTER_H

//directives//
#include <string>
#include <iostream>
using namespace std;

/*A class is a blueprint for creating objects (instances) with 
specific properties (data members) and behaviors (member functions)*/
class Character {
//Members of class are by default private so that they can only be accessed from 
//within Character class//
private:
    string name;
    int health;
    int damage;

                                // MEMBER FUNCTIONS: //
                                
    //using a public scope so all functions and variables declared after it are 
    //accessible from outside the class//
public:
    // Constructor to initialize the Character object when it is created//
    //This way every character starts with a name, a health of 50, and a damage of 5//
    Character(string n) : name(n), health(50), damage(5) {}

    // Update health based on the damage of another character, and uses pass through in
    //order to accurately track the health based on the damage done//
    void updateHealth(const Character& c) {
    health -= c.getDamage();
    }

    // Increase the character's damage by 10//
    void updateDamage() {
        damage += 10;
    }

    //Returns the current health of the character//
    int getHealth() const {
        return health;
    }
    
    //Returns the current damage value of the character//
    int getDamage() const {
        return damage;
    }

    //Returns the name of the character//
    string getName() const {
        return name;
    }

    //Marked as const so they do not modify the object they belong to. This is important because 
    //getters are meant to only retrieve information without changing the state of the object//

    //Function to allow a change in the character’s name after the object has been created// 
    //It accepts a string parameter newName, and assigns it to the name member variable//
    void setName(const string& newName) {
        name = newName;
    }

    //This function outputs the character's details//
    void print() const {
        cout << "Name: " << name << ", Health: " << health << ", Damage: " << damage << endl;
    }

};

//Closes the #ifndef directive//
//This tells the preprocessor to stop checking if the file has been included//
#endif
