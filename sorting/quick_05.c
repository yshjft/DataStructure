#include <stdio.h>
#define MAX_SIZE 7

int partition(int* list, int left, int right) {
	int pivot = list[left];
	int low = left;
	int high = right + 1;

	do {

		do
			++low;
		while (list[low] <= pivot && low <= right);

		do
			--high;
		while (list[high] > pivot && high >= left);

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

void quick_sorting(int* list, int left, int right) {
	int index;

	if (left < right) {
		index = partition(list, left, right);
		quick_sorting(list, left, index - 1);
		quick_sorting(list, index + 1, right);
	}
}

void main() {
	int list[MAX_SIZE] = { 25, 0, 10, 19, 5, 8, 2 };

	quick_sorting(list, 0, MAX_SIZE - 1);

	for (int index = 0; index < MAX_SIZE; index++) {
		printf("%d ", list[index]);
	}
	printf("\n");
}