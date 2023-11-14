/*
Implement a program that

    accepts two arguments -aA and -bB for integers A and B in arbitrary 
    order, i.e. -aA -bB and -bB -aA are both legitimate arguments when 
    calling your program,
    converts A and B to integers, and
    writes to stdout the line "A is (INSERT A) and B is (INSERT B)".

For example calling

printargs -a2 -b4

or

printargs -b4 -a2

should output

A is 2 and B is 4

As a final remark observe that standard programs would equally accept
 "-a2" and "-a 2". When using standard solutions like POSIX getopt, 
 this is automatically taken care of.

 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(
	int argc,
	char *argv[]
	)

{
int A;
int B;


for (int i = 1; i<argc;i++)
	{

	if (strlen(argv[i]) != 3)
		{
		printf("Error, wrong size of input element");
		exit(0);
		return -1;
		}
	else if (argc != 3)
		{
		printf("Error, wrong amount of input element");
		exit(0);
		return -1;
		}
	else
		{
		if  (argv[i][1] == 'a')

			{
			A = argv[i][2] -'0';
			}
		else if (argv[i][1] == 'b')
			{
			B = argv[i][2] - '0';
			}

		printf("A is %d and B is %d\n", A, B);

		}
	}

}
