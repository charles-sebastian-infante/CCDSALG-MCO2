/**
 * Programmed by: Allen Hizon
 * Tested by: Allen Hizon
 */
#include "graph.h"
#include <stdio.h>

void
recursiveDFS(FILE *fp, Graph *g, bool visited[], int vertex)
{

    if (visited[vertex]) {
        return; // immediately return to avoid revisiting
    }

    fprintf(fp, "%s ", g->adjacencyList[vertex]->name);
    visited[vertex] = true;

    for (int i = 0; i < g->numVertices; i++) {
        if (g->adjacencyMatrix[vertex][i] == true && !visited[i]) {
            recursiveDFS(fp, g, visited, i);
        }
    }
    return;
}