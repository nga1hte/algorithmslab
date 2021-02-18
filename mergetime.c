#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

long int min(long int x,long int y) 
{    return (x<y)? x :y; 
     } 
void merge(long int arr[],long int l,long int m,long int r) 
{   long int i, j, k;     
    long int n1 = m - l + 1;     
    long int n2 =  r - m;    
    long int L[n1], R[n2];     
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];     
        for (j = 0; j < n2; j++)         
            R[j] = arr[m + 1+ j];     
            i = 0;     
            j = 0;     
            k = l;     
            while (i < n1 && j < n2)     
            {         
                if (L[i] <= R[j])         
                {             
                    arr[k] = L[i];             
                    i++;        
                    }         
                else         
                {             
                    arr[k] = R[j];             
                    j++;         
                    }         
                k++;     
                }     
                while (i < n1)     
                {         
                    arr[k] = L[i];         
                    i++;         
                    k++;     
                    }     
                while (j < n2)     
                {         
                    arr[k] = R[j];         
                    j++;         
                    k++;     
                    } 
                } 
void mergeSort(long int arr[],long int n) 
{    
    long int curr_size;     
    long int left_start;    
    for (curr_size=1; curr_size<=n-1; curr_size = 2*curr_size)    
        {        
        for (left_start=0; left_start<n-1; left_start += 2*curr_size)        
        {           
            long int mid = min(left_start + curr_size - 1, n-1);            
            long int right_end = min(left_start + 2*curr_size - 1, n-1);            
            merge(arr, left_start, mid, right_end);        
            }    
        } 
    }
int main() 
{    long int n=10000;     
     int it=0;     
     double time;     
     printf("A_size\t\tMerge\n");     
     while (it<10)     
     {        
         long int a[n],b[n],c[n];        
         for(int i=0;i<n;i++)        
         {            
             long int no = rand() % n+1;            
             a[i] = no;       
             }        
         clock_t start, end;                
         start = clock();        
         mergeSort(a,n);        
         end=clock();        
         time= ((double)(end - start))/CLOCKS_PER_SEC;         
         printf("%li\t\t %f\n",n,time);         
         n+= 10000;         
         it++;     
         }     
    return 0; 
}
