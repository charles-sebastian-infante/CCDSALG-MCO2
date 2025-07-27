/**
 * Programmed by: Allen Hizon
 * Tested by: Allen Hizon
 */
#include "graph.h"
#include <stdbool.h>
#include <stdio.h>

// Stack of vertices using an array
typedef struct {
    int top;
    int vertices[MAX_VERTICES];
} Stack;

Stack *
createStack()
{
    Stack *s = malloc(sizeof(Stack));
    s->top = -1;
    return s;
}

bool
isFull(Stack *s)
{
    return s->top >= MAX_VERTICES - 1;
}

bool
isEmpty(Stack *s)
{
    return s->top == -1;
}

void
push(Stack *s, int value)
{
    if (isFull(s)) {
        printf("The stack is full.") return;
    }
    s->top++;
    s->vertices[s->top] = value;
}

int
pop(Stack *s)
{
    if (isEmpty(s)) {
        printf("The stack is empty.");
        return -1;
    }

    int value = s->vertices[s->top];
    s->top--;
    return value;
}
