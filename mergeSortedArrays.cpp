/*
OVERVIEW: You are given 2 bank statements that are ordered by date -
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>
#include<stdlib.h>
int compare_date(char *date_1, char *date_2);
struct transaction {
	int amount;
	char date[11];
	char description[20];
};



struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen)
{
	if (A == NULL || B == NULL || ALen <= 0 || BLen <= 0)
		return NULL;

	int i = 0, j = 0, l = 0;
	struct transaction *merge = NULL;
	merge = (struct transaction *)malloc(sizeof(struct transaction)*(ALen + BLen));
	while (l < ALen + BLen)
	{
		if (compare_date(A[i].date, B[j].date) == 1)
		{
			merge[l] = B[j];
			l++;
			j++;
		}
		else
		{
			merge[l] = A[i];
			l++;
			i++;
		}
		if (i == ALen)
		{
			while (j < BLen)
			{
				merge[l] = B[j];
				l++;
				j++;
			}
		}
		if (j == BLen)
		{
			while (i < ALen)
			{
				merge[l] = A[i];
				l++;
				i++;
			}
		}
	}
	return merge;

}

int compare_date(char *date_1, char *date_2)
{
	int d1, d2, m1, m2, y1, y2;

	sscanf_s(date_1, "%d-%d-%d", &d1, &m1, &y1);
	sscanf_s(date_2, "%d-%d-%d", &d2, &m2, &y2);
	if (y1 > y2)
		return 1;
	else if (y1 < y2)
		return -1;
	else
	{
		if (m1 > m2)
		{
			return 1;
		}
		else if (m1 < m2)
			return -1;
		else
		{
			if (d1 > d2)
				return 1;
			else if (d1 < d2)
				return -1;
			else
				return 0;
		}
	}
}