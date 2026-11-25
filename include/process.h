#include "types.h"
#include <stdio.h>

#ifndef PROCESS_H
#define PROCESS_H

void processPairs(IntStack *dest, int *src, size_t src_len);
void getdigits(IntStack *dest, int *src, size_t src_len);

#endif