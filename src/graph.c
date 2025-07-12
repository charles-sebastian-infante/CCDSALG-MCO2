#include "graph.h"

Graph *
createGraph(int numVertices)
{
    Graph *g = malloc(sizeof(*g));
    if (g == NULL) {
        return NULL;
    }

    g->numVertices = numVertices;

    // initialize g->numVertices rows with 0 using calloc()
    g->edges = calloc(sizeof(bool *), g->numVertices);
    if (g->edges == NULL) {
        return NULL;
    }
    // initialize g->numVertices cols with 0 using calloc()
    for (int i = 0; i < g->numVertices; i++) {
        g->edges[i] = calloc(sizeof(bool), g->numVertices);
    }

    return g;
}

bool
hasEdge(Graph *g, unsigned int a, unsigned int b)
{
    return g->edges[a][b];
}

bool
addEdge(Graph *g, unsigned int a, unsigned int b)
{
    if (hasEdge(g, a, b)) {
        return false;
    }

    // undirected graphs are agnostic in direction
    // edges (a-b) and (b-a) are biconditional
    g->edges[a][b] = true;
    g->edges[b][a] = true;
    return true;
}