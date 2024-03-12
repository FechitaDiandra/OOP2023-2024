#include "Canvas.h"

int main() {
    Canvas canvas(10, 50);
    canvas.SetPoint(4, 4, 25);
    canvas.SetPoint(3, 7, 2);
    canvas.SetPoint(3, 4, 41);
    canvas.SetPoint(3, 1, 31);
    canvas.SetPoint(5, 2, 16);
    canvas.SetPoint(5, 2, 38);
    canvas.SetPoint(5, 5, 27);
    canvas.SetPoint(4, 4, 13);
    canvas.SetPoint(4, 7, 32);
    canvas.SetPoint(4, 5, 15);
    canvas.SetPoint(3, 4, 2);
    canvas.SetPoint(5, 6, 30);
    canvas.SetPoint(3, 5, 17);
    canvas.SetPoint(5, 3, 44);
    canvas.SetPoint(4, 6, 6);
    canvas.SetPoint(5, 3, 10);
    canvas.SetPoint(4, 6, 2);
    canvas.SetPoint(5, 3, 46);
    canvas.SetPoint(3, 4, 17);
    canvas.SetPoint(3, 4, 47);
    canvas.SetPoint(5, 5, 44);
    canvas.SetPoint(3, 4, 38);
    canvas.SetPoint(4, 4, 18);
    canvas.SetPoint(4, 5, 12);
    canvas.SetPoint(5, 4, 40);
    canvas.SetPoint(3, 0, 42);
    canvas.SetPoint(5, 3, 12);
    canvas.SetPoint(4, 3, 25);
    canvas.SetPoint(5, 5, 36);
    canvas.SetPoint(3, 3, 22);
    canvas.SetPoint(3, 1, 33);
    canvas.SetPoint(4, 4, 6);
    canvas.SetPoint(3, 4, 11);
    canvas.SetPoint(4, 2, 43);
    canvas.SetPoint(1, 5, 43);

    canvas.Print();
}