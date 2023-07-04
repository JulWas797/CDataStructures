#pragma once

typedef struct stack {
    unsigned index;
    unsigned max_elements;
    int *elements;
} stack, *stackptr;

stackptr get(unsigned);

void push(stackptr, int);

void pop(stackptr);

int peek(stackptr);