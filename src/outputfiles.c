#include "outputfiles.h"

void 
outputAsSet(Graph *g, char *name)
{
    char file[1024];
    // copy name and add corresponding output content & file extension
    strcpy(file, name);
    strcat(file, "-LIST.txt");
    FILE *fp = fopen(file, "w");

    fclose(fp);
}

void 
outputVertexIDs(Graph *g, char *name)
{
    char file[1024];
    // copy name and add corresponding output content & file extension
    strcpy(file, name);
    strcat(file, "-LIST.txt");
    FILE *fp = fopen(file, "w");

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


   fprintf(fp, "%8s", " ");

    for (int i = 0; i < g->numVertices; i++){
       fprintf(fp, "%8s", g->adjacencyList[i]->name);
    }
   fprintf(fp, "\n");
    
    for (int i = 0; i < g->numVertices; i++){
       fprintf(fp, "%8s", g->adjacencyList[i]->name);
        for (int j = 0; j < g->numVertices; j++){
           fprintf(fp, "%8d", matrix[i][j]);
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