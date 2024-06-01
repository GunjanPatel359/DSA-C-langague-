#include<stdio.h>
#include<stdlib.h>

struct circularqueue{
    int size;
    int f;
    int r;
    int *arr;
};

int isfull(struct circularqueue *q){
    if((q->r+1)%q->size==q->f){
        return 1;
    }else{
        return 0;
    }
}

int isempty(struct circularqueue *q){
    if(q->r==q->f){
        return 1;
    }else{
        return 0;
    }
}

void enqueue(struct circularqueue *q,int val){
    if(isfull(q)){
        printf("This queue is full \n");
    }else{
        q->r=(q->r+1)%q->size;
        q->arr[q->r]=val;
        printf("enqueueing element %d",q->arr[q->r]);
    }
}

int dequeue(struct circularqueue *q){
    int a=-1;
    if(isempty(q)){
        printf("This queue is empty \n");
    }else{
        q->f=(q->f+1)%q->size;
        a=q->arr[q->f];
        return a;
    }
}

int main(){
    struct circularqueue q;
    q.size=100;
    q.f=-1;
    q.r=-1;
    q.arr=(int *)malloc(q.size*sizeof(int));

    if(isempty(&q)){
        printf("queue is empty \n");
    }

    enqueue(&q,12);
    enqueue(&q,15);

    printf("Dequeueing element %d \n",dequeue(&q));
}