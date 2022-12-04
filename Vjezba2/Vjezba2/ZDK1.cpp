#include<stdio.h>
#include<stdlib.h>

int* podniz(int* niz, int start, int stop) {
	int i = 0;
	int* pniz = (int*)malloc((stop - start )* sizeof(int));
	for (start; start < stop; start++, i++) {
		pniz[i] = niz[start];
	}
	return pniz;
}

int main() {
	int start, stop;
	int niz[] = { 1,2,3,4,5,6,7,8,9,10 };
	scanf("%d %d", &start, &stop);
	int* pniz = podniz(niz, start, stop);

	if (stop < start) return 1;

	if (stop > sizeof(niz)) return 1;

	int i = 0;
	for (i; i < (stop - start); i++) {
		printf("%d\n", pniz[i]);
	}

	return 0;
}