#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void hanoi(int n, char a, char b, char c) {

	if (n == 1)
		printf("%c %c\n", a, c);
	else {
		hanoi(n - 1, a, c, b);
		printf("%c %c\n", a, c);
		hanoi(n - 1, b, a, c);
	}
}

int main()
{
	int n;
	char from, aux, to;
	
	from = 'A', aux = 'B', to = 'C';

	scanf("%d", &n);

	hanoi(n, from, aux, to);

	return 0;
}
