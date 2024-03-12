#define _CRT_SECURE_NO_WARNINGS
#include "Math.h"
#include <cstdarg>
#include <cstring>
#include <stdlib.h>

int Math::Add(int x, int y)
{
	return x + y;
}

int Math::Add(int x, int y, int z)
{
	return x + y + z;
}

int Math::Add(double x, double y)
{
	return int(x + y);
}

int Math::Add(double x, double y, double z)
{
	return int(x + y + z);
}

int Math::Mul(int x, int y)
{
	return x * y;
}

int Math::Mul(int x, int y, int z)
{
	return x * y * z;
}

int Math::Mul(double x, double y)
{
	return int(x * y);
}

int Math::Mul(double x, double y, double z)
{
	return int(x * y * z);
}

int Math::Add(int count, ...)
{
	va_list args;
	int a, i, sum;
	va_start(args, count);
	sum = 0;
	for (i = 1; i <= count; i++)
	{
		a = va_arg(args, int);
		sum += a;
	}
	va_end(args);
	return sum;
}

char* Math::Add(const char* x, const char* y)
{
	int i = 0;
	char* ok;
	ok = (char*)malloc(strlen(x) + strlen(y) + 1);
	if (x == NULL || y == NULL)
		return NULL;
	else
	{
		while (*x != '\0')
		{
			ok[i] = *x;
			x++;
			i++;
		}
		while (*y != '\0')
		{
			ok[i] = *y;
			y++;
			i++;
		}
	}
	ok[i] = '\0';
	return ok;
}