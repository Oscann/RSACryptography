#include "types.h"
#include "stack.h"
#include "stdio.h"
#include "stdlib.h"

void addToStack(IntStack *dest, int n) {
    IntStackNode *newNode = (IntStackNode *) malloc(sizeof(IntStackNode));
    newNode->next = NULL;
    newNode->value = n;

    if (dest->top != NULL) {
        newNode->next = dest->top;
    }
    dest->top = newNode;
    dest->length++;
}

int pop(IntStack *src) {
    if (src->length == 0) return -1;

    IntStackNode *topNode = src->top;

    src->top = topNode->next;
    src->length--;

    int n = topNode->value;
    
    free(topNode);

    return n;
}

void printStack(IntStack *s) {
    if (s->length == 0) {
        printf("No elements to prinit in the stack.\n");
        return;
    }

    IntStackNode *head = s->top;

    printf("Printing stack:\n");

    while (head != NULL) {
        printf("%d\n", head->value);

        head = head->next;
    }
}