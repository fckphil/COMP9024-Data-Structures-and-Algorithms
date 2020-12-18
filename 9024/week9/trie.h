// Trie ADT interface ... COMP9024 20T2

typedef int  Item;
typedef char *Key;

typedef struct Node *Trie;

Trie newTrie();        // create an empty Trie
void freeTrie(Trie);   // free memory associated with Trie
void showTrie(Trie);   // display a Trie (branch-by-branch)

Trie TrieInsert(Trie, Key, Item);  // insert a new item into a Trie