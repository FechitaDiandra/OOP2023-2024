
#pragma once

#include <iostream>

class Complex {
private:
    double real_data;
    double imag_data;

public:
    Complex();
    Complex(double real, double imag);

    bool is_real() const;
    double real() const;
    double imag() const;
    double abs() const;
    Complex conjugate() const;

    Complex& operator()(double real, double imag);
    Complex& operator++();       // Prefix increment
    Complex operator++(int);     // Postfix increment
    Complex& operator--();       // Prefix decrement
    Complex operator--(int);     // Postfix decrement
};

Complex operator+(const Complex& l, const Complex& r);
Complex operator+(const Complex& l, double r);
Complex operator+(double l, const Complex& r);

Complex operator-(const Complex& obj);

bool operator==(const Complex& l, const Complex& r);
bool operator!=(const Complex& l, const Complex& r);

std::ostream& operator<<(std::ostream& out, const Complex& complex);
Complex operator-(const Complex& l, const Complex& r) {
    return Complex(l.real() - r.real(), l.imag() - r.imag());
}
Complex operator*(const Complex& l, const Complex& r) {
    double real_part = l.real() * r.real() - l.imag() * r.imag();
    double imag_part = l.real() * r.imag() + l.imag() * r.real();
    return Complex(real_part, imag_part);
}
Complex operator*(const Complex& c, int scalar) {
    return Complex(c.real() * scalar, c.imag() * scalar);
}

