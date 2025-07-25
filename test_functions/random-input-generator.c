#include "../src/graph.c"
#include <time.h>

int getRandNum(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int getRandArrayIndex(int n) {
    return getRandNum(0, n - 1);
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
    char inputFilename[20], outputFilename[20];
    srand(time(NULL)); // for random numbers

    printf("Enter the file name of the list of vertex names: ");
    scanf("%s", inputFilename);

    printf("Enter the name of the output graph (preferably one letter): ");
    scanf("%s", outputFilename);
    strcat(outputFilename, ".TXT");

    FILE *fp = fopen(inputFilename, "r");

    if (fp == NULL) {
        printf("Error reading the file for input\n");
        return 1;
    }
    
    // just counting the number of lines in the file
    char buffer[200];

    int numVertices = 0;
    while (fgets(buffer, 200, fp) != NULL) {
        numVertices++;

        if (strcmp(buffer, "") == 0) {
            printf("Empty line found\n");
            numVertices--;
        }
    }
    printf("Number of vertices: %d", numVertices);

    rewind(fp); // go back to start of file

    char vertexNameArray[numVertices][9];

    for (int i = 0; i < numVertices; i++) {
        fscanf(fp, "%s", vertexNameArray[i]);
    }

    fclose(fp);

    bool adjacencyMatrix[numVertices][numVertices];

    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (i == j) {
                adjacencyMatrix[i][j] = 0;
            } else if (i > j) { // prevents redundancy
                bool randNum = rand() % 2;
                adjacencyMatrix[i][j] = randNum;
                adjacencyMatrix[j][i] = randNum;
            }
        }
    }

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