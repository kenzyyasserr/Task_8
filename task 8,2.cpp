#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class Weapon {
public:
    string name;
    int damage;
    int accuracy; // %

    Weapon() {} // default
    Weapon(string n, int d, int a) {
        name = n;
        damage = d;
        accuracy = a;
    }
};

class Character {
public:
    string name;
    int health;
    Weapon weapons[3]; 
    bool missUsed; // each character tracks their own miss

    Character(string n, int h) {
        name = n;
        health = h;
        missUsed = false;
    }