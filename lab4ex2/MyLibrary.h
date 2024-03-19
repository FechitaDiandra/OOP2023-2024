

#ifndef MYLIBRARY_H
#define MYLIBRARY_H

#include <iostream>
#include <initializer_list>

class MyLibrary {
    std::ostream& output_stream;
    unsigned books_count;
    int* books;

public:
    MyLibrary(std::ostream& output_stream);
    MyLibrary(std::ostream& output_stream, unsigned books_count, int* books);
    MyLibrary(std::ostream& output_stream, unsigned books_count, int min, int max);
    MyLibrary(std::ostream& output_stream, const char* books_values);
    MyLibrary(std::ostream& output_stream, unsigned books_count, ...);
    MyLibrary(std::initializer_list<int> v);
    ~MyLibrary();

    void print_books() const; // Modificare adăugând const
    void update_book_id_by_index(unsigned book_index, int book_id);

    unsigned get_books_count() const;
    int get_book_id_by_index(unsigned book_index) const;
};

#endif // MYLIBRARY_H
