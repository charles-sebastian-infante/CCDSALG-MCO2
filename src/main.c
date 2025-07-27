/**
 * Programmed by: Christian Gendrano, Charles Infante, and Allen Hizon
 * Tested by: Christian Gendrano, Charles Infante, and Allen Hizon
 */

#include "outputfiles.c"
#include "reader.c"

int main() {
    char inputFileName[9];

    printf("Input filename:");
    scanf("%s", inputFileName);

    bool fileReadSuccessfully, startVertexFound;
    Graph *g;

    fileReadSuccessfully = readInputFile(inputFileName, &g);

    if (!fileReadSuccessfully) {
        printf("File %s not found.", inputFileName);
    } else {
        char graphName = inputFileName[0]; // graph name is first character in file name

        char output1FileName[10] = "#-SET.TXT";
        output1FileName[0] = graphName;
        char output2FileName[13] = "#-DEGREE.TXT";
        output2FileName[0] = graphName;
        char output3FileName[11] = "#-LIST.TXT";
        output3FileName[0] = graphName;
        char output4FileName[13] = "#-MATRIX.TXT";
        output4FileName[0] = graphName;
        char output5FileName[10] = "#-BFS.TXT";
        output5FileName[0] = graphName;
        char output6FileName[10] = "#-DFS.TXT";
        output6FileName[0] = graphName;

        outputSet(output1FileName, *g);                 // output 1
        outputDegree(output2FileName, *g);           // output 2
        outputAdjacencyList(output3FileName, g);       // output 3
        outputAdjacencyMatrix(output4FileName, g);   // output 4
        char startVertex[9];

        printf("Input start vertex for the traversal: ");
        scanf("%s", startVertex);
        startVertexFound = true; // TODO make this based on BFS/DFS later

        if (!startVertexFound) {
            printf("Vertex %s not found.", startVertex);
        } else {
            outputBFS(output5FileName, g, startVertex);
            // TODO put DFS here
        }
    }
    
    return 0;
}