/**
 * Programmed by: Charles Infante
 * Tested by: Charles Infante
 */
#ifndef GRAPH_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 20

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
 * @param adjacencyMatrix A square 2D array of boolean values representing the graph
 */
typedef struct graphTag {
    int numVertices;
    Node **adjacencyList;
    bool **adjacencyMatrix;
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
 * This function creates an adjacency matrix for a graph, provided that the
 * graph already has a populated adjacency list.
 * 
 * @param g Pointer to the graph
 * @return 2D bool array representing the adjacency matrix
 */
bool **createAdjacencyMatrix(Graph *g);
/**
 * Frees the dynamic memory allocated for the adjacency list of the graph.
 * 
 * @param g Pointer to the graph
 */
void freeAdjacencyList(Graph *g);
/**
 * Frees the dynamic memory allocated for the adjacency matrix of the graph.
 * 
 * @param g Pointer to the graph
 */
void freeAdjacencyMatrix(Graph *g);

#define GRAPH_H
#endif