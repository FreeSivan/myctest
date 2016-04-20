#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
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

void perm(int *arr, int len, int pos) {
    int i;
    if (pos >= len) {
        printArr(arr, len);
    }
    for (i = pos; i < len; ++i) {
        swap (&arr[i], &arr[pos]);
        perm (arr, len, pos+1);
        swap (&arr[i], &arr[pos]);
    }
}

int main(int argc, char **argv) {
    int ch, num = 4;
    int *arr ,i;
    
    while (-1 != (ch=getopt(argc, argv, "n:"))) {
        switch(ch) {
        case 'n': {
            num = atoi(optarg);
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
    perm(arr, num, 0); 
    free (arr);
    return 0;
}

