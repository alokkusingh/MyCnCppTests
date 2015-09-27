/*
 * BitCount.c
 *
 *  Created on: 28-Aug-2011
 *      Author: Alok
 */
#include <stdio.h>

int main()
{
	int x, count = 0;

	scanf("%d", &x);

	for (; ((unsigned)x) >= 1; x = ((unsigned)x)/ 2 )
	{
		count = count + ((unsigned)x)%2;
	}

	printf("num of set bit: %d\n", count);

	return 0;
}
