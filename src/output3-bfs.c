/**
 * Programmed by: Allen Hizon
 * Tested by: Allen Hizon
 */
#include <stdbool.h>
#include <stdio.h>

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