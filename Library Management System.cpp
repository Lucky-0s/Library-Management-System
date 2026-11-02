#include<bits/stdc++.h>
using namespace std;



class LibraryManagementSystem {
    static constexpr const char* DATA_FILE = "bookdata.txt";
    static constexpr const char* TEMP_FILE = "temp.txt";

    struct Book {
        string id, name, author;
    };

    // Tabs would break the file format, so replace them with spaces.
    static string sanitize(string s) {
        for (char& c : s) if (c == '\t') c = ' ';
        return s;
    }

    // Parse one tab-separated line into a Book.
    static bool parse(const string& line, Book& b) {
        istringstream ss(line);
        return getline(ss, b.id, '\t') && getline(ss, b.name, '\t') && getline(ss, b.author);
    }

    bool bookExists(const string& id) const {
        ifstream in(DATA_FILE);
        string line;
        Book b;
        while (getline(in, line))
            if (parse(line, b) && b.id == id) return true;
        return false;
    }

public:
    void addBook();
    void showAllBooks() const;
    void extractBook();
};

void LibraryManagementSystem::addBook() {
    Book b;
    cout << "Enter Book ID: ";
    getline(cin, b.id);
    cout << "Enter Book Name: ";
    getline(cin, b.name);
    cout << "Enter Author Name: ";
    getline(cin, b.author);

    b.id = sanitize(b.id);
    b.name = sanitize(b.name);
    b.author = sanitize(b.author);

    if (b.id.empty() || b.name.empty()) {
        cout << "Book ID and Name cannot be empty.\n";
        return;
    }
    if (bookExists(b.id)) {
        cout << "A book with this ID already exists.\n";
        return;
    }

    ofstream out(DATA_FILE, ios::app);
    if (!out) {
        cout << "Error: could not open data file.\n";
        return;
    }
    out << b.id << '\t' << b.name << '\t' << b.author << '\n';
    cout << "Book added successfully.\n";
}

void LibraryManagementSystem::showAllBooks() const {
    ifstream in(DATA_FILE);
    if (!in) {
        cout << "No books found.\n";
        return;
    }

    cout << left << setw(12) << "Book ID" << setw(30) << "Book Name" << "Author Name\n";
    cout << string(60, '-') << '\n';

    string line;
    Book b;
    bool any = false;
    while (getline(in, line)) {
        if (!parse(line, b)) continue;
        cout << left << setw(12) << b.id << setw(30) << b.name << b.author << '\n';
        any = true;
    }
    if (!any) cout << "(library is empty)\n";
}

void LibraryManagementSystem::extractBook() {
    string bookId;
    cout << "Enter Book ID to extract: ";
    getline(cin, bookId);

    ifstream in(DATA_FILE);
    if (!in) {
        cout << "No books found.\n";
        return;
    }
    ofstream temp(TEMP_FILE);
    if (!temp) {
        cout << "Error: could not create temporary file.\n";
        return;
    }

    string line;
    Book b;
    bool found = false;
    while (getline(in, line)) {
        if (!parse(line, b)) continue;
        if (b.id == bookId) {
            found = true;
            continue;               // skip = delete
        }
        temp << line << '\n';
    }
    in.close();
    temp.close();

    if (!found) {
        remove(TEMP_FILE);
        cout << "Book ID not found.\n";
        return;
    }
    if (remove(DATA_FILE) != 0 || rename(TEMP_FILE, DATA_FILE) != 0) {
        cout << "Error: could not update data file.\n";
        return;
    }
    cout << "Book extracted successfully.\n";
}

int main() {
    LibraryManagementSystem library;
    int choice = 0;

    do {
        cout << "\n--------------------------------\n"
             << "Library Management System\n"
             << "--------------------------------\n"
             << "1- Show All Books\n"
             << "2- Extract a Book\n"
             << "3- Add a Book (Admin)\n"
             << "4- Exit\n"
             << "Enter your choice: ";

        if (!(cin >> choice)) {
            if (cin.eof()) break;
            cin.clear();
            choice = 0;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1: library.showAllBooks(); break;
            case 2: library.extractBook();  break;
            case 3: library.addBook();      break;
            case 4: cout << "Goodbye!\n";    break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}