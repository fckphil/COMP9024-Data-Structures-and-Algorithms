#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<assert.h>
typedef struct node {
    int value;
    struct node *next;
}   NodeT;

NodeT* ListInitialize(){
    NodeT *L=malloc(sizeof(struct node));
    assert(L!=NULL);
    L->value=-1;
    L->next=NULL;
    return L;
}

void freeLL(NodeT *list){
    NodeT *p, *temp;

    p=list;
    while(p!=NULL){
        temp=p->next;
        free(p);
        p=temp;
    }
}

void showLL(NodeT *list){
    NodeT *p;
    for(p=list;p!=NULL;p=p->next){
        if(p->next!=NULL) printf("%d-->",p->value);
        else printf("%d",p->value);
    }
}

NodeT *joinLL(NodeT *list, int v){
    NodeT *new=malloc(sizeof(NodeT));
    new->value=v;
    new->next=NULL;
    NodeT *p=list;
    while(p->next!=NULL) p=p->next;
    p->next=new;
    return list;
}

int main( )
{
    int integer;
    double num=0;
    int i=0;
    NodeT *all = ListInitialize();
    printf("Enter an integer:");
    while(scanf("%d",&integer)==1){
        num+=1;
        all=joinLL(all,integer);
        printf("Enter an integer:");

    }
    printf("Done. ");
    if(all->next!=NULL){
        printf("List is ");
        all=all->next;
        showLL(all);

        NodeT *temp = all;
        printf("\nFirst part is ");
        for (i = 0; i < ceil(num / 2) - 1; i++) {
            printf("%d-->", temp->value);
            temp = temp->next;
        }
        printf("%d", temp->value);
        if(num>1) {
            printf("\nSecond part is ");
            if (temp->next != NULL) {
                for (i = ceil(num / 2); i < num - 1; i++) {
                    temp = temp->next;
                    printf("%d-->", temp->value);
                }
                printf("%d", temp->next->value);
            }
        }

    }

}


