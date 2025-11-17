#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX 30  // limit because exponential growth!

int graph[MAX][MAX];

// Check if the given vertices form a clique
int isClique(int vertices[], int m) {
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            if (!graph[vertices[i]][vertices[j]]) {
                return 0;
            }
        }
    }
    return 1;
}

// Recursive function to generate all combinations of size m
int findCliqueUtil(int n, int m, int start, int depth, int vertices[], int *found) {
    if (*found) return 1;

    if (depth == m) {
        if (isClique(vertices, m)) {
            *found = 1;
            printf("Clique found: { ");
            for (int i = 0; i < m; i++)
                printf("%d ", vertices[i]);
            printf("}\n");
            return 1;
        }
        return 0;
    }

    for (int i = start; i < n; i++) {
        vertices[depth] = i;
        findCliqueUtil(n, m, i + 1, depth + 1, vertices, found);
        if (*found) return 1;
    }
    return 0;
}

// Main function
int containsClique(int n, int m) {
    int vertices[MAX];
    int found = 0;
    findCliqueUtil(n, m, 0, 0, vertices, &found);
    return found;
}

int main() {
    int n, e, u, v, m;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    // Initialize graph
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }

    printf("Enter clique size (m): ");
    scanf("%d", &m);

    clock_t start = clock();
    int result = containsClique(n, m);
    clock_t end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    if (result)
        printf("\nGraph contains a clique of size %d.\n", m);
    else
        printf("\nGraph does NOT contain a clique of size %d.\n", m);

    printf("Execution time: %.6f seconds\n", time_taken);

    return 0;
}
