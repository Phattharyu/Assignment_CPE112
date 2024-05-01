#include<stdio.h>

void resetarr(int arr[]) {
    for(int i=0;i<10;i++) {
        arr[i] = 10-i;
    }
}

void printarr(int n,int arr[]) {
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");
}

void swap(int *a,int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main() {
    int n = 10;
    int arr[n];
    resetarr(arr);

    //Bubble
    for(int i=0;i<n;i++) {
        for(int j=0;j<n-1;j++) {
            if(arr[j+1] < arr[j]) {
                swap(&arr[j+1], &arr[j]);
            }
        }
    }
    printf("BUBBLE : ");
    printarr(n,arr);

    resetarr(arr);

    //Insertion
    for(int i =0;i<n;i++) {
        int key = arr[i];
        int j=i-1;

        while(j>=0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        j++;
        arr[j] = key;
    }
    printf("INSERTION : ");
    printarr(n,arr);

    resetarr(arr);

    //SELECT
    int cnt=0;
    for(int i=0;i<n;i++) {
        int min=9999,p;
        for(int j=cnt;j<n;j++) {
            if(arr[j] < min) {
                min = arr[j];
                p = j;
            }
        }
        swap(&arr[p],&arr[cnt]);
        cnt++;
    }
    printf("SELECTION : ");
    printarr(n,arr);
}
