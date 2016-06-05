#include <stdio.h>

void printArr(int *arr, int len) {
	int i;
	for (i = 0; i < len; ++i) {
		printf ("%d ", arr[i]);
	}
	printf ("\n");
}

void swappos(int *arr, int left, int right) {
	int i, j = left;
	int tmp;
	for (i = left; i <= right; ++i) {
		if (arr[i]%2) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j++] = tmp;
		}
	}
}

int main(void) {
	int arr[] = {2, 3, 6, 1, 4, 7, 8, 9, 5, 0};
	printArr (arr, sizeof(arr)/sizeof(int));
	swappos (arr, 0, sizeof(arr)/sizeof(int)-1);
	printArr (arr, sizeof(arr)/sizeof(int));
	return 0;
}

