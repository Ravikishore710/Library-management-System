# Library Management System in C++

## Overview
The **Library Management System** is a program designed to manage a library efficiently. It allows users to log in, manage books, issue and return books, and track due dates. The system includes user authentication and a fine system for late returns.

## Features

### 1️⃣ User Authentication
- Users must **log in** before accessing the system.
- A **default admin user** is available (`username: admin`, `password: admin123`).
- Additional users can be added for role management.

### 2️⃣ Book Management
- Users can **add new books** with the following details:
  - Title
  - Author
  - ISBN (Unique identifier)
- Books can be **searched** by:
  - Title
  - Author
  - ISBN

### 3️⃣ Issuing Books
- Books can be issued to users.
- Once issued:
  - The book is marked as **issued**.
  - A **due date** is assigned (7 days from issue date).
- If a book is already issued, it **cannot be reissued** until returned.

### 4️⃣ Returning Books & Fine Calculation
- Users can **return books** using the ISBN.
- If returned **after the due date**, a **fine** is imposed:
  - Fine = **Rs. 10 per day** after the due date.

### 5️⃣ Displaying Available Books
- Users can **view all books** in the library.
- The system displays:
  - Title
  - Author
  - ISBN
  - Issued status (including due date, if applicable).

## Class Descriptions

### 1️⃣ `Book` Class
Represents a **book** in the library.

#### Attributes:
- `title` – Stores the book's title.
- `author` – Stores the book's author.
- `ISBN` – Unique identifier for the book.
- `isIssued` – `true` if the book is issued, `false` otherwise.
- `dueDate` – Stores the due date if the book is issued.

### 2️⃣ `User` Class
Represents a **user** of the library system.

#### Attributes:
- `username` – Stores the username.
- `password` – Stores the password.

### 3️⃣ `Library` Class
The main class that **manages the library system**.

#### Attributes:
- `books` – Stores all books in the library.
- `users` – Stores all registered users.
- `currentUser` – Pointer to the currently logged-in user.

#### Methods:
- `addBook()` – Adds a new book to the library.
- `searchBook()` – Searches for books by title, author, or ISBN.
- `issueBook()` – Issues a book and sets a due date (7 days).
- `returnBook()` – Returns a book and checks for late fine.
- `displayBooks()` – Displays all books and their status.
- `login()` – Authenticates a user.
- `addUser()` – Registers a new user.


