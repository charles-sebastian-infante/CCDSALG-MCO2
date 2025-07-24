/**
 * Programmed by: Christian Gendrano
 * Tested by: Christian Gendrano
 */

#include <stdio.h>
#include <string.h>
#include "graph.c"

#ifndef EDGE_DEFINED
#define EDGE_DEFINED
/**
 * Representation of an edge.
 * 
 * @param startVertex String containing the ID of the start vertex
 * @param endVertex String containing the ID of the end vertex
 */
typedef struct {
    char startVertex[9]; // vertex ID has maximum length of 8 characters
    char endVertex[9];
} Edge;
#endif

/**
 * Gets vertex IDs from a graph and adds them to an array of strings.
 * 
 * @param g The graph to get the vertex IDs from
 * @param arrVertexIds The array of strings where the vertex IDs will go
 */
void getVertexIds(Graph g, char arrVertexIds[][9]) {
    for (int i = 0; i < g.numVertices; i++) {
        strcpy(arrVertexIds[i], g.adjacencyList[i]->name);
    }
}

/**
 * Swaps two strings. Note that this can only swap strings with a maximum
 * length of 8 characters.
 * 
 * @param a The first string to be swapped
 * @param b The second string to be swapped
 */
void swapStrings(char a[], char b[]) {
    char temp[9];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

/**
 * Sorts the vertex IDs in alphabetical order.
 * 
 * @param arrVertexIds The array of vertex IDs
 * @param nVertexIds The number of vertex IDs in the array
 */
void sortVertexIds(char arrVertexIds[][9], int numVertexIds) {
    // selection sort
    int i, j, minIndex;

    for (i = 0; i < numVertexIds - 1; i++) {
        minIndex = i;

        for (j = i + 1; j < numVertexIds; j++) {
            if (strcmp(arrVertexIds[j], arrVertexIds[minIndex]) < 0) {
                minIndex = j;
            }
        }

        swapStrings(arrVertexIds[i], arrVertexIds[minIndex]);
    }
}

/**
 * Gets edges from a graph and adds them to an array of edges.
 * 
 * @param g The graph to get the edges from
 * @param arrEdges The array where the edges will go
 * @return The number of edges
 */
int getEdges(Graph g, Edge arrEdges[]) {
    int numVertices = g.numVertices;
    int numEdges = 0; // counter for number of edges
    Edge tempEdge;
    
    for (int i = 0; i < numVertices; i++) {
        Node *pCurrNode = g.adjacencyList[i]; // pointer to the current node

        /* setting the start vertex for all edges in this iteration of the for
           loop to the name of the first node in the linked list */
        strcpy(tempEdge.startVertex, pCurrNode->name);

        /* iterating through the nodes that the current node is connected to,
           setting those nodes as the end vertices of the edges, then adding
           the edges to the array */
        while (pCurrNode->next != NULL) {
            pCurrNode = pCurrNode->next;
            strcpy(tempEdge.endVertex, pCurrNode->name);
            arrEdges[numEdges] = tempEdge;
            numEdges++;
        }
    }

    return numEdges;
}

/**
 * Removes duplicate edges from an array of edges by discarding all edges where
 * the ID of the end vertex comes before the ID of the start vertex in alphabetical
 * order.
 * 
 * @param arrOldEdges The original array of edges
 * @param arrNewEdges The array where only non-duplicate edges will go
 * @param numEdges Pointer to the number of edges in the array
 */
void removeDuplicateEdges(Edge arrOldEdges[], Edge arrNewEdges[], int *numEdges) {
    int numOriginalEdges = *numEdges; // original number of edges
    *numEdges = 0;

    for (int i = 0; i < numOriginalEdges; i++) {
        Edge currentEdge = arrOldEdges[i];

        /* only add current edge to the new array if the start vertex comes before
           the end vertex in alphabetical order */
        if (strcmp(currentEdge.startVertex, currentEdge.endVertex) == -1) {
            arrNewEdges[*numEdges] = currentEdge;
            (*numEdges)++;
        }
    }
}

/**
 * Swaps two edges.
 * 
 * @param a The first edge to be swapped
 * @param b The second edge to be swapped
 */
void swapEdges(Edge *a, Edge *b) {
    Edge temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * Compares two edges, first based on alphabetical order of the start vertices,
 * then based on alphabetical order of the end vertices.
 * 
 * @param a The first edge to be compared
 * @param b The second edge to be compared
 * @return 0 if the edges are identical, -1 if the first edge comes before the
 *         second edge, or 1 if the second edge comes after the first edge
 */
int compareEdges(Edge a, Edge b) {
    if (strcmp(a.startVertex, b.startVertex) == 0) {
        /* if the start vertices are identical, return the result of the
           strcmp between the end vertices */
        return strcmp(a.endVertex, b.endVertex);
    } else {
        /* if the start vertices are not identical, just return the result
           of the strcmp between the start vertices */
        return strcmp(a.startVertex, b.startVertex);
    }
}

/**
 * Sorts the edges in alphabetical order, first by the ID of the start vertex,
 * then by the ID of the end vertex.
 * 
 * @param arrEdges The array of edges to be sorted
 * @param numEdges The number of edges in the array
 */
void sortEdges(Edge arrEdges[], int numEdges) {
    // selection sort
    int i, j, minIndex;

    for (i = 0; i < numEdges - 1; i++) {
        minIndex = i;

        for (j = i + 1; j < numEdges; j++) {
            if (compareEdges(arrEdges[j], arrEdges[minIndex]) < 0) {
                minIndex = j;
            }
        }

        swapEdges(&arrEdges[i], &arrEdges[minIndex]);
    }
}