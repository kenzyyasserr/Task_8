#include <stdio.h>
#include <iostream>
#include <string>
#include <thread>  //for the delay
#include <chrono>


using namespace std;

class weapon {
public:
    string name;
    int damage;
    int accuracy;

    weapon() {}
    weapon(string n, int d, int a) {
        name = n;
        damage = d;
        accuracy = a;
    }
};

class Character {
public:
    string name;
    int health;
    weapon weapons[3]; 
    bool missHit;

    Character(string n, int h) {
        name = n;
        health = h;
        missHit = false;
    }

     bool isAlive() {
        return health > 0;
    }

    void takeDamage(int dmg) {
        health -= dmg;
        if (health < 0) health = 0;
    }

 void attack(Character &opponent, int weaponIndex) {
        weapon w = weapons[weaponIndex];
        cout << name << " attacks with " << w.name << "!\n";

        bool hit = true;
        if (!missHit) { //one miss for this character
            int roll = rand() % 100 + 1;
            if (roll > w.accuracy) {
                hit = false;
                missHit = true; //character used their miss
            }
        }

        if (hit) {
            opponent.takeDamage(w.damage);
            cout << " it's a hit!! " << opponent.name << " takes "
                 << w.damage << " damage.\n";
        } else {
            cout << "Missed!\n";
        }

        cout << opponent.name << " health: " << opponent.health << "\n\n";
    }
};

//main function----------------------------------------------------
int main() {
    srand(time(0));

    Character optimus("Optimus Prime", 100);
    Character megatron("Megatron", 100);

    //Optimus' weapons
    optimus.weapons[0] = weapon("Ion Rifle", 6, 100);
    optimus.weapons[1] = weapon("Energon Swords", 12, 80);
    optimus.weapons[2] = weapon("Shoulder Cannon", 45, 25);

    //Megatron's weapons
    megatron.weapons[0] = weapon("Fusion Cannon", 9, 90);
    megatron.weapons[1] = weapon("Fusion Sword", 18, 70);
    megatron.weapons[2] = weapon("Tank Mode", 60, 15);

    cout << "Optimus Prime vs Megatron\n";
    cout << "Let the fight begin!\n\n";

    bool optimusTurn = true;
    while (optimus.isAlive() && megatron.isAlive()) {
        int choice = rand() % 3; //picking a random weapon
        if (optimusTurn) {
            optimus.attack(megatron, choice);
        } else {
            megatron.attack(optimus, choice);
        }
        optimusTurn = !optimusTurn;

        this_thread::sleep_for(chrono::seconds(2));
    }

    if (optimus.isAlive())
        cout << "Fight's over and Optimus Prime is the WINNER!\n";
    else
        cout << "Fight's over and Megatron is the WINNER!\n";

    return 0;
}