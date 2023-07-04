#include "stackinc.h"

#include <stdlib.h>
#include <stdio.h>

#define error(param) fprintf(stderr, param)

stackptr get(unsigned max_elements)
{
    stackptr instance = (stackptr) malloc(sizeof(stack));
    instance->elements = (int *) malloc(max_elements * sizeof(int));
    instance->max_elements = max_elements;
    instance->index = 0;
    return instance;
}

void push(stackptr stack, int elem)
{
    if (stack->max_elements > stack->index) {
        stack->elements[stack->index++] = elem;
    } else {
        fprintf(stderr, "Error: Stack size (%d) is higher or equals current index (%d)!\n", stack->max_elements, stack->index);
    }
}

int peek(stackptr stack)
{
    if (stack->index) {
        return stack->elements[stack->index - 1];
    } else {
        error("Error. Stack is empty!\n");
        return 0;
    }
}

void pop(stackptr stack)
{
    if (stack->index > 0) {
        stack->index--;
    } else {
        error("Error: Stack is empty!\n");
    }
}

void finalize(stackptr stack)
{
	free(stack->elements);
}

#undef error
