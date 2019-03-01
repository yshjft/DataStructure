#include <stdio.h>
#define MAX_SIZE 7

void quick_sort(int* list, int left, int right) {
	int index;

	if (left < right) {
		index = partition(list, left, right);
		quick_sort(list, left, index-1);
		quick_sort(list, index + 1, right);
	}

}

int partition(int* list, int left, int right) {
	int pivot = list[left];
	int low = left;
	int high = right+1;

	while (1) {
		do
			++low;
		while (list[low] <= pivot && low <= right);

		do
			--high;
		while (list[high] > pivot && high >= left);

		if (low > high)
			break;

		int tmp = list[low];
		list[low] = list[high];
		list[high] = tmp;
	}


	int tmp = list[left];
	list[left] = list[high];
	list[high] = tmp;

	return high;
}

void main() {
	int list[MAX_SIZE] = {5, 3, 7, 6, 2, 1, 4};

	quick_sort(list, 0, MAX_SIZE-1);

	for (int index = 0; index < MAX_SIZE; index++) {
		printf("%d ", list[index]);
	}
	printf("\n");
}