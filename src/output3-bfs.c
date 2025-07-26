/**
 * Programmed by: Allen Hizon
 * Tested by: Allen Hizon
 */
#include <stdbool.h>
#include <stdio.h>
#define MAX_VERTICES 20

// Queue of vertices using an array
typedef struct {
    int front;
    int rear;
    int vertices[MAX_VERTICES];
} Queue;

Queue *
createQueue()
{

    Queue *q = malloc(sizeof(Queue));
    
    if (q == NULL) {
        printf("\nMemory allocation error for queue!");
        return NULL;
    }

    q->front = 0;
    q->rear = 0;

    return q;
}

bool
isEmpty(Queue *q)
{
    return (q->front == q->rear);
}

bool
isFull(Queue *q)
{
    return (q->rear == MAX_VERTICES);
}

void
enqueue(Queue *q, int value)
{
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }

    q->vertices[q->rear] = value;
    q->rear++;
}

int
dequeue(Queue *q)
{
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }

    int val = q->vertices[q->front];
    q->front++;

    if (isEmpty(q)) {
        q->front == 0;
        q->rear == 0;

        // Reset to 0 so front and rear don't get too big when the queue is emptied
    }
    return val;
}

void
printQueue(Queue *q)
{
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Current Queue: ");
    for (int i = q->front; i < q->rear - 1; i++) {
        printf("%d ", q->vertices[i]);
    }
    printf("\n");
}

bool
isVisited(int vertexID, bool vertexList[])
{
    return vertexList[vertexID];
}

void
insertionSort(int *array, int start, int n)
{
    int i, j, key;
    for (i = start + 1; i < n; i++) {
        key = array[i];
        j = i - 1;

        while (j >= start && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }

        array[j + 1] = key;
    }
}

void
sortQueue(Queue *q)
{
    if (!isEmpty(q)) {
        insertionSort(q->vertices, q->front, q->rear);
    }
}