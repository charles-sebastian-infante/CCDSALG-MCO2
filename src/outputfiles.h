/**
 * Programmed by: Christian Gendrano, Charles Infante, and Allen Hizon
 * Tested by: Christian Gendrano, Charles Infante, and Allen Hizon
 */

#ifndef OUTPUTFILES
#define OUTPUTFILES
#include "graph.h"
#include <stdio.h>

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
 * Produces output file #1, which contains the set of vertices and the set of edges in alphabetical order.
 * 
 * @param strOutputFileName The filename where the output will be stored
 * @param g Pointer to the graph to be outputted
 */
void outputSet(char *strOutputFileName, Graph g);

/**
 * Produces output file #2, which contains the list of vertex IDs and their corresponding degrees.
 * 
 * @param strOutputFileName The filename where the output will be stored
 * @param g Pointer to the graph to be outputted
 */
void outputDegree(char *strOutputFileName, Graph g);

/**
 * Produces output file #3, which contains the adjacency list representation of the graph.
 * 
 * @param strOutputFileName The filename where the output will be stored
 * @param g Pointer to the graph to be outputted
 */
void outputAdjacencyList(char *strOutputFileName, Graph *g);

/**
 * Produces output file #4, which contains the adjacency matrix representation of the graph.
 * 
 * @param strOutputFileName The filename where the output will be stored
 * @param g Pointer to the graph to be outputted
 */
void outputAdjacencyMatrix(char *strOutputFileName, Graph *g);

/**
 * Produces output file #5, which contains the BFS traversal of the graph starting
 * from a given vertex.
 * 
 * @param strOutputFileName The filename where the output will be stored
 * @param g Pointer to the graph to be outputted
 * @param vertex String containing the ID of the start vertex
 */
void outputBFS(char *strOutputFileName, Graph *g, char *vertex);

/**
 * Produces output file #6, which contains the DFS traversal of the graph starting
 * from a given vertex.
 * 
 * @param strOutputFileName The filename where the output will be stored
 * @param g Pointer to the graph to be outputted
 * @param vertex String containing the ID of the start vertex
 */
void outputDFS(char *strOutputFileName, Graph *g, char *vertex);

#endif