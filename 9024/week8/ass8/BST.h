//
// Created by izual on 2020/7/27.
//

#ifndef ASS8_BST_H
#define ASS8_BST_H
// Binary Search Tree ADT interface ... COMP9024 20T2

#include <stdbool.h>

typedef int Item;      // item is just a key

typedef struct Node *Tree;

Tree newTree();        // create an empty Tree
void freeTree(Tree);   // free memory associated with Tree
void showTree(Tree);   // display a Tree (sideways)

bool TreeSearch(Tree, Item);   // check whether an item is in a Tree
int  TreeHeight(Tree);         // compute height of Tree
int  TreeNumNodes(Tree);       // count #nodes in Tree
Tree TreeInsert(Tree, Item);   // insert a new item into a Tree
Tree TreeDelete(Tree, Item);   // delete an item from a Tree

// internal functions made visible for testing
Tree rotateRight(Tree);
Tree rotateLeft(Tree);
Tree insertAtRoot(Tree, Item);
Tree insertRandom(Tree, Item);
Tree insertAVL(Tree, Item);
Tree insertSplay(Tree, Item);
Tree rebalance(Tree);
#endif //ASS8_BST_H
