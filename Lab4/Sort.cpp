#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <cstring>
#include <iostream>

 
 Sort::Sort(int count, ...) {
     this->v = new int;
     int val, k = 0;
    va_list vl;
    va_start(vl, count);
    for (int i = 0; i < count; i++)
    {
        this->v[i] = va_arg(v1, int);
        v[k++] = val;
    }
    va_end(vl);
}

 Sort::Sort(int n, int max, int min)
 {
     this->count = n;
     this->v = new int[this->count];
     time_t t;
     srand((unsigned)time(&t));
     for (int i = 0; i < n; i++)
     {
         this->v[i] = min + rand() % (min - max + 1);

     }

 }
 Sort::Sort(int* a, int n){
     this->count = n;
     this->v = new int[this->count];
 for (int i = 0; i < ; i++)
 

     this->v[i] = a[i];
 
 }

     Sort::Sort() : v(new int[6] {1, 2, 3, 4, 5, 6})
 {
     this->count = 6;
 }

 Sort::Sort(char* c)
 {
     int k = 0;
     this->v = new int[101];
     char* s;
     s = strtok(c, ",");
     while (s) {
         this->v[k++] = (int)s;
         s = strtok(NULL, ",");

     }
     this->count = k;

     
 }



 void Sort::BubbleSort()
 {
	 bool ok = false;
	 while (ok == false)
	 {
		 ok = true;
		 for (int i = 0; i < this->size - 1; i++)
			 if (ascendent == true)
				 if (this->v[i] > this->v[i + 1])
				 {
					 int aux = this->v[i];
					 this->v[i] = this->v[i + 1];
					 this->v[i + 1] = aux;
					 ok = false;
				 }
				 else
					 if (this->v[i] < this->v[i + 1])
					 {
						 int aux = this->v[i];
						 this->v[i] = this->v[i + 1];
						 this->v[i + 1] = aux;
						 ok = false;
					 }

	 }

 }

 void Sort::InsertSort(bool ascendent)
 {
	 for (int i = 1; i < this->size; i++)
	 {
		 int p = i;

		 while (p > 0 && ((ascendent == true && this->v[p] < this->v[p - 1]) || (ascendent == false && this->v[p] > this->v[p - 1])))
		 {
			 int aux = this->v[p];
			 this->v[p] = this->v[p - 1];
			 this->v[p - 1] = aux;
			 p--;
		 }
	 }
	 ascendent = true;
 }

 void Sort::QuickSort(int st, int dr, bool ascendent)
 {
	 if (st < dr)
	 {
		 //pivotul este inițial v[st]
		 int m = (st + dr) / 2;
		 int aux = this->v[st];
		 this->v[st] = this->v[m];
		 this->v[m] = aux;
		 int i = st, j = dr, d = 0;
		 while (i < j)
		 {
			 if (ascendent)
			 {
				 if (this->v[i] > this->v[j])
				 {
					 aux = this->v[i];
					 this->v[i] = this->v[j];
					 this->v[j] = aux;
					 d = 1 - d;
				 }
				 i += d;
				 j -= 1 - d;
			 }
			 else
			 {
				 if (this->v[i] < this->v[j])
				 {
					 aux = this->v[i];
					 this->v[i] = this->v[j];
					 this->v[j] = aux;
					 d = 1 - d;
				 }
				 i += d;
				 j -= 1 - d;

			 }

		 }
		 QuickSort(st, i - 1, ascendent);
		 QuickSort(i + 1, dr, ascendent);
	 }

 }

 void Sort::QuickSort(bool ascendent)
 {
	 QuickSort(0, this->size, ascendent);

 }


 void Sort::Print()
 {
	 for (int i = 0; i < this->size; i++)
		 printf("%d%c", this->v[i], ' ');

 }

 int  Sort::GetElementsCount()
 {
	 printf("%d", this->size);
 }

 int  Sort::GetElementFromIndex(int index)
 {
	 printf("%d", this->v[index]);
 }
 void Sort::Print(std::vector<int> this->v)
 {
     for (int i = 0; i < this->count);i++) {
         printf("%d\n", this->v[i],"");
         printf("\n");
   

 }


