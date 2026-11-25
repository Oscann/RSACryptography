#include "types.h"
#include "stdio.h"

#ifndef LIST_H
#define LIST_H

void split(StringLinkedList *dest, char text[]);

// Move to different module
void processPairs(IntStack *dest, int *src, size_t src_len);
void getdigits(IntStack *dest, int *src, size_t src_len);

void add(StringLinkedList *dest, char text[]);

void destroyList(StringLinkedList *list);

void printList(StringLinkedList *list);

#endif