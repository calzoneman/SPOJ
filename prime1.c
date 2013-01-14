#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool isprime(int p) {
    if(p == 1)
        return false;
    if(p == 2)
        return true;
    if(p % 2 == 0)
        return false;
    int i;
    for(i = 3; p * p <= i; i += 2) {
        if(p % i == 0 && p != i)
            return false;
    }
    return true;
}

void primes(int m, int n) {
    int *cache = calloc((n - m + 1), sizeof(int));
    int p;
    for(p = 2; p * p <= n; p++) {
        if(!isprime(p))
            continue;
        int i = m / p;
        i *= p;
        int j;
        for(j = i; j <= n; j += p) {
            if(j - m >= 0 && j != p) {
                cache[j - m] = 1;
            }
        }
    }
    for(p = 0; p <= n - m; p++) {
        if(cache[p] == 0 && p + m != 1)
            printf("%d\n", p + m);
    }
}

int main() {

    int t;
    scanf("%d", &t);
    int i;
    for(i = 0; i < t; i++) {
        int m, n;
        scanf("%d %d", &m, &n);
        primes(m, n);
        printf("\n");
    }

    return 0;
}
