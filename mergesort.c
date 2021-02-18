#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//functions declarations
void swap(long int* a,long int* b);
void merge(long int arr[], long int l, long int m, long int r);
void mergeSort(long int arr[], long int l, long int r);

int main(){
    clock_t start, end;
    double exe[10];
    long int n = 10000;
    int i = 0;
    printf("A_Size, Merge\n");
    while(i < 10){
        long int a[n];
        for(int j = 0; j < n; j++){
            long int num = rand() % n + 1; // for average case
            //long int num = j; // for best case
            //long int num = n - j; // for worst case
            a[j] = num;
        }

        //MergeSort
        start = clock();
        mergeSort(a, 0, n-1);
        end = clock();
        exe[i] = ((double) end - start)/CLOCKS_PER_SEC;

        printf("%li, %lf\n", n, exe[i]);
        n += 10000;
    i++;
    }
    return 0;
}

void swap(long int* a,long int* b){
    long int tmp = *a;
    *a = *b;
    *b = tmp;
}

void merge(long int arr[], long int l, long int m, long int r)
{
	long int i, j, k;
	long int n1 = m - l + 1;
	long int n2 = r - m;

	long int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0; 
	j = 0;
	k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(long int arr[], long int l, long int r)
{
	if (l < r) {
		long int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

