#include "graph.h"
#include <stdbool.h>

Graph* 
createGraph(int numVertex)
{
    Graph *g = malloc(sizeof(*g));
    if (g == NULL){
        free(g);
        return NULL;
    }

    g->numVertex = numVertex;
    
    // initialize g->numVertex rows with 0 using calloc()
    g->edges = calloc(sizeof(bool*), g->numVertex);
    if (g->edges == NULL){
        free(g);
        return NULL;
    }
    // initialize g->numVertex cols with 0 using calloc()
    for (int i = 0; i < g->numVertex; i++)
    {
        g->edges[i] = calloc(sizeof(bool), g->numVertex);
    }

    return g;
}

bool 
hasEdge(Graph *g, unsigned int a, unsigned int b)
{
    return g->edges[a][b];
}

bool 
addEdge(Graph* g, unsigned int a, unsigned int b)
{
    if (hasEdge(g, a, b))
    {
        return false;
    }
    
    // undirected graphs are agnostic in direction
    // edges (a-b) and (b-a) are biconditional 
    g->edges[a][b] = true;
    g->edges[b][a] = true;
    return true;
}

void
printGraph(Graph* g){
    printf("Graph: {\n");
    for (int i = 0; i < g->numVertex; i++){
        for (int j = 0; j < g->numVertex; j++){
            if (hasEdge(g, i, j)){
                printf("(%d -> %d)\n", i, j);
            }
        }
    }
    printf("}\n");
}