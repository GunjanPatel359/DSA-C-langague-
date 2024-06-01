#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
};

void traversal(struct node*p){
    while(p!=NULL){
        printf("%d \n",p->data);
        p=p->next;
    }
}

struct node*deletestart(struct node*head){
    struct node*p=head;
    head=head->next;
    free(p);
    return head;
}

struct node*deletebetween(struct node*head,int index){
    struct node*p=head;
    struct node*q=head->next;
    int i=0;
    while(i!=index-1){
        p=p->next;
        q=q->next;
        i++;
    }
    p->next=q->next;
    free(q);
    return head;
}

struct node*deleteend(struct node*head){
    struct node*p=head;
    struct node*q=head->next;
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}

struct node*deleteatnode(struct node*head,int value){
    struct node*p=head;
    struct node*q=head->next;
    while(q->data!=value&&q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    if(q->data==value){
    p->next=q->next;
    free(q);
    }
    return head;
    
}

int main(){
    struct node*head=(struct node*)malloc(sizeof(struct node));
    struct node*second=(struct node*)malloc(sizeof(struct node));
    struct node*third=(struct node*)malloc(sizeof(struct node));
    struct node*forth=(struct node*)malloc(sizeof(struct node));

    head->data=23;
    head->next=second;

    second->data=76;
    second->next=third;

    third->data=65;
    third->next=forth;

    forth->data=98;
    forth->next=NULL;

    // head=deletestart(head);
    // head=deletebetween(head,2);
    // head=deleteend(head); 
    head=deleteatnode(head,65); 
    traversal(head);

}