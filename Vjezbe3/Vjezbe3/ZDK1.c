#include<stdio.h>
#include<stdlib.h>
#include"stl.h"

int main() {
	FILE* fp;
	fp = fopen("primjerbin.stl", "rb");
	if (!fp) return 0;
	Objekt3D* objekt = funkcija1(fp);
	funkcija2(objekt);
	funkcija3(objekt);
	funkcija4(objekt);

	fclose(fp);
	return 0;
}