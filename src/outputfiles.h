#ifndef OUTPUTFILES
#define OUTPUTFILES
#include "graph.h"
#include <stdio.h>
/**
 * writess a graph in the form of a set to a file
 * @param g graph to be outputted
 * @param outputFileName the name of the outputfile
 */
void outputAsSet(Graph g, char *outputFileName);
/**
 * writes the vertex ids of a graph to a file
 * @param g graph to be outputted
 * @param outputFileName the name of the outputfile
 */
void outputVertexIDs(Graph g, char *outputFileName);
/**
 * writes the adjacency lists of a graph to a file
 * @param g graph to be outputted
 * @param outputFileName the name of the outputfile
 */
void outputAdjacencyList(Graph g, char *outputFileName);
/**
 * writes an adjacency matrix of a graph to a file
 * @param g graph to be outputted
 * @param outputFileName the name of the outputfile
 */
void outputAdjacencyMatrix(Graph g, char *outputFileName);
/**
 * writes the BFS traversal of a node from a graph to a file
 * @param g graph to be outputted
 * @param outputFileName the name of the outputfile
 */
void outputBFS(Graph g, char *outputFileName);
/**
 * writes the DFS traversal of a node from a graph to a file
 * @param g graph to be outputted
 * @param outputFileName the name of the outputfile
 */
void outputDFS(Graph g, char *outputFileName);
#endif