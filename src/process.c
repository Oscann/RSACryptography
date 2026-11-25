#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include "process.h"
#include "stack.h"

void processPairs(IntStack *dest, int *src, size_t src_len) {
    if (src_len == 0) {
        printf("No elements to process pair");
        return;
    }

    IntStack *digits = (IntStack *) malloc(sizeof(IntStack));

    digits->length = 0;
    digits->top = NULL;

    getdigits(digits, src, src_len);

    int pairbuffer[2];
    int buffer_length = 0;

    while (digits->length > 0) {
        pairbuffer[buffer_length++] = pop(digits);

        if (buffer_length >= 2) {
            addToStack(dest, pairbuffer[0] * 10 + pairbuffer[1]);
            buffer_length = 0;
        }
    }

    // Fix this: free each node
    free(digits);
}

void getdigits(IntStack *dest, int *src, size_t src_len) {
    for (int i = 1; i <= src_len; i++) {
        int n = src[src_len - i];

        while (n > 0) {
            addToStack(dest, n % 10);
            n /= 10;
        }
    }
}