

#include "MyLibrary.h"
#include <iostream>
#include <cstdlib>
#include <cstdarg>
#include <cstring>
#include <algorithm>

MyLibrary::MyLibrary(std::ostream& output_stream) : output_stream(output_stream), books_count(-1), books(nullptr) {}

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, int* books) : output_stream(output_stream), books_count(books_count) {
    this->books = new int[books_count];
    for (unsigned i = 0; i < books_count; ++i)
        this->books[i] = books[i];
}

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, int min, int max) : output_stream(output_stream), books_count(books_count) {
    this->books = new int[books_count];
    for (unsigned i = 0; i < books_count; ++i)
        this->books[i] = min + rand() % (max - min);
}

MyLibrary::MyLibrary(std::ostream& output_stream, const char* books_values) : output_stream(output_stream), books_count(0), books(nullptr) {
    const char* ptr = books_values;
    while (*ptr != '\0') {
        if (*ptr == ';')
            ++books_count;
        ++ptr;
    }
    ++books_count; // count the last book as well
    this->books = new int[books_count];
    ptr = books_values;
    for (unsigned i = 0; i < books_count; ++i) {
        char* end_ptr;
        this->books[i] = std::strtol(ptr, &end_ptr, 10);
        ptr = end_ptr + 1;
    }
}

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, ...) : output_stream(output_stream), books_count(books_count) {
    this->books = new int[books_count];
    va_list args;
    va_start(args, books_count);
    for (unsigned i = 0; i < books_count; ++i)
        this->books[i] = va_arg(args, int);
    va_end(args);
}

MyLibrary::MyLibrary(std::initializer_list<int> v) : output_stream(std::cout), books_count(v.size()), books(new int[v.size()]) {
    std::copy(v.begin(), v.end(), this->books);
}

MyLibrary::~MyLibrary() {
    delete[] books;
}

// Definiția corectată cu calificatorul const adăugat
void MyLibrary::print_books() const {
    output_stream << "Number of books: " << books_count << "\n";
    if (books_count == -1) {
        output_stream << "No books available.\n";
        return;
    }
    output_stream << "Book IDs:";
    for (unsigned i = 0; i < books_count; ++i)
        output_stream << " " << books[i];
    output_stream << "\n";
}

void MyLibrary::update_book_id_by_index(unsigned book_index, int book_id) {
    if (book_index < books_count)
        books[book_index] = book_id;
}

unsigned MyLibrary::get_books_count() const {
    return books_count;
}

int MyLibrary::get_book_id_by_index(unsigned book_index) const {
    if (book_index < books_count)
        return books[book_index];
    return -1;
}
