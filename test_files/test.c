#include "../src/outputfiles.c"

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

    outputSet("G-SET.TXT", *g);
    outputDegree("G-DEGREE.TXT", *g);
    outputAdjacencyList("G-LIST.TXT", g);
    outputAdjacencyMatrix("G-MATRIX.TXT", g);
    outputBFS("G-BFS.TXT", 3, *g);
    // Idk if the BFS function is supposed to turn "Clark" into ID 3 or
    // it's supposed to search until "Clark" is found as an index or another function
    // can search for clark's index and pass it to the BFS function.
}