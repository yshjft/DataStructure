#include <stdio.h>

void sorting(int *arr, int left, int right) {
	int index;

	if (left < right) {
		index = partition(arr, left, right);

		for (int index = 0; index < right+1; index++) {
			printf("%d ", arr[index]);
		}
		printf("\n");

		sorting(arr, left, index-1);
		sorting(arr, index + 1, right);
	}
}

int partition(int* arr, int left, int right) {
	int pivot = arr[left];
	int low = left;
	int high = right + 1;

	while (1) {
		do
			++low;
		while (arr[low] <= pivot && low <= right);
		
		do
			--high;
		while (arr[high] > pivot && high >= left);

		if (low >=high)
			break;
		int tmp = arr[low];
		arr[low] = arr[high];
		arr[high] = tmp;
	}
	int tmp = arr[left];
	arr[left] = arr[high];
	arr[high] = tmp;

	return high;
}

int main() {
	int arr[] = { 10, 12, 2, 9, 5, 2, 11, 0};
	int size = sizeof(arr) / sizeof(int);

	int left = 0;
	int right = size - 1;

	sorting(arr, left, right);

	for (int index = 0; index < size ; index++) {
		printf("%d ", arr[index]);
	}
	printf("\n");

	return 0;
}