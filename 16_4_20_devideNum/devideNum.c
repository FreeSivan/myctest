#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <unistd.h>

void devide(int *arr, int len, int remain, int thr);
void devideNum(int *arr, int len, int remain, int thr);

void printArr(int *arr, int len) {
    int i = len-1;
    while (arr[i]) {
        printf ("%d ", arr[i]);
        i -= arr[i];
    }
    printf ("\n");
}

void devide(int *arr, int len, int remain, int thr) {
    arr[remain] = thr;
    remain -= thr;
    if (!remain) {
        printArr(arr, len);
        return;
    }
    devideNum (arr, len, remain, thr);
}

void devideNum(int *arr, int len, int remain, int thr) {
    int i;
    if (remain < thr) {
        thr = remain;
    }
    for (i = 1; i <= thr; ++i) {
        devide (arr, len, remain, i); 
    }
}

int main(int argc, char **argv) {
    int ch, num = 6;
    int *arr, i;

    while(-1 != (ch=getopt(argc, argv, "n:"))) {
        switch(ch) {
        case 'n': {
            num = atoi(optarg);
            break;
        }
        default : {
            break;
        } 
        }
    }
    
    arr = (int*)malloc(sizeof(int)*(num+1));
    arr[0] = 0;
    devideNum(arr, num+1, num, num);
    return 0;
}

