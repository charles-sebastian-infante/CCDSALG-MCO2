#include "../src/outputfiles.c"
#include "../src/reader.c"
#include "../test_functions/graph-printing.c"

int main() {
    /*
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
    */

    Graph *g;
    readInputFile("../text_files/G.txt", &g);

    outputAdjacencyList("G-LIST.TXT", g);
    outputAdjacencyMatrix("G-MATRIX.TXT", g);
    outputSet("G-SET.TXT", *g);
    outputDegree("G-DEGREE.TXT", *g);

    printGraph(*g);
}