#include <iostream>
#include <string>
using namespace std;

// Base class
class Media {
protected:
    string title;
    bool borrowed;

public:
    Media(string t) {
        title = t;
        borrowed = false;
    }

    void borrowItem() {
        if (!borrowed) {
            borrowed = true;
            cout << title << " has been borrowed.\n";
        } else {
            cout << title << " is already borrowed.\n";
        }
    }

    void returnItem() {
        if (borrowed) {
            borrowed = false;
            cout << title << " has been returned.\n";
        } else {
            cout << title << " was not borrowed.\n";
        }
    }

    void displayMedia() {
        cout << "Title: " << title << endl;
        cout << "Status: " << (borrowed ? "Borrowed" : "Available") << endl;
    }
};

// Book specific attributes
class BookInfo {
protected:
    string author;

public:
    BookInfo(string a) {
        author = a;
    }
};

// Magazine specific attributes
class MagazineInfo {
protected:
    int issueNumber;

public:
    MagazineInfo(int issue) {
        issueNumber = issue;
    }
};

// DVD specific attributes
class DVDInfo {
protected:
    string director;

public:
    DVDInfo(string d) {
        director = d;
    }
};

// Book class using multiple inheritance
class Book : public Media, public BookInfo {
public:
    Book(string t, string a) : Media(t), BookInfo(a) {}

    void display() {
        cout << "\n--- Book Information ---\n";
        displayMedia();
        cout << "Author: " << author << endl;
    }
};

// Magazine class using multiple inheritance
class Magazine : public Media, public MagazineInfo {
public:
    Magazine(string t, int issue) : Media(t), MagazineInfo(issue) {}

    void display() {
        cout << "\n--- Magazine Information ---\n";
        displayMedia();
        cout << "Issue Number: " << issueNumber << endl;
    }
};

// DVD class using multiple inheritance
class DVD : public Media, public DVDInfo {
public:
    DVD(string t, string d) : Media(t), DVDInfo(d) {}

    void display() {
        cout << "\n--- DVD Information ---\n";
        displayMedia();
        cout << "Director: " << director << endl;
    }
};

int main() {
    Book b("C++ Programming", "Bjarne Stroustrup");
    Magazine m("Tech Monthly", 25);
    DVD d("Inception", "Christopher Nolan");

    b.display();
    b.borrowItem();
    b.returnItem();

    m.display();
    m.borrowItem();

    d.display();
    d.borrowItem();

    return 0;
}