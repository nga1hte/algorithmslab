#include <stdio.h>

int n,i,j,k,t;

int check(int s[],int p){
    int ptr=0;
    for(int i=0;i<n;i++){
		if(s[i]==p)
            ptr++;
        }           
        if(ptr==0)
            return 1;
        else
            return 0;
}                 

int main(){  
    printf("Enter the no of jobs: ");
    scanf("%d",&n);
    int slot[n],profit,p[n],d[n];
    for(i=0;i<n;i++)
    {
	   printf("enter profit of Job%d: ",i+1);
       scanf("%d",&p[i]);                 
       printf("enter deadline of Job%d: ",i+1);
       scanf("%d",&d[i]);
    }
    for(i=0;i<n;i++){
       for(j=i+1;j<n;j++){
           if(p[i]<p[j]){
	           t=p[i];
               p[i]=p[j];
               p[j]=t;
               t=d[i];
               d[i]=d[j];
               d[j]=t;             
           }
        }
    }
    for(i=0;i<n;i++)
        slot[i]=0;            

    for(i=0;i<n;i++){
        for(j=d[i];j>0;j--){
	        if(check(slot,j)==1){
	          slot[i]=j;
              break;
            } 
        }     
    }
    printf("\nIn descending order of profits:\n");
    
    printf("JOBS\tPROFITS\tDEADLINES\n");
    for(i=0;i<n;i++)
        printf("%d\t%d\t%d\n",i+1,p[i],d[i]);

    printf("The order of job for maximum profit: ");      
    int mprofit = 0;
    for(i=0;i<n;i++){
        if(slot[i]>0){
            printf("JOB %d ", i+1);
            mprofit += p[i];
        }
    }
    printf("\nThe maximum profit is: %d\n", mprofit);

}   
    
