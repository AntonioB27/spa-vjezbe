#include<stdio.h>
#include<stdlib.h>

int** podijeli(int* niz, int n) {
	int** arr;
	int i;
	arr = (int**)malloc(2 * sizeof(int*));
	arr[0] = (int*)malloc(n/2 * sizeof(int));
	arr[1] = (int*)malloc(n / 2 * sizeof(int));
	
	for (i = 0; i < n / 2; i++) {
		arr[0][i] = niz[i];
	}

	int j = i;

	for (i=0; i < n; i++,j++) {
		arr[1][i] = niz[j];
	}

	return arr;
}

int main() {
	int niz[]={1,2,3,4,5,6,7,8,9,10};
	int** nniz;
	int n = sizeof(niz) / sizeof(int);
	int i;

	if (n % 2 != 0) return NULL;

	nniz = podijeli(niz, n);

	for (i = 0; i < n/2; i++)
	{
		printf("a[%d] = %d\n", i, nniz[0][i]);
		printf("b[%d] = %d\n", i, nniz[1][i]);
	}

	free(nniz[1]);
	free(nniz[0]);
	free(nniz);

	return 0;
}