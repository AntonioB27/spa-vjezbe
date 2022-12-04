#include<stdio.h>
#include<stdlib.h>

typedef struct{
	float x,y;
}Tocka;

typedef struct {
	Tocka* tocke;
	int n;
}Poligon;

Poligon* novi_poligon(float* niz_x, float* niz_y, int n) {
	Poligon* poligon=(Poligon*)malloc(sizeof(Poligon));
	poligon->tocke = (Tocka*)malloc(n * sizeof(Tocka));

	int i;
	for (i = 0; i < n; i++) {
		poligon->tocke[i].x = niz_x[i];
		poligon->tocke[i].y = niz_y[i];
		
	}
	poligon->n = n;
	return poligon;
}

Tocka** pozitivni(Poligon* p, int* np) {
	int i,brojac=0;
	
	for (i = 0; i < p->n; i++) {
		if ((p->tocke[i].x > 0) && (p->tocke[i].y > 0)) brojac++;
	}

	Tocka** pozitivni_vrhovi = (Tocka**)malloc(brojac * sizeof(Tocka*));


	int j = 0;

	for (i = 0; i < p->n;i++) {
		if ((p->tocke[i].x > 0) && (p->tocke[i].y > 0)) {
			pozitivni_vrhovi[j] = &p->tocke[i];
			j++;
		}
	}

	*np = brojac;

	return pozitivni_vrhovi;
}

int main() {
	int n,i,np;

	printf("Unesi broj vrhova: ");
	scanf("%d", &n);

	if (n < 3) return 1;

	float* niz_x=(float*)malloc(n*sizeof(float));
	float* niz_y=(float*)malloc(n * sizeof(float));

	for (i = 0; i<n; i++) {
		scanf("%f", &niz_x[i]);
	}

	for (i = 0; i<n; i++) {
		scanf("%f", &niz_y[i]);
	}

	Poligon* nPoligon = novi_poligon(niz_x, niz_y, n);

	for (i = 0; i < n; i++) {
		printf("%f %f\n", nPoligon->tocke[i].x, nPoligon->tocke[i].y);
	}

	Tocka** pozitivni_vrhovi = pozitivni(nPoligon, &np);

	printf("\n");
	
	int j = 0;
	for (i = 0;i < np; i++) {
		printf("(%f %f)\n", pozitivni_vrhovi[i]->x, pozitivni_vrhovi[i]->y);
	}

	return 0;
}