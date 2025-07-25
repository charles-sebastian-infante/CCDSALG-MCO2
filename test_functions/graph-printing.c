#include "..\src\graph.c"

void printGraph(Graph g) {
    Node *current;
    char nameAndNodeIndex[15];

    for (int i; i < g.numVertices; i++) {
        current = g.adjacencyList[i];
        sprintf(nameAndNodeIndex, "%s(%d)", current->name, current->nodeIndex);
        printf("%-12s", nameAndNodeIndex);

        while (current->next != NULL) {
            current = current->next;
            sprintf(nameAndNodeIndex, "%s(%d)", current->name, current->nodeIndex);
            printf("%-12s", nameAndNodeIndex);
        }

        printf("\n");
    }
}