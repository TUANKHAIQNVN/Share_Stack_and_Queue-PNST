//#include<iostream>
//using namespace std;

//struct Queue {
//	int* list;
//	int max;
//	int size;
//};
//
//Queue initQueue(int n) {
//	Queue q;
//	q.list = new int[n];
//	if (q.list == NULL) cout << "Not enough memory" << endl;
//	q.max = n;
//	q.size = 0;
//	return q;
//}
//bool isEmpty(Queue& q) {
//	return q.size == 0;;
//}
//bool isFull(Queue& q) {
//	return q.size == q.max;
//}
//bool Push(Queue& q, int x) {
//	if (q.size == q.max) return false;
//	q.list[q.size] = x;
//	q.size++;
//	return true;
//}
//bool Pop(Queue& q) {
//	if (isEmpty(q))
//		return false;
//	for (int i = 0; i < q.size - 1; i++) {
//		q.list[i] = q.list[i + 1];
//	}
//	q.size--;
//	q.list[q.size] = INT_MIN;
//	return true;
//}
//int Front(Queue& q) {
//	if (isEmpty(q)) return INT_MIN;
//	return q.list[0];
//}

//struct node {
//	int x;
//	node* pNext;
//};
//
//struct Queue {
//	node* head, * tail;
//	int max;
//	int size;
//};
//Queue* initQueue(int n) {
//	Queue* q = new Queue;
//	if (q == NULL) {
//		cout << "Not enough memory" << endl;
//		return NULL;
//	}
//	q->head = q->tail = NULL;
//
//	q->max = n;
//	q->size = 0;
//	return q;
//}
//bool isEmpty(Queue*& q) {
//	return q->size == 0;;
//}
//bool isFull(Queue*& q) {
//	return q->size == q->max;
//}
//node* createNode(int x) {
//	node* nod = new node;
//	if (nod == NULL) return NULL;
//	nod->pNext = NULL;
//	nod->x = x;
//	return nod;
//}
//bool Push(Queue*& q, int x) {
//	if (q->size == 0) {
//		node* nNode = createNode(x);
//		q->head = q->tail = nNode;
//	}
//	else if (q->size < q->max) {
//		node* nNode = createNode(x);
//		q->tail->pNext = nNode;
//		q->tail = nNode;
//	}
//	else return false;
//	q->size++;
//	return true;
//}
//bool Pop(Queue*& q) {
//	if (isEmpty(q)) return false;
//	node* del = q->head;
//	q->head = q->head->pNext; 
//	delete del;
//	if (q->head == NULL)
//		q->head = q->tail = NULL;
//	q->size--;
//	return true;
//}
//int Front(Queue*& q) {
//	if (isEmpty(q)) return INT_MIN;
//	return q->head->x;
//}

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct node {
	string x;
	node* pNext;
};

struct Queue {
	node* head, * tail;
	int max;
	int size;
};
Queue* initQueue(int n) {
	Queue* q = new Queue;
	if (q == NULL) {
		cout << "Not enough memory" << endl;
		return NULL;
	}
	q->head = q->tail = NULL;

	q->max = n;
	q->size = 0;
	return q;
}
bool isEmpty(Queue*& q) {
	return q->size == 0;;
}
bool isFull(Queue*& q) {
	return q->size == q->max;
}
node* createNode(string x) {
	node* nod = new node;
	if (nod == NULL) return NULL;
	nod->pNext = NULL;
	nod->x = x;
	return nod;
}
bool Push(Queue*& q, string x) {
	if (q->size == 0) {
		node* nNode = createNode(x);
		q->head = q->tail = nNode;
	}
	else if (q->size < q->max) {
		node* nNode = createNode(x);
		q->tail->pNext = nNode;
		q->tail = nNode;
	}
	else return false;
	q->size++;
	return true;
}
bool Pop(Queue*& q) {
	if (isEmpty(q)) return false;
	node* del = q->head;
	q->head = q->head->pNext;
	delete del;
	if (q->head == NULL)
		q->head = q->tail = NULL;
	q->size--;
	return true;
}
string Front(Queue*& q) {
	if (isEmpty(q)) return "";
	return q->head->x;
}
int main() {
	char ch;
	Queue* que = NULL;
	ifstream input("input.txt");
	if (input.fail())
		cout << "Failed to open this file!" << endl;
	while (input.eof()) {
		input >> ch;
		Push(que, ch);

	}
	
	que = initQueue(10);
	return 0;
	system("pause");
}