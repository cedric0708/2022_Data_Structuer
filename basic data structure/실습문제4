### My Answer

#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int N, M;
    int arr[100][100];
    scanf("%d %d", &N, &M);
    int i = 0, j = 0, a = 1;
   
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            arr[i][j] = 0;
        }
    }
   
    i = 0;
    j = 0;
    arr[i][j] = 1;
    a = 2;


    while (a <= N * M) {

        while (j + 1 < M && arr[i][j + 1] == 0) {
            j++;
            arr[i][j] = a;
            a++;
        }

        while (i + 1 < N && arr[i + 1][j] == 0) {
            i++;
            arr[i][j] = a;
            a++;
        }

        while (j - 1 >= 0 && arr[i][j - 1] == 0) {
            j--;
            arr[i][j] = a;
            a++;
        }
        while (i - 1 >= 0 && arr[i - 1][j] == 0) {
            i--;
            arr[i][j] = a;
            a++;
        }

    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            printf(" %d", arr[i][j]);

        }
        printf("\n");
    }
    return 0;
}

### 교수님 해설

void screw(int X[][100], int N, M)
{
    int left = 0, right = M - 1;
    int top = 0, bottom = N - 1;
    int value = 1;

    while (left <= right && top <= bottom)
    {
        for (int j = left; j <= right; j++)
            X[top][j] = value++;
        top++;

        if (top <= bottom)
        {
            for (int i = top; i <= bottom; i++)
                X[i][right] = value++;
            right--;

            if (left <= right)
            {
                for (int j = left; j <= right; j++)
                    X[bottom][right - j + left] = value++;
                bottom--;

                if (top <= bottom)
                {

                }
            }
        }
    }
}
