#include<stdio.h>
#include<stdlib.h>
#include"stl.h"


Objekt3D* funkcija1(FILE* fp) {
	Objekt3D* objekt;
	objekt = (Objekt3D*)malloc(sizeof(Objekt3D));
	fseek(fp, 80, SEEK_SET);
	fread(&objekt->n, sizeof(unsigned int), 1, fp);
	objekt->niz_trokut = (Trokut*)malloc(objekt->n * sizeof(Trokut));

	int i = 0;

	for (i = 0; i < objekt->n; i++) {
		fread(&objekt->niz_trokut[i], 50, 1, fp);
	}

	return objekt;
}

void funkcija2(Objekt3D* objekt) {
	int i;
	FILE* fp = fopen("binarna.stl", "wb+");
	char niz[80] = { 0 };
	fwrite(niz,sizeof(niz)/sizeof(char), 1, fp);
	fwrite(&objekt->n, sizeof(unsigned int), 1, fp);
	for (i = 0; i < objekt->n; i++) {
		fwrite(&objekt->niz_trokut[i], 50, 1, fp);
	}
	fclose(fp);
}

void funkcija3(Objekt3D* objekt) {
	int i;
	FILE* fp = fopen("tekstualna.stl", "wt+");
	fprintf(fp, "SOLID ime\n");
	for (i = 0; i < objekt->n; i++) {
		fprintf(fp, "\tfacet normal %f %f %f\n", objekt->niz_trokut[i].n.i, objekt->niz_trokut[i].n.j, objekt->niz_trokut[i].n.x);
		fprintf(fp, "\t\touterloop\n");
		fprintf(fp, "\t\t\tvertex %f %f %f\n", objekt->niz_trokut[i].v1.x, objekt->niz_trokut[i].v1.y, objekt->niz_trokut[i].v1.z);
		fprintf(fp, "\t\t\tvertex %f %f %f\n", objekt->niz_trokut[i].v2.x, objekt->niz_trokut[i].v2.y, objekt->niz_trokut[i].v2.z);
		fprintf(fp, "\t\t\tvertex %f %f %f\n", objekt->niz_trokut[i].v3.x, objekt->niz_trokut[i].v3.y, objekt->niz_trokut[i].v3.z);
		fprintf(fp, "\t\tendloop\n");
		fprintf(fp, "\tendfacet\n");
	}
	fclose(fp);
}

	void funkcija4(Objekt3D* objekt) {
	free(objekt->niz_trokut);
	free(objekt);
}