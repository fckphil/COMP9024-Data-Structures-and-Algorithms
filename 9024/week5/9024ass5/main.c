#include <stdio.h>
#include<stdlib.h>
#include "WGraph.h"

void insertionSort(float p[], int v[], int n);
int main() {
    int num_v;
    int i = 0, j = 0;
    int v, w;
    Graph g;
    Edge e;
    printf("Enter the number of vertices: ");
    scanf("%d", &num_v);
    int index_v[num_v];
    for (i = 0; i < num_v; i++) index_v[i] = i;
    g = newGraph(num_v);
    printf("Enter an edge (from): ");
    while (scanf("%d", &v)) {
        printf("Enter an edge (to): ");
        scanf("%d", &w);
        e.v = v;
        e.w = w;
        e.weight = 1;
        insertEdge(g, e);
        printf("Enter an edge (from): ");
    }
    printf("Done.\n");
    float pR[num_v]; //popularityRank(v) = inDegree(v) / outDegree(v)
    float in = 0, out = 0;
    for (i = 0; i < num_v; i++) {
        in = 0;
        out = 0;
        for (j = 0; j < num_v; j++) {
            if (adjacent(g, i, j)) out++;
            if (adjacent(g, j, i)) in++;
        }
        if (out == 0) out = 0.5;
        pR[i] = in / out;
    }
    insertionSort(pR, index_v, num_v);
    printf("\nPopularity ranking:\n");
    for (i = 0; i < num_v; i++) {
        printf("%d %.1f\n", index_v[i], pR[i]);
    }
    freeGraph(g);
    return 0;
}

void insertionSort(float p[], int v[],int n) {
    int i;
    for (i = 1; i < n; i++) {
        float popularity = p[i];
        int index = v[i];
        int j = i-1;
        while (j >= 0 && p[j] < popularity) {
            p[j+1] = p[j];
            v[j+1] = v[j];
            j--;
        }
        p[j+1] = popularity;
        v[j+1] = index;
    }
}


