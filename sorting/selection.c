// selection sorting practice

#include<stdio.h>
#define max_size 6

int* sorting(int* arr) {

	for (int total = 0; total < max_size - 1; total++) {
		for (int index = total; index < max_size; index++) {
			if (arr[total] > arr[index]) {
				int tmp = arr[total];
				arr[total]=arr[index];
				arr[index] = tmp;
			}
		}
	}

	return arr;
}

int main() {
	int arr[max_size] = { 10, 3, 9, 3, 8, 1 };

	int* sorted_arr= sorting(arr);

	for (int i = 0; i < max_size; i++) {
		printf("%d ", sorted_arr[i]);
	}
	printf("\n");

	return 0;
}