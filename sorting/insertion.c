/*
num3 = ++num1;과 num4 = --num2
num1 = num1 + 1;
num3 = num1;

num2 = num2 - 1;
num4 = num2;
*/

/*
num3 = num1++;와 num4 = num2--
num3 = num1;
num1 = num1 + 1;

num4 = num2;
num2 = num2 - 1;
*/

//후위 연산자나 전위 연산자 모두 변수 자체값을 건드린다. 주의 할 것!!
#include<stdio.h>
#define max_size 5

void sorting(int * arr) {
	for (int total = 1; total < max_size; total++) {
		for (int index = total; index >0; index--) {
			int now = index;
			int pre = now-1;
			printf("%d \n", index);
			printf("%d \n", now);
			printf("%d \n", pre);
			printf("%d %d \n", arr[now], arr[pre]);

			if (arr[now] < arr[pre]) {
				
				int tmp = arr[now];
				arr[now] = arr[pre];
				arr[pre] = tmp;
			}
		}
	}


	for (int i = 0; i < max_size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {
	int arr[max_size] = { 10, 3, 9, 8, 1 };
	sorting(arr);

	return 0;
}