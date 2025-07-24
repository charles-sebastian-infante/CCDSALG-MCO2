#include "graph.c"

/**
 * Gets the degree of a vertex based on its ID. The degree
 * of a vertex is the number of vertices connected to it
 * through an edge.
 * 
 * @param g The graph
 * @param vertexId String containing the ID of the vertex
 */
int getDegreeOfVertex(Graph g, char vertexId[]) {
    int vertexIndex;
    bool found = false;

    for (int i = 0; i < g.numVertices && !found; i++) {
        if (strcmp(g.adjacencyList[i]->name, vertexId) == 0) {
            vertexIndex = i;
            found = true;
        }
    }

    if (!found) {
        return -1; // given vertex ID not found in the graph
    }

    int degree = 0; // counting the number of neighbors of the vertex
    Node *currentNode = g.adjacencyList[vertexIndex];

    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
        degree++;
    }

    return degree;
}