#include <iostream>
#include <string>
using namespace std;

class Media {
protected:
    string title;
    int year;
    bool isBorrowed;

public:
    Media() : isBorrowed(false) {
        cout << "Enter title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter year: ";
        cin >> year;
    }

    Media(string t, int y) : title(t), year(y), isBorrowed(false) {}

    void borrow() {
        if (isBorrowed)
            cout << "\"" << title << "\" is already borrowed.\n";
        else {
            isBorrowed = true;
            cout << "\"" << title << "\" has been borrowed successfully.\n";
        }
    }

    void returnMedia() {
        if (!isBorrowed)
            cout << "\"" << title << "\" was not borrowed.\n";
        else {
            isBorrowed = false;
            cout << "\"" << title << "\" has been returned successfully.\n";
        }
    }

    virtual void displayInfo() const {
        cout << "  Title   : " << title << "\n";
        cout << "  Year    : " << year  << "\n";
        cout << "  Status  : " << (isBorrowed ? "Borrowed" : "Available") << "\n";
    }

    virtual ~Media() {}
};

class BookAttributes {
protected:
    string author;
    string ISBN;

public:
    BookAttributes() {
        cout << "Enter author: ";
        cin.ignore();
        getline(cin, author);
        cout << "Enter ISBN: ";
        cin >> ISBN;
    }

    BookAttributes(string a, string isbn) : author(a), ISBN(isbn) {}

    virtual void displayInfo() const {
        cout << "  Author  : " << author << "\n";
        cout << "  ISBN    : " << ISBN   << "\n";
    }

    virtual ~BookAttributes() {}
};

class MagazineAttributes {
protected:
    int issueNumber;
    string publisher;

public:
    MagazineAttributes() {
        cout << "Enter issue number: ";
        cin >> issueNumber;
        cout << "Enter publisher: ";
        cin.ignore();
        getline(cin, publisher);
    }

    MagazineAttributes(int issue, string pub)
        : issueNumber(issue), publisher(pub) {}

    virtual void displayInfo() const {
        cout << "  Issue No  : " << issueNumber << "\n";
        cout << "  Publisher : " << publisher   << "\n";
    }

    virtual ~MagazineAttributes() {}
};

class DVDAttributes {
protected:
    string director;
    double duration; // in minutes

public:
    DVDAttributes() {
        cout << "Enter director: ";
        cin.ignore();
        getline(cin, director);
        cout << "Enter duration (minutes): ";
        cin >> duration;
    }

    DVDAttributes(string dir, double dur) : director(dir), duration(dur) {}

    virtual void displayInfo() const {
        cout << "  Director : " << director << "\n";
        cout << "  Duration : " << duration << " mins\n";
    }

    virtual ~DVDAttributes() {}
};

class Book : public Media, public BookAttributes {
public:
    Book() : Media(), BookAttributes() {}

    Book(string title, int year, string author, string isbn)
        : Media(title, year), BookAttributes(author, isbn) {}

    void displayInfo() const override {
        cout << "\n[ BOOK ]\n";
        Media::displayInfo();
        BookAttributes::displayInfo();
    }
};

class Magazine : public Media, public MagazineAttributes {
public:
    Magazine() : Media(), MagazineAttributes() {}

    Magazine(string title, int year, int issue, string publisher)
        : Media(title, year), MagazineAttributes(issue, publisher) {}

    void displayInfo() const override {
        cout << "\n[ MAGAZINE ]\n";
        Media::displayInfo();
        MagazineAttributes::displayInfo();
    }
};

class DVD : public Media, public DVDAttributes {
public:
    DVD() : Media(), DVDAttributes() {}

    DVD(string title, int year, string director, double duration)
        : Media(title, year), DVDAttributes(director, duration) {}

    void displayInfo() const override {
        cout << "\n[ DVD ]\n";
        Media::displayInfo();
        DVDAttributes::displayInfo();
    }
};

int main() {
    cout << "========================================\n";
    cout << "        LIBRARY MANAGEMENT SYSTEM\n";
    cout << "========================================\n\n";

    // Create objects using parameterized constructors
    Book    b("The Alchemist",      1988, "Paulo Coelho",    "978-0062315007");
    Magazine m("National Geographic", 2024, 312,             "Nat Geo Partners");
    DVD     d("Inception",          2010, "Christopher Nolan", 148.0);

    // Display all media info
    b.displayInfo();
    m.displayInfo();
    d.displayInfo();

    // Borrow and return operations
    cout << "\n--- Borrow / Return Operations ---\n";
    b.borrow();
    b.borrow();       // try borrowing again (already borrowed)
    b.returnMedia();
    b.returnMedia();  // try returning again (already returned)

    m.borrow();
    d.borrow();

    // Display updated statuses
    cout << "\n--- Updated Info After Borrowing ---";
    b.displayInfo();
    m.displayInfo();
    d.displayInfo();

    // Polymorphism via base class pointer
    cout << "\n--- Polymorphism Demo (Media* array) ---\n";
    Media* library[3] = { &b, &m, &d };
    for (int i = 0; i < 3; i++)
        library[i]->displayInfo();

    return 0;
}