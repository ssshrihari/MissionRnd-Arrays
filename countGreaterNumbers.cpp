/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include<stdio.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int d1 = 0, d2 = 0, count = 0, m1 = 0, m2 = 0, y1 = 0, y2 = 0;
	int i, x, j = 1;

	for (i = 0; i <= 9; i++)
	{
		if (i == 2 || i == 5)
		{
			//j = 1;
			continue;
		}
		if (i <= 1)
		{
			x = date[i] - 48;
			d1 = (d1 * 10) + x;

		}
		if (i <= 4 && i >= 3)
		{

			x = date[i] - 48;
			m1 = (m1 * 10) + x;
		}

		if (i <= 9 && i >= 6)
		{

			x = date[i] - 48;
			y1 = (y1 * 10) + x;

		}
	}
	//	int d1 = 0, d2 = 0, m1 = 0, m2 = 0, y1 = 0, y2 = 0;
	//	int i, x, j = 1;
	for (j = len - 1; j >= 0; j--)
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
				x = Arr[j].date[i] - 48;
				d2 = (d2 * 10) + x;

			}
			if (i <= 4 && i >= 3)
			{

				x = Arr[j].date[i] - 48;
				m2 = (m2 * 10) + x;
			}

			if (i <= 9 && i >= 6)
			{

				x = Arr[j].date[i] - 48;
				y2 = (y2 * 10) + x;

			}
		}
		printf("\n %d\t%d\n", y2, y1);
		if (y1 < y2)
		{
			count++;
			printf("\n %d", count);
		}
		if (y1 == y2)
		{
			if (m1 < m2)
				count++;
			else if (m1 == m2)
			{
				if (d1 < d2)
					count++;
				else if (d1 == d2)
				{
					break;
				}
				else break;
			}
			else
				break;
		}
		if (y2 < y1)
			break;
	}




	return count;
}