#include <stdio.h>
#include <stdlib.h>

void heapify(char *a, int root, int bottom);

// From <http://www.algorithmist.com/index.php/Heap_sort.c>
inline void hsort(char *a, int size) {
	register i;
	char temp;
	for(i = size / 2; i >= 0; i--)
		heapify(a, i, size - 1);

	for(i = size - 1; i >= 1; i--) {
		temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		heapify(a, 0, i - 1);
	}
}

inline void heapify(char *a, int root, int bottom) {
	register maxChild = root * 2 + 1;
	if(maxChild < bottom) {
		int otherChild = maxChild + 1;
		maxChild = (a[otherChild] > a[maxChild]) ? otherChild : maxChild;
	}
	else if(maxChild > bottom)
		return;

	if(a[root] >= a[maxChild])
		return;

	char temp = a[root];
	a[root] = a[maxChild];
	a[maxChild] = temp;

	heapify(a, maxChild, bottom);
}


int jnext(char *src, int len) {
	int i, idx;
	// Store the last seen index of each digit
	int indexes[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

	int smallest = 10, smallestidx;
	int swapidx;
	for(i = len - 1; i >= 0; i--) {
		if(i - 1 < 0)
			return 0;
		indexes[src[i]] = i;
		int prev = src[i - 1];
		if(src[i] > prev) {
			swapidx = i - 1;
			break;
		}
	}

	// Check all digits starting at the next greatest one after the one
	// to be swapped for an index past the swap index
	for(i = src[swapidx] + 1; i < 10; i++) {
		if(indexes[i] > swapidx) {
			src[indexes[i]] = src[swapidx];
			src[swapidx] = i;
			break;
		}
	}

	idx = swapidx + 1;
	// inlined heapsort is apparently faster than qsort for this
	// case
	hsort(src + idx, len - idx);
	return 1;
}

int main() {
	int t;
	scanf("%d", &t);
	for(;t > 0; t--) {
		int n;
		scanf("%d", &n);
		char *src = calloc(n, sizeof(char));
		int i;
		for(i = 0; i < n; i++) {
			scanf("%d", src + i);
		}
		if(jnext(src, n)) {
			for(i = 0; i < n; i++) {
				printf("%d", src[i]);
			}
			printf("\n");
		}
		else {
			printf("-1\n");
		}
	}
	return 0;
}
