/*
quick sorting
*/

#include <stdio.h>
#define max_size 7

void sorting(int* arr, int left, int right) {
	int index;

	if (left < right) {
		index = partition(arr, left, right);
		sorting(arr, left, index - 1);
		sorting(arr, index + 1, right);
	}
}

int partition(int *arr, int left, int right) {
	int pivot, i, j, tmp;

	pivot = arr[left];
	i = left;
	j = right + 1;

	while (1) {
		do
			++i;
		while (arr[i] <= pivot && i <= right);

		do
			--j;
		while (arr[j] > pivot);
		if (i >= j)
			break;
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
	tmp = arr[left];
	arr[left] = arr[j];
	arr[j] = tmp;

	return j;
}

int main() {
	int arr[max_size] = { 5, 3, 7, 6, 2, 1, 4 };

	sorting(arr, 0, max_size - 1);

	for (int i = 0; i < max_size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}