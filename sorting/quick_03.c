#include<stdio.h>
#define MAX_SIZE 8

void quick_sorting(int* arr, int left, int right) {
	int index;

	if (left < right) {
		index = partition(arr, left, right);

		quick_sorting(arr, left, index-1);
		quick_sorting(arr, index + 1, right);
	}
}

int partition(int* arr, int left, int right) {
	int pivot = arr[left];
	int low = left;
	int high = right+1;

	do {
		do
			low++;
		while (arr[low] <= pivot && low <= right);

		do
			high--;
		while (arr[high] > pivot &&  high >= left);

		if (low < high) {
			int tmp = arr[low];
			arr[low] = arr[high];
			arr[high] = tmp;
		}
	} while (low < high);

	int tmp = arr[left];
	arr[left] = arr[high];
	arr[high] = tmp;

	return high;
}

int main() {
	int arr[] = { 10, 12, 2, 9, 5, 2, 11, 0 };
	int left = 0;
	int right = MAX_SIZE - 1;

	quick_sorting(arr, left, right);

	for (int i = 0; i < MAX_SIZE; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}