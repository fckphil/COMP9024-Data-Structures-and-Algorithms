//
// Created by izual on 2020/7/6.
//

#ifndef INC_9024ASS5_PQUEUE_H
#define INC_9024ASS5_PQUEUE_H
#include "WGraph.h"
#include <stdbool.h>

#define MAX_NODES 1000

void   PQueueInit();
void   joinPQueue(Vertex);
Vertex leavePQueue(int[]);
bool   PQueueIsEmpty();
#endif //INC_9024ASS5_PQUEUE_H
