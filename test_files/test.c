#include "../src/outputfiles.c"
#include "../src/reader.c"

int main() {
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

    g->adjacencyMatrix = createAdjacencyMatrix(g);

    outputAdjacencyList("G-LIST.TXT", g);
    outputAdjacencyMatrix("G-MATRIX.TXT", g);
    outputSet("G-SET.TXT", *g);
    outputDegree("G-DEGREE.TXT", *g);
    outputBFS("G-BFS.TXT", g, "Clark");
    outputDFS("G-DFS.TXT", g, "Clark");
}