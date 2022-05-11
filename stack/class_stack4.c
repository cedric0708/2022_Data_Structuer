#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define size 6

void spans(int X[], int S[]) {
	int s;
	for (int i = 0; i < size; i++) {
		s = 1;
		while ((s <= i) && (X[i - s] <= X[i]))
			s++;
		S[i] = s;
	}
}

int main()
{
	int X[size] = { 6,3,4,2,5,3 };
	int S[size] = { 0 };

	spans(X, S);


	for (int i = 0; i < size; i++)
		printf("[%d] ", S[i]);
	printf("\n");

	return 0;
}
