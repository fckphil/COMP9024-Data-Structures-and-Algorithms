// Queue ADT header file ... COMP9024 20T2

typedef struct QueueRep *queue;
typedef struct node {
    int time;
    char stop[32];
    struct node *next;
} NodeT;
typedef struct QueueRep {
    int   length;
    NodeT *head;
    NodeT *tail;
} QueueRep;

queue newQueue();               // set up empty queue
void  dropQueue(queue);         // remove unwanted queue
int   QueueIsEmpty(queue);      // check whether queue is empty
void  QueueEnqueue(queue, int, char *); // insert an int at end of queue
NodeT*   QueueDequeue(queue);      // remove int from front of queue