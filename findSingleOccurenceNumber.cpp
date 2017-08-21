/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/

#include<stdio.h>
#include <stdlib.h>


int findSingleOccurenceNumber(int *arr, int n) {
	if (arr == NULL || n <= 0)
		return -1;
	int one = 0, two = 0;
	int common;
	for (int i = 0; i< n; i++)
	{
		two = (two) | (one & arr[i]);
		one = (one ^ arr[i]);
		common = ~(one & two);
		one = one & common;
		two = two & common;
	}
	return one;
}