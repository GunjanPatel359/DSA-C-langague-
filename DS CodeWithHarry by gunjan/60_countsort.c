#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

void printarray(int *A ,int n){
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}

int maximum(int A[],int n){
    int max=INT_MIN;
    for(int i=0;i<n;i++){
        if(max<A[i]){
            max=A[i];
        }
    }
    return max;
}

void countsort(int *A,int n){
    int max=maximum(A,n);
    int i,j;

    int *count=(int *)malloc((max+1)*sizeof(int));
    for(i=0;i<max+1;i++){
        count[i]=0;
    }
    for(i=0;i<n;i++){
        count[A[i]]=count[A[i]]+1;
    }
    i=0;
    j=0;
    while(i<max+1){
        if(count[i]>0){
            A[j]=i;
            count[i]=count[i]-1;
            j++;
        }else{
            i++;
        }
    }
    free(count);
}

// void countsort(int *A, int n) {
//     int max = maximum(A, n);
//     int i, j;

//     int *count = (int *)malloc((max + 1) * sizeof(int));
//     for (i = 0; i < max + 1; i++) { // Initialize count array to zeros
//         count[i] = 0;
//     }
//     for (i = 0; i < n; i++) {
//         count[A[i]] = count[A[i]] + 1;
//     }
//     i = 0;
//     j = 0;
//     while (i < max + 1) {
//         if (count[i] > 0) {
//             A[j] = i;
//             count[i] = count[i] - 1;
//             j++;
//         } else {
//             i++;
//         }
//     }
//     free(count); // Free the dynamically allocated memory
// }


int main(){
    int A[]={3,5,2,13,12};
    int n=5;
    printarray(A,n);
    countsort(A,n);
    printarray(A,n);
    return 0;
}