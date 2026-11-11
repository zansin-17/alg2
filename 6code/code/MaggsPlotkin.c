/*

author : Ryoya Torkai
id     : s1300080

*/

#include <stdio.h>
#include <stdlib.h>
#define INFTY 99999

int Maggs_Plotkin(int, int, int);
void MST_view(int **D0, int **, int);

int main() {
    int i, j, k;
    int **Data, **copy,n;

    /* input data (size) */
    printf("Input the number of data: ");
    scanf("%d", &n);
    /* Generate arrays (memory allocation)*/
    Data = (int **)malloc(n * sizeof(int *));
    copy = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        Data[i] = (int *)malloc(n * sizeof(int));
        copy[i] = (int *)malloc(n * sizeof(int));
    }

    /* input data (matrix)*/
    printf("Input the Adjacency or Distance matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &Data[i][j]);
            copy[i][j] = Data[i][j];
        }
    }

    /* Main routines */
    /* [ Complete Here!! ( 3-level nested loop) ] */

    /* Call main routines */
    for(k = 0;k < n ; k++){
        for(i = 0 ; i < n ;i++){
            for(j = 0 ; j < n ; j++){
                Data[i][j] = Maggs_Plotkin(Data[i][j], Data[i][k], Data[k][j]);
    
            }
        }
    }
    // end 3-level nested loop

    // you can use MST_view function to obtain MST and its cost.
    MST_view(copy, Data, n);

    /* free allocated memory*/
    for (i = 0; i < n; i++) {
        free(Data[i]);
    }
    free(Data);

    return 0;
}

int Maggs_Plotkin(int D_ij, int D_ik, int D_kj) {
    int Dk_ij;
    int max;

    if(D_ik > D_kj) max = D_ik;
    else max = D_kj;

    if(D_ij < max) Dk_ij = D_ij;
    else Dk_ij = max;

    return Dk_ij;
}

// D0[][] -> 元の2次元配列。つまり隣接行列A
// Dn[][] -> アルゴリズムで処理された2次元配列。つまりA^k
// n -> グラフの頂点数|V|
void MST_view(int **D0, int **Dn, int n) {
    int i, j;
    int cost = 0;

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {  // A上で辺があったところが、A^kの全域木に採用されているなら重みを加える
            if (/* Complete Here!! */D0[i][j] == D0[i][j]&&D0[i][j] != INFTY) {
                cost += Dn[i][j];
                printf("%d\n", Dn[i][j]);
            }
        }
    }

    printf("MST cost:%d\n", cost);
}
/*
    詳しくはMaggsとPlotkinの論文を参考
    Maggs, Bruce M., and Serge A. Plotkin. ``Minimum-cost spanning tree as a path-finding problem.''
    Information Processing Letters 26.6 (1988): 291-293.
*/
