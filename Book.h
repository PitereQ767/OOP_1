//
// Created by 48734 on 10.03.2025.
//

#ifndef BOOK_H
#define BOOK_H

#include <iostream>

using namespace std;

class Book {
    string author, title;

public:
    Book(){};

    Book(const string & author, const string & title) : author(author), title(title){};

    Book (string && author, string && title) : author(move(author)), title(move(title)){};

    const string getAuthor() const {
        return author;
    }

    const string getTitle() const {
        return title;
    }

    void setAuthor(const string & newAuthor) {
        author = newAuthor;
    }

    void setTitle(const string & newTitle) {
        title = newTitle;
    }

    void SetAuthor(string && newAuthor) {
        author = move(newAuthor);
    }

    void SetTitle(string && newTitle) {
        title = move(newTitle);
    }

    friend ostream& operator << (ostream& os, Book& book) {
        os << "Book[" << book.author << ", " << book.title << "]" << endl;
        return os;
    }

    Book(const Book & otherBook) : Book(otherBook.getAuthor(), otherBook.getTitle()) {}

    Book(Book && otherBook) : author(move(otherBook.author)), title(move(otherBook.title)){}

    Book& operator = (const Book& otherBook) {
        if (this != &otherBook) {
            author = otherBook.getAuthor();
            title = otherBook.getTitle();
        }

        return *this;
    }

    Book& operator = (Book && otherBook) {
        if (this != &otherBook) {
            author = move(otherBook.author);
            title = move(otherBook.title);
        }

        return *this;
    }
};

#endif //BOOK_H
