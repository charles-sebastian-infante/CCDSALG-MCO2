#ifndef OUTPUTFILES
#define OUTPUTFILES
#include <stdio.h>
#include "graph.c"

/**
 * writess a graph in the form of a set to a file
 * @param g graph to be outputted
 * @param name the name of the outputfile
 */
void outputAsSet(Graph *g, char *name);
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