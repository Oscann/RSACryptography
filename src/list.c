#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "types.h"
#include "list.h"
#include "stack.h"
#include "process.h"

void split(StringLinkedList *dest, char text[]) {
    char *tmp = text;
    char *end = text + strlen(text);
    char toAdd[5];
    int count = 0;

    while (tmp <= end) {
        if (*tmp != '-' && *tmp != '\0') {
            count++;
        } else {
            if (count < 4) {
                for (int i = 0; i < 4 - count; i++) {
                    toAdd[i] = '0';
                }
            }

            strncpy(&toAdd[4 - count], tmp - count, count);
            toAdd[4] = '\0';

            add(dest, toAdd);
            count = 0;
        }

        tmp++;
    }
}

void add(StringLinkedList *dest, char text[]) {
    StringLinkedListNode* newNode = (StringLinkedListNode*) malloc(sizeof(StringLinkedListNode));

    if (newNode == NULL) {
        printf("Error: couldn't find memory");
        return;
    }

    strcpy(newNode->text, text);

    if (dest->head == NULL) dest->head = newNode;
    if (dest->tail != NULL) dest->tail->next = newNode;
    dest->tail = newNode;
    dest->length++;
}

void destroyList(StringLinkedList *list) {
    StringLinkedListNode *node = list->head;

    while (node != NULL) {
        StringLinkedListNode * tmp = node;
        node = node->next;

        free(tmp);
    }

    list->head = NULL;
    list->tail = NULL;
}

void printList(StringLinkedList *list) {
    StringLinkedListNode *node = list->head;

    while (node != NULL) {
        printf("%s\n", node->text);
        node = node->next;
    }
}