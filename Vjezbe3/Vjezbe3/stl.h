#ifndef stl
#define stl_h

typedef struct{
	float x,y,z;
}Vrh;

typedef struct {
	float i, j, x;
}Normala;

typedef struct {
	Normala n;
	Vrh v1;
	Vrh v2;
	Vrh v3;
	unsigned short boja;
}Trokut;

typedef struct {
	unsigned int n;
	Trokut* niz_trokut;
	
}Objekt3D;

Objekt3D* funkcija1(FILE* fp);
void funkcija2(Objekt3D* objekt);
void funkcija3(Objekt3D* objekt);
void funkcija4(Objekt3D* objekt);
#endif