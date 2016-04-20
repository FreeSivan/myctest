#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <unistd.h>

void printArr(int *arr, int len) {
    int i;
    for (i = 0; i < len; ++i) {
        if (arr[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void combine(int *arr, int len, int pos) {
    if (pos >= len) {
        printArr(arr, len);
        return;
    }
    arr[pos] = 0;
    combine(arr, len, pos+1);
    arr[pos] = 1;
    combine(arr, len, pos+1);
}

int main(int argc, char **argv) {
    int ch, num = 6, i;
    int *flag;
    
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

    flag = (int*)malloc(sizeof(int)*num);

    combine(flag, num, 0);    

    free(flag);
}

