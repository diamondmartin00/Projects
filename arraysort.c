/*
Diamond Martin
Class: CSC 362-001, Programming Assignment 3
November 4th, 2020
This programs sorts two arrays using two different sorting algorithms, which are bubble sort and selection sort, and prints the arrays. The arrays are sorted and printed by using pointers rather than array references.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//function prototypes
void sort1(int *a1, int n); //sorts the array using the bubble sort algorithm
void sort2(int *a2, int n); //sorts the array using the selection sort algorithm
void print(int *a, int n); //prints the sorted array
void main() {
	int array1[] = {99, 98, 97, 96, 95, 94, 93, 92, 91, 89, 88, 87, 86, 85, 84, 83, 82, 81, 79, 78, 77, 76, 75, 74, 73, 72, 71, 69, 68, 67}; //first array being sorted by bubble sort and printed
	int array2[] = {99, 98, 97, 96, 95, 94, 93, 92, 91, 89, 88, 87, 86, 85, 84, 83, 82, 81, 79, 78, 77, 76, 75, 74,73, 72, 71, 69, 68, 67}; //second array being sorted by selection sort and printed
	int n = 30; //number of elements in the array
	sort1(array1, n); //sorts array1 using the bubble sort algorithm
	print(array1, n); //prints array1
	sort2(array2, n); //sorts array2 using the selection sort algorithm
	print(array2, n); //prints array2
	scanf("%d", &n);
}
//sort1 uses bubble sort to sort through the array, and pointers are used to access array elements
void sort1(int *arr, int n) {
	int sorted, k, temp, *ptr; //variables used for bubble sort and ptr is a pointer for array1
	sorted = 0; //used to denote sorted as false
	k = n; //number of elements in array
	while (sorted == 0) { //loop until array is sorted
		sorted = 1; //sorted is denoted as true
		for (ptr = arr; ptr < arr + (k - 1); ptr++) { //loop is used to iterate through the array
			if (*ptr > *(ptr + 1)) {     //if the current element, which is the ptr derefrenced, is greater than the next element, which is the ptr + 1 being derefenced
				sorted = 0;              //sorted is denoted as false since the array isn't sorted
				temp = *ptr;             //the current element is placed into the temp variable
				*ptr = *(ptr + 1);       //the next element is swapped with the current element
				*(ptr + 1) = temp;       //current element in the temp variable is swapped with the next element
			}
		}
		k--;  //decrement k
		}
	}

//sort2 uses selection sort to sort through the array, and pointers are used to access array elements
void sort2(int *arr, int n) {
	int *minPosition, *ptr2, *ptr, temp; //minPosition, ptr2, and ptr are pointers for array2 and temp is a variable
	for (ptr = arr; ptr < arr + (n - 1); ptr++) { //loop is used to iterate through the array
		minPosition = ptr;               //minPosition points to what ptr points to
		for (ptr2 = ptr + 1; ptr2 < arr + n; ptr2++) { //loop is used to iterate through the array
            //ptr2 points to the element after the element that the ptr points to
			if (*ptr2 < *minPosition) { //if the next element, which is the ptr2 being deferenced, is least than the current element, which is the minPosition being deferenced
				minPosition = ptr2;     //minPosition points to what ptr2 points to
			}
		}
		temp = *minPosition;            //the minPosition element is placed into the temp variable
		*minPosition = *ptr;            //the current element is swapped with the minPosition element
		*ptr = temp;                    // the minPosition element, which is in the temp variable, is swapped with the current element
	}

}
//print iterates through the sorted array to print out the array elements and prints out the number of elemetns in the array
void print(int *arr, int n) {
	int *ptr; //pointer for the array
	printf("\n");
	for (ptr = arr; ptr < arr + n; ptr++) { //loop is used to iterate through the sorted array
		printf("%d", *ptr);                 //the element is printed by deferencing the pointer
		if (ptr != arr + (n - 1)) { //if the element is not the last element of the array
			printf(", ");           //prints comma and space
		}
	}
	printf("\nn = %d", n);          //prints the number of elements in the array
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