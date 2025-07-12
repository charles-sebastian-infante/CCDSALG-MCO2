#ifndef GRAPH_HEADER
#define GRAPH_HEADER

/**
 * Programmed by: Allen Hizon
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


typedef struct nodeTag {
    char *name;
    struct nodeTag *next;
} Node;

typedef struct graphTag{
    int numVertices;
    Node** adjacencyList; 
       
} Graph;

#endif