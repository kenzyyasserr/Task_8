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