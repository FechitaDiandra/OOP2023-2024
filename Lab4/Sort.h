#pragma once
class Sort

{
private:
    int* v;
    int count;

public:

    Sort(int n, int min, int max);
    Sort(int v, int count);
    Sort();
    Sort(int count, ...);
    Sort(char* string);

    void InsertSort(bool ascendent = false);

    void QuickSort(bool ascendent = false);

    void BubbleSort(bool ascendent = false);

    void Print();

    int  GetElementsCount();

    int  GetElementFromIndex(int index);

};

