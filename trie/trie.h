#ifndef TRIE_H
#define TRIE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26
#define SMALL_CHAR_TO_INDEX(c) ((int)c - (int)'a')
#define CAP_CHAR_TO_INDEX(c) ((int)c - (int)'A')

typedef struct trie_node trie_node_t;
struct trie_node
{
    long int* loc;
    int word_count;
    trie_node_t *children[ALPHABET_SIZE];
};

typedef struct trie trie_t;
struct trie
{
	trie_node_t *root;
};

trie_node_t *get_node(void);
void initialize(trie_t *ptrie);
void insert (trie_t *ptrie, char key[], long int location);
long int* search (trie_t *ptrie, char key[]);


#endif	