#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

class Book {
public:
    string title;
    string author;
    string ISBN;
    bool isIssued;
    time_t dueDate;

    Book(string t, string a, string i) : title(t), author(a), ISBN(i), isIssued(false), dueDate(0) {}
};

class User {
public:
    string username;
    string password;

    User(string u, string p) : username(u), password(p) {}
};

class Library {
private:
    vector<Book> books;
    vector<User> users;
    User* currentUser;

    Book* findBook(const string& ISBN) {
        for (auto& book : books) {
            if (book.ISBN == ISBN) {
                return &book;
            }
        }
        return nullptr;
    }

public:
    void addBook(string title, string author, string ISBN) {
        books.push_back(Book(title, author, ISBN));
        cout << "Book added successfully!\n";
    }

    void searchBook(const string& query) {
        bool found = false;
        for (const auto& book : books) {
            if (book.title.find(query) != string::npos || 
                book.author.find(query) != string::npos || 
                book.ISBN.find(query) != string::npos) {
                cout << "Title: " << book.title << ", Author: " << book.author << ", ISBN: " << book.ISBN;
                if (book.isIssued) {
                    cout << " (Issued, Due: " << ctime(&book.dueDate) << ")";
                }
                cout << "\n";
                found = true;
            }
        }
        if (!found) {
            cout << "No books found matching your query.\n";
        }
    }

    void issueBook(const string& ISBN) {
        Book* book = findBook(ISBN);
        if (book && !book->isIssued) {
            book->isIssued = true;
            book->dueDate = time(0) + 7 * 24 * 60 * 60; 
            cout << "Book issued successfully! Due date: " << ctime(&book->dueDate);
        } else {
            cout << "Book not available or already issued.\n";
        }
    }

\    void returnBook(const string& ISBN) {
        Book* book = findBook(ISBN);
        if (book && book->isIssued) {
            book->isIssued = false;
            time_t now = time(0);
            if (now > book->dueDate) {
                double fine = difftime(now, book->dueDate) / (24 * 60 * 60) * 10; 
                cout << "Book returned late! Fine: Rs. " << fine << "\n";
            } else {
                cout << "Book returned successfully!\n";
            }
            book->dueDate = 0;
        } else {
            cout << "Invalid ISBN or book not issued.\n";
        }
    }

    void displayBooks() {
        if (books.empty()) {
            cout << "No books in the library.\n";
            return;
        }
        for (const auto& book : books) {
            cout << "Title: " << book.title << ", Author: " << book.author << ", ISBN: " << book.ISBN;
            if (book.isIssued) {
                cout << " (Issued, Due: " << ctime(&book.dueDate) << ")";
            }
            cout << "\n";
        }
    }

    bool login(string username, string password) {
        for (auto& user : users) {
            if (user.username == username && user.password == password) {
                currentUser = &user;
                return true;
            }
        }
        return false;
    }

    void addUser(string username, string password) {
        users.push_back(User(username, password));
        cout << "User added successfully!\n";
    }
};

int main() {
    Library library;
    library.addUser("admin", "admin123"); 
    library.addBook("C++ Programming", "Bjarne Stroustrup", "9780321563842");
    library.addBook("Data Structures", "Mark Allen Weiss", "9780132576277");

    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (library.login(username, password)) {
        cout << "Login successful!\n";
        int choice;
        do {
            cout << "\n1. Add Book\n2. Search Book\n3. Issue Book\n4. Return Book\n5. Display Books\n6. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            string title, author, ISBN;
            switch (choice) {
                case 1:
                    cout << "Enter title: ";
                    cin.ignore();
                    getline(cin, title);
                    cout << "Enter author: ";
                    getline(cin, author);
                    cout << "Enter ISBN: ";
                    cin >> ISBN;
                    library.addBook(title, author, ISBN);
                    break;
                case 2:
                    cout << "Enter search query: ";
                    cin.ignore();
                    getline(cin, title);
                    library.searchBook(title);
                    break;
                case 3:
                    cout << "Enter ISBN to issue: ";
                    cin >> ISBN;
                    library.issueBook(ISBN);
                    break;
                case 4:
                    cout << "Enter ISBN to return: ";
                    cin >> ISBN;
                    library.returnBook(ISBN);
                    break;
                case 5:
                    library.displayBooks();
                    break;
                case 6:
                    cout << "Exiting...\n";
                    break;
                default:
                    cout << "Invalid choice!\n";
            }
        } while (choice != 6);
    } else {
        cout << "Invalid username or password!\n";
    }

    return 0;
}
