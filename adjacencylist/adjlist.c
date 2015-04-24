#include "adjlist.h"


adjListNode* newadjListNode (int dest)
{
	adjListNode* newnode = (adjListNode*) malloc(sizeof(adjListNode));
	newnode->dest = dest;
	newnode->next = NULL;
	return newnode;
}


Graph*  createGraph(int V)
{
	Graph* newgraph = (Graph*) malloc(sizeof(Graph));
	newgraph->V = V;

	newgraph->array = (adjList*)malloc(V*sizeof(adjList));

	int i;
	for (i = 0; i < V; ++i)
	{
		newgraph->array[i].head = NULL;
	}

	return newgraph;
}

void addEdge (Graph* graph, int src, int dest)
{
	adjListNode* temp = graph->array[src].head;

	if (temp == NULL)
	{
		graph->array[src].head = newadjListNode(dest);
	}
	else
	{
		while (temp->next != NULL)
		{
			if (temp->dest = dest)
				break;			
			temp = temp->next;
		}
		if (temp->next == NULL)
			temp->next = newadjListNode(dest);
	}

	#ifdef UNDIRECTED
	temp = graph->array[dest].head;

	if (temp == NULL)
	{
		graph->array[dest].head = newadjListNode(src);
	}
	else
	{
		while (temp->next != NULL)
		{
			if (temp->dest = src)
				break;			
			temp = temp->next;
		}
		if (temp->next == NULL)
			temp->next = newadjListNode(src);
	}
	#endif
}

void printGraph (Graph* graph)
{
	int i;
	for ( i = 0; i < graph->V; ++i)
	{
		adjListNode* iterator = graph->array[i].head;
		printf("Adjacency list of vertex %d\n head", i);
		while (iterator)
		{
			printf("-> %d", iterator->dest);
			iterator = iterator->next;
		}

		printf("\n");
	}
}
