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
        g->adjacencyList[i]->nodeIndex = i;
    }

    return g;
}


bool
createVertex(Graph *g, int vertex, char *name)
{
    // if vertex has been created
    if (g->adjacencyList[vertex] != NULL) {
        printf("\nThat vertex has already been created!\n");
        return false;
    }

    Node *newNode = createNode(name);
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
    // initial check for duplicate edge
    if (hasEdge(g, startVertex, endName) || hasEdge(g, endVertex, startName)){
        return false;
    }
    
    // create startVertex->endVertex connection
    Node *current = g->adjacencyList[startVertex];
    bool alreadyConnected = false;

    while (current != NULL && alreadyConnected) {
        if (strcmp(current->name, endName) != 0) {
            alreadyConnected = true;
        }
        current = current->next;
    }

    if (!alreadyConnected) {
        Node *new = createNode(endName);
        new->next = g->adjacencyList[startVertex];
        g->adjacencyList[startVertex] = new;
    }
    
    // create endVertex->startVertex connection
    current = g->adjacencyList[endVertex];
    alreadyConnected = false;
    while (current != NULL && alreadyConnected){
        if (strcmp(current->name, startName) != 0){
            alreadyConnected = true;
        }
        current = current->next;
    }

    if (!alreadyConnected){
        Node *new = createNode(startName);
        new->next = g->adjacencyList[endVertex];
        g->adjacencyList[endVertex] = new;
    }

    return true;
}

// temp and it's not in the format sir asked for
void
printAdjacencyList(Node *head)
{

    Node *current = head;
    while (current != NULL) {
        printf("<%s> -> ", current->name);
        current = current->next;
    }
}

void
printGraph(Graph *g)
{
    for (int i = 0; i < g->numVertices; i++) {
        printAdjacencyList(g->adjacencyList[i]);
        printf("[NULL]\n");
    }
}

int
main(void)
{
    Graph *test = createGraph(3);
    createVertex(test, 0, "Allen");
    addEdge(test, 0, 2, "Allen", "Ryan");
    createVertex(test, 1, "Jack");
    createVertex(test, 2, "Ryan");

    printGraph(test);
}