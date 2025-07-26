/**
 * Programmed by: Christian Gendrano, Charles Infante, and Allen Hizon
 * Tested by: Christian Gendrano, Charles Infante, and Allen Hizon
 */

#include "outputfiles.h"

#include "output1-set.c"
#include "output2-degree.c"
#include "output3-bfs.c"

/**
 * Produces output file #1, which contains the set of vertices and the set of edges in alphabetical order.
 * 
 * @param strOutputFileName The filename where the output will be stored
 * @param g The graph
 */
void
outputSet(char *strOutputFileName, Graph g)
{
    /* Getting the sorted list of vertices */
    char arrVertexIds[g.numVertices][9];

    getVertexIds(g, arrVertexIds);
    sortVertexIds(arrVertexIds, g.numVertices);

    /* Getting the sorted list of edges */
    int numEdges;
    int maxEdges =
        g.numVertices * (g.numVertices - 1); /* maximum number of edges (including duplicates),
                                                           to be used in the array declaration */
    Edge arrOriginalEdges[maxEdges]; // original array of edges, which includes duplicate edges

    numEdges = getEdges(g, arrOriginalEdges); // gets edges from the graph, including duplicates

    Edge arrEdges[numEdges]; // new array of edges, which does not include duplicates

    removeDuplicateEdges(arrOriginalEdges, arrEdges, &numEdges);
    sortEdges(arrEdges, numEdges);

    /* Printing output to file */
    FILE *fp = fopen(strOutputFileName, "w");

    // printing set of vertices
    fprintf(fp, "V(%c)={", strOutputFileName[0]); // first character of file name is the graph name

    for (int i = 0; i < g.numVertices; i++) {
        fprintf(fp, "%s", arrVertexIds[i]);

        // print a comma if it is not the last vertex
        if (i != g.numVertices - 1) {
            fprintf(fp, ",");
        }
    }

    fprintf(fp, "}\n");

    // printing set of edges
    fprintf(fp, "E(%c)={", strOutputFileName[0]); // first character of file name is the graph name

    for (int i = 0; i < numEdges; i++) {
        fprintf(fp, "(%s,%s)", arrEdges[i].startVertex, arrEdges[i].endVertex);

        // print a comma if it is not the last edge
        if (i != numEdges - 1) {
            fprintf(fp, ",");
        }
    }

    fprintf(fp, "}");

    fclose(fp);
}

/**
 * Produces output file #2, which contains the list of vertex IDs and their corresponding degrees.
 * 
 * @param strOutputFileName The filename where the output will be stored
 * @param g The graph
 */
void
outputDegree(char *strOutputFileName, Graph g)
{
    /* Getting the sorted list of vertices */
    char arrVertexIds[g.numVertices][9];

    getVertexIds(g, arrVertexIds);
    sortVertexIds(arrVertexIds, g.numVertices);

    FILE *fp = fopen(strOutputFileName, "w");

    for (int i = 0; i < g.numVertices; i++) {
        fprintf(fp, "%-8s %d", arrVertexIds[i], getDegreeOfVertex(g, arrVertexIds[i]));

        if (i != g.numVertices - 1) { // print \n if it is not the last vertex
            fprintf(fp, "\n");
        }
    }

    fclose(fp);
}

void
outputAdjacencyList(char *strOutputFileName, Graph *g)
{
    FILE *fp = fopen(strOutputFileName, "w");
    // traverse the linked list, print every Node until null.
    for (int i = 0; i < g->numVertices; i++) {
        Node *current = g->adjacencyList[i];
        while (current != NULL) {
            fprintf(fp, "%s->", current->name);
            current = current->next;
        }
        fprintf(fp, "\\\n");
    }

    fclose(fp);
}

bool **
createAdjacencyMatrix(Graph *g)
{
    int numVertex = g->numVertices;

    // populate matrix with 0s
    bool **matrix = calloc(sizeof(bool *), numVertex);

    for (int i = 0; i < numVertex; i++) {
        matrix[i] = calloc(sizeof(bool), numVertex);
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

void
outputAdjacencyMatrix(char *strOutputFileName, Graph *g)
{
    FILE *fp = fopen(strOutputFileName, "w");

    int numVertex = g->numVertices;

    bool **matrix = createAdjacencyMatrix(g);

    fprintf(fp, "%9s", " ");

    for (int i = 0; i < g->numVertices; i++) {
        fprintf(fp, "%9s", g->adjacencyList[i]->name);
    }
    fprintf(fp, "\n");

    for (int i = 0; i < g->numVertices; i++) {
        fprintf(fp, "%9s", g->adjacencyList[i]->name);
        for (int j = 0; j < g->numVertices; j++) {
            fprintf(fp, "%9d", matrix[i][j]);
        }
        fprintf(fp, "\n");
    }

    for (int i = 0; i < numVertex; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void
outputBFS(char *strOutputFileName, int startVertex, Graph *g)
{

    FILE *fp = fopen(strOutputFileName, "w");

    bool *visited = calloc(g->numVertices, sizeof(bool));
    // Create an array of boolean values where each index is the vertex number

    // Create a queue to store all the unvisited indices
    Queue *verticeQueue = createQueue();

    // Create adjacency matrix so the BFS is in the right order
    bool **matrix = createAdjacencyMatrix(g);

    enqueue(verticeQueue, startVertex);
    visited[startVertex] = true;

    while (!isEmpty(verticeQueue)) {
        int currentVertex = dequeue(verticeQueue);
        Node *current = g->adjacencyList[currentVertex];
        printf("[%s]", current->name);

        // Add all unvisited neighbors to the queue
        for (int i = 0; i < g->numVertices; i++) {
            if (matrix[currentVertex][i] == true && !visited[i]) {
                enqueue(verticeQueue, i);
                visited[i] = true;
            }
        }
    }

    for (int i = 0; i < g->numVertices; i++) {
        free(matrix[i]);
    }

    free(matrix);

    fclose(fp);
}

void
outputDFS(char *strOutputFileName, Graph *g)
{
    FILE *fp = fopen(strOutputFileName, "w");

    fclose(fp);
}