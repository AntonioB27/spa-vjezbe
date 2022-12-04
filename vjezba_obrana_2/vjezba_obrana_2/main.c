#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _Element{
	int broj;
	struct _Element* next;
}Element;

Element* dodaj_u_glavu(Element* lst,int broj) {
	Element* novi = (Element*)malloc(sizeof(Element));
	novi->broj = broj;
	novi->next = lst;
	return novi;
}

Element* dodaj_na_kraj(int broj, Element* lst) {
	Element* tmp = lst;
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}

	Element* novi = (Element*)malloc(sizeof(Element));
	novi->broj = broj;
	novi->next = NULL;
	tmp->next = novi;
	return lst;
}

void print_list(Element* lst) {
	Element* tmp = lst;
	while (tmp != NULL) {
		printf("%d ", tmp->broj);
		tmp = tmp->next;
	}
	printf("\n");
}

Element* dodaj_prije_nekog_broja(int broj,int broj_novi,Element* lst) {
	Element* tmp = lst;
	while (tmp->next->broj != broj) {
		tmp = tmp->next;
	}
	if (tmp->next == NULL) return lst;
	Element* novi = (Element*)malloc(sizeof(Element));
	novi->broj = broj_novi;
	novi->next = tmp->next;
	tmp->next = novi;
	return lst;
}

Element* dodaj_prije_indeksa(int broj, int indeks, Element* lst) {
	Element* tmp = lst;
	for (int i = 0; i < indeks-1; i++) {
		tmp = tmp->next;
	}
	Element* novi = (Element*)malloc(sizeof(Element));
	novi->broj = broj;
	novi->next = tmp->next;
	tmp->next = novi;
	return lst;
}

Element* ukloni_s_pocetka_liste(Element* lst) {
	if (lst == NULL) return lst;
	Element* tmp = lst;
	Element* b = lst;
	lst = tmp->next;
	free(b);
	return lst;
}

Element* ukloni_s_kraja_liste(Element* lst) {
	Element* tmp = lst;
	while (tmp->next->next != NULL) {
		tmp = tmp->next;
	}
	Element* b = tmp->next;
	free(b);
	tmp->next = NULL;
	return lst;
}

Element* okreni_listu(Element* lst) {
	Element* okrenuta = NULL;
	while (lst != NULL) {
		Element* tmp = lst;
		lst = lst->next;
		tmp->next = okrenuta;
		okrenuta = tmp;
	}
	return okrenuta;
}

Element* ukloni_elemente_vece_od_5(Element* lst) {
	Element* tmp = lst;
	while (tmp->next != NULL) {
		if (tmp->next->broj > 5) {
			tmp->next = tmp->next->next;
		}
		else
			tmp = tmp->next;
	}
	return lst;
}

Element* ukloni_prva2_elementa(Element* lst) {
	for (int i = 0; i < 2; i++) {
		Element* b = lst;
		lst = lst->next;
		free(b);
	}
	return lst;
}

Element* dodaj_0_prije_parnih(Element* lst) {
	Element* tmp = lst;
	while (tmp != NULL) {
		if (tmp->next->broj % 2 == 0) {
			Element* novi = (Element*)malloc(sizeof(Element));
			novi->broj = 0;
			novi->next = tmp->next;
			tmp->next = novi;
			tmp = tmp->next->next;
		}
		else {
			tmp = tmp->next;
		}
	}
	return lst;
}

int main() {
	Element* lst=NULL;
	lst = dodaj_u_glavu(lst, 5);
	lst = dodaj_u_glavu(lst, 60);
	lst = dodaj_u_glavu(lst, 5);
	lst = dodaj_u_glavu(lst, 5);
	lst = dodaj_u_glavu(lst, 70);
	lst = dodaj_na_kraj(4, lst);
	lst = dodaj_na_kraj(6, lst);
	lst = dodaj_na_kraj(8, lst);
	lst = dodaj_prije_indeksa(3, 2, lst);
	lst = dodaj_prije_nekog_broja(6, 5, lst);
	lst = ukloni_s_pocetka_liste(lst);
	lst = dodaj_na_kraj(30, lst);
	print_list(lst);
	lst = ukloni_s_kraja_liste(lst);
	print_list(lst);
	lst = ukloni_elemente_vece_od_5(lst);
	print_list(lst);
	lst = ukloni_prva2_elementa(lst);
	lst = dodaj_u_glavu(lst, 2);
	lst = dodaj_u_glavu(lst, 5);
	lst = dodaj_u_glavu(lst, 2);
	print_list(lst);
	lst = okreni_listu(lst);
	print_list(lst);
	lst = dodaj_0_prije_parnih(lst);
	print_list(lst);
	return 0;
}