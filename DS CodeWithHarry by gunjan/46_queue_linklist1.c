#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

    struct node *f = NULL;
    struct node *r = NULL;

void linklist_traversal(struct node *ptr) {
    while (ptr != NULL) {
        printf("%d \n", ptr->data);
        ptr = ptr->next;
    }
}

void enqueue(int val) {
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL) {
        printf("Queue is full");
    } else {
        n->data = val;
        n->next = NULL;
        if (f == NULL) { 
            f = n;
            r = n;
        } else {
            r->next = n;
            r = n;
        }
    }
}

int dequeue() {
    struct node *n = (struct node *)malloc(sizeof(struct node));
    int a=-1;
    if (f == NULL) {
        printf("Queue is empty");
        free(n);
        return -1;
    } else {
        a=f->data;
        n=f;
        f=f->next;
        free(n);
        return a;
    }
}

int main() {
    enqueue(37);
    enqueue(56);
    enqueue(78);
    linklist_traversal(f);
    int a;
    a=dequeue();
    printf("%d \n",a);
    linklist_traversal(f);
    return 0;
}
