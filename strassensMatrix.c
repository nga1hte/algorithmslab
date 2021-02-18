#include <stdio.h>
#define N 2

int main(){
    int a[N][N], b[N][N], c[N][N], i, j;
    int m1,m2,m3,m4,m5,m6,m7;

    printf("Enter elements for first 2x2 matrix:\n");
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &a[i][j]);

    printf("Enter elements for second 2x2 matrix:\n");
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &b[i][j]);

    printf("The first matrix is: \n");
    for(int i = 0; i < N; i++){
        printf("\n");
        for(int j = 0; j < N; j++){
            printf("%d\t", b[i][j]);
        }
    }
    printf("\n");

    printf("The second matrix is: \n");
    for(int i = 0; i < N; i++){
        printf("\n");
        for(int j = 0; j < N; j++){
            printf("%d\t", b[i][j]);
        }
    }
    printf("\n");

    m1= (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
    m2= (a[1][0] + a[1][1]) * b[0][0];
    m3= a[0][0] * (b[0][1] - b[1][1]);
    m4= a[1][1] * (b[1][0] - b[0][0]);
    m5= (a[0][0] + a[0][1]) * b[1][1];
    m6= (a[1][0] - a[0][0]) * (b[0][0]+b[0][1]);
    m7= (a[0][1] - a[1][1]) * (b[1][0]+b[1][1]);

    c[0][0] = m1 + m4- m5 + m7;
    c[0][1] = m3 + m5;
    c[1][0] = m2 + m4;
    c[1][1] = m1 - m2 + m3 + m6;

    printf("The matrix after Strassen's algorithm \n");
    for(int i = 0; i < N; i++){
        printf("\n");
        for(int j = 0; j < N; j++)
            printf("%d\t", c[i][j]);
            
    }
    printf("\n");
    return 0;
}
