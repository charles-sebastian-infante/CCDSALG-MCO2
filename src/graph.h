/**
 * Programmed by: Charles Infante, Christian Gendrano, Allen Hizon
 * Tested by: Charles Infante, Christian Gendrano, Allen Hizon
 */

#ifndef GRAPH_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 20
#define ID_LENGTH 9

/**
 * Node structure for a singly linked list
 * @param name the node's unique identifier
 * @param next pointer to the next node in the linked list
 * @param nodeIndex the index of the node.
 */
typedef struct nodeTag {
    char *name;
    struct nodeTag *next;
    int nodeIndex;
} Node;

/**
 * an implementation of the Graph data structure
 * @param numVertices is the number of vertices or Nodes in the graph
 * @param adjacencyList Array of singly linked lists containing Nodes
 * @param mapUnsortedToSorted An array of integers mapping the original vertex indices to their indices when sorted alphabetically 
 * @param mapSortedToUnsorted An array of integers mapping the sorted vertex indices to their original indices in order of insertion
 */
typedef struct graphTag {
    int numVertices;
    Node **adjacencyList;
    int mapUnsortedToSorted[MAX_VERTICES];
    int mapSortedToUnsorted[MAX_VERTICES];
} Graph;

/**
 * creates a node with an identifier.
 * @param name string of the unique identifier
 * @return pointer to the created node if successful, NULL otherwise
 */
Node *createNode(char *name);

/**
 * creates a graph with a specified number of vertices/nodes.
 * @param numVertices is the number of vertices in the graph.
 * @return a pointer to the created graph if successful, NULL otherwise
 */
Graph *createGraph(int numVertices);

/**
 * creates a vertex in a specific graph with specific identifier.
 * @param g is a pointer to the graph where vertex is added
 * @param vertex is the index of the adjacency list to add to
 * @param name is the identifier of the vertex
 * @return true if vertex was successfully created, false otherwise
 */
bool createVertex(Graph *g, int vertex, char *name);

/**
 * checks if a graph has an edge from one vertex to another.
 * @param g is a pointer to the graph where both vertices are located
 * @param startVertex is the index of the adjacency list to check
 * @param name is the unique identifier of the terminal vertex to be checked
 * @return true if an edge has been found, false otherwise
 */
bool hasEdge(Graph *g, int startVertex, char *name);

/**
 * adds an edge from one vertex to another
 * @param g is a pointer to the graph to add a vertex.
 * @param startVertex is the index of the destination adjacency list
 * @param endName is the identifier of the Node to add
 * @return true if the edge is successfully created, false otherwise.
 */
bool addEdge(Graph *g, int startVertex, char *endName);

/**
 * Gets vertex IDs from a graph and adds them to an array of strings.
 * 
 * @param g The graph to get the vertex IDs from
 * @param arrVertexIds The array of strings where the vertex IDs will go
 */
void getVertexIds(Graph g, char arrVertexIds[][ID_LENGTH]);

/**
 * Swaps two strings. Note that this can only swap strings with a maximum
 * length of 8 characters.
 * 
 * @param a The first string to be swapped
 * @param b The second string to be swapped
 */
void swapStrings(char a[], char b[]);

/**
 * Sorts the vertex IDs in alphabetical order.
 * 
 * @param arrVertexIds The array of vertex IDs
 * @param nVertexIds The number of vertex IDs in the array
 */
void sortVertexIds(char arrVertexIds[][ID_LENGTH], int numVertexIds);

/**
 * This function finds the index of a vertex in the adjacency
 * list from the vertex's name.
 * 
 * @param name String containing the name of the vertex
 * @param g Pointer to the graph
 * @return Index of the vertex
 */
int findVertexIDFromName(char *name, Graph *g);

/**
 * Creates an adjacency matrix for a graph, provided that the
 * graph already has a populated adjacency list.
 * 
 * @param g Pointer to the graph
 * @return 2D bool array representing the adjacency matrix
 */
bool **createAdjacencyMatrix(Graph *g);

/**
 * Creates a sorted adjacency matrix for a graph, provided that
 * the graph already has a populated adjacency list.
 * 
 * @param g Pointer to the graph
 * @return 2D bool array representing the adjacency matrix
 */
bool **createSortedAdjacencyMatrix(Graph *g);

/**
 * Frees the dynamic memory allocated for a graph, including its adjacency list.
 * 
 * @param g Pointer to the graph
 */
void freeGraph(Graph *g);

/**
 * Frees the dynamic memory allocated for an adjacency matrix.
 * 
 * @param m pointer to the matrix
 * @param numVertices the number of vertices in the matrix
 */
void freeAdjacencyMatrix(bool **m, int numVertices);

#define GRAPH_H
#endif