#include "graph.h"

Node *
createNode(char *name)
{

    Node *newNode = malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("\nUnable to allocate memory for node.\n");
        return NULL;
    }

    newNode->name = name;
    newNode->next = NULL;

    return newNode;
}

Graph *
createGraph(int numVertices)
{
    Graph *g = malloc(sizeof(Graph));
    g->numVertices = numVertices;

    g->adjacencyList = malloc(numVertices * sizeof(Node *));

    if (g->adjacencyList == NULL) {
        printf("\nUnable to allocate memory for adjacency list.\n");
        return NULL;
    }

    for (int i = 0; i < numVertices; i++) {
        g->adjacencyList[i] = NULL;
    }

    return g;
}

// Call this for each line in the text file
int
createVertex(Graph *g, int vertex, char *name)
{

    if (g->adjacencyList[vertex] != NULL) {
        printf("\nThat vertex has already been created!\n");
        return EXIT_FAILURE;
    }

    Node *newNode = createNode(name);
    g->adjacencyList[vertex] = newNode;

    return EXIT_SUCCESS;
}

int
hasEdge(Graph *g, int startVertex, char *name)
{
    Node *current = g->adjacencyList[startVertex];

    while (current != NULL) {
        if (strcmp(name, current->name) == 0) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

int
addEdge(Graph *g, int startVertex, char *name)
{
    Node *current = g->adjacencyList[startVertex];
    bool alreadyConnected = false;

    while (current != NULL && alreadyConnected) {
        if (strcmp(current->name, name) != 0) {
            alreadyConnected = true;
        }
        current = current->next;
    }

    if (!alreadyConnected) {
        current->next = createNode(name);
    }
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
    addEdge(test, 0, "Ryan");
    createVertex(test, 1, "Jack");
    createVertex(test, 2, "Ryan");

    printGraph(test);
}