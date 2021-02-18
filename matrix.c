#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    long int n = 1000;
    long int **A, **B, **C;
    printf("Inputs\t\tExecution time\n");
    int it = 0;
    while(it++ < 10){

        A = (long int**) malloc(sizeof(long int*) * n);
        B = (long int**) malloc(sizeof(long int*) * n);
        C = (long int**) malloc(sizeof(long int*) * n);

        for(int i = 0; i < n; i++){
            A[i] = (long int*) malloc(sizeof(long int) * n);
            B[i] = (long int*) malloc(sizeof(long int) * n);
            C[i] = (long int*) malloc(sizeof(long int) * n);
        }
        //initialising values in the matrix;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                A[i][j] = i+1;
                B[i][j] = i+2;
            }
        }
        clock_t begin, end;
        begin = clock();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                C[i][j] = 0;
                for(int k = 0; k < n; k++){
                    C[i][j] = C[i][j] + A[i][k] * B[k][j];
                }
            }
        }
        end = clock();
        double time = (double)(end - begin)/CLOCKS_PER_SEC;
        printf("%li\t\t%lf\n", n, time);
        n += 50;
    }
    return 0;
}
