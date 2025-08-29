#include <stdio.h>
#include <iostream>
#include <string>

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