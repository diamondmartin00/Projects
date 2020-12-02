/*
This programs sorts arrays using two different sorting algorithms and prints arrays by using pointers. 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//function prototypes
void sort1(int *a, int n); //sorts the arry using the bubble sort algorithms
void sort2(int *a, int n); //sorts the arry using the selection sort algorithms
void print(int a, int n); //prints the array
void main() { 
	int array1[] = {60, 70, 40, 45, 30, 35, 80, 75, 43, 31, 20, 88, 76, 74, 62, 71, 82, 64, 39, 21}; //first array being sorted and printed by bubble sort
	int array2[] = {60, 70, 40, 45, 30, 35, 80, 75, 43, 31, 20, 88, 76, 74, 62, 71, 82, 64, 39, 21}; //second array being sorted and printed by selection sort
	int n = 20; //number of elements in the array
	sort1(array1, n);
	print(array1, n);
	sort2(array2, n);
	print(array2, n);
	scanf("%d", &n); 
}
void sort1(int *array, int n) {
	int sorted = 0;
	int k = n;
	int i, *ptr;
	int *temp;
	ptr = array;
	while (sorted == 0) {
		sorted = 1;
		for (i = 0; i < k - 1; i++) {
			if (*ptr > *(ptr + 1)) {
				sorted = 0;
				*temp = *ptr;
				*ptr = *(ptr + 1);
				*(ptr + 1) = *temp;
			}
			k--;
		}
	}
}
void sort2(int *array, int n) {
	int i, j, minPosition, *temp;
	int *ptr;
	ptr = array;
	for (i = 0; i < n - 1; i++) {
		minPosition = i;
		for (j = i + 1; j < n; j++) {
			if (*ptr < *(ptr + minPosition)) {
				minPosition = j;
			}
			*temp = *ptr + minPosition;
			*(ptr + minPosition) = *(ptr + i);
			*(ptr + i) = *temp;
		}
	}
}
void print(int array, int n) {
	int i, k;
	int *ptr;
	ptr = array;
	k = n;
	for (i = 0; i < n - 1; i++)
		printf("%d",*(ptr + i));
	if (k != n - 1) {
		printf(", ");
		}
	printf("\nn = %d", n);
}
/*
Run 2:
20, 21, 30, 31, 35, 39, 40, 43, 45, 60, 62, 64, 70, 71, 74, 75, 76, 80, 82, 88
n = 20
20, 21, 30, 31, 35, 39, 40, 43, 45, 60, 62, 64, 70, 71, 74, 75, 76, 80, 82, 88
n = 20
Run 3:
67, 68, 69, 71, 72, 73, 74, 75, 76, 77, 78, 79, 81, 82, 83, 84, 85, 86, 87, 88, 89, 91, 92, 93, 94, 95, 96, 97, 98, 99
n = 30
67, 68, 69, 71, 72, 73, 74, 75, 76, 77, 78, 79, 81, 82, 83, 84, 85, 86, 87, 88, 89, 91, 92, 93, 94, 95, 96, 97, 98, 99
n = 30
*/