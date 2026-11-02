Library Management System (C++)

A console-based Library Management System written in C++. It lets librarians manage books and members, issue and return books, track due dates, and calculate late fines. Data is stored in plain files so it persists between runs.

Description

This project simulates the day-to-day operations of a small library. It is built using object-oriented programming (classes, encapsulation, inheritance) and the C++ Standard Library (STL), and is intended as a learning project for students as well as a base for further extension.

Features
Book management: add, edit, delete, and view books (ID, title, author, category, quantity)
Member management: register, update, and remove members
Search: find books by title, author, category, or ID
Issue and return: issue books to members, record returns, and update stock automatically
Due dates and fines: default loan period of 14 days with a fine of 2 per day for late returns (configurable)
Persistent storage: books, members, and transactions saved to text/CSV files
Reports: list of all books, issued books, overdue books, and member history
Admin login: simple password-protected librarian access
Technologies Used
C++17
STL (vector, map, string, fstream, algorithm, chrono)
File handling for storage
OOP concepts: classes, objects, inheritance, encapsulation
Project Structure
LibraryManagementSystem/
├── src/
│   ├── main.cpp          # Entry point and menu loop
│   ├── Book.h / Book.cpp
│   ├── Member.h / Member.cpp
│   ├── Library.h / Library.cpp   # Core logic (issue, return, search)
│   └── Utils.h / Utils.cpp       # Date helpers, input validation
├── data/
│   ├── books.txt
│   ├── members.txt
│   └── transactions.txt
├── Makefile
└── README.md
Requirements
A C++17-compatible compiler (g++ 7+, clang++ 5+, or MSVC 2017+)
make (optional)
Build and Run

Using g++ directly

bash
g++ -std=c++17 -o library src/*.cpp
./library

Using make

bash
make
./library

On Windows (MinGW), run library.exe instead.

Usage

When the program starts, log in as admin (default password: admin123; change it in Utils.h) and use the main menu:

===== LIBRARY MANAGEMENT SYSTEM =====
1. Add Book
2. View All Books
3. Search Book
4. Update / Delete Book
5. Register Member
6. View Members
7. Issue Book
8. Return Book
9. Reports
0. Exit
Enter your choice:
Example Workflow
Add a book: Add Book → enter ID, title, author, category, quantity
Register a member: Register Member → enter name and contact details
Issue the book: Issue Book → enter member ID and book ID
Return it: Return Book → fine is calculated automatically if overdue
Data Files
File	Contents
books.txt	One book per line: id,title,author,category,quantity
members.txt	One member per line: id,name,phone,email
transactions.txt	Issue/return records with dates and fines

Do not edit these files manually while the program is running.

Core Classes
Book: stores book details and availability
Member: stores member details and borrowed books
Transaction: records issue date, due date, return date, and fine
Library: manages collections and implements all operations
Future Improvements
GUI using Qt
SQLite database instead of text files
Book reservations and renewals
Email/SMS overdue reminders
Barcode scanning
Multiple librarian accounts with hashed passwords
Contributing
Fork the repository
Create a feature branch (git checkout -b feature/new-feature)
Commit your changes
Push and open a pull request
License

This project is released under the MIT License. Free to use and modify for learning and personal projects.

Author
Lakshya Panwar - luckypanwar1909@gmail.com
