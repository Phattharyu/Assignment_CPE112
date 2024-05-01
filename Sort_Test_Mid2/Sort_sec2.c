#include<stdio.h>

void reset(int arr[],int n) {
    for(int i=0;i<n;i++) arr[i] = 10-i;
}

void printarr(int arr[],int n) {
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");
}

void merge(int arr[],int l,int m,int r) {
    int i,j,k;
    int n1 = m-l+1;
    int n2 = r-m;

    int L[n1],R[n2];
    for(i=0;i<n1;i++) L[i] = arr[l+i];
    for(j=0;j<n2;j++) R[j] = arr[j+m+1];

    i=0,j=0,k=l;
    while(i<n1 && j<n2) {
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i<n1) {
        arr[k] = L[i];
        i++,k++;
    }
    while(j<n2) {
        arr[k] = R[j];
        j++,k++;
    }
}

void mergesort(int arr[],int l,int r) {
    if(l<r) {
        int m = l+(r-l)/2;

        mergesort(arr,l,m);
        mergesort(arr,m+1,r);

        merge(arr,l,m,r);
    }
}

void swap(int *a,int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[],int low,int high) {
    int i = low-1;

    for(int j=low; j<high;j++) {
        if(arr[j] < arr[high]) {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return (i+1);
}

void quicksort(int arr[],int low,int high) {
    if(low < high) {
        int pi = partition(arr,low,high);

        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}

int main() {
    int n=10;
    int arr[n];
    reset(arr,n);

    mergesort(arr,0,n-1);
    printf("MERGE : ");
    printarr(arr,n);

    reset(arr,n);
    quicksort(arr,0,n-1);
    printf("QUICK : ");
    printarr(arr,n);
}
