/**
 * Programmed by: Christian Gendrano
 * Tested by: Christian Gendrano
 */

#include "output1-set.c"
#include "reader.c"
#include "graph.c"

int main() {
    // input data for graph 1
    char graph1FileName[9];
    Graph *graph1;
    
    printf("Input graph 1 filename: ");
    scanf("%s", graph1FileName);

    bool graph1FileRead = readInputFile(graph1FileName, &graph1);

    if (!graph1FileRead) {
        printf("File %s not found.", graph1FileName);
        return 0;
    }

    char graph1Name = graph1FileName[0]; // graph name is the first character of the filename

    // input data for graph 2
    char graph2FileName[9];
    Graph *graph2;

    printf("Input graph 2 filename: ");
    scanf("%s", graph2FileName);

    bool graph2FileRead = readInputFile(graph2FileName, &graph2);

    if (!graph2FileRead) {
        printf("File %s not found.", graph2FileName);
        return 0;
    }

    char graph2Name = graph2FileName[0];
    
    // get and sort vertices from first graph
    int numGraph1Vertices = graph1->numVertices;
    char arrGraph1Vertices[numGraph1Vertices][9];
    getVertexIds(*graph1, arrGraph1Vertices);
    sortVertexIds(arrGraph1Vertices, numGraph1Vertices);

    // get and sort vertices from second graph
    int numGraph2Vertices = graph2->numVertices;
    char arrGraph2Vertices[numGraph2Vertices][9];
    getVertexIds(*graph2, arrGraph2Vertices);
    sortVertexIds(arrGraph2Vertices, numGraph2Vertices);

    // get and sort edges from first graph
    int numGraph1Edges;
    int maxGraph1Edges = numGraph1Vertices * (numGraph1Vertices - 1);
    Edge arrGraph1OriginalEdges[maxGraph1Edges]; // includes duplicate edges
    numGraph1Edges = getEdges(*graph1, arrGraph1OriginalEdges);
    Edge arrGraph1Edges[numGraph1Edges]; // does not include duplicate edges
    removeDuplicateEdges(arrGraph1OriginalEdges, arrGraph1Edges, &numGraph1Edges);
    sortEdges(arrGraph1Edges, numGraph1Edges);

    // get and sort edges from second graph
    int numGraph2Edges;
    int maxGraph2Edges = numGraph2Vertices * (numGraph2Vertices - 1);
    Edge arrGraph2OriginalEdges[maxGraph2Edges]; // includes duplicate edges
    numGraph2Edges = getEdges(*graph2, arrGraph2OriginalEdges);
    Edge arrGraph2Edges[numGraph2Edges]; // does not include duplicate edges
    removeDuplicateEdges(arrGraph2OriginalEdges, arrGraph2Edges, &numGraph2Edges);
    sortEdges(arrGraph2Edges, numGraph2Edges);

    // open output file
    char outputFileName[17] = "#-#-SUBGRAPH.TXT"; // '#'s are placeholders
    outputFileName[0] = graph1Name; // replacing first # with name of graph 1
    outputFileName[2] = graph2Name; // replacing second # with name of graph 2

    FILE *fp = fopen(outputFileName, "w");

    // print and check if vertices from second graph match first graph
    bool isSubgraph = true;

    char result; // either plus (+) or minus (-)
    bool resultObtained;

    int graph1VertexIndex, graph2VertexIndex;
    int vertexComparison; // result of the comparison between the two vertices

    graph1VertexIndex = 0;
    for (graph2VertexIndex = 0; graph2VertexIndex < numGraph2Vertices; graph2VertexIndex++) {
        resultObtained = false;

        while (!resultObtained) {
            if (graph1VertexIndex < numGraph1Vertices) {
                vertexComparison = strcmp(arrGraph1Vertices[graph1VertexIndex], arrGraph2Vertices[graph2VertexIndex]);

                if (vertexComparison == 0) {
                    // case 1: already matching
                    result = '+';
                    resultObtained = true;
                    graph1VertexIndex++;
                } else if (vertexComparison < 0) {
                    /* case 2: not matching, but the current vertex in the first graph comes before the current
                       vertex in the second graph */
                    graph1VertexIndex++;
                } else {
                    /* case 3: not matching, and the current vertex in the first graph comes after the current
                       vertex in the second graph, meaning the vertex is not in the first graph */
                    result = '-';
                    resultObtained = true;
                    isSubgraph = false; // any vertex that is not found means it is not a subgraph
                }
            } else {
                // case 4: all vertices in graph 1 have been checked already
                result = '-';
                resultObtained = true;
                isSubgraph = false;
            }
        }

        fprintf(fp, "%s %c\n", arrGraph2Vertices[graph2VertexIndex], result);
    }

    // print and check if edges from second graph match first graph
    int graph1EdgeIndex, graph2EdgeIndex;
    int edgeComparison; // result of the comparison between the two edges

    graph1EdgeIndex = 0;
    for (graph2EdgeIndex = 0; graph2EdgeIndex < numGraph2Edges; graph2EdgeIndex++) {
        resultObtained = false;

        while (!resultObtained) {
            if (graph1EdgeIndex < numGraph1Edges) {
                edgeComparison = compareEdges(arrGraph1Edges[graph1EdgeIndex], arrGraph2Edges[graph2EdgeIndex]);

                if (edgeComparison == 0) {
                    // case 1: already matching
                    result = '+';
                    resultObtained = true;
                    graph1EdgeIndex++;
                } else if (edgeComparison < 0) {
                    /* case 2: not matching, but the current edge in the first graph comes before the current
                       edge in the second graph */
                    graph1EdgeIndex++;
                } else {
                    /* case 3: not matching, and the current edge in the first graph comes after the current
                       edge in the second graph, meaning the edge is not in the first graph */
                    result = '-';
                    resultObtained = true;
                    isSubgraph = false; // any edge that is not found means it is not a subgraph
                }
            } else {
                // case 4: all edges in graph 1 have been checked already
                result = '-';
                resultObtained = true;
                isSubgraph = false;
            }
        }

        fprintf(fp, "(%s,%s) %c\n", arrGraph2Edges[graph2EdgeIndex].startVertex,
                arrGraph2Edges[graph2EdgeIndex].endVertex, result);
    }

    // finally, print result
    if (isSubgraph) {
        fprintf(fp, "%c is a subgraph of %c.", graph2Name, graph1Name);
    } else {
        fprintf(fp, "%c is not a subgraph of %c.", graph2Name, graph1Name);
    }

    fclose(fp);

    freeGraph(graph1);
    freeGraph(graph2);

    return 0;
}