#include "Number.h"
#include <iostream>

using namespace std;

int main()
{
	int i;
	Number n1("1101", 2); //=13 in baza 10
	Number n2("1010", 3); //=31 in baza 10
	Number r("0", 10);
	cout << "n1 este:"; n1.Print();
	cout << "\nBaza lui n1 este:" << n1.GetBase();
	cout << "\nn2 este:"; n2.Print();
	cout << "\nBaza lui n2 este:" << n2.GetBase();
	r = n1 + n2;
	cout << "\nn1+n2 (in baza 3) este:";
	r.Print();
	r = n1 - n2;
	cout << "\nn1-n2 (in baza 3) este:"; r.Print();
	cout << "\nValoarea expresiei n1 == n2 este:" << (n1 == n2);
	cout << "\nValoarea expresiei n1 < n2 este:" << (n1 < n2);
	cout << "\nValoarea expresiei n1 > n2 este:" << (n1 > n2);
	cout << "\nValoarea expresiei n1 <= n2 este:" << (n1 <= n2);
	cout << "\nValoarea expresiei n1 >= n2 este:" << (n1 >= n2);
	cout << "\nValoarea expresiei n1 != n2 este:" << (n1 != n2);
	cout << "\nValoarea expresiei n1 == n2 este:" << (n1 == n2);
	cout << "\nCifrele lui n1 de la dreapta la stanga sunt:";
	for (i = n1.GetDigitsCount() - 1; i >= 0; i--)
		cout << n1[i] << " ";
	cout << "\nCifrele lui n2 de la dreapta la stanga sunt:";
	for (i = n2.GetDigitsCount() - 1; i >= 0; i--)
		cout << n2[i] << " ";
	n1.SwitchBase(3);
	cout << "\nn1 in baza 3 este:"; n1.Print();
	n2.SwitchBase(2);
	cout << "\nn2 in baza 2 este:"; n2.Print();
	--n1;
	cout << "\nn1 fara prima cifra:"; n1.Print();
	n2--;
	cout << "\nn2 fara ultima cifra:"; n2.Print();
}