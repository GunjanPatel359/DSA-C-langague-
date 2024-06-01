#include<stdio.h>

int insertion(int arr[],int size,int element,int index,int capacity){
    if(size>=capacity){
        printf("insertion failed");
        return -1;
    }
    for(int i=size-1;i>=index;i--){
        arr[i+1]=arr[i];
    }
    arr[index]=element;
} 


int main(){
    int arr[100]={7,8,12,45,88};
    int size=5;
    int element=10;
    insertion(arr,size,element,2,100);
    size+=1;
    for(int i=0;i<size;i++){
        printf("%d \n",arr[i]);
    }

    return 0;
}