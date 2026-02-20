//CT 166            MEMOONA 
#include <iostream>
using namespace std;

class Weapons {
public:
    void WeaponsDescription() {
        cout << "Weapons are tools used to cause damage or destruction." << endl;
    }
};
class HotWeapons : public Weapons {
public:
    void HotWeaponsDescription() {
        cout << "Hot weapons use heat, gunpowder, or explosive reactions." << endl;
    }
};
class Bombs : public HotWeapons {
public:
    void BombsDescription() {
        cout << "Bombs are weapons that blow up and cause massive destruction." << endl;
    }
};
class NuclearBombs : public Bombs {
public:
    void NuclearBombsDescription() {
        cout << "Nuclear bombs blow up and use nuclear fission and fusion." << endl;
    }
};
int main() {
    NuclearBombs nb;

    nb.WeaponsDescription();
    nb.HotWeaponsDescription();
    nb.BombsDescription();
    nb.NuclearBombsDescription();

    return 0;
}