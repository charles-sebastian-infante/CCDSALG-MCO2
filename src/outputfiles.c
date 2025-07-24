#include "outputfiles.h"

#include "o1-vertices-and-edges.c"
#include "o2-degree.c"

/**
 * Produces output file #1, which contains the set of vertices and the set of edges in alphabetical order.
 * 
 * @param g The graph of the file
 * @param name String containing the name of the graph
 */
void outputSet(Graph g, char *name)
{
    /* Getting the sorted list of vertices */
    char arrVertexIds[g.numVertices][9];

    getVertexIds(g, arrVertexIds);
    sortVertexIds(arrVertexIds, g.numVertices);

    /* Getting the sorted list of edges */
    int numEdges;
    int maxEdges = g.numVertices * (g.numVertices - 1); /* maximum number of edges (including duplicates),
                                                           to be used in the array declaration */
    Edge arrOriginalEdges[maxEdges]; // original array of edges, which includes duplicate edges

    numEdges = getEdges(g, arrOriginalEdges); // gets edges from the graph, including duplicates

    Edge arrEdges[numEdges]; // new array of edges, which does not include duplicates

    removeDuplicateEdges(arrOriginalEdges, arrEdges, &numEdges);
    sortEdges(arrEdges, numEdges);
    
    /* Printing output to file */
    char file[1024];
    // copy name and add corresponding output content & file extension
    strcpy(file, name);
    strcat(file, "-SET.txt");
    FILE *fp = fopen(file, "w");

    // printing set of vertices
    fprintf(fp, "V(%s)={", name);

    for (int i = 0; i < g.numVertices; i++) {
        fprintf(fp, "%s", arrVertexIds[i]);

        // print a comma if it is not the last vertex
        if (i != g.numVertices - 1) {
            fprintf(fp, ",");
        }
    }

    fprintf(fp, "}\n");

    // printing set of edges
    fprintf(fp, "E(%s)={", name);

    for (int i = 0; i < numEdges; i++) {
        fprintf(fp, "(%s,%s)", arrEdges[i].startVertex, arrEdges[i].endVertex);

        // print a comma if it is not the last vertex
        if (i != g.numVertices - 1) {
            fprintf(fp, ",");
        }
    }

    fprintf(fp, "}");

    fclose(fp);
}

void 
outputDegree(Graph g, char *name)
{
    /* Getting the sorted list of vertices */
    char arrVertexIds[g.numVertices][9];

    getVertexIds(g, arrVertexIds);
    sortVertexIds(arrVertexIds, g.numVertices);

    char file[1024];
    // copy name and add corresponding output content & file extension
    strcpy(file, name);
    strcat(file, "-DEGREE.txt");
    FILE *fp = fopen(file, "w");

    for (int i = 0; i < g.numVertices; i++) {
        fprintf(fp, "%-8s %d", arrVertexIds[i], getDegreeOfVertex(g, arrVertexIds[i]));

        if (i != g.numVertices - 1) { // print \n if it is not the last vertex
            fprintf(fp, "\n");
        }
    }

    fclose(fp);
}

void 
outputAdjacencyList(Graph *g, char *name)
{
    char file[1024];
    // copy name and add corresponding output content & file extension
    strcpy(file, name);
    strcat(file, "-LIST.txt");
    FILE *fp = fopen(file, "w");
    // traverse the linked list, print every Node until null.
    for (int i = 0; i < g->numVertices; i++){
        Node *current = g->adjacencyList[i];
            while (current != NULL) {
            fprintf(fp, "%s->", current->name);
            current = current->next;
        }
    fprintf(fp, "\\\n");
    }

    fclose(fp);
}

void 
outputAdjacencyMatrix(Graph *g, char *name)
{
    char file[1024];
    // copy name and add corresponding output content & file extension
    strcpy(file, name);
    strcat(file, "-MATRIX.txt");
    FILE *fp = fopen(file, "w");

    int numVertex = g->numVertices;

    // populate matrix with 0s
    bool** matrix = calloc(sizeof(bool*), numVertex);

    for (int i = 0; i < numVertex; i++){
        matrix[i] = calloc(sizeof(bool), numVertex);
    }
    
    // populate matrix with necessary values
    for (int i = 0; i < numVertex; i++){
        Node *current = g->adjacencyList[i];

        // note that since the initial node is itself, there will never be an edge from self-self.
        while (current->next != NULL){
            current = current->next;
            matrix[i][current->nodeIndex] = true;
        } 
    }


   fprintf(fp, "%9s", " ");

    for (int i = 0; i < g->numVertices; i++){
       fprintf(fp, "%9s", g->adjacencyList[i]->name);
    }
   fprintf(fp, "\n");
    
    for (int i = 0; i < g->numVertices; i++){
       fprintf(fp, "%9s", g->adjacencyList[i]->name);
        for (int j = 0; j < g->numVertices; j++){
           fprintf(fp, "%9d", matrix[i][j]);
        }
       fprintf(fp, "\n");
    }

}

void 
outputBFS(Graph *g, char *name)
{
    char file[1024];
    // copy name and add corresponding output content & file extension
    strcpy(file, name);
    strcat(file, "-LIST.txt");
    FILE *fp = fopen(file, "w");

    fclose(fp);
}

void 
outputDFS(Graph *g, char *name)
{
    char file[1024];
    // copy name and add corresponding output content & file extension
    strcpy(file, name);
    strcat(file, "-DFS.txt");
    FILE *fp = fopen(file, "w");

    fclose(fp);
}