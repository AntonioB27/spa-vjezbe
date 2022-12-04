#include "dictionary.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Dictionary create() {
	Dictionary dict = (Dictionary)malloc(sizeof(Word));
	dict->word = NULL;
	dict->count = 0;
	dict->next = NULL;
	return dict;
}

void add(Dictionary dict, char* str) {
	
	while (dict->next != NULL) {
		if (strcmp(str, dict->next->word) > 0) 
			dict = dict->next;
		else if (strcmp(str, dict->next->word) < 0) {
			Dictionary novi = (Dictionary)malloc(sizeof(Word));
			novi->word = _strdup(str);
			novi->count = 1;
			novi->next = dict->next;
			dict->next = novi;
			return;
		}
		else {
			dict->next->count++;
			return;
		}
	} 
	Dictionary novi = (Dictionary)malloc(sizeof(Word));
	novi->word = _strdup(str);
	novi->count = 1;
	novi->next = dict->next;
	dict->next = novi;
	return;
}

void print(Dictionary dict) {
	dict = dict->next;
	while (dict != NULL) {
		printf("%s, %d\n", dict->word, dict->count);
		dict = dict->next;
	}
}

void destroy(Dictionary dict) {
	Dictionary b = dict;
	dict = dict->next;
	free(b);
	while (dict != NULL) {
		b = dict;
		dict = dict->next;
		free(b->word);
		free(b);
	}
}

int filter(Word* w) {
	if (strlen(w->word) > 3 && (w->count >= 5 && w->count <= 10)) return 1;
	return 0;
}

Dictionary filterDictionary(Dictionary indict, int (*filter)(Word* w)) {
	Dictionary p, t;
	p = indict;
	t = indict->next;
	while (!t) {
		if (filter(t)) {
			p->next = t->next;
			free(t->word);
			free(t);
			t = p->next;
		}
		else {
			p = p->next;
			t = t->next;
		}
	}
	return indict;
}
