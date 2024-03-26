#pragma once
#include <cstring>
#include <cstdlib>
#include <iostream>

class Number {
private:
    char* value;
    int base;
    bool negativ;

    // Metodă privată pentru a converti valoarea stocată în șir de caractere la întreg
    int ToInteger() const {
        return std::stoi(this->value, nullptr, this->base);
    }

public:
    // Constructor pentru a inițializa un obiect Number cu o valoare întreagă
    Number(int value) {
        std::string strValue = std::to_string(value);
        this->value = (char*)malloc((strValue.length() + 1) * sizeof(char));
        strcpy(this->value, strValue.c_str());
        this->base = 10;
        this->negativ = false;
    }

    // Constructor pentru a inițializa un obiect Number cu un șir de caractere și o bază specificată
    Number(const char* value, int base);

    // Destructor pentru eliberarea memoriei alocate dinamic
    ~Number();

    // Constructor de mutare
    Number(Number&&);

    // Constructor de copiere
    Number(const Number&);

    // Operator de mutare
Number& operator=(const char* value) {
        if (this->value != nullptr) {
            free(this->value); // Eliberăm memoria alocată anterior
        }
        this->value = (char*)malloc((strlen(value) + 1) * sizeof(char));
        strcpy(this->value, value);
        return *this;
    }

    // Operator de atribuire
    Number& operator=(const Number&);

    // Metodă pentru a schimba baza numărului
    void SwitchBase(int);

    // Metodă pentru a afișa numărul
    void Print();

    // Metodă pentru a obține numărul de cifre
    int GetDigitsCount();

    // Metodă pentru a obține baza numărului
    int GetBase();

    // Supraincarcare a operatorului de adunare
    friend Number operator+(const Number&, const Number&);

    // Supraincarcare a operatorului de scădere
    friend Number operator-(const Number&, const Number&);

    // Supraincarcare a operatorului unar "-"
    Number operator-();

    // Supraincarcare a operatorului "<"
    const bool operator<(const Number&);

    // Supraincarcare a operatorului ">"
    const bool operator>(const Number&);

    // Supraincarcare a operatorului "<="
    const bool operator<=(const Number&);

    // Supraincarcare a operatorului ">="
    const bool operator>=(const Number&);

    // Supraincarcare a operatorului "=="
    const bool operator==(const Number&);

    // Supraincarcare a operatorului "!="
    const bool operator!=(const Number&);

    // Supraincarcare a operatorului "+="
    Number& operator+=(const Number&);

    // Supraincarcare a operatorului "--" prefixat
    Number operator--();

    // Supraincarcare a operatorului "--" sufixat
    Number operator--(int);

    // Supraincarcare a operatorului de indexare
    char& operator[](int);
};
