/**
 * Programmed by: Charles Infante
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * a Node structure for a doubly linked list implementation.
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
 * @param adjacencyList 2D array of nodes
 */
typedef struct graphTag{
    int numVertices;
    Node** adjacencyList; 
} Graph;

/**
 * creates a node with an identifier.
 * @param name string of the unique identifier
 * @return pointer to the created node if successful, NULL otherwise
 */
Node * createNode(char *name);
/**
 * creates a graph with a specified number of vertices/nodes.
 * @param numVertices is the number of vertices in the graph.
 * @return a pointer to the created graph if successful, NULL otherwise
 */
Graph * createGraph(int numVertices);
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
 * @param endVertex is the identifier of the Node to add
 * @return true if the edge is successfully created, false otherwise.
 */
bool addEdge(Graph *g, int startVertex, char *endName);
/**
 * prints the adjacency list of a Node.
 * @param head is the head node of a given adjacency list.
 * @return void
 */
void printAdjacencyList(Node *head);
/**
 * prints a graph.
 * @param g is the graph to be printed
 * @return void
 */
void printGraph(Graph *g);