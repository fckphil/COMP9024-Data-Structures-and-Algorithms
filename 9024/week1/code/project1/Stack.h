//
// Created by izual on 2020/6/9.
//

#ifndef PROJECT1_STACK_H
#define PROJECT1_STACK_H
// Stack ADO header file ... COMP9024 20T2

#define MAXITEMS 10

void StackInit();      // set up empty stack
int  StackIsEmpty();   // check whether stack is empty
void StackPush(char);  // insert char on top of stack
char StackPop();       // remove char from top of stack
#endif //PROJECT1_STACK_H
