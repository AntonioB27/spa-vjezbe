#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BIGRAND (rand()*rand())


int max(int* niz,int n) {
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (max < niz[i]) {
			max = niz[i];
		}
	}
	return max;
}

int cmp(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

void shuffle(int* niz, int n) {
	for (int i = 0; i < n - 1; i++) {
		int j = i + BIGRAND % (n - i);
		int tmp = niz[i];
		niz[i] = niz[j];
		niz[j] = tmp;
	}
}

int* generate(int n) {
	int* niz = (int*)malloc(sizeof(int) * n);
	niz[0] = 1 + BIGRAND % 3;
	for (int i = 1; i < n; i++)
		niz[i] = niz[i - 1] + BIGRAND % 3 + 1;
	shuffle(niz, n);
	return niz;
}

int presjek(int* skupA, int* skupB, int n) {
	int i, j;
	int brojac = 0;
	for (i=0; i < n; i++)
		for (j=0; j < n; j++)
			if (skupA[i] == skupB[j]) {
				brojac++;
			}
	return brojac;
}

int presjek_jedan_sortiran(int* skupA, int* skupB,int n) {
	qsort(skupB, n, sizeof(int), cmp);
	int brojac = 0;
	for (int i = 0; i < n; i++) {
		if (bsearch(skupA + i, skupB, n, sizeof(int), cmp)) brojac++;
	}
	return brojac;
}

int presjek_oba_sortirana(int* skupA, int* skupB, int n) {
	int i = 0, j=0,brojac =0;
	qsort(skupB, n, sizeof(int), cmp);
	qsort(skupA, n, sizeof(int), cmp);
	while (i < n || j < n)
	{
		if (i >= n) j++;
		if (j >= n) i++;
		if (skupA[i] < skupB[j]) i++; 
		else if (skupA[i] > skupB[j]) j++; 
		else{
			i++;
			j++;
			brojac++;
		}
	}
	return brojac;
}

int presjek_po_indeksima(int* skupA, int* skupB,int n) {

	int i = 0, j = 0, brojac = 0;

	int nA = max(skupA,n);
	int nB = max(skupB,n);

	int* indeksA = (int*)malloc(nA * sizeof(int));
	int* indeksB = (int*)malloc(nB * sizeof(int));

	for (int i = 0; i < nA; i++) {
		indeksA[i] = 0;
	}

	for (int i = 0; i < nB; i++) {
		indeksB[i] = 0;
	}
	
	for(int i=0;i<n;i++){
		indeksA[skupA[i]] = 1;
	}

	for (int i = 0; i < n; i++) {
		indeksB[skupB[i]] = 1;
	}
	i = 0, j = 0;
	
	if (nB < nA) nA = nB;
	
	for(i;i<=nA;i++)
	{
		if (indeksA[i] == 1 && indeksB[i] == 1) brojac++;
	}

	return brojac;
}

void main() {
	srand(time(NULL));
	/*
	int* skupA = generate(n);
	for (int i = 0; i < 10; i++) {
		printf("%d ", skupA[i]);
	}
	printf("\n");
	int* skupB = generate(n);
	for (int i = 0; i < 10; i++) {
		printf("%d ", skupB[i]);
	}
	printf("\n");
	*/
	for(int i=10000;i<300000;i+=30000){
		int time1 = clock();
		int* skupA = generate(i);
		int* skupB = generate(i);
		presjek_po_indeksima(skupA, skupB, i);
		int time2 = clock();
		printf("Vrijeme:%.2f sekundi za %d brojeva.\n", (float)(time2 - time1)/CLOCKS_PER_SEC, i);

	}/*
	printf("Broj presjeka: %d\n", presjek_jedan_sortiran(skupA, skupB));

	printf("Broj presjeka: %d\n", presjek_oba_sortirana(skupA, skupB));

	printf("Broj presjeka: %d\n", presjek_po_indeksima(skupA, skupB));

	*/
}