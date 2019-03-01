#include<stdio.h>
#define MAX_SIZE 10

int search(int* list, int target, int left, int right) {
	int mid;
	int index;

	if (target >= list[left] && target <= list[right]) {
		mid = (left + right) / 2;

		if (target > list[mid]) {
			index = search(list, target, mid + 1, right);
		}
		else if (target < list[mid]) {
			index = search(list, target, left, mid - 1);
		}
		else if (target == list[mid]) {
			index = mid;
		}
		return index;
	}
	else {
		return -1;
	}
	

}

void main() {
	int list[MAX_SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int index;

	index=search(list, 0, 0, MAX_SIZE - 1);

	if (index == -1) {
		printf("No Result \n");
	}
	else {
		printf("%d \n", index);
	}
}