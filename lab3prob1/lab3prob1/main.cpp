#include <iostream>
#include "Math.h"

using namespace std;

int main()
{
    int x, y, z, t;
    double a, b, c;
    char s1[100], s2[100];
    cout << "Please introduce the first string(s1):" << endl;
    cin.getline(s1, 100);
    cout << "Please introduce the second string(s2):" << endl;
    cin.getline(s2, 100);
    char* s3 = Math::Add(s1, s2);
    cout << "s1 + s2 =" << s3 << endl;
    if (s3 != NULL)
        free(s3);
    cout << "Please introduce 3 integer numbers(x, y, z):" << endl;
    cin >> x >> y >> z;
    cout << "x + y = " << Math::Add(x, y) << endl;
    cout << "x + y + z = " << Math::Add(x, y, z) << endl;
    cout << "x * y = " << Math::Mul(x, y) << endl;
    cout << "x * y * z = " << Math::Mul(x, y, z) << endl;

    cout << "Please introduce an extra integer number(t):" << endl;
    cin >> t;
    cout << "x + y + z + t = " << Math::Add(4, x, y, z, t) << endl;

    cout << "Please introduce 3 real numbers(a, b, c):" << endl;
    cin >> a >> b >> c;
    cout << "a + b = " << Math::Add(a, b) << endl;
    cout << "a + b + c = " << Math::Add(a, b, c) << endl;
    cout << "a * b = " << Math::Mul(a, b) << endl;
    cout << "a * b * c = " << Math::Mul(a, b, c) << endl;

    return 0;
}
