
#include "Complex.h"
#include <cmath>
#include <iostream>

Complex::Complex() : real_data(0), imag_data(0) {}

Complex::Complex(double real, double imag) : real_data(real), imag_data(imag) {}

bool Complex::is_real() const {
    return imag_data == 0;
}

double Complex::real() const {
    return real_data;
}

double Complex::imag() const {
    return imag_data;
}

double Complex::abs() const {
    return std::sqrt(real_data * real_data + imag_data * imag_data);
}

Complex Complex::conjugate() const {
    return {real_data, -imag_data};
}

Complex& Complex::operator()(double real, double imag) {
    real_data = real;
    imag_data = imag;
    return *this;
}

Complex& Complex::operator++() {
    ++real_data;
    return *this;
}

Complex Complex::operator++(int) {
    Complex temp(*this);
    ++real_data;
    return temp;
}

Complex& Complex::operator--() {
    --real_data;
    return *this;
}

Complex Complex::operator--(int) {
    Complex temp(*this);
    --real_data;
    return temp;
}

Complex operator+(const Complex& l, const Complex& r) {
    return Complex(l.real() + r.real(), l.imag() + r.imag());
}

Complex operator+(const Complex& l, double r) {
    return Complex(l.real() + r, l.imag());
}

Complex operator+(double l, const Complex& r) {
    return Complex(l + r.real(), r.imag());
}

Complex operator-(const Complex& obj) {
    return Complex(-obj.real(), -obj.imag());
}

bool operator==(const Complex& l, const Complex& r) {
    return l.real() == r.real() && l.imag() == r.imag();
}

bool operator!=(const Complex& l, const Complex& r) {
    return !(l == r);
}

std::ostream& operator<<(std::ostream& out, const Complex& complex) {
    if (complex.is_real()) {
        out << complex.real();
    } else {
        out << complex.real() << (complex.imag() >= 0 ? " + " : " - ") << std::abs(complex.imag()) << "i";
    }
    return out;
}
