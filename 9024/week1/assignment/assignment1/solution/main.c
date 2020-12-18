
#include<stdio.h>
#include"IntQueue.h"
int main()
{
    QueueInit();
    printf("%d\n",QueueIsEmpty());
    for(int i=0;i<10;i++)
        QueueEnqueue(i);
    printf("%d\n",QueueDequeue());
    printf("%d\n",QueueDequeue());
    printf("%d\n",QueueDequeue());
}


