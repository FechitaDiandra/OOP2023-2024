#include "Complex.h" 
#include <iostream>
#include <cmath>

// Funcție pentru a verifica egalitatea a două numere cu virgulă dublă
bool double_equals(double l, double r) {
    return std::abs(l - r) < 0.001;
}

// Funcție pentru a afișa un număr complex
void printComplex(const Complex& c);

// Macro pentru a verifica condiții și a afișa mesajul de eroare
#define check(x)                                                                                                       \
    if (!(x)) {                                                                                                        \
        std::cout << "at line #" << __LINE__ << " -> `" << #x << "` is not satisfied\n";                                \
        return 1;                                                                                                      \
    }

int main() {
    // Inițializare obiecte Complex
    Complex a{ 1, 2 };
    check(double_equals(a.real(), 1));
    check(double_equals(a.imag(), 2));

    Complex b{ 2, 3 };
    Complex c = a + b;
    check(double_equals(c.real(), 3));
    check(double_equals(c.imag(), 5));

    Complex d = c - a;
    check(b == d);

    Complex e = (a * d).conjugate();
    check(double_equals(e.imag(), -7));

    {
        // Incrementarea părții reale și imaginare
        Complex res1 = e++;
        check(res1 == Complex(-2, -7));
        Complex res2 = ++e;
        check(res2 == Complex(-1, -7));
        check(double_equals(e.real(), -1));
    }

    {
        // Decrementarea părții reale și imaginare
        Complex res1 = e--;
        check(res1 == Complex(-1, -7));
        Complex res2 = --e;
        check(res2 == Complex(-2, -7));
        check(double_equals(e.real(), -2));
    }

    // Calculul expresiei f
    Complex f = (a + b - d) * c;
    if (f != Complex{ 1, 2 }) {
        // Afisarea rezultatului în formatul specificat
        printComplex(f);
        std::cout << '\n';

        // Afișarea altor numere complexe conform cerințelor
        printComplex(a);
        std::cout << '\n';
        printComplex(Complex{ 1, 2 });
        std::cout << '\n';
        printComplex(Complex{ 1, -2 });
        std::cout << '\n';
        printComplex(Complex{ 0, 5 });
        std::cout << '\n';
        printComplex(Complex{ 7, 0 });
        std::cout << '\n';
        printComplex(Complex{ 0, 0 });
        std::cout << '\n';
    }

    // Updatarea părții reale și imaginare utilizând op()
    Complex g = f(-1, -2)(-2, -3)(-4, -5);
    Complex h = { -4, -5 };
    check(g == h);

    Complex i = h - (h + 5) * 2;
    check(double_equals(i.real(), -6));

    // Operatorul - unar
    Complex j = -i + i;
    check(double_equals(j.abs(), 0));

    std::cout << "All tests passed successfully!\n";
    return 0;
}

// Funcție pentru a afișa un număr complex
void printComplex(const Complex& c) {
    // Dacă partea imaginară este zero, afișăm doar partea reală
    if (c.imag() == 0) {
        std::cout << c.real();
    }
    // Dacă partea reală este zero, afișăm doar partea imaginară urmată de 'i'
    else if (c.real() == 0) {
        std::cout << c.imag() << "i";
    }
    // În celelalte cazuri, afișăm întregul număr complex
    else {
        std::cout << c.real() << (c.imag() > 0 ? " + " : " - ") << std::abs(c.imag()) << "i";
    }
}
