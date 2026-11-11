/*

    author : your name
    id     : your id

*/

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAIL 0
#define FREE 1
#define NOT_FREE 0
#define N 8  // クイーンの数

int try(int);

int row[N], col[N], pos[2 * N - 1], neg[2 * N - 1];
int count = 0;
int hole_row = 8;
int hole_col = 0;

int main() {
    int i, j;

    for (i = 0; i < N; i++) {
        row[i] = -1;
        col[i] = FREE;
    }
    for (i = 0; i < 2 * N - 1; i++) {
        pos[i] = FREE;
        neg[i] = FREE;
    }

    if (try(0) == SUCCESS) {
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                if (row[i] == j) {
                    printf("Q ");
                } else {
                    printf(". ");
                }
            }
            printf("\n");
        }
    } else {
        printf("No solution is found.\n");
    }
    return 0;
}

int try(int i) {
    int j;

    for (j = 0; j < N; j++) {
        if(i == hole_row && j == hole_col) continue;
        if (col[j] == FREE && pos[i + j] == FREE && neg[i - j + N - 1] == FREE) {
            row[i] = j;
            col[j] = NOT_FREE;
            pos[i + j] = NOT_FREE;
            neg[i - j + N - 1] = NOT_FREE;

            if (i >= N - 1) {
                return SUCCESS;
            } else {
                if (try(i + 1) == SUCCESS) {
                    return SUCCESS;
                } else {
                    row[i] = -1;
                    col[j] = FREE;
                    pos[i + j] = FREE;
                    neg[i - j + N - 1] = FREE;
                }
            }
        }
    }
    return FAIL;
}
