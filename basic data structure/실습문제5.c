#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int N, M;
    int arr[100][100];
    scanf("%d %d", &N, &M);

    int row = N, col = M;
    int i = 0, j = 0;
    int a = 1;

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            arr[i][j] = 0;
        }
    }

    int point_i = 0;
    int point_j = 0;
    arr[point_i][point_j] = 1;
    a = 1;

    while (point_j + 1 < M && arr[point_i][point_j + 1] == 0) {
        point_j++;
        a++;
        i = point_i;
        j = point_j;
        arr[i][j] = a;
        while (i + 1 < N && j - 1 >= 0 && arr[i + 1][j - 1] == 0) {
            a++;
            arr[i + 1][j - 1] = a;
            i++;
            j--;
        }
    }

    while (point_i + 1 < N && arr[point_i + 1][point_j] == 0) {
        point_i++;
        a++;
        i = point_i;
        j = point_j;
        arr[i][j] = a;

        while (i + 1 < N && j - 1 >= 0 && arr[i + 1][j - 1] == 0) {
            a++;
            arr[i + 1][j - 1] = a;
            i++;
            j--;
        }
    }

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf(" %d", arr[i][j]);

        }
        printf("\n");
    }

    return 0;
}
