#include <stdio.h>

void findFirstRepeatedChar (const char *str)
{

    unsigned int i, j ;

    for (i = 0; *(str + i); i++)
    	for (j = i + 1; *(str + j); j++)
    	{
    		if (*(str + i) == *(str + j))
    		{
    			printf("\"%c\"", *(str + i));
    			return;
    		}
    	}

    printf("No duplicate found!!!");

}

int main()
{

    char str[] = "Hello world";

    findFirstRepeatedChar(str);

	return 0;
}
