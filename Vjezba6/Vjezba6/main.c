#include<stdio.h>
#include<stdlib.h>

#define N 10000

typedef struct {
	int priority;
	void* data;
}bheap;

typedef struct {
	int n;
	bheap* data_queue;
}queue;

queue create(int size) {
	queue q;
	q.data_queue = (bheap*)malloc(size * sizeof(bheap));
	q.n = 0;

	return q;
}

void sort_data(queue* q, int c) {
	if (c==0) return;
	int r;
	r = (c - 1) / 2;
	if (q->data_queue[c].priority > q->data_queue[r].priority) {
		bheap temp = q->data_queue[c];
		q->data_queue[c] = q->data_queue[r];
		q->data_queue[r] = temp;
		sort_data(q, r);
	}
}

void add_data(queue* q, bheap* b) {
	q->data_queue[q->n].data = b->data;
	q->data_queue[q->n].priority = b->priority;
	sort_data(q, (q->n)++);
}

void sort_to_bottom(queue* q,int r) {
	int cl = 2 * r+1;
	int cr = 2 * r+ 2;

	if (q->n < cl && q->n < cr) {
		return;
	}
	if (q->n > cl && q->n > cr) {
		if (q->data_queue[r].priority < q->data_queue[cl].priority || q->data_queue[r].priority < q->data_queue[cr].priority) {
			if (q->data_queue[cl].priority > q->data_queue[cr].priority) {
				int temp = q->data_queue[r].priority;
				q->data_queue[r].priority = q->data_queue[cl].priority;
				q->data_queue[cl].priority = temp;
				sort_to_bottom(q, cl);
			}

			else {
				int temp = q->data_queue[r].priority;
				q->data_queue[r].priority = q->data_queue[cr].priority;
				q->data_queue[cr].priority = temp;
				sort_to_bottom(q, cr);
			}
		}
	}
	if (cl<q->n && cr>q->n) {
		if (q->data_queue[r].priority < q->data_queue[cl].priority) {
			int temp = q->data_queue[r].priority;
			q->data_queue[r].priority = q->data_queue[cl].priority;
			q->data_queue[cl].priority = temp;
			return;
		}
	}
}

void remove_first(queue* q) {
	q->data_queue[0] = q->data_queue[q->n - 1];
	q->n--;
	sort_to_bottom(q, 0);
}

int main() {
	int size = 10;
	queue q = create(size);
	for (int i = 0; i < size; i++) {
		bheap tmp;
		tmp.priority = i;
		add_data(&q, &tmp);
		for (int j = 0; j < q.n; j++) {
			printf("%d ", q.data_queue[j].priority);
		}
		printf("\n");
	}
	remove_first(&q);
	for (int j = 0; j < q.n; j++) {
		printf("%d ", q.data_queue[j].priority);
	}
	printf("\n");
	return 0;
}