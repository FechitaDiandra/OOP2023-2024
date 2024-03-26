#pragma once

class Number
{
private:
	char* value;
	int base;
	bool negativ;
public:
	Number(const char*, int); // where base is between 2 and 16
	~Number();
	Number(Number&&);
	Number(const Number&);
	Number& operator = (Number&&);
	Number& operator = (const Number&);
	void SwitchBase(int);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
	friend Number operator + (const Number&, const Number&);
	friend Number operator - (const Number&, const Number&);
	Number operator -();
	const bool operator < (const Number&);
	const bool operator > (const Number&);
	const bool operator <= (const Number&);
	const bool operator >= (const Number&);
	const bool operator == (const Number&);
	const bool operator != (const Number&);
	Number operator --();
	Number operator --(int);
	char& operator[](int);
};