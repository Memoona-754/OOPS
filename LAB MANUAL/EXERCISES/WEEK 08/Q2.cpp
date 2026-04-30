#include <iostream>
#include <string>
using namespace std;

class Character {
protected:
    string name;
    int    level;
    int    health;

public:
    Character(string n, int l, int h)
        : name(n), level(l), health(h) {}

    virtual void displayInfo() {
        cout << "Name  : " << name   << endl;
        cout << "Level : " << level  << endl;
        cout << "Health: " << health << endl;
    }

    virtual void ability() = 0;   // Pure virtual — every character must have ability

    virtual ~Character() {}
};

class Warrior : virtual public Character {
protected:
    int    strength;
    string weaponProficiency;

public:
    Warrior(string n, int l, int h, int s, string wp)
        : Character(n, l, h), strength(s), weaponProficiency(wp) {}

    void displayInfo() override {
        Character::displayInfo();
        cout << "Strength   : " << strength          << endl;
        cout << "Weapon     : " << weaponProficiency << endl;
    }

    void ability() override {
        cout << name << " uses SLASH! Melee attack!" << endl;
    }
};

class Mage : virtual public Character {
protected:
    int    intelligence;
    string spellProficiency;

public:
    Mage(string n, int l, int h, int intel, string sp)
        : Character(n, l, h), intelligence(intel), spellProficiency(sp) {}

    void displayInfo() override {
        Character::displayInfo();
        cout << "Intelligence     : " << intelligence    << endl;
        cout << "Spell Proficiency: " << spellProficiency << endl;
    }

    void ability() override {
        cout << name << " casts FIREBALL! Magic attack!" << endl;
    }
};

class Archer : public Character {
protected:
    int    dexterity;
    string rangedProficiency;

public:
    Archer(string n, int l, int h, int dex, string rp)
        : Character(n, l, h), dexterity(dex), rangedProficiency(rp) {}

    void displayInfo() override {
        Character::displayInfo();
        cout << "Dexterity  : " << dexterity        << endl;
        cout << "Ranged     : " << rangedProficiency << endl;
    }

    void ability() override {
        cout << name << " fires RAPID SHOT! Ranged attack!" << endl;
    }
};

class NPC : public Character {
private:
    string movementPattern;
    string dialogue;

public:
    NPC(string n, int l, int h, string mp, string d)
        : Character(n, l, h), movementPattern(mp), dialogue(d) {}

    void displayInfo() override {
        Character::displayInfo();
        cout << "Movement : " << movementPattern << endl;
        cout << "Dialogue : " << dialogue        << endl;
    }

    void ability() override {
        cout << name << " says: \"" << dialogue << "\"" << endl;
    }

    void patrol() {
        cout << name << " is patrolling: " << movementPattern << endl;
    }
};

class Mighty : public Warrior, public Mage {
private:
    string specialPower;

public:
    Mighty(string n, int l, int h,
           int str, string wp,
           int intel, string sp,
           string power)
        : Character(n, l, h),
          Warrior(n, l, h, str, wp),
          Mage(n, l, h, intel, sp),
          specialPower(power) {}

    void displayInfo() override {
        Character::displayInfo();
        cout << "--- Warrior Traits ---"   << endl;
        cout << "Strength   : " << strength          << endl;
        cout << "Weapon     : " << weaponProficiency << endl;
        cout << "--- Mage Traits ---"      << endl;
        cout << "Intelligence     : " << intelligence     << endl;
        cout << "Spell Proficiency: " << spellProficiency << endl;
        cout << "Special Power    : " << specialPower     << endl;
    }

    void ability() override {
        // Uses BOTH warrior and mage abilities
        cout << name << " uses SLASH! Warrior strike!"  << endl;
        cout << name << " casts FIREBALL!  Mage spell!"   << endl;
        cout << name << " activates " << specialPower << "! 💥" << endl;
    }
};

int main() {
    cout << "=============================" << endl;
    cout << "       GAME ENGINE           " << endl;
    cout << "=============================" << endl;

    // --- Warrior ---
    cout << "\n WARRIOR" << endl;
    cout << "-----------------------------" << endl;
    Warrior w("Thor", 10, 200, 95, "Melee Weapons");
    w.displayInfo();
    w.ability();

    // --- Mage ---
    cout << "\n MAGE" << endl;
    cout << "-----------------------------" << endl;
    Mage m("Gandalf", 15, 150, 98, "Arcane Spells");
    m.displayInfo();
    m.ability();

    // --- Archer ---
    cout << "\n ARCHER" << endl;
    cout << "-----------------------------" << endl;
    Archer a("Legolas", 12, 170, 97, "Ranged Weapons");
    a.displayInfo();
    a.ability();

    // --- NPC ---
    cout << "\n NPC" << endl;
    cout << "-----------------------------" << endl;
    NPC npc("Village Elder", 1, 100,
            "Circular patrol around village",
            "Beware the dark forest!");
    npc.displayInfo();
    npc.ability();
    npc.patrol();

    // --- Mighty (Multiple Inheritance) ---
    cout << "\n MIGHTY CHARACTER" << endl;
    cout << "-----------------------------" << endl;
    Mighty mighty("Archon", 20, 350,
                  90, "Dual Blades",
                  95, "Ancient Spells",
                  "Divine Storm");
    mighty.displayInfo();
    mighty.ability();

    // --- Polymorphism Demo ---
    cout << "\n POLYMORPHISM DEMO" << endl;
    cout << "-----------------------------" << endl;
    Character* party[4];
    party[0] = new Warrior ("Conan",   8,  180, 88, "Sword");
    party[1] = new Mage    ("Merlin",  9,  130, 92, "Fire Spells");
    party[2] = new Archer  ("Robin",   7,  160, 90, "Bow");
    party[3] = new NPC     ("Guard",   2,  120,
                             "Back and forth", "Halt! Who goes there?");

    for (int i = 0; i < 4; i++) {
        party[i]->ability();     // Correct ability called at runtime
        delete party[i];
    }

    return 0;
}