/**
 * Programmed by: Allen Hizon
 * Tested by: Allen Hizon
 */
#include "graph.h"
#include <stdio.h>

/**
 * Performs a recursive depth-first search algorithm on a graph and
 * outputs the results to a file.
 * 
 * @param fp Pointer to the output file
 * @param g Pointer to the graph
 * @param sortedAdjacencyMatrix A version of the graph's adjacency matrix sorted alphabetically
 * @param visited Bool array that represents whether or not a vertex
 *                has been visited
 * @param vertex Index of the vertex to possibly visit
 */
void
recursiveDFS(FILE *fp, Graph *g, bool** sortedAdjacencyMatrix, bool visited[], int vertex)
{

    if (visited[vertex]) {
        return; // immediately return to avoid revisiting
    }

    fprintf(fp, "%s ", g->adjacencyList[g->mapSortedToUnsorted[vertex]]->name);
    // use mapSortedToUnsorted to get the right name from the adjacency list
    visited[vertex] = true;

    for (int i = 0; i < g->numVertices; i++) {
        if (sortedAdjacencyMatrix[vertex][i] == true && !visited[i]) {
            recursiveDFS(fp, g, sortedAdjacencyMatrix, visited, i);
        }
    }
    return;
}