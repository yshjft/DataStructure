#include<stdio.h>
#define MAX_SIZE 7

int sorted[MAX_SIZE];

void merge(int* list, int left, int mid, int right) {
	int index_for_left = left;
	int index_for_right = mid + 1;
	int index_for_sorted = left;

	while (index_for_left <= mid && index_for_right <= right) {
		if (list[index_for_left] > list[index_for_right])
			sorted[index_for_sorted++] = list[index_for_right++];
		else
			sorted[index_for_sorted++] = list[index_for_left++];
	}

	if (index_for_left > mid) {
		for (int index = index_for_right; index <= right; index++) {
			sorted[index_for_sorted++] = list[index];
		}
	}
	else {
		for (int index = index_for_left; index <= mid; index++) {
			sorted[index_for_sorted++] = list[index];
		}
	}

	for (int index =left; index <= right; index++) {
		list[index] = sorted[index];
		printf("%d ", list[index]);
	}
	printf("\n");

	for (int index = 0; index < MAX_SIZE; index++) {
		printf("%d ", list[index]);
	}
	printf("\n");
}

merge_sort(int* list, int left, int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2;
		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);
		merge(list, left, mid, right);
	}
}

void main() {

	int list[MAX_SIZE] = { 25, 0, 10, 19, 5, 8, 2 };

	merge_sort(list, 0, MAX_SIZE - 1);

	for (int index = 0; index < MAX_SIZE; index++) {
		printf("%d ", list[index]);
	}
	printf("\n");
}