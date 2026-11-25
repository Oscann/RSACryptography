#ifndef TYPES_H
#define TYPES_H

typedef struct SStringLinkedListNode {
    char text[5];
    struct SStringLinkedListNode * next;
} StringLinkedListNode;

typedef struct {
    int length;
    StringLinkedListNode * head;
    StringLinkedListNode * tail;
} StringLinkedList;

typedef struct SIntStackNode {
    struct SIntStackNode * next;
    int value;
} IntStackNode;

typedef struct {
    int length;
    IntStackNode * top;
} IntStack;


#endif