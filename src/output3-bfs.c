/**
 * Programmed by: Allen Hizon
 * Tested by: Allen Hizon
 */
#include "graph.h"
#include <stdbool.h>
#include <stdio.h>

// Queue of vertices using an array
typedef struct {
    int front;
    int rear;
    int vertices[MAX_VERTICES];
} Queue;

/**
 * Creates an empty queue.
 * 
 * @return Pointer to the queue
 */
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

/**
 * Checks if the queue is empty.
 * 
 * @param q Pointer to the queue
 * @return True if the queue is empty, false otherwise
 */
bool
isEmpty(Queue *q)
{
    return (q->front == q->rear);
}

/**
 * Checks if the queue is full.
 * 
 * @param q Pointer to the queue
 * @return True if the queue is full, false otherwise
 */
bool
isFull(Queue *q)
{
    return (q->rear == MAX_VERTICES);
}

/**
 * Adds an element to the rear of the queue.
 * 
 * @param q Pointer to the queue
 * @param value Element to add
 */
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

/**
 * Removes and returns an element from the front of the queue.
 * 
 * @param q Pointer to the queue
 * @return Element at the front
 */
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
        q->front = 0;
        q->rear = 0;
        // Reset to 0 so front and rear don't get too big when the queue is emptied
    }
    
    return val;
}