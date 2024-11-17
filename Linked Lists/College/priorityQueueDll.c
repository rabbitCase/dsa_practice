//pririty queue using circular double linked list
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    int priority;
    struct node *llink;
    struct node *rlink;
}*head=NULL;
void display(struct node *head){
    if(head==NULL){
        printf("\nEmpty list");
        return;
    }
    struct node *cur=head;
    do{
        printf("(%d,%d)->",cur->data,cur->priority);
        cur=cur->rlink;
    }while(cur!=head);
    printf("(%d, %d)[HEAD]",cur->data,cur->priority);
}

struct node* enqueue(struct node *head){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter data to insert: ");
    int data;
    scanf("%d",&data);
    printf("Enter its priority: ");
    int priority;
    scanf("%d",&priority);
    temp->data=data;
    temp->priority=priority;
    temp->rlink=temp->llink=NULL;
    if(head==NULL){
        head=temp;
        head->rlink=head->llink=head;
        return head;
    }
    struct node *cur=head;
    while(cur->rlink!=head){
        cur=cur->rlink;
    }
    temp->rlink=cur->rlink;
    temp->llink=cur;
    cur->rlink=temp;
    head->llink=temp;
    return head;
}
int findmin(struct node *head){
    int min=999;
    struct node* cur=head;
    do{
        if(cur->priority < min){
            min=cur->priority;
        }
        cur=cur->rlink;
    }while(cur!=head);
    return min;
}

struct node* dequeue(struct node* head){
    if(head->priority==findmin(head)){
        struct node *cur=head;
        do{
            cur=cur->rlink;
        }while(cur->rlink!=head);
        cur->rlink=cur->rlink->rlink;
        struct node *temp=head->llink;
        head=head->rlink;
        head->llink=temp;
        return head;
    }
    struct node *cur=head;
    struct node *prev=cur;
    do{
        if(cur->priority==findmin(head)){
            prev->rlink=cur->rlink;
            cur->rlink->llink=cur->llink;
        }
        prev=cur;
        cur=cur->rlink;
    }while(cur!=head);
    return head;
}

int main(){
    printf("Enqueueing 5 elements:\n");
    head=enqueue(head);
    head=enqueue(head);
    head=enqueue(head);
    head=enqueue(head);
    head=enqueue(head);
    printf("Your list: \n");
    display(head);
    head=dequeue(head);
    printf("\nAfter 1st dequeue:\n");
    display(head);
    head=dequeue(head);
    printf("\nAfter 2nd dequeue:\n");
    display(head);
}