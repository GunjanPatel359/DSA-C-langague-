#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*prev;
    struct node*next;
};

int main(){
    struct node*head=(struct node*)malloc(sizeof(struct node));
    struct node*first=(struct node*)malloc(sizeof(struct node));
    struct node*second=(struct node*)malloc(sizeof(struct node));
    struct node*third=(struct node*)malloc(sizeof(struct node));
    struct node*forth=(struct node*)malloc(sizeof(struct node));

    head->prev=NULL;
    head->data=3;
    head->next=first;

    first->prev=head;
    first->data=3;
    first->next=second;

    second->prev=first;
    second->data=3;
    second->next=third;

    third->prev=second;
    third->data=3;
    third->next=forth;

    forth->prev=third;
    forth->data=3;
    forth->next=NULL;

    
}