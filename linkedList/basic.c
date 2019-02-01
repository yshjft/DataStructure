/*
head->3
기본적인 구조체 생성을 통하여 기초적인 링크드 리스트를 만들었다.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	int data;
	struct node *next;
}node;

int main() {
	node *head;
	node *tmp = (node*)malloc(sizeof(struct NODE));
	tmp->data = 3;
	tmp->next = NULL;
	head = tmp;

	return 0;
}