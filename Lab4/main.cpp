
#include "Sort.h"
#include <stdlib.h>

int main() {
	Sort c1(10, 10, 100);
	int v[5] = { 1, 2, 3, 4, 5 };
	Sort c2(v, 5);
	Sort c3(6, 1, 2, 3, 4, 5, 6);
	char c[] = "12,34,56,78";
	Sort c4(c);
	Sort c5();

	c1.BubbleSort(true);
	c1.Print();
	c2.InsertSort(true);
	c2.Print();
	c3.QuickSort();
	c3.Print();


	system("pause");
	return 0;
}
