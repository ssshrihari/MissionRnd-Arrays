/*
OVERVIEW: You are given 2 bank statements that are ordered by date.
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input:
A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	int d1 = 0, d2 = 0, count = 0, m1 = 0, m2 = 0, y1 = 0, y2 = 0, c;
	int i, x, j = 1, k;
	struct transaction * common = (struct transaction*)malloc(sizeof(struct transaction) * 10);
	if (BLen <= 0 || A == NULL || B == NULL || ALen <= 0)
		return NULL;

	//	int d1 = 0, d2 = 0, m1 = 0, m2 = 0, y1 = 0, y2 = 0;
	//	int i, x, j = 1;
	for (j = ALen - 1; j >= 0; j--)
	{

		d1 = 0;
		m1 = 0;
		y1 = 0;
		for (i = 0; i <= 9; i++)
		{
			if (i == 2 || i == 5)
			{
				//j = 1;
				continue;
			}
			if (i <= 1)
			{
				x = A[j].date[i] - 48;
				d1 = (d1 * 10) + x;

			}
			if (i <= 4 && i >= 3)
			{

				x = A[j].date[i] - 48;
				m1 = (m1 * 10) + x;
			}

			if (i <= 9 && i >= 6)
			{

				x = A[j].date[i] - 48;
				y1 = (y1 * 10) + x;

			}
		}
		for (k = BLen - 1; k >= 0; k--)
		{
			d2 = 0;
			m2 = 0;
			y2 = 0;
			for (i = 0; i <= 9; i++)
			{
				if (i == 2 || i == 5)
				{
					//j = 1;
					continue;
				}
				if (i <= 1)
				{
					x = B[k].date[i] - 48;
					d2 = (d2 * 10) + x;

				}
				if (i <= 4 && i >= 3)
				{

					x = B[k].date[i] - 48;
					m2 = (m2 * 10) + x;
				}

				if (i <= 9 && i >= 6)
				{

					x = B[k].date[i] - 48;
					y2 = (y2 * 10) + x;

				}
			}
		}
		//printf("\n %d\t%d\n", y2, y1);
		if (y1 < y2)
		{
			//count++;
			//printf("\n %d", count);
			continue;
		}
		if (y1 == y2)
		{
			if (m1 < m2)
				continue;
			else if (m1 == m2)
			{
				if (d1 < d2)
					continue;
				else if (d1 == d2)
				{
					for (c = 0; c < 10; c++)
					{

						common[c] = A[c];
					}

				}
				else continue;
			}
			else
				continue;
		}
		if (y2 < y1)
			continue;
	}
	if (c == 0)
		return NULL;

	return common;
}