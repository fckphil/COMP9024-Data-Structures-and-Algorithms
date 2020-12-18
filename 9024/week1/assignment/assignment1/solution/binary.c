//
// Created by izual on 2020/6/7.
//

#include <stdio.h>
#include "IntStack.h"
int main(){
    int n;
    StackInit();
    printf("Enter a number: ");
    scanf("%d",&n);
    int result=0;
    while(n>0){
        StackPush(n%2);
        n=n/2;}
    while(!StackIsEmpty()){
        result=10*result+StackPop();}
    printf("%d",result);
}