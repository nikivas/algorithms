#include<iostream>


typedef int T;                 
typedef int hashTableIndex;   
#define compEQ(a,b) (a == b)

typedef struct Node_ {
	struct Node_ *next;       
	T data;                    
} Node;


Node **hashTable;
int hashTableSize;

hashTableIndex hash(T data) {



	return (data % hashTableSize);
}

Node *insertNode(T data) {
	Node *p, *p0;
	hashTableIndex bucket;


	bucket = hash(data);
	p = new Node();
	p0 = hashTable[bucket];
	hashTable[bucket] = p;
	p->next = p0;
	p->data = data;
	return p;
}

void deleteNode(T data) {
	Node *p0, *p;
	hashTableIndex bucket;


	p0 = 0;
	bucket = hash(data);
	p = hashTable[bucket];
	while (p && !compEQ(p->data, data)) {
		p0 = p;
		p = p->next;
	}
	if (!p) return;
	if (p0)
		p0->next = p->next;
	else
		hashTable[bucket] = p->next;

	free(p);
}

Node *findNode(T data) {
	Node *p;
	p = hashTable[hash(data)];
	while (p && !compEQ(p->data, data))
		p = p->next;
	return p;
}

int main(int argc, char **argv) {
	int i, *a, maxnum, random;
	maxnum = 19;
	hashTableSize = 200;
	random = argc > 3;


	a = new int[maxnum];
	hashTable = new Node*[hashTableSize];


	if (random) {

		for (i = 0; i < maxnum; i++) a[i] = rand();
		printf("ran ht, %d items, %d hashTable\n", maxnum, hashTableSize);
	}
	else {
		for (i = 0; i<maxnum; i++) a[i] = i;
		printf("seq ht, %d items, %d hashTable\n", maxnum, hashTableSize);
	}


	for (i = 0; i < maxnum; i++) {
		insertNode(a[i]);
	}

	for (i = maxnum - 1; i >= 0; i--) {

		int asd = findNode(a[i])->data;
		printf("\nwe found %d - the index is: %d", a[i], asd);
	}

	for (i = maxnum - 1; i >= 0; i--) {
		deleteNode(a[i]);
	}
	return 0;
}