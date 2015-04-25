#include "trie.h"


trie_node_t *get_node(void)
{
	trie_node_t *newnode = NULL;
	newnode = (trie_node_t *)malloc(sizeof(trie_node_t));

	if (newnode)
	{
		int i;
		newnode->word_count = 0;
		newnode->loc = (long int *)malloc(sizeof(long int));
		newnode->loc[0] = 0;
		for (i = 0; i<ALPHABET_SIZE; i++)
		{
			newnode->children[i] = NULL;
		}
	}

	return newnode;
}

void initialize(trie_t *ptrie)
{
	ptrie->root = get_node();
}

void insert (trie_t *ptrie, char key[], long int location)
{
	int level;
	int length = strlen(key);
	int index;

	trie_node_t *ptrav;
	ptrav = ptrie->root;

	for (level =  0; level < length; level++)
	{
		if (key[level]>='A' && key[level] <= 'Z')
		{
			index = CAP_CHAR_TO_INDEX(key[level]);	
		}		

		else if (key[level]>='a' && key[level] <= 'z')
		{
			index = SMALL_CHAR_TO_INDEX(key[level]);	
		}
		else 
		{
			return;
		}
		if (index >= ALPHABET_SIZE || index <0)
			return;

		if (!ptrav->children[index])
		{		
			ptrav->children[index] = get_node();
		}
		ptrav = ptrav->children[index];


	}
	ptrav->word_count++;
	ptrav->loc = (long int*)realloc(ptrav->loc, ptrav->word_count*sizeof(long int));
	ptrav->loc[ptrav->word_count-1] = location;
}

long int* search (trie_t *ptrie, char key[])
{
	int level;
	int length = strlen(key);
	int index;

	trie_node_t *ptrav;
	ptrav = ptrie->root;

	for (level = 0; level < length; level++)
	{
		if (key[level]>='A' && key[level] <= 'Z')
		{
			index = CAP_CHAR_TO_INDEX(key[level]);	
		}		

		else if (key[level]>='a' && key[level] <= 'z')
		{
			index = SMALL_CHAR_TO_INDEX(key[level]);	
		}
		else 
			return NULL;
		if (ptrav->children[index] == NULL)
			return NULL;
		ptrav = ptrav->children[index];
	}
	if (ptrav->word_count == 0)
	{
		return NULL;
	}
	else
	{
		return ptrav->loc;

	}
}