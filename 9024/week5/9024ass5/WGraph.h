//
// Created by izual on 2020/7/6.
//

#ifndef INC_9024ASS5_WGRAPH_H
#define INC_9024ASS5_WGRAPH_H

// edges are pairs of vertices (end-points) plus positive weight
typedef struct Edge {
    Vertex v;
    Vertex w;
    int    weight;
} Edge;

// returns weight, or 0 if vertices not adjacent
int adjacent(Graph, Vertex, Vertex);
#endif //INC_9024ASS5_WGRAPH_H
