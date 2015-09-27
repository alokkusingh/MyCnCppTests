/*
 * IsPowerOfTwo.c
 *
 *  Created on: 28-Aug-2011
 *      Author: Alok
 */
#include <stdio.h>

#define MAX 100

int isPower_of_TWO(int a)
{
	return ((((a)&(-a))==a)?1:0);
}



int main()
{
	int a;
	const int b = 10;

	//b = 10;

	//scanf("%d", &a);

	//printf("%d\n", isPower_of_TWO(a));
	printf("%d",MAX);
	return 0;
}



