#include <stdio.h>

int matrixChain(int arr[], int n){
    int min[n][n], j , q, i, L, k;

    for(i = 1; i < n; i++){
        min[i][i] = 0;
    }

    for(L = 2; L < n; L++){
        for(i = 1; i < n - L + 1; i++){
            j = i + L - 1;
            min[i][j] = 999999;
            for(k = i; k <= j - 1; k++){
                q = min[i][k] + min[k+1][j] + arr[i - 1] * arr[k] * arr[j];
                if(q < min[i][j])
                    min[i][j] = q;
            }
        }
    }
    return min[1][n - 1];
}

int main(){
    int n, i;
    printf("Enter the size of the matrix: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the order of the matrices: \n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Minimum no. of multiplications required for the matrices multiplication is %d\n", matrixChain(arr, n));
    return 0;
}
