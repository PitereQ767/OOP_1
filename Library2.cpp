#include "Book.h"
#include <list>
#include <iostream>

using namespace std;


class Library {
    Book* books;
    size_t size;

public:
    Library() : books(nullptr), size(0){}

    Library(initializer_list<Book> initList) : size(initList.size()), books(new Book[initList.size()]) {
        size_t i = 0;
        for (Book b : initList) {
            books[i] = b;
            i++;
        }
    }

    Library(const Library& other) : size(other.size), books(new Book[other.size]) {
        for (size_t i =0; i< size; i++) {
            books[i] = other.books[i];
        }
    }

    Library(Library&& other) : size(other.size), books(other.books) {
        for (size_t i = 0; i<size; i++) {
            other.books = nullptr;
            other.size = 0;
        }
    }

    Library(size_t size) : size(size), books(new Book[size]) {
        cout << "Library("<<size<<")" << endl;
    }

    Library& operator=(const Library& right) {
        if (this != &right) {
            Library tmp = right;
            swap(books, tmp.books);
            swap(size, tmp.size);
        }

        return *this;
    }

    Book& operator[](size_t index) {
        return books[index];
    }

    friend ostream& operator << (ostream& os, const Library& lib) {
        os << "Library with " << lib.size << "books:" <<endl;
        for (size_t i =0; i< lib.size; i++) {
            os << lib.books[i] << endl;
        }
        return os;
    }

    ~Library() {
        delete[] books;
        books = nullptr;
    }
};



int main() {
    Library e;
    cout << "e: "<< e << endl;
    //3-5 książek
    Library l1 = {{"Adam Mickiewicz", "Pan Tadeusz"},
                    {"Juliusz Slowacki", "Kordian"},
                    {"Adam Mickiewicz", "Dziady"}};

    cout << "l1: "<<l1<<endl;
    Library l2(2);
    cout << "l2: "<< l2 << endl;
    l2[0] = {"Piotr", "Ratkowski"};
    l2[1] = {"Pawel", "Ratkowski"};
    cout << "l2: "<< l2 << endl;
    e = move(l2);
    cout << "e: " << e << " l2: "<< l2 << endl;
    l1[0] = move(e[1]);
    cout << "l1: " << l1 << " e: "<< e << endl;
    return 0;
}
