#include<stdio.h>
#define MAX_SIZE 8

void quick_sort(int* list, int left, int right) {
	int index;

	if (left<right) {
		index = partition(list, left, right);
		quick_sort(list, left, index-1);
		quick_sort(list, index+1, right);
	}
}

int partition(int* list, int left, int right) {
	int pivot = list[left];
	int low = left;
	int high = right + 1;

	do {
		do
			++low;
		while (pivot>=list[low] && low<=right);

		do
			--high;
		while (pivot<list[high] &&  high>=left);


		if (low < high) {
			int tmp = list[low];
			list[low] = list[high];
			list[high] = tmp;
		}
		
	} while (low < high);

	int tmp = list[high];
	list[high] = list[left];
	list[left] = tmp;

	return high;
}


void main() {
	int list[MAX_SIZE] = { 7, 1, 5, 3, 10, 9, 8, 6 };

	quick_sort(list, 0, MAX_SIZE - 1);

	for (int index = 0; index < MAX_SIZE; index++) {
		printf("%d ", list[index]);
	}
	printf("\n");

}