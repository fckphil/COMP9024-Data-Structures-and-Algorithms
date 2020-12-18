// Starting code for Dijkstra's algorithm ... COMP9024 20T2

#include <stdio.h>
#include <stdbool.h>
#include "PQueue.h"

#define VERY_HIGH_VALUE 999999

void dijkstraSSSP(Graph g, Vertex source) {
    int dist[MAX_NODES];
    int pred[MAX_NODES];
    bool vSet[MAX_NODES];  // vSet[v] = true <=> v has not been processed
    int s;

    PQueueInit();
    int nV = numOfVertices(g);
    for (s = 0; s < nV; s++) {
        joinPQueue(s);
        dist[s] = VERY_HIGH_VALUE;
        pred[s] = -1;
        vSet[s] = true;
    }
    dist[source] = 0;

    /* NEEDS TO BE COMPLETED */
    int weight;
    int i = 0;
    while (!PQueueIsEmpty()) {
        int cur = leavePQueue((dist));
        vSet[cur] = false;
        for (i = 0; i < nV; i++) {
            weight = adjacent(g, cur, i);
            if (weight && dist[cur] + weight < dist[i] && vSet[i] == true) {
                dist[i] = dist[cur] + weight;
                pred[i] = cur;
            }
        }
    }

    for (i = 0; i < nV; i++) {
        printf("%d: ", i);
        if (dist[i] < VERY_HIGH_VALUE) {
            int array_path[nV];
            array_path[0] = i;
            int j = 1;
            int index = i;
            while (pred[index] != -1) {
                array_path[j++] = pred[index];
                index = pred[index];
            }

            printf("distance = %d, shortest path: ", dist[i]);
            int k;
            for (k = j - 1; k > 0; k--) {
                printf("%d-", array_path[k]);
            }
            printf("%d\n", array_path[0]);
        }
        else printf("no path\n");
    }
}

void reverseEdge(Edge *e) {
    Vertex temp = e->v;
    e->v = e->w;
    e->w = temp;
}

int main(void) {
    Edge e;
    int  n, source;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    Graph g = newGraph(n);

    printf("Enter the source node: ");
    scanf("%d", &source);
    printf("Enter an edge (from): ");
    while (scanf("%d", &e.v) == 1) {
        printf("Enter an edge (to): ");
        scanf("%d", &e.w);
        printf("Enter the weight: ");
        scanf("%d", &e.weight);
        insertEdge(g, e);
        reverseEdge(&e);               // ensure to add edge in both directions
        insertEdge(g, e);
        printf("Enter an edge (from): ");
    }
    printf("Done.\n");

    dijkstraSSSP(g, source);
    freeGraph(g);
    return 0;
}

