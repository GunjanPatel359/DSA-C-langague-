#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int *arr;
};

int isfull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }else{
        return 0;
    }
}

int isempty(struct queue *q){
    if(q->r==q->f){
        return 1;
    }else{
        return 0;
    }
}

void enqueue(struct queue *q,int val){
    if(isfull(q)){
        printf("This queue is full \n");
    }else{
        q->r++;
        q->arr[q->r]=val;
        printf("enqueueing element %d",q->arr[q->r]);
    }
}

int dequeue(struct queue *q){
    int a=-1;
    if(isempty(q)){
        printf("This queue is empty \n");
    }else{
        q->f++;
        a=q->arr[q->f];
        return a;
    }
}

int main(){
    struct queue q;
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