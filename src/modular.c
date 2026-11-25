#include "modular.h"
#include <stdio.h>

int mod(int n, int b) {
    return n - (n / b) * b;
}

int powmod(int a, int e, int n) {
    int res = 1;

    for (int i = 0 ; i < e; i++) {
        res *= a;

        if (res >= n) res = mod(res, n);
    }
    
    return res;
}
