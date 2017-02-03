#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//defines the 0th fibonacci number as 0 and the 1st fibonacci number as 1
int fib_m(int n);
void mult_2x2 (int* a, int* b, int* result);
void square_2x2(int* a, int* result);
void sqpows_2x2(int* a, int k, int* result);
void print_2x2(int* a);
int main(int argc, char** argv)
{
	printf ("answer is %i", fib_m(atoi(argv[1])));
	printf("\n");
}

int fib_m(int n)
{
	int f[2][2]= {{0, 1}, {1, 1}};
	int k = 1;
	int count = 1;
	while(k*2 <= n)
	{
		k = k*2;
		count++;
	};
	printf("count is %i\n", count);
	int sqpows[count][2][2];
	sqpows_2x2((int*) &f, count, (int*) &sqpows);
	printf("\ncounts in fib_m\n");
	for (int i = 0; i < count; i++)
	{
		print_2x2((int*)sqpows[i]);
	}

	int answer[2][2] = {{1, 0}, {0, 1}};
	while(n>0)
	{
		//k = 2^count
		
		if (n-k>=0)
		{
			mult_2x2((int*) &(sqpows[count-1]), (int*) (&answer), (int*) (&answer));
			n -= k;
		}
		k = k/2;
		count--;
	}

	return answer[0][1];//should work if n is a power of 2
}

//k is the number of digits in the binary representation of n
void sqpows_2x2 (int* a, int count, int* result)
{
	int sqpows[count][2][2]; //sqpows[k] is the matrix a^(2^k)
	memcpy(&(sqpows[0]), a, sizeof(int[2][2]));
	square_2x2(a, result);
	for (int i = 0; i < count-1; i++)
	{
		square_2x2((int*) &(sqpows[i]), (int*)&(sqpows[i+1]));
	}
	printf("\ncounts\n");
	for (int i = 0; i < count; i++)
	{
		print_2x2((int*)sqpows[i]);
	}
	memcpy(result, &sqpows, sizeof(sqpows));
}
void square_2x2(int* a, int* result)
{
	mult_2x2(a, a, result);
}
void mult_2x2 (int* a, int* b, int* result)
{
	printf("a");
	print_2x2(a);
	printf("b");
	print_2x2(b);
	int ans[2][2];
	ans[0][0] = (*a) * (*b) + *(a+1) * *(b+2);
	ans[0][1] = (*a) * *(b+1) + *(a+1) * *(b+3);
	ans[1][0] = *(a+2) * (*b) + *(a+3) * *(b+2);
	ans[1][1] = *(a+2) * *(b+1) + *(a+3) * *(b+3);
	print_2x2((int*) &ans);
	memcpy(result, &ans, sizeof(ans));
}

void print_2x2 (int* a)
{
	printf ("[[%i, %i], [%i, %i]]\n", *a, *(a+1), *(a+2), *(a+3));
}
/*
void sqpow_2x2 (int a[][2], int k, void* result)
{
	memcpy(result, &a, sizeof(a));
	for (int i = 2; i <= k, i++)
	{
		square_2x2()
	}
}

void square_2x2 (int a[][2], void* result)
{
	mult_2x2(a, result);
}
void mult_2x2 (int a[][2], int b[][2], void* result)
{
	int ans[2][2] = {{a[0][0]*b[0][0]+a[0][1]*b[1][0], a[0][0]*b[0][1]+a[0][1]*b[1][1]},
{a[1][0]*b[0][0]+a[1][1]*b[1][0], a[1][0]*b[0][1]+a[1][1]*b[1][1]}};
	memcpy(result, &ans, sizeof(int[2][2]));
}
*/

