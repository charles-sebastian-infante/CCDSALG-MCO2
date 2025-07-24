/**
 * Programmed by:
 * Tested by:
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "graph.c"

int readInputFile(char* inputFileName, Graph* graph) {

    char buffer[1024];

    FILE* inputFile = fopen(inputFileName, "r");
    
    if (inputFile == NULL) {
        printf("File <%s> not found", inputFileName);
        return EXIT_FAILURE;
    }

}


int main(void) {

    char buffer[1024];
    char* inputFileName;
    Graph* test;

    printf("Enter the file name: ");
    scanf("%1023s", buffer); // scan a max of 1023 characters to prevent buffer overflow

    inputFileName = malloc(strlen(buffer) + 1);
    strcpy(inputFileName, buffer);

    readInputFile(inputFileName, test);

    free(inputFileName);
    return 0;
}