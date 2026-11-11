/*
author : your name
id     : your id
*/

#include <stdio.h>
#include <stdlib.h>

void DFS(int);
void DFS1(int);
void DFS2(int);
void kosaraju();

int n;
int label = 0;
int *visited;
int **A, **revA;
int *stack, top = -1;

int main() {
    int start, i, j, mode;

    printf("Select mode: 1=DFS Tree, 2=Kosaraju SCC\n");
    scanf("%d", &mode);

    printf("Input the number of data: ");
    scanf("%d", &n);

    visited = (int *)malloc(sizeof(int) * n);
    stack = (int *)malloc(sizeof(int) * n);
    A = (int **)malloc(sizeof(int *) * n);
    revA = (int **)malloc(sizeof(int *) * n);
    for (i = 0; i < n; i++) {
        A[i] = (int *)malloc(sizeof(int) * n);
        revA[i] = (int *)malloc(sizeof(int) * n);
        visited[i] = 0;
    }

    printf("Input the Adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    if (mode == 1) {
        printf("Input the initial node: 1 to %d\n", n);
        scanf("%d", &start);

        printf("The edges in the DFS tree with root %d are:\n", start);
        DFS(start - 1);
    } else if (mode == 2) {
        kosaraju();
    } else {
        printf("Invalid mode.\n");
    }

    for (i = 0; i < n; i++) {
        free(A[i]);
        free(revA[i]);
    }
    free(A);
    free(revA);
    free(visited);
    free(stack);

    return 0;
}

void DFS(int node) {
    int t;

    visited[node] = ++label;
    for (t = 0; t < n; t++) {
        if (A[node][t] == 1 && visited[t] == 0) {
            printf("(%d,%d)\n", node + 1, t + 1);
            DFS(t);
        }
    }
}

// ============ Kosaraju Support Functions ============

void DFS1(int v) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (A[v][i] && !visited[i])
            DFS1(i);
    }
    stack[++top] = v;
}

void DFS2(int v) {
    visited[v] = 1;
    printf("Vertex. %d\n", v + 1);
    for (int i = 0; i < n; i++) {
        if (revA[v][i] && !visited[i])
            DFS2(i);
    }
}

void reverseGraph() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            revA[j][i] = A[i][j];
}

void kosaraju() {
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    for (int i = 0; i < n; i++)
        if (!visited[i])
            DFS1(i);

    reverseGraph();

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int group = 1;
    while (top >= 0) {
        int v = stack[top--];
        if (!visited[v]) {
            printf("Strongly Connected Decomposition (Group %d):\n", group++);
            DFS2(v);
            printf("\n");
        }
    }
}
