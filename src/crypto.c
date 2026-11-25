#include "crypto.h"

#define TABLE "ABCDEFGHIJKLMNOPQRSTUVWXYZ .,!?"

int index_table(int n) {
    return n - 10 - (n / 10);
}

char decrypto(int c) {
    int charn = index_table(c);

    return TABLE[charn];
}
