//
// Created by izual on 2020/6/9.
//
// Euclid's algorithm (recursive version) ... COMP9024 20T2

#include <stdio.h>

int euclid_gcd(int m, int n) {
    if (n == 0) {
        return m;
    } else {
        return euclid_gcd(n, m % n);
    }
}

int main(void) {

    printf("%d\n", euclid_gcd(30,18));
    return 0;
}
