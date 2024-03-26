#define _CRT_SECURE_NO_WARNINGS
#include "Number.h"
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

Number::Number(const char* value, int base)
{
	if (value[0] == '-')
	{
		this->value = (char*)malloc(strlen(value) * sizeof(char));
		strcpy(this->value, value+1);
		negativ = true;
	}
	else
	{
		this->value = (char*)malloc((strlen(value) + 1) * sizeof(char));
		strcpy(this->value, value);
		negativ = false;
	}
	this->base = base;
}
Number::~Number()
{
	if(value != NULL)
		free(value);
}
Number::Number(Number&& x)
{
	value = x.value;
	base = x.base;
	negativ = x.negativ;
	x.value = NULL;
}
Number& Number::operator = (Number&& x)
{
	if (this != &x)
	{
		free(value);
		value = x.value;
		base = x.base;
		negativ = x.negativ;
		x.value = NULL;
	}
	return *this;
}
Number::Number(const Number& n)
{
	base = n.base;
	negativ = n.negativ;
	value = (char*)malloc((strlen(n.value) + 1) * sizeof(char));
	strcpy(value, n.value);
}
Number& Number::operator = (const Number& n)
{
	if (this != &n)
	{
		base = n.base;
		negativ = n.negativ;
		free(value);
		value = (char*)malloc((strlen(n.value) + 1) * sizeof(char));
		strcpy(value, n.value);
	}
	return *this;
}
void Number::SwitchBase(int newBase)
{
	int n, i, lg, c, cat, cn;
	//Transform numarul din base in baza 10
	n = 0;
	lg = strlen(value);
	for (i = 0; i < lg; i++)
	{
		if (value[i] <= '9')
			c = value[i] - '0';
		else
			c = value[i] - 'A' + 10;
		n = n * base + c;
	}
	//Transform numarul din baza 10 in baza newBase
	//Etapa 1: determin numarul de cifre
	lg = 0;
	cn = n;
	do
	{
		cat = cn / newBase;
		lg++;
		cn = cat;
	} while (cat != 0);
	//Etapa 2: Pun cifrele in memoria alocata
	lg++;
	value = (char*)malloc(lg * sizeof(char));
	value[lg - 1] = 0;
	do
	{
		c = n % newBase;
		lg--;
		if (c <= 9)
			value[lg - 1] = '0' + c;
		else
			value[lg - 1] = 'A' + c - 10;
		cat = n / newBase;
		n = cat;
	} while (cat != 0);
	base = newBase;
}
void Number::Print()
{
	if (negativ)
		cout << "-";
	cout << value;
}
int Number::GetDigitsCount()
{
	return strlen(value);
}
int Number::GetBase()
{
	return base;
}
Number operator + (const Number &n1, const Number &n2)
{
	Number r("0", 10);
	int v1, v2, ln1, ln2, c, s, lr, cs, i;
	//Obtin valoarea lui n1 in baza 10.
	v1 = 0;
	ln1 = strlen(n1.value);
	for (i = 0; i < ln1; i++)
	{
		if (n1.value[i] <= '9')
			c = n1.value[i] - '0';
		else
			c = n1.value[i] - 'A' + 10;
		v1 = v1 * n1.base + c;
	}
	//Obtin valoarea lui n2 in baza 10.
	v2 = 0;
	ln2 = strlen(n2.value);
	for (i = 0; i < ln2; i++)
	{
		if (n2.value[i] <= '9')
			c = n2.value[i] - '0';
		else
			c = n2.value[i] - 'A' + 10;
		v2 = v2 * n2.base + c;
	}
	//Obtin suma in baza 10
	if (n1.negativ)
		v1 = -v1;
	if (n2.negativ)
		v2 = -v2;
	s = v1 + v2;
	if (s < 0)
	{
		r.negativ = true;
		s = -s;
	}
	else
		r.negativ = false;
	//Construiesc obiectul rezultat
	if (n1.base > n2.base)
		r.base = n1.base;
	else
		r.base = n2.base;
	//Transform s din baza 10 in baza r.base
	//Etapa 1: determin numarul de cifre
	lr = 0;
	cs = s;
	do
	{
		cs = cs / r.base;
		lr++;
	} while (cs!= 0);
	//Etapa 2: Pun cifrele in memoria alocata
	lr++;
	r.value = (char*)malloc(lr * sizeof(char));
	r.value[lr - 1] = 0;
	do
	{
		c = s % r.base;
		lr--;
		if (c <= 9)
			r.value[lr - 1] = '0' + c;
		else
			r.value[lr - 1] = 'A' + c - 10;
		s = s / r.base;
	} while (s != 0);
	return r;
}
Number operator - (const Number &n1, const Number &n2)
{
	Number r("0", 10);
	int v1, v2, ln1, ln2, c, d, lr, cd, i;
	//Obtin valoarea lui n1 in baza 10.
	v1 = 0;
	ln1 = strlen(n1.value);
	for (i = 0; i < ln1; i++)
	{
		if (n1.value[i] <= '9')
			c = n1.value[i] - '0';
		else
			c = n1.value[i] - 'A' + 10;
		v1 = v1 * n1.base + c;
	}
	//Obtin valoarea lui n2 in baza 10.
	v2 = 0;
	ln2 = strlen(n2.value);
	for (i = 0; i < ln2; i++)
	{
		if (n2.value[i] <= '9')
			c = n2.value[i] - '0';
		else
			c = n2.value[i] - 'A' + 10;
		v2 = v2 * n2.base + c;
	}
	//Obtin suma in baza 10
	if (n1.negativ)
		v1 = -v1;
	if (n2.negativ)
		v2 = -v2;
	d = v1 - v2;
	if (d < 0)
	{
		r.negativ = true;
		d = -d;
	}
	else
		r.negativ = false;
	//Construiesc obiectul rezultat
	if (n1.base > n2.base)
		r.base = n1.base;
	else
		r.base = n2.base;
	//Transform s din baza 10 in baza r.base
	//Etapa 1: determin numarul de cifre
	lr = 0;
	cd = d;
	do
	{
		cd = cd / r.base;
		lr++;
	} while (cd != 0);
	//Etapa 2: Pun cifrele in memoria alocata
	lr++;
	r.value = (char*)malloc(lr * sizeof(char));
	r.value[lr - 1] = 0;
	do
	{
		c = d % r.base;
		lr--;
		if (c <= 9)
			r.value[lr - 1] = '0' + c;
		else
			r.value[lr - 1] = 'A' + c - 10;
		d = d / r.base;
	} while (d != 0);
	return r;
}
Number Number::operator -()
{
	if (strcmp(value, "0") != 0)
		negativ = !negativ;
	return *this;
}
const bool Number::operator < (const Number& x)
{
	int vn, i, lg, c,vx;
	//Transform numarul din obiectul curent in baza 10
	vn = 0;
	lg = strlen(value);
	for (i = 0; i < lg; i++)
	{
		if (value[i] <= '9')
			c = value[i] - '0';
		else
			c = value[i] - 'A' + 10;
		vn = vn * base + c;
	}
	if (negativ)
		vn = -vn;
	//Transform numarul din obiectul x in baza 10
	vx = 0;
	lg = strlen(x.value);
	for (i = 0; i < lg; i++)
	{
		if (x.value[i] <= '9')
			c = x.value[i] - '0';
		else
			c = x.value[i] - 'A' + 10;
		vx = vx * x.base + c;
	}
	if (x.negativ)
		vx = -vx;
	return vn < vx;
}
const bool Number::operator > (const Number& x)
{
	int vn, i, lg, c, vx;
	//Transform numarul din obiectul curent in baza 10
	vn = 0;
	lg = strlen(value);
	for (i = 0; i < lg; i++)
	{
		if (value[i] <= '9')
			c = value[i] - '0';
		else
			c = value[i] - 'A' + 10;
		vn = vn * base + c;
	}
	if (negativ)
		vn = -vn;
	//Transform numarul din obiectul x in baza 10
	vx = 0;
	lg = strlen(x.value);
	for (i = 0; i < lg; i++)
	{
		if (x.value[i] <= '9')
			c = x.value[i] - '0';
		else
			c = x.value[i] - 'A' + 10;
		vx = vx * x.base + c;
	}
	if (x.negativ)
		vx = -vx;
	return vn > vx;
}
const bool Number::operator <= (const Number& x)
{
	int vn, i, lg, c, vx;
	//Transform numarul din obiectul curent in baza 10
	vn = 0;
	lg = strlen(value);
	for (i = 0; i < lg; i++)
	{
		if (value[i] <= '9')
			c = value[i] - '0';
		else
			c = value[i] - 'A' + 10;
		vn = vn * base + c;
	}
	if (negativ)
		vn = -vn;
	//Transform numarul din obiectul x in baza 10
	vx = 0;
	lg = strlen(x.value);
	for (i = 0; i < lg; i++)
	{
		if (x.value[i] <= '9')
			c = x.value[i] - '0';
		else
			c = x.value[i] - 'A' + 10;
		vx = vx * x.base + c;
	}
	if (x.negativ)
		vx = -vx;
	return vn <= vx;
}
const bool Number::operator >= (const Number& x)
{
	int vn, i, lg, c, vx;
	//Transform numarul din obiectul curent in baza 10
	vn = 0;
	lg = strlen(value);
	for (i = 0; i < lg; i++)
	{
		if (value[i] <= '9')
			c = value[i] - '0';
		else
			c = value[i] - 'A' + 10;
		vn = vn * base + c;
	}
	if (negativ)
		vn = -vn;
	//Transform numarul din obiectul x in baza 10
	vx = 0;
	lg = strlen(x.value);
	for (i = 0; i < lg; i++)
	{
		if (x.value[i] <= '9')
			c = x.value[i] - '0';
		else
			c = x.value[i] - 'A' + 10;
		vx = vx * x.base + c;
	}
	if (x.negativ)
		vx = -vx;
	return vn >= vx;
}
const bool Number::operator == (const Number& x)
{
	return strcmp(value, x.value) == 0 && base == x.base && negativ == x.negativ;
}
const bool Number::operator != (const Number& x)
{
	return !(strcmp(value, x.value) == 0 && base == x.base && negativ == x.negativ);
}
Number Number::operator --()
{
	int lg, i;
	lg = strlen(value);
	if (lg > 1)
		for (i = 0; i < lg; i++)
			value[i] = value[i + 1];
	return *this;
}
Number Number::operator --(int)
{
	int lg;
	lg = strlen(value);
	if (lg > 1)
		value[lg - 1] = 0;
	return *this;
}
char& Number::operator[](int i)
{
	return value[i];
}