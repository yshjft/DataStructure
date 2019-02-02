/*
head->1->2->3->4->5
노드를 함수를 통하여 연결하여 링크드리스트 생성
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct NODE {
	int data;
	struct NODE* next;
}node;

node* newNode(int data) {
	node* tmp = (node*)malloc(sizeof(struct NODE));
	tmp->data = data;
	tmp->next = NULL;

	return tmp;
}

void linkNode(node** head, node* newNode) {
	if (*head == NULL) {
		*head = newNode;
	}
	else {
		node* pointer = *head;
		while (1) {
			if (pointer->next == NULL)
				break;
			pointer = pointer->next;
		}
		pointer->next = newNode;
	}
}

void print(node* head) {
	node* pointer = head;
	while (1) {
		int data = pointer->data;
		printf("%d ", data);
		if (pointer->next == NULL) {
			break;
		}
		else {
			pointer = pointer->next;
		}
	}
	printf("\n");
}

void main() {
	node* head=NULL;

	linkNode(&head, newNode(1));
	linkNode(&head, newNode(2));
	linkNode(&head, newNode(3));
	linkNode(&head, newNode(4));
	linkNode(&head, newNode(5));

	print(head);
}