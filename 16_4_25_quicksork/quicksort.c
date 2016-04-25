#include <stdio.h>

void printArr(int *arr, int len) {
    int i;
    for (i = 0; i < len; ++i) {
        printf ("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int *arr, int left, int right) {
    int i, j, tmp;
    j = left;
    for (i = left; i < right; ++i) {
        if (arr[i] < arr[right]) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j++] = tmp;
        }
    }
    tmp = arr[j];
    arr[j] = arr[right];
    arr[right] = tmp;
    return j;
}

void quicksort(int *arr, int left, int right) {
    int pos;
    if (left >= right) {
        return;
    }
    pos = partition(arr, left, right);
    quicksort(arr, left, pos-1);
    quicksort(arr, pos+1, right);
}

void qsort(int *arr, int len) {
    quicksort(arr, 0, len - 1);
}

int main() {
    int arr[] = {6, 5, 1, 4, 3, 9, 7, 0, 2, 8};
    
    qsort(arr, sizeof(arr)/sizeof(int));
    
    printArr(arr, sizeof(arr)/sizeof(int));
    return 0;
}

