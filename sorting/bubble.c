// bubble sorting

#include <stdio.h>
#define max_size 5

int* sorting(int* arr) {
	int num = max_size;
	int num2 = num - 1;
	for (int i = 0; i < max_size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");


	for (int total = 0; total < num-1; total++) {
		for (int index = 0; index < num2; index++) {
			if (arr[index] > arr[index + 1]) {
				int tmp = arr[index];
				arr[index] = arr[index + 1];
				arr[index + 1] = tmp;
			}
		}
		num2--;
	}

	return arr;
}

int main() {
	int arr[max_size] = { 10, 3, 9, 8, 1 };
	
	int *sorted_arr=sorting(arr);

	for (int i = 0; i < max_size; i++) {
		printf("%d ", sorted_arr[i]);
	}
	printf("\n");

	return 0;
}