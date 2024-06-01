#include <stdio.h>
#include <stdlib.h>

struct link_list{
    int data;
    struct link_list *next;
};

void linklist_traversal(struct link_list *head){
    struct link_list*ptr=head;
    do{
        printf("%d \n",ptr->data);
       ptr=ptr->next; 
    }while(ptr!=head);   
}

struct link_list*insertatfirst(struct link_list*head,int data){
    struct link_list*ptr=(struct link_list*)malloc(sizeof(struct link_list));
    ptr->data=data;

    struct link_list*p=head->next;
    while(p->next!=head){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    return ptr;
}

int main(){
    struct link_list *head;
    struct link_list *second;
    struct link_list *third;
    head = (struct link_list *)malloc(sizeof(struct link_list));
    second = (struct link_list *)malloc(sizeof(struct link_list));
    third = (struct link_list *)malloc(sizeof(struct link_list));

    head->data = 7;
    head->next=second;

    second->data = 8;
    second->next=third;

    third->data = 9;
    third->next=head;

    linklist_traversal(head);
    head=insertatfirst(head,60);
    linklist_traversal(head);

        return 0;
}