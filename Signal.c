#include <signal.h>
#include <stdio.h>
#include <stdlib.h>


void sigAbrt(int signal)
{
	printf("Process killed, do some useful thing: %d\n", signal);
	exit(0);

}

int main()
{
    if (signal(SIGINT, sigAbrt) == SIG_ERR)
    {
		printf ("Signal catch error");
		exit(1);
    }

    if (signal(SIGABRT, sigAbrt) == SIG_ERR)
    {
		printf ("Signal catch error");
		exit(1);
    }

	if (signal(SIGFPE, sigAbrt) == SIG_ERR)
    {
		printf ("Signal catch error");
		exit(1);
    }

    if (signal(SIGILL, sigAbrt) == SIG_ERR)
    {
		printf ("Signal catch error");
		exit(1);
    }

    if (signal(SIGSEGV, sigAbrt) == SIG_ERR)
    {
		printf ("Signal catch error");
		exit(1);
    }

    if (signal(SIGTERM, sigAbrt) == SIG_ERR)
    {
		printf ("Signal catch error");
		exit(1);
    }

 
	while (1)
	{

	}
	return 0;
}
