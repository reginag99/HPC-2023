#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc,char *argv[])

{
//char * argChar = NULL;

int numberThreads;

if (argv[1][0] != '-' && argv[1][1] != 't' )
	{
	perror("Wrong input begin with -t");
	exit(EXIT_FAILURE);
	}


for (size_t xj = 2; xj < strlen(argv[1]); xj++)
	{
	if (isdigit(argv[1][xj]))
		numberThreads = atoi(&argv[1][xj]);
		break;

	}

if (numberThreads == 0)
	{
	perror("Interger value must be larger than zero");
	exit(EXIT_FAILURE);
	}


printf("Number of threads: %d", numberThreads);
	

}
