#include "Canvas.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

Canvas::Canvas(int width, int height)
{
	int i;
	this->width = width;
	this->height = height;
	matrix = (char**)(malloc(height * sizeof(char*)));
	for (i = 0; i < height; i++)
		matrix[i] = (char*)(malloc(width * sizeof(char)));
	Clear();
}
Canvas::~Canvas()
{
	int i;
	for (i = 0; i < height; i++)
		free(matrix[i]);
	free(matrix);
}
void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	int i, j;
	for (i = 0; i < width; i++)
		for (j = 0; j < height; j++)
			if ((i - x) * (i - x) + (j - y) * (j - y) >= ray * (ray - 1) &&
				(i - x) * (i - x) + (j - y) * (j - y) <= ray * (ray + 1))
				SetPoint(i, j, ch);
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	int i, j;
	for (i = 0; i < width; i++)
		for (j = 0; j < height; j++)
			if ((i - x) * (i - x) + (j - y) * (j - y) <= ray * ray)
				SetPoint(i, j, ch);
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	int i, j;
	for (i = top; i <= bottom; i++)
	{
		matrix[i][left] = ch;
		matrix[i][right] = ch;
	}
	for (j = left; j <= right; j++)
	{
		matrix[top][j] = ch;
		matrix[bottom][j] = ch;
	}
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	int i, j;
	for (i = top; i <= bottom; i++)
		for (j = left; j <= right; j++)
			matrix[i][j] = ch;
}

void Canvas::SetPoint(int x, int y, char ch)
{
	if (x >= 0 && x < width && y >= 0 && y < height)
	{
		matrix[y][x] = ch;
	}
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int x, y;
	double deltax, deltay;
	double panta;
	if (x1 == x2)
		if (y1 <= y2)
			for (y = y1; y <= y2; y++)
				SetPoint(x1, y, ch);
		else
			for (y = y2; y <= y1; y++)
				SetPoint(x1, y, ch);
	else
	{
		deltax = x2 - x1;
		deltay = y2 - y1;
		panta = deltay / deltax;
		if (x1 <= x2)
			for (x = x1; x <= x2; x++)
			{
				y = int(y1 + panta * (x - x1));
				SetPoint(x, y, ch);
			}
		else
			for (x = x1; x >= x2; x--)
			{
				y = int(y1 + panta * (x - x1));
				SetPoint(x, y, ch);
			}
	}
}

void Canvas::Print()
{
	int i, j;
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
			cout << matrix[i][j];
		cout << endl;
	}
}

void Canvas::Clear()
{
	int i, j;
	for (i = 0; i < height; i++)
		for (j = 0; j < width; j++)
			matrix[i][j] = ' ';
}