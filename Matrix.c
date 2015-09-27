/*
 * Matrix.c
 *
 *  Created on: 07-Sep-2011
 *      Author: Alok
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	//int mat[4][6]
	int **mat = (int **)malloc(sizeof(int*) * 4);
	int i, j;
	for (i = 0; i<4; i++)
		*(mat + i) = (int *)malloc(sizeof(int) * 6);

	for (i = 0; i<4; i++)
		for (j = 0; j<6; j++)
			*(*(mat + i) + j) = (i + 1) * (j + 1);


	for (i = 0; i<4; i++)
	{
			for (j = 0; j<6; j++)
				printf ("%2d ", *(*(mat + i) + j));
		printf ("\n");
	}

	for (i = 0; i<4; i++)
		free(*(mat + i));
	free(mat);

	return 0;
}
