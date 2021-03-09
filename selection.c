#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int p, int q){
    int x = arr[p];
    int i = p;
    for(int j = p + 1; j <= q; j++){
        if(arr[j] <= x){
            i = i+1;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[p], &arr[i]);
    return i;
}

int selection(int arr[], int p, int q, int k){
    if(p == q) return arr[p];
    else{
        int m = partition(arr, p, q);
        if(m == k) return arr[m];
        else if(k<m) selection(arr, p, m-1, k);
        else selection(arr, m+1, q, k);
    }
}

int main(){
    int A[15], k;
    for(int i = 0; i < 15; i++) A[i] = rand() % (100 - 1 + 1) + 1;
    printf("The original sequence is: ");
    for(int i = 0; i < 15; i++) printf("%d ", A[i]);
    printf("\nEnter the Kth smallest element you want to find: ");
    scanf("%d", &k);
    printf("The smallest %dth smallest element is %d\n", k, selection(A, 0, 15, k-1)); //k-1 since k starts at 0
    return 0;
}

