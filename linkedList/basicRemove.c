/*
head->1-> 3-> 5-> 7-> 9
head->1-> 2-> 3-> 4-> 5-> 6-> 7-> 8-> 9
head->1-> 2-> 4-> 5-> 6-> 7-> 8-> 9

생성 삽입 삭제
현제 삭제할 시 동정할당해제와 NULL처리에 대하여 의문
*/
#include <stdio.h>
#include <stdlib.h>


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

void linkNode(node** head, node* tmp) {
	if (*head == NULL) {
		*head = tmp;
	}
	else {
		node* pointer = *head;
		while (1) {
			if (pointer->next == NULL)
				break;
			pointer = pointer->next;
		}
		pointer->next = tmp;
	}
}

void insertNode(node* head, int location, node* tmp) {
	node* pointer = head;
	while (1) {
		if (pointer->data == location)
			break;
		pointer = pointer->next;
	}
	tmp->next = pointer->next;
	pointer->next = tmp;
	tmp = NULL;
}

void removeNode(node* head, int data) {
	node *mainPointer = head;
	node *subPointer=NULL;
	while (1) {
		if (mainPointer->data == data)
			break;
		subPointer = mainPointer;
		mainPointer = mainPointer->next;
	}
	subPointer->next = mainPointer->next;
	mainPointer->next = NULL;
	free(mainPointer);

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

int main() {
	node*head = NULL;

	linkNode(&head, newNode(1));
	linkNode(&head, newNode(3));
	linkNode(&head, newNode(5));
	linkNode(&head, newNode(7));
	linkNode(&head, newNode(9));

	print(head);

	insertNode(head, 1, newNode(2));
	insertNode(head, 3, newNode(4));
	insertNode(head, 5, newNode(6));
	insertNode(head, 7, newNode(8));

	print(head);


	removeNode(head, 3);

	print(head);
}