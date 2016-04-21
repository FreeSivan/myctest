#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <malloc.h>

void printArr(int *arr, int len) {
    int i;
    for (i = 0; i < len; ++i) {
        if (arr[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void combine(int *arr, int len, int sub, int pos) {
    if (sub > len - pos) {
        return;
    }
    if (!sub) {
        printArr(arr, len);
        return;
    }
    arr[pos] = 1;
    combine(arr, len, sub-1, pos+1);
    arr[pos] = 0;
    combine(arr, len, sub, pos+1);
}

int main(int argc, char **argv) {
    int ch, m=6, n=2;
    int *flag, i;
    while (-1 != (ch=getopt(argc, argv, "m:n:"))) {
        switch(ch) {
        case 'm': {
            m = atoi(optarg);
            break;
        }
        case 'n': {
            n = atoi(optarg);
            break;
        }
        default: {
            break;
        }
        }
    }
    if (m < n) {
        m = n;
    }
    printf ("m = %d, n = %d\n", m, n);
    flag = (int*)malloc(sizeof(int)*m);
    memset(flag, 0, sizeof(int)*m);
    combine(flag, m, n, 0);
    free(flag);
    return 0;
}

