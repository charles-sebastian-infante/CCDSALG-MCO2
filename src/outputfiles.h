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
 * @param g The graph
 */
void outputSet(char *strOutputFileName, Graph g);

/**
 * Produces output file #2, which contains the list of vertex IDs and their corresponding degrees.
 * 
 * @param strOutputFileName The filename where the output will be stored
 * @param g The graph
 */
void outputDegree(char *strOutputFileName, Graph g);

/**
 * Writes the adjacency lists of a graph to a file
 * @param strOutputFileName The filename where the output will be stored
 * @param g Graph to be outputted
 */
void outputAdjacencyList(char *strOutputFileName, Graph *g);

/**
 * Writes an adjacency matrix of a graph to a file
 * @param strOutputFileName The filename where the output will be stored
 * @param g Graph to be outputted
 */
void outputAdjacencyMatrix(char *strOutputFileName, Graph *g);

/**
 * Writes the BFS traversal of a node from a graph to a file
 * @param strOutputFileName The filename where the output will be stored
 * @param g Graph to be outputted
 * @param vertex The start vertex
 */
void outputBFS(char *strOutputFileName, Graph *g, char *vertex);

/*
/**
 * Writes the DFS traversal of a node from a graph to a file
 * @param strOutputFileName The filename where the output will be stored
 * @param g Graph to be outputted
 *
void outputDFS(char *strOutputFileName, Graph *g);*/

#endif