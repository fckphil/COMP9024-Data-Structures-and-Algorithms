//
// Created by izual on 2020/6/7.
//
#include "IntQueue.h"
#include<stdlib.h>
static int *q;
static int size;
static int front;
static int rear;
void QueueInit(){
    q = malloc(MAXITEMS*sizeof(int));
    size=0;
    front=0;
    rear=1;
}

int QueueIsEmpty(){
    return size==0;
}

void QueueEnqueue(int a){
    q[size] = a;
    size++;
    rear++;
}

int QueueDequeue(){
    size--;
    return q[front++];

}

