#include <stdio.h>
#include "types.h"
#include "modular.h"
#include "list.h"
#include "stdlib.h"
#include "crypto.h"
#include "stack.h"
#include "process.h"

#define N 3763
#define D 2519
#define ENCRYPTED_TEXT "334-2991-2817-2038-3217-982-1129-1414-190-843-3625-2350-3437-550-2441-1751-3217-2380-3437-1543-2817-2563-2441-1"

int main() {
    StringLinkedList groupsList;
    IntStack pairStack, reversedStack;

    split(&groupsList, ENCRYPTED_TEXT);

    StringLinkedListNode *head = groupsList.head;

    int decryptedNs[groupsList.length];
    int i = 0;

    // Raise every group to D and calculates the module
    while (head != NULL) {
        int n = atoi(head->text);
        int d = powmod(n, D, N);
        decryptedNs[i++] = d;

        head = head->next;
    }

    // Seperate the digits in pairs
    processPairs(&pairStack, decryptedNs, i);

    // Reverse the stack
    while (pairStack.length > 0) {
        addToStack(&reversedStack, pop(&pairStack));
    }

    // Translate the characteres based in the table given by the professor
    while (reversedStack.length > 0) {
        // Output: SISTEMA GERA RELATORIOS AUTOMATICOS
        printf("%c", decrypto(pop(&reversedStack)));
    }

    printf("\n");

    return 0;
}