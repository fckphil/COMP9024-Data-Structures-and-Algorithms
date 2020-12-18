// Weighted Directed Graph ADT
// Adjacency Matrix Representation ... COMP9024 20T2
#include "WGraph.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct GraphRep {
    Edge **edges;  // adjacency matrix storing positive weights
    // 0 if nodes not adjacent
    int nV;       // #vertices
    int nE;       // #edges
} GraphRep;

Graph newGraph(int V) {
    assert(V >= 0);
    int i;
    Edge e;
    e.inthis = 0;
    Graph g = malloc(sizeof(GraphRep));
    assert(g != NULL);
    g->nV = V;
    g->nE = 0;

    // allocate memory for each row
    g->edges = malloc(V * sizeof(Edge *));
    assert(g->edges != NULL);
    // allocate memory for each column and initialise with 0
    for (i = 0; i < V; i++) {
        g->edges[i] = calloc(V, sizeof(Edge));
        assert(g->edges[i] != NULL);
        for(int j=0; j<V; j++){
            g->edges[i][j] = e;
        }
    }

    return g;
}

int numOfVertices(Graph g) {
    return g->nV;
}

// check if vertex is valid in a graph
int validV(Graph g, Vertex v) {
    return (g != NULL && v >= 0 && v < g->nV);
}

void insertEdge(Graph g, Edge e) {
    assert(g != NULL && validV(g,e.v) && validV(g,e.w));

    if (g->edges[e.v][e.w].inthis == 0) {   // edge e not in graph
        g->edges[e.v][e.w] = e;
        g->nE++;
    }
}

void removeEdge(Graph g, Edge e) {
    assert(g != NULL && validV(g,e.v) && validV(g,e.w));

    if (g->edges[e.v][e.w].inthis != 0) {   // edge e in graph
        g->edges[e.v][e.w].inthis = 0;
        g->nE--;
    }
}

int adjacent(Graph g, Vertex v, Vertex w) {
    assert(g != NULL && validV(g,v) && validV(g,w));

    return g->edges[v][w].weight;
}

void showGraph(Graph g) {
    assert(g != NULL);
    int i, j;

    printf("Number of vertices: %d\n", g->nV);
    printf("Number of edges: %d\n", g->nE);
    for (i = 0; i < g->nV; i++)
        for (j = 0; j < g->nV; j++)
            if (g->edges[i][j].inthis != 0)
                printf("Edge %d - %d: %d\n", i, j, g->edges[i][j].weight);
}


void freeGraph(Graph g) {
    assert(g != NULL);

    int i;
    for (i = 0; i < g->nV; i++)
        free(g->edges[i]);
    free(g->edges);
    free(g);
}
Edge **matrix(Graph g){
    return g->edges;
}
Edge findEdge(Edge **edges, Vertex v, Vertex w){
    return edges[v][w];
}