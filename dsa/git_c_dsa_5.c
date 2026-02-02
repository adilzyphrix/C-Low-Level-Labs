#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
typedef struct node{
    int val;
    struct node *next;
}node;

void insert(node *,int,int); //insert the value at the 3rd parameter after the value at the 2nd parameter
void traverse(node *); //print the LL
int main()
{
    int count; //number of nodes
    printf("Enter number of nodes: ");
    if (scanf("%d",&count) != 1 || count <= 0){ //edge case checking
        printf("At least one node needed\n");
        exit(1);
    }
    node *head = calloc(1,sizeof(node));
    if(!head) perror("Error");
    head->val = 10; //value of the first node
    node *p = head;
    for(int i=1;i<count;i++){ //initializing each node with values 10,20,30...
        node *p1 = calloc(1,sizeof(node));
        if(!p1) perror("Error");
        p1->val = (i+1)*10;
        p->next = p1;
        p = p->next;
    }
    p = head;

    traverse(head); //before insertion
    insert(head,30,35); //insert a ndoe with value 35 after the node with value 30 in the LL
    traverse(head); //after insertion

    while(head != NULL){ //free the LL
        node *tmp = head;
        head = head->next;
        free(tmp);
    }
    return 0;
}
void insert(node *p,int x,int y){
    if(p==NULL){ //if the LL is empty
        printf("Linked List empty\n");
        exit(2);
    }
    else{
        while(p != NULL && p->val != x) //traversing until we find 'x' or we reach NULL
            p = p->next;
        if(p == NULL){ //means value 'x' not found
            printf("Value %d not found\n",x);
            exit(3);
        }
        else{ //value 'x' found
            node *p1 = calloc(1,sizeof(node));
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
