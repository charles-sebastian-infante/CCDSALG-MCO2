#include "../src/graph.c"
#include <time.h>

/* Note: Despite the name of the file, this actually generates a graph that the original graph is a subgraph of
         (as opposed to a graph that is a subgraph of the original graph) */

#define INPUT_GRAPH_NAME 'A' // name of input graph (preferably one letter) - don't include .txt
#define OUTPUT_GRAPH_NAME 'C' // name of output graph (preferably one letter)
#define PERCENT 25 // percent chance that an edge connects any two vertices that were previously not connected

int getRandNum(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int getRandArrayIndex(int n) {
    return getRandNum(0, n - 1);
}

bool percentChance(int percent) {
    return getRandNum(1, 100) <= percent;
}

int convertNameToIndex(char name[], char nameArray[][9], int n) {
    for (int i = 0; i < n; i++) {
        if (strcmp(name, nameArray[i]) == 0) {
            return i;
        }
    }

    return -1;
}

void resetBoolArray(bool arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = false;
    }
}

bool isArrayAllTrue(bool arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (!arr[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    if (INPUT_GRAPH_NAME == OUTPUT_GRAPH_NAME) {
        printf("Error: Input and output graph names should be different!");
        return 1;
    }

    srand(time(NULL)); // for random numbers

    char inputFilename[] = "#.TXT";
    inputFilename[0] = INPUT_GRAPH_NAME;

    FILE *fp = fopen(inputFilename, "r");

    if (fp == NULL) {
        printf("Error reading the file for input\n");
        return 1;
    }

    int numVertices;
    fscanf(fp, "%d", &numVertices);

    char vertexNameArray[numVertices][9];
    char buffer[400];

    for (int i = 0; i < numVertices; i++) {
        fscanf(fp, "%s", vertexNameArray[i]);
        fgets(buffer, 400, fp); // just go to next line
    }

    rewind(fp);
    fgets(buffer, 400, fp); // ignore first line (number of vertices)

    bool adjacencyMatrix[numVertices][numVertices];

    // initializing everything to false at first
    for (int i = 0; i < numVertices; i++) {
        resetBoolArray(adjacencyMatrix[i], numVertices);
    }

    char vertexName[9];
    for (int i = 0; i < numVertices; i++) {
        do {
            fscanf(fp, "%s", vertexName);

            if (strcmp(vertexName, vertexNameArray[i]) != 0 && strcmp(vertexName, "-1") != 0) {
                int index = convertNameToIndex(vertexName, vertexNameArray, numVertices);
                adjacencyMatrix[i][index] = true;
            }
        } while (strcmp(vertexName, "-1") != 0);
    }

    fclose(fp);

    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (i > j && adjacencyMatrix[i][j] == false) {
                // adding some edges but not removing any
                bool randBool = percentChance(PERCENT);
                adjacencyMatrix[i][j] = randBool;
                adjacencyMatrix[j][i] = randBool;
            }
        }
    }

    char outputFilename[6] = "#.TXT";
    outputFilename[0] = OUTPUT_GRAPH_NAME;

    fp = fopen(outputFilename, "w");

    if (fp == NULL) {
        printf("Error reading the file for output\n");
        return 1;
    }

    fprintf(fp, "%d\n", numVertices); // first thing to print is the number of vertices

    bool rowsDone[numVertices]; // take note of whether the row has been printed already
    bool colsDone[numVertices]; // take note of whether the column has been printed already

    resetBoolArray(rowsDone, numVertices);
    int randomRow, randomCol;

    while (!isArrayAllTrue(rowsDone, numVertices)) {
        resetBoolArray(colsDone, numVertices);

        do {
            randomRow = getRandArrayIndex(numVertices);
        } while (rowsDone[randomRow]); // get another random row if that row is done

        fprintf(fp, "%s ", vertexNameArray[randomRow]); // print name of "main" vertex

        while (!isArrayAllTrue(colsDone, numVertices)) {
            do {
                randomCol = getRandArrayIndex(numVertices);
            } while (colsDone[randomCol]);

            if (adjacencyMatrix[randomRow][randomCol]) {
                fprintf(fp, "%s ", vertexNameArray[randomCol]);
            }

            colsDone[randomCol] = true;
        }

        rowsDone[randomRow] = true;

        fprintf(fp, "-1\n");
    }
    
    fclose(fp);

    return 0;
}