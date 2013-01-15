#include <stdio.h>
#include <math.h>
#include <stdlib.h>

unsigned int ilogn(unsigned int i, unsigned int n) {
	return log(i) / log(n);
}

unsigned int z(unsigned int n) {
	unsigned int power = ilogn(n, 5);
	unsigned int sum = 0;
	unsigned int i;
	for(i = 1; i <= power; i++) {
		sum += n / pow(5.0, (double) i);
	}
	return sum;
}

int main() {
	unsigned int t;
	scanf("%u", &t);
	for(t; t > 0; t--) {
		unsigned int n;
		scanf("%u", &n);
		printf("%u\n", z(n));
	}
	return 0;
}
