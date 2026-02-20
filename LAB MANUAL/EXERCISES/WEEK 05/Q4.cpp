//CT 166            MEMOONA 
#include <iostream>
#include <string>
using namespace std;

class Item {
protected:
    string name;
    int quantity;

public:
    void setItem(string n, int q) {
        name = n;
        quantity = q;
    }

    int getQuantity() {
        return quantity;
    }
};
class BakedGoods : public Item {
protected:
    float discount = 0.10;  };
class Cakes : public BakedGoods {
private:
    float price = 600;

public:
    float calculateBill() {
        float total = price * quantity;
        return total - (total * discount);
    }
};
class Bread : public BakedGoods {
private:
    float price = 200;

public:
    float calculateBill() {
        float total = price * quantity;
        return total - (total * discount);
    }
};
class Drinks : public Item {
private:
    float price = 100;
    float discount = 0.05;   

public:
    float calculateBill() {
        float total = price * quantity;
        return total - (total * discount);
    }
};
int main() {
    int qty;
    float grandTotal = 0;

    Cakes cake;
    Bread bread;
    Drinks drink;

    cout << "Enter quantity of Cakes: ";
    cin >> qty;
    cake.setItem("Cake", qty);
    grandTotal += cake.calculateBill();

    cout << "Enter quantity of Bread: ";
    cin >> qty;
    bread.setItem("Bread", qty);
    grandTotal += bread.calculateBill();

    cout << "Enter quantity of Drinks: ";
    cin >> qty;
    drink.setItem("Drink", qty);
    grandTotal += drink.calculateBill();

    cout << "\nTotal Bill = Rs. " << grandTotal << endl;

    return 0;
}