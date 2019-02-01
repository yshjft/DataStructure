/*
head->1->2
링크드리스트를 출력하는 함수를 만들어 사용한 프로그램이다.
*/
#include<stdio.h>
#include<stdlib.h>


typedef struct NODE {
	int data;
	struct NODE* next;
}node;

void print(node *head) {
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

int main(){
	node* head;
	node* tmp = (node*)malloc(sizeof(struct NODE));
	tmp->data = 1;
	tmp->next = NULL;

	head = tmp;
	tmp = NULL;

	print(head);
	
	tmp = (node*)malloc(sizeof(struct NODE));
	tmp->data = 2;
	tmp->next = NULL;

	head->next = tmp;
	tmp = NULL;

	print(head);
	

	return 0;
}