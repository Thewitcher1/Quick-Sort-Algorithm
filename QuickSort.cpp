#include<stdio.h>
//#include<iostream>

void swap(int* a, int* b){
    int t = *a;
    *a=*b;
    *b= t;
}
int partition(int A[], int start, int end) {

    int i = start;
    int piv = A[end];
    int c;
    for(c=start; c<end; c++) {
        if(A[c] < piv) {
            swap(&A[c], &A[i]);
            i++;
        }
    }
    swap(&A[i],&A[c]);
    return i;
}

void quick_sort(int A[], int s, int e) {

    if(s<e) {
        int pi = partition(A,s,e);
        quick_sort(A,s,pi-1);
        quick_sort(A,pi+1,e);
    }
}
int main()
{
    int arr[] = {7,3,5,8,9,2,0,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    quick_sort(arr,0,n-1);
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}