#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <unistd.h>

void swap(int *left, int *right) {
    int tmp = *left; 
    *left = *right;
    *right = tmp;
}

void printArr(int *arr, int len) {
    int i;
    for (i = 0; i < len; ++i) {
        printf ("%d ", arr[i]);
    }
    printf ("\n");
}

void partperm(int *arr, int len, int pos, int thr) {
    int i;
    if (pos >= thr) {
        printArr(arr, thr);
        return;
    }
    for (i = pos ; i < len; ++i) {
        swap(&arr[i], &arr[pos]);
        partperm(arr, len, pos+1, thr);
        swap(&arr[i], &arr[pos]);
    }
}

int main(int argc, char **argv) {
    int ch, num = 4, thr = 2, i;
    int *arr;
    
    while (-1 != (ch=getopt(argc, argv, "n:m:"))) {
        switch(ch) {
        case 'n': {
            num = atoi(optarg);    
            break;
        }
        case 'm': {
            thr = atoi(optarg);
            break;
        }
        default: {
            break;
        }
        }
    }

    arr = (int*)malloc(sizeof(int)*num);
    for (i = 0; i < num; ++i) {
        arr[i] = i;
    }

    partperm(arr, num, 0, thr);    

    free(arr);
    
    return 0;
}

