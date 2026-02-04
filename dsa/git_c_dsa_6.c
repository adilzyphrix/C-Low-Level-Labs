//Not fully correct code. Scope issues are there in the first else-if clause in insert()
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#define COUNT 10 //no of nodes
typedef struct node{
    int val;
    struct node *next;
}node;
void insert(node *,int,int);
void traverse(node *);
int main()
{
    node *head = calloc(1,sizeof(node));
    if(!head){
        perror("Error");
        exit(1);
    }
    head->val = 10;
    node *p = head;
    for(int i=1;i<COUNT;i++){
        node *p1 = calloc(1,sizeof(node));
        if(!p1){
            perror("Error");
            exit(2);
        }
        p1->val = (i+1)*10;
        p->next = p1;
        p = p->next;
    }
    p = head; //Linked List made

    traverse(head); //before insertion
    insert(head,50,45); //insert the node with value 45 before the node with value 50 in the linked list
    traverse(head); //after insertion
    
    return 0;
}
void insert(node *p,int x,int y){
    if(p == NULL){
        printf("Empty list...Insertion unsuccessfull\n");
        exit(3);
    }
    else if(p->val == x){
        node *p1 = calloc(1,sizeof(node));
        if(!p1){
            perror("Error");
            exit(4);
        }
        p1->val = y;
        p1->next = p;
        p = p1;
    }
    else if(p->next == NULL){
        printf("At least two nodes needed...Insertion unsuccessfull\n");
        exit(5);
    }
    else{
        while(p->next != NULL && p->next->val != x)
            p = p->next;
        if(p->next == NULL){
            printf("%d not found...Insertion unsuccessfull\n",x);
            exit(6);
        }
        else{
            node *p1 = calloc(1,sizeof(node));
            if(!p1){
                perror("Error");
                exit(7);
            }
            p1->val = y;
            p1->next = p->next;
            p->next = p1;
        }
    }
}
void traverse(node *p){
    while(p != NULL){
        printf("%d %p\n",p->val,p->next);
        p = p->next;
    }
    printf("\n");
}
