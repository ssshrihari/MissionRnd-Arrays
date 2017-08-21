/*
Well Done for completing the first part of the C Course ,If you didnt finish
Do complete them and come here again .

Use MainArrays2 File for testing any other function in other Cpp files of the Strings Project.

DO NOT write main function in any other File or else your Build Fails.s

Objectives of C-Arrays-2 Lesson:

->Handling Arrays of Structures
->Sorting Arrays
->Learning Complexities of your Algorithm

*/
#include <stdio.h>
#include "FunctionHeadersArrays2.h"
struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int main(){

	//Test countGreaterNumbers
	//struct transaction Arr[5] = { { 60, "09-10-2003", "First" }, { 70, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" }, { 90, "21-05-2006", "Fourth" }, { 10, "29-11-2007", "Fifth" } };
	//int count = countGreaterNumbers(Arr, 5, "09-10-2003");
	//Test findSingleOccurenceNumber

	//Test mergeSortedArray
	//struct transaction A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
	//struct transaction B[3] = { { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" }, { 60, "22-04-2006", "Sixth" } };
	//int A[3] = { 1, 2, 3 }, B[3] = { 2, 3, 6 };
	//struct transaction *result = mergeSortedArrays(A, 3, B, 3);
	//Test sortedArraysCommonElements

	//Test others
	//int input[10] = { -10, -30, -50, 100, 50, 25, -100, -225 };
	//int ans[6] = { 0, 2, 5, 7, 3, 5 };
	//int len = 8;
	//int *res = find_sequences(input, len);

	int arr[100] = { 1, 2, 7, 20, 3, 5, 4, 9, 8 };
	int len = 9;
	int expectedArray[2] = { 3, 3 };
	int *actualArray = getLeaderIndex(arr, len);
	//printf("%d %d", a[0], a[1]);
	
	for (int i = 0; i < 2; i++) 
	{
		printf("%d\n", *(actualArray + i));
	}

	getchar();
	return 0;
}