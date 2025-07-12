/**
 * Programmed by: Charles Infante
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 /**
  * define a structure variable 
  */
#ifndef GRAPHTAG
#define GRAPHTAG
typedef struct graphTag{
    int numVertices;
    
    // note that double pointer was used as array size yet to be init
    // C requires multi-dimensional arrays to have at least one init. dimension (other than first)
    int** edges; 

    // TODO (CHARLES): add probably a node for identifiers and call those instead? 
       
} Graph;
#endif

/**
 * creates a graph using an adjacency matrix
 * @param numVertex is the number of vertexes/nodes in the graph
 * @return the pointer to the created graph
 */
Graph* createGraph(int numVertex);

/**
 * adds an edge to a graph
 * @param g pointer to the graph that edge will be added to
 * @param a is the index of the first node
 * @param b is the index of the second node
 * @return true if successful, false otherwise 
 */
bool addEdge(Graph* g, unsigned int a, unsigned int b);

/**
 * checks if a graph has an edge connecting nodes
 * @param g pointer to the graph that will be checked
 * @param a index of the first node
 * @param b index of the second node
 * @return true if graph contains, false otherwise
 */
bool hasEdge(Graph* g, unsigned int a, unsigned int b);

/**
 * prints the edges of a graph in set form.
 * @param g pointer to the graph to be printed
 */
void printGraph(Graph* g);