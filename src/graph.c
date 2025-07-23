#include "graph.h"

Node *
createNode(char *name)
{
    // allocate memory to a new node
    Node *newNode = malloc(sizeof(Node));

    // free the created node in event that newNode cannot be allocated memory
    if (newNode == NULL) {
        free(newNode);
        printf("\nUnable to allocate memory for node.\n");
        return NULL;
    }
    // set the identifier of the newNode, and set next to NULL
    newNode->name = name;
    newNode->next = NULL;

    return newNode;
}

Graph *
createGraph(int numVertices)
{
    // allocate memory for the graph and set # of vertices
    Graph *g = malloc(sizeof(Graph));
    if (g == NULL){
        printf("Unable to allocate memory for graph.\n");
        return NULL;
    }

    g->numVertices = numVertices;

    // allocate memory for the adjacency lists of g
    g->adjacencyList = malloc(numVertices * sizeof(Node *));

    // free g in the event that adjacencyList cannot be allocated memory
    if (g->adjacencyList == NULL) {
        free(g);
        printf("\nUnable to allocate memory for adjacency list.\n");
        return NULL;
    }

    for (int i = 0; i < numVertices; i++) {
        g->adjacencyList[i] = NULL;
    }

    return g;
}

bool
createVertex(Graph *g, int vertex, char *name)
{
    // if vertex has been created
    if (g->adjacencyList[vertex] != NULL) {
        printf("\nVertex %s has already been created!\n", name);
        return false;
    }

    Node *newNode = createNode(name);
    newNode->nodeIndex = vertex;
    g->adjacencyList[vertex] = newNode;

    return true;
}

bool
hasEdge(Graph *g, int startVertex, char *name)
{
    Node *current = g->adjacencyList[startVertex];

    while (current != NULL) {
        if (strcmp(name, current->name) == 0) {
            return true;
        }
        current = current->next;
    }

    return false;
}

bool
addEdge(Graph *g, int startVertex, int endVertex, char *startName, char *endName)
{
    // check if edge has been connected previously
    if (hasEdge(g, startVertex, endName) || hasEdge(g, endVertex, startName)){
        printf("Edge <%s,%s> is already connected!\n", startName, endName);
        return false;
    }

    // create the first connection (startVertex->endVertex)
    Node *current = g->adjacencyList[startVertex];
    
    while (current->next != NULL){
        current = current->next;
    }

    Node *new = createNode(endName);
    current->next = new;

    // create second connection (endVertex->startVertex)
    current = g->adjacencyList[endVertex];

    while (current->next != NULL){
        current = current->next;
    }

    new = createNode(startName);
    current->next = new;
    return true;
}

void
printAdjacencyList(Node *head)
{
    Node *current = head;
    while (current != NULL) {
        printf("%s->", current->name);
        current = current->next;
    }
    printf("\\\n");
}

void
printGraph(Graph *g)
{
    for (int i = 0; i < g->numVertices; i++) {
        printAdjacencyList(g->adjacencyList[i]);
    }
}