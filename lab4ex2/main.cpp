#include "MyLibrary.h"
#include <iostream>

int main(int argc, char* argv[]) {
    // Creăm o instanță a clasei MyLibrary fără cărți
    MyLibrary l1 = { std::cout };

    // Afișăm informații despre cărțile din bibliotecă
    l1.print_books(); // Se va afișa: "Found -1 books\nNo books available."

    // Creăm o instanță a clasei MyLibrary cu câteva cărți date
    int l2_ids[] = { 3356, 2213, 5723, 1246, 12573, 6424, 85573, 2235113, 2241 };
    MyLibrary l2{ std::cout, 9, l2_ids };

    // Afișăm informații despre cărțile din bibliotecă
    l2.print_books(); // Se va afișa: "Found 9 books\nBook IDs: 3356 2213 5723 1246 12573 6424 85573 2235113 2241"

    // Creăm o instanță a clasei MyLibrary cu cărți generate aleatoriu
    MyLibrary l3 = { std::cout, 20, 15, 200 };

    // Afișăm informații despre cărțile din bibliotecă
    l3.print_books(); // Se va afișa: "Found 20 books\nBook IDs: ..."

    // Creăm o instanță a clasei MyLibrary cu cărțile specificate în șirul de caractere
    MyLibrary l4 = { std::cout, "12;13;15;16" };

    // Afișăm informații despre cărțile din bibliotecă
    l4.print_books(); // Se va afișa: "Found 4 books\nBook IDs: 12 13 15 16"

    // Creăm o instanță a clasei MyLibrary cu cărțile specificate ca argumente
    MyLibrary l5 = { std::cout, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // Afișăm informații despre cărțile din bibliotecă
    l5.print_books(); // Se va afișa: "Found 10 books\nBook IDs: 1 2 3 4 5 6 7 8 9 10"

    // Obținem o referință constantă la instanța l5
    const MyLibrary& l = l5;

    // Afișăm numărul de cărți și ID-ul unei cărți de la un anumit index
    std::cout << "Found book number: " << l.get_books_count() << std::endl;
    std::cout << "Found book id: " << l.get_book_id_by_index(3) << std::endl;
    std::cout << "Found book id: " << l.get_book_id_by_index(10) << std::endl;

    // Afișăm informații despre cărțile din bibliotecă
    l.print_books();

    // Creăm o altă instanță a clasei MyLibrary
    MyLibrary l6{ std::cout, 0, 5, 10, 15 };

    // Afișăm informații despre cărțile din bibliotecă
    l6.print_books();

    {
        // Creăm o copie a instanței l2
        MyLibrary l2_copy = l2;
        std::cout << "Before update" << std::endl;

        // Afișăm ID-ul primei cărți din instanța l2 și a copiei sale
        std::cout << "Library l2: Book index 0 " << l2.get_book_id_by_index(0) << std::endl;
        std::cout << "Library l2_copy: Book index 0 " << l2_copy.get_book_id_by_index(0) << std::endl;

        // Actualizăm ID-ul primei cărți din instanța l2_copy
        l2_copy.update_book_id_by_index(0, 20);

        // Afișăm ID-ul primei cărți din ambele instanțe pentru a verifica actualizarea
        std::cout << "Library l2: Book index 0 " << l2.get_book_id_by_index(0) << std::endl;
        std::cout << "Library l2_copy: Book index 0 " << l2_copy.get_book_id_by_index(0) << std::endl;
    }

    return 0;
}
