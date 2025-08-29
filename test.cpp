#include <iostream>
#include <cstdlib>  // rand, srand
#include <ctime>    // time

using namespace std;

// ---------------- Weapon ----------------
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

// ---------------- Character ----------------
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

    bool isAlive() {
        return health > 0;
    }

    void takeDamage(int dmg) {
        health -= dmg;
        if (health < 0) health = 0;
    }

    void attack(Character &opponent, int weaponIndex) {
        Weapon w = weapons[weaponIndex];
        cout << name << " attacks with " << w.name << "!\n";

        bool hit = true;
        if (!missUsed) { // allow one miss for this character
            int roll = rand() % 100 + 1;
            if (roll > w.accuracy) {
                hit = false;
                missUsed = true; // this character used their miss
            }
        }

        if (hit) {
            opponent.takeDamage(w.damage);
            cout << "Hit! " << opponent.name << " takes "
                 << w.damage << " damage.\n";
        } else {
            cout << "Missed!\n";
        }

        cout << opponent.name << " health: " << opponent.health << "\n\n";
    }
};

// ---------------- Main ----------------
int main() {
    srand(time(0));

    Character optimus("Optimus Prime", 100);
    Character megatron("Megatron", 100);

    // Optimus weapons
    optimus.weapons[0] = Weapon("Ion Rifle", 6, 100);
    optimus.weapons[1] = Weapon("Energon Swords", 12, 80);
    optimus.weapons[2] = Weapon("Shoulder Cannon", 45, 25);

    // Megatron weapons
    megatron.weapons[0] = Weapon("Fusion Cannon", 9, 90);
    megatron.weapons[1] = Weapon("Fusion Sword", 18, 70);
    megatron.weapons[2] = Weapon("Tank Mode", 60, 15);

    cout << "=== Optimus Prime vs Megatron ===\n\n";

    bool optimusTurn = true;
    while (optimus.isAlive() && megatron.isAlive()) {
        int choice = rand() % 3; // pick random weapon
        if (optimusTurn) {
            optimus.attack(megatron, choice);
        } else {
            megatron.attack(optimus, choice);
        }
        optimusTurn = !optimusTurn;
    }

    if (optimus.isAlive())
        cout << "Optimus Prime wins!\n";
    else
        cout << "Megatron wins!\n";

    return 0;
}
