// Queue ADT implementation ... COMP9024 20T2
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"
#include <string.h>



// set up empty queue
queue newQueue() {
    queue Q = malloc(sizeof(QueueRep));
    Q->length = 0;
    Q->head = NULL;
    Q->tail = NULL;
    return Q;
}

// remove unwanted queue
void dropQueue(queue Q) {
    NodeT *curr = Q->head;
    while (curr != NULL) {
        NodeT *temp = curr->next;
        free(curr);
        curr = temp;
    }
    free(Q);
}

// check whether queue is empty
int QueueIsEmpty(queue Q) {
    return (Q->length == 0);
}

// insert an int at end of queue
void QueueEnqueue(queue Q, int v, char *place) {
    NodeT *new = malloc(sizeof(NodeT));
    assert(new != NULL);
    new->time = v;
    strcpy(new->stop,place);
    new->next = NULL;
    if (Q->tail != NULL) {
        Q->tail->next = new;
        Q->tail = new;
    } else {
        Q->head = new;
        Q->tail = new;
    }
    Q->length++;
}

// remove int from front of queue
NodeT* QueueDequeue(queue Q) {
    assert(Q->length > 0);
    NodeT *p = Q->head;
    Q->head = Q->head->next;
    if (Q->head == NULL) {
        Q->tail = NULL;
    }
    Q->length--;
    NodeT* item = p;
    free(p);
    return item;
}