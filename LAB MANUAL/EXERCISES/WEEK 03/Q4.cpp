#include <iostream>
#include <string>
using namespace std;

class bookType {
private:
    string title;
    string authors[4];
    int numAuthors;
    string publisher;
    string ISBN;
    double price;
    int copiesInStock;

public:
    // Constructors
    bookType() {
        title = "";
        publisher = "";
        ISBN = "";
        price = 0.0;
        copiesInStock = 0;
        numAuthors = 0;
    }

    // Setters
    void setTitle(string t) {
        title = t;
    }

    void setAuthors(string auth[], int n) {
        numAuthors = n;
        for (int i = 0; i < n && i < 4; i++)
            authors[i] = auth[i];
    }

    void setPublisher(string p) {
        publisher = p;
    }

    void setISBN(string i) {
        ISBN = i;
    }

    void setPrice(double p) {
        if (p > 0)
            price = p;
        else
            price = 0;
    }

    void setCopies(int c) {
        copiesInStock = c;
    }

    // Getters
    string getTitle() const {
        return title;
    }

    string getISBN() const {
        return ISBN;
    }

    int getCopies() const {
        return copiesInStock;
    }

    // Update stock
    void updateCopies(int change) {
        copiesInStock += change;
    }

    // Search helpers
    bool checkTitle(string t) const {
        return title == t;
    }

    bool checkISBN(string i) const {
        return ISBN == i;
    }

    // Display book info
    void displayBook() const {
        cout << "\nTitle: " << title;
        cout << "\nAuthors: ";
        for (int i = 0; i < numAuthors; i++)
            cout << authors[i] << " ";
        cout << "\nPublisher: " << publisher;
        cout << "\nISBN: " << ISBN;
        cout << "\nPrice: $" << price;
        cout << "\nCopies in stock: " << copiesInStock << endl;
    }
};
int main() {
    bookType books[100];
    int totalBooks = 2;

    string authors1[2] = {"Ali", "Ahmed"};
    books[0].setTitle("C++ Programming");
    books[0].setAuthors(authors1, 2);
    books[0].setPublisher("Pearson");
    books[0].setISBN("111");
    books[0].setPrice(500);
    books[0].setCopies(10);

    string authors2[1] = {"Sara"};
    books[1].setTitle("Data Structures");
    books[1].setAuthors(authors2, 1);
    books[1].setPublisher("Oxford");
    books[1].setISBN("222");
    books[1].setPrice(650);
    books[1].setCopies(5);

    // Search by Title
    string searchTitle;
    cout << "\nEnter title to search: ";
    getline(cin, searchTitle);

    for (int i = 0; i < totalBooks; i++) {
        if (books[i].checkTitle(searchTitle)) {
            books[i].displayBook();
        }
    }

    // Search by ISBN
    string searchISBN;
    cout << "\nEnter ISBN to search: ";
    cin >> searchISBN;

    for (int i = 0; i < totalBooks; i++) {
        if (books[i].checkISBN(searchISBN)) {
            books[i].updateCopies(5);
            cout << "\nStock updated successfully.";
            books[i].displayBook();
        }
    }

    return 0;
}
