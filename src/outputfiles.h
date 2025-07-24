#ifndef OUTPUTFILES
#define OUTPUTFILES
#include <stdio.h>
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
 * Produces output file #1, which contains the set of vertices and the set of edges in alphabetical order.
 * 
 * @param g The graph of the file
 * @param name String containing the name of the graph
 */
void outputSet(Graph g, char *name);

/**
 * writes the vertex ids of a graph to a file
 * @param g graph to be outputted
 * @param name the name of the outputfile
 */
void outputVertexIDs(Graph *g, char *name);
/**
 * writes the adjacency lists of a graph to a file
 * @param g graph to be outputted
 * @param name the name of the outputfile
 */
void outputAdjacencyList(Graph *g, char *name);
/**
 * writes an adjacency matrix of a graph to a file
 * @param g graph to be outputted
 * @param name the name of the outputfile
 */
// void outputAdjacencyMatrix(Graph *g, char *name);
/**
 * writes the BFS traversal of a node from a graph to a file
 * @param g graph to be outputted
 * @param name the name of the outputfile
 */
void outputBFS(Graph *g, char *name);
/**
 * writes the DFS traversal of a node from a graph to a file
 * @param g graph to be outputted
 * @param name the name of the outputfile
 */
void outputDFS(Graph *g, char *name);
#endif