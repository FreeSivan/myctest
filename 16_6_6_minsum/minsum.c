#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>

void printArr (int **arr, int len) {
	int i, j;
	for (i = 0; i < len; ++i) {
		for (j = 0; j < len; ++j) {
			printf ("%03d ", arr[i][j]);
		}
		printf ("\n");
	}
}

int minsum (int *arr, int len) {
	assert(arr && len > 0);
	int i, j, k, sum, min, result;
	int **tmp = (int**)malloc(sizeof(int*)*len);
	for (i= 0; i < len; ++i) {
		tmp[i] = (int*)malloc(sizeof(int)*len);
		memset(tmp[i], 0, sizeof(int)*len);
	}

	for (i = 1; i < len; ++i) {
		for (j = 0; j+i < len; ++j) {
			sum = 0;
			min = 65536;
			for (k = 0; k <=i; ++k) {
				sum += arr[j+k];
			}
			for (k = 0; k < i; ++k) {
				if (min > tmp[j][j+k] + tmp[j+k+1][j+i]) {
					min = tmp[j][j+k] + tmp[j+k+1][j+i];
				}
			}
			tmp[j][j+i] = sum + min;
		}
	}
	result = tmp[0][len-1];
	printArr(tmp, len);
	for (i = 0; i < len; ++i) {
		free(tmp[i]);
	}
	free(tmp);
	return result;
}

int main(void) {
	int arr[] = {4, 2, 3, 5, 1, 6, 2, 4};
	int sum = minsum(arr, sizeof(arr)/sizeof(int));
	printf("sum = %d\n", sum);
	return 0;
}

