#include<stdio.h>

void printarray(int *A ,int n){
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n")
}

void bubblesort(int *A,int n){
    int issorted=0;
    for(int i=0;i<n-1;i++){
    issorted=1;
        for(int j=0;j<n-1-i;j++){
          if(A[j]>A[j+1]){
            int temp;
            temp=A[j];
            A[j]=A[j+1];
            A[j+1]=temp;
            issorted=0;
          }  
        }
        if(issorted){
            return;
        }
    }
}

int main(){
    int A[]={12,56,65,7,23,9};
    int n=6;
    printarray(A,n);
    printf("/////////////n");
    bubblesort(A,n);
    printarray(A,n);
    return 0;
}