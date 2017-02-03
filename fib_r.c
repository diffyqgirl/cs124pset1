#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MOD 65536 //2^16
//defines the 0th fibonacci number as 0 and the 1st fibonacci number as 1
int fib_r(int n);
int main(int argc, char** argv)
{
	printf ("%i", fib_r(atoi(argv[1])));
	printf("\n");
}

int fib_r(int n)
{
	if (n == 0 || n == 1)
		return n;
	return (fib_r(n-1) + fib_r(n-2)) % MOD;
}