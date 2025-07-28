/**
 * Programmed by: Charles Infante, Christian Gendrano, Allen Hizon
 * Tested by: Charles Infante, Christian Gendrano, Allen Hizon
 */

#include "graph.h"

/**
 * creates a node with an identifier.
 * @param name string of the unique identifier
 * @return pointer to the created node if successful, NULL otherwise
 */
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

/**
 * creates a graph with a specified number of vertices/nodes.
 * @param numVertices is the number of vertices in the graph.
 * @return a pointer to the created graph if successful, NULL otherwise
 */
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

/**
 * creates a vertex in a specific graph with specific identifier.
 * @param g is a pointer to the graph where vertex is added
 * @param vertex is the index of the adjacency list to add to
 * @param name is the identifier of the vertex
 * @return true if vertex was successfully created, false otherwise
 */
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

/**
 * checks if a graph has an edge from one vertex to another.
 * @param g is a pointer to the graph where both vertices are located
 * @param startVertex is the index of the adjacency list to check
 * @param name is the unique identifier of the terminal vertex to be checked
 * @return true if an edge has been found, false otherwise
 */
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

/**
 * adds an edge from one vertex to another
 * @param g is a pointer to the graph to add a vertex.
 * @param startVertex is the index of the destination adjacency list
 * @param endName is the identifier of the Node to add
 * @return true if the edge is successfully created, false otherwise.
 */
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

/**
 * This function finds the index of a vertex in the adjacency
 * list from the vertex's name.
 * 
 * @param name String containing the name of the vertex
 * @param g Pointer to the graph
 * @return Index of the vertex
 */
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

/**
 * Creates an adjacency matrix for a graph, provided that the
 * graph already has a populated adjacency list.
 * 
 * @param g Pointer to the graph
 * @return 2D bool array representing the adjacency matrix
 */
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

/**
 * Creates a sorted adjacency matrix for a graph, provided that
 * the graph already has a populated adjacency list.
 * 
 * @param g Pointer to the graph
 * @return 2D bool array representing the adjacency matrix
 */
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

    // create a mapping from sorted to the original indices (used to sort the columns of the adjacency matrix)
    int reversedIndices[numVertex];
    for (int i = 0; i < numVertex; i++) {
        int original = sortedIndices[i];
        reversedIndices[original] = i;
    }

    for (int i = 0; i < numVertex; i++) {
        int currentId = sortedIndices[i];
        // populate matrix with necessary values using the sorted index list
        Node *current = g->adjacencyList[currentId];
        // note that since the initial node is itself, there will never be an edge from self-self.
        while (current->next != NULL) {
            current = current->next;
            int originalColumn = current->nodeIndex;
            int sortedColumn = reversedIndices[originalColumn];
            matrix[i][sortedColumn] = true;
        }
    }

    return matrix;
}

/**
 * Frees the dynamic memory allocated for a graph, including its adjacency list.
 * 
 * @param g Pointer to the graph
 */
void
freeGraph(Graph *g) {
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

    free(g); // finally, frees the memory allocated for the graph itself
}

/**
 * Frees the dynamic memory allocated for an adjacency matrix.
 * 
 * @param m pointer to the matrix
 * @param numVertices the number of vertices in the matrix
 */
void
freeAdjacencyMatrix(bool **m, int numVertices)
{

    for (int i = 0; i < numVertices; i++) {
        free(m[i]);
    }

    free(m);
}