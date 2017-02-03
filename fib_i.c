#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//defines the 0th fibonacci number as 0 and the 1st fibonacci number as 1
int fib_i(int n);
int main(int argc, char** argv)
{
	printf ("%i", fib_i(atoi(argv[1])));
	printf("\n");
}

int fib_i(int n)
{
	if (n == 0|| n == 1)
		return n;
	int f0 = 0;
	int f1 = 1;
	int temp = -1;
	for (int i = 1; i < n; i ++)
	{
		temp = f0 + f1;
		f0 = f1;
		f1 = temp;
	}
	return temp;

}

