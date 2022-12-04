#include<stdio.h>
#include<stdlib.h>

int* filtriraj(int* niz, int n, int th, int* nth) {
	int i = 0, j=0;
	for (i = 0; i<n; i++) {
		if (niz[i] < th) ++(* nth);
	}
	int* nniz = (int*)malloc(*nth * sizeof(int));
	for (i = 0; i<n; i++) {
		if (niz[i] < th) {
			nniz[j] = niz[i];
			j++;
		}
	}
	return nniz;
}

int main() {
	int niz[] = { 1,2,3,4,5,6,7,8,9,10 };
	int n = sizeof(niz)/sizeof(int);
	int nth = 0, i;
	int th;
	cin >> th;
	int* nniz = filtriraj(niz, n, th, &nth);
	printf("NTH:%d\n", nth);
	for(i=0; i < nth; i++) {
		printf("%d\n", nniz[i]);
	}
	return 0;
}