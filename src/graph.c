/**
 * Programmed by: Charles Infante
 * Tested by: Charles Infante
 */

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
addEdge(Graph *g, int startVertex, char *endName)
{
    // check if edge has been connected previously
    if (hasEdge(g, startVertex, endName)){
        printf("Edge <%s,%s> is already connected!\n", g->adjacencyList[startVertex]->name, endName);
        return false;
    }
    
    // create the first connection (startVertex->endVertex)
    Node *current = g->adjacencyList[startVertex];
    int endVertexIndex;

    for (int i = 0; i < g->numVertices; i++) {
        if (strcmp(g->adjacencyList[i]->name, endName) == 0)
            endVertexIndex = i;
    }
    

    while (current->next != NULL){
        current = current->next;
    }

    Node *new = createNode(endName);
    new->nodeIndex = endVertexIndex;
    current->next = new;

    return true;
}

/**
 * Gets vertex IDs from a graph and adds them to an array of strings.
 * 
 * @param g The graph to get the vertex IDs from
 * @param arrVertexIds The array of strings where the vertex IDs will go
 */
void
getVertexIds(Graph g, char arrVertexIds[][ID_LENGTH])
{
    for (int i = 0; i < g.numVertices; i++) {
        strcpy(arrVertexIds[i], g.adjacencyList[i]->name);
    }
}

/**
 * Swaps two strings. Note that this can only swap strings with a maximum
 * length of 8 characters.
 * 
 * @param a The first string to be swapped
 * @param b The second string to be swapped
 */
void
swapStrings(char a[], char b[])
{
    char temp[9];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

/**
 * Sorts the vertex IDs in alphabetical order.
 * 
 * @param arrVertexIds The array of vertex IDs
 * @param nVertexIds The number of vertex IDs in the array
 */
void
sortVertexIds(char arrVertexIds[][ID_LENGTH], int numVertexIds)
{
    // selection sort
    int i, j, minIndex;

    for (i = 0; i < numVertexIds - 1; i++) {
        minIndex = i;

        for (j = i + 1; j < numVertexIds; j++) {
            if (strcmp(arrVertexIds[j], arrVertexIds[minIndex]) < 0) {
                minIndex = j;
            }
        }

        swapStrings(arrVertexIds[i], arrVertexIds[minIndex]);
    }
}

int
findVertexIDFromName(char *name, Graph *g)
{
    for (int i = 0; i < g->numVertices; i++) {
        if (strcmp(g->adjacencyList[i]->name, name) == 0) {
            return i;
        }
    }
    return -1;
}

bool **
createAdjacencyMatrix(Graph *g)
{
    int numVertex = g->numVertices;

    // populate matrix with 0s
    bool **matrix = calloc(numVertex, sizeof(bool *));

    for (int i = 0; i < numVertex; i++) {
        matrix[i] = calloc(numVertex, sizeof(bool));
    }

    // populate matrix with necessary values
    for (int i = 0; i < numVertex; i++) {
        Node *current = g->adjacencyList[i];

        // note that since the initial node is itself, there will never be an edge from self-self.
        while (current->next != NULL) {
            current = current->next;
            matrix[i][current->nodeIndex] = true;
        }
    }

    // return matrix
    return matrix;
}

bool **
createSortedAdjacencyMatrix(Graph *g) {
    int numVertex = g->numVertices;

    // populate matrix with 0s
    bool **matrix = calloc(numVertex, sizeof(bool *));

    for (int i = 0; i < numVertex; i++) {
        matrix[i] = calloc(numVertex, sizeof(bool));
    }

    // create an array of vertex IDs to sort them
    char vertexIds[numVertex][ID_LENGTH];

    getVertexIds(*g, vertexIds);
    sortVertexIds(vertexIds, g->numVertices);

    // turn the sorted IDs into an array of their indices
    int sortedIndices[numVertex];
    for (int i = 0; i < numVertex; i++) {
        sortedIndices[i] = findVertexIDFromName(vertexIds[i], g);
    }

    printf("Printing sorted list\n");
    for (int i = 0; i < numVertex; i++) {
        printf("[%s][%d]\n", vertexIds[i], sortedIndices[i]);
    }

    for (int i = 0; i < numVertex; i++) {
        int currentId = sortedIndices[i];
        // populate matrix with necessary values using the sorted indice list
        Node *current = g->adjacencyList[currentId];
        // note that since the initial node is itself, there will never be an edge from self-self.
        while (current->next != NULL) {
            current = current->next;
            matrix[i][current->nodeIndex] = true;
        }
    }
}

void
freeAdjacencyList(Graph *g) {
    Node **list = g->adjacencyList;
    int numVertex = g->numVertices;

    Node *current, *previous;
    for (int i = 0; i < numVertex; i++) {
        current = list[i];

        while (current->next != NULL) {
            previous = current;
            current = current->next;
            free(previous);
        }

        free(current); // freeing the last element in the list
    }

    free(list); // freeing the memory for the pointer to the list
}

void
freeAdjacencyMatrix(Graph *g) {
    bool **matrix = g->adjacencyMatrix;
    int numVertex = g->numVertices;

    for (int i = 0; i < numVertex; i++) {
        free(matrix[i]);
    }

    free(matrix);
}

/*
// G.txt used for testing outputs
// delete for final submission
int main(){
    Graph *g = createGraph(4);

    createVertex(g, 0, "Diana");
    createVertex(g, 1, "Bruce");
    createVertex(g, 2, "Hal");
    createVertex(g, 3, "Clark");
    
    addEdge(g,0,"Hal");
    addEdge(g,0,"Bruce");
    addEdge(g,0,"Clark");
    addEdge(g,1,"Diana");
    addEdge(g,2,"Clark");
    addEdge(g,2,"Diana");
    addEdge(g,3,"Hal");
    addEdge(g,3,"Diana");
}
*/