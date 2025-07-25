/**
 * Programmed by: Christian Gendrano
 * Tested by: Christian Gendrano
 */

#include "graph.c"

/**
 * Reads an input file containing a graph data structure. Note that the
 * parameter g is a double pointer to the graph. This is necessary because
 * the pointer to the graph is modified within the function.
 * 
 * @param strInputFileName String containing the name of the file to read
 * @param g Pointer to a pointer to the graph where the data will be stored
 * @return True if file was read successfully, false otherwise
 */
bool readInputFile(char strInputFileName[], Graph **g) {
    int numVertices;
    FILE *fp;

    fp = fopen(strInputFileName, "r");

    if (fp == NULL) {
        return false; // not able to read file
    }

    // scans first line, which is the number of vertices
    fscanf(fp, "%d", &numVertices);

    /* an array of char pointers (strings) to store the values of the text file,
       so the text file is only read once */
    char *nameArray[numVertices][numVertices + 1];
    // there are "numVertices + 1" columns because it also stores the -1

    int i, j;
    bool endOfRow; // it is the end of the row when it reaches -1

    for (i = 0; i < numVertices; i++) {
        endOfRow = false;

        for (j = 0; j < numVertices + 1 && !endOfRow; j++) {
            nameArray[i][j] = malloc(9 * sizeof(char)); // to store string of at most 8 characters
            /* also, malloc is used so the string is not deleted when the function call ends */
            fscanf(fp, "%s", nameArray[i][j]);

            if (strcmp(nameArray[i][j], "-1") == 0) {
                endOfRow = true;
            }
        }
    }

    fclose(fp);

    // now, transferring the contexts of the array to the actual graph
    *g = createGraph(numVertices);

    /* the vertices at the beginning of each linked list must be created first, because
       each vertex receives its own index number which is used when it is linked to
       by another vertex */
    for (i = 0; i < numVertices; i++) {
        createVertex(*g, i, nameArray[i][0]);
    }

    /* iterating through the rest of the array */
    for (i = 0; i < numVertices; i++) {
        endOfRow = false;

        for (j = 1; j < numVertices + 1 && !endOfRow; j++) {
            if (strcmp(nameArray[i][j], "-1") == 0) {
                free(nameArray[i][j]); // since we do not need to store -1
                endOfRow = true;
            } else {
                addEdge(*g, i, nameArray[i][j]);
            }
        }
    }
}