// #include "Book.h"
// #include <list>
// #include <iostream>
//
// using namespace std;
//
//
// class Library {
//     list<Book> books;
//
// public:
//     Library(){}
//
//     Library(initializer_list<Book> initList) : books(initList){}
//
//     Library(const Library& otherLibrary) : books(otherLibrary.books){}
//
//     Library(Library&& otherLibrary) : books(otherLibrary.books){}
//
//     Library& operator = (const Library& right) {
//         if(this != &right) {
//             books = right.books;
//         }
//
//         return *this;
//     }
//
//     Library& operator = (Library&& right) {
//         if (this != &right) {
//             books = move(right.books);
//         }
//
//         return *this;
//     }
//
//     Book& operator[](size_t index) {
//         auto szukana = books.begin();
//         advance(szukana, index);
//         return *szukana;
//     }
//
//     friend ostream &operator<<(ostream &os, const Library &library) {
//         for (const auto &book : library.books) {
//             os << book <<endl;
//         }
//
//         return os;
//     }
//
//     const Book& operator[](size_t index) const {
//         auto szukana = books.begin();
//         advance(szukana, index);
//         return *szukana;
//     }
//
//     size_t GetSize() const {
//         return books.size();
//     }
//
//     ~Library() {
//
//     }
// };
//
// int main() {
//     Library e;
//     cout << "e: "<< e << endl;
//     //3-5 książek
//     Library l1 = {{"Adam Mickiewicz", "Pan Tadeusz"},
//     {"Juliusz Slowacki", "Kordian"},
//     {"Adam Mickiewicz", "Dziady"}};
//
//
//     return 0;
// }