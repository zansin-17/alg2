/*

author : Ryoya Torikai
id     : s1300080

*/

#include <stdio.h>
#include <stdlib.h>

#define INFTY 99999

int Warshall(int, int, int);

int main() {
    int i, j, k;

    int **Data, n;

    /* input data (size) */
    printf("Input the number of data: ");
    scanf("%d", &n);

    /* Generate arrays (memory allocation)*/
    Data = (int **)malloc(n * sizeof(int *));

    for (i = 0; i < n; i++) {
        Data[i] = (int *)malloc(n * sizeof(int));
    }


    /* input data (matrix)*/
    printf("Input the Adjacency or Distance matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &Data[i][j]);
        }
    }

    /* Main routines */

    /* [ Complete Here!! ( 3-level nested loop) ] */
    /* Call main routines */
    // Warshall's Algorithm

    for(k = 0;k < n ; k++){
        for(i = 0 ; i < n ;i++){
            for(j = 0 ; j < n ; j++){
                Data[i][j] = Warshall(Data[i][j], Data[i][k], Data[k][j]);
        
            }
        }
    }
    // end 3-level nested loop
    printf("Transitive Closure:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", Data[i][j]);
        }
        printf("\n");
    }
    /* free allocated memory*/
    for (i = 0; i < n; i++) {
        free(Data[i]);
    }
    free(Data);

    return 0;
}

int Warshall(int A_ij, int A_ik, int A_kj) {
    /* Arguments A_ij, A_ik, A_kj means A^{k-1}[i][j],
     * A^{k-1}[i][k],A^{k-1}[k][j] at the pseudo code. */
    int Ak_ij; /* A^k[i][j] */
    if (A_ij == 1) {
        Ak_ij = 1;
    } else if(A_ik == 1 && A_kj == 1) {
        Ak_ij = 1;  // 新たに i→k→j で到達可能になった
    } else {
        Ak_ij = 0;  // 到達できない
    }

    return Ak_ij;
}
