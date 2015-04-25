#include <stdio.h>
#include <stdlib.h>

#define UNDIRECTED

typedef struct adjListNode
{
	int dest;
	struct adjListNode* next;
} adjListNode;

typedef struct adjList
{
	adjListNode* head;
} adjList;

typedef struct Graph
{
	int V;
	adjList* array;
} Graph;

adjListNode* newadjListNode (int dest);

Graph*  createGraph(int V);

void addEdge(Graph* graph, int src, int dest);

void printGraph (Graph* graph);

void DFS (Graph* graph, int v, int connected, int marked[]);