/*Leetcode 83 - Remove duplicates from SORTED list.

In case of warning "arr intitialized and declared extern"
compile it with the option -w
like, in case of GCC

gcc filename.c -w

*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

extern int arr[] = {1,1,2,3,3,4,5}; //values of each node in ascending(SORTED) order

typedef struct node{
    int val;
    struct node *next;
}node;

node *create(); //creating the list
void traverse(node *); //printing the list
node *remove_dupli(node *); //removing duplicates from the list
void free_ll(node **); //freeing the list
int main()
{
    printf("Initial list\n\n");
    node *head = create(); //creation of the list
    traverse(head);

    printf("List after removing all duplicates\n\n");
    head = remove_dupli(head); //removing duplicates from the list
    traverse(head);

    free_ll(&head);
    return 0;
}

node *remove_dupli(node *head){
    if(head == NULL) return NULL; //if the head is empty
    else{
        node *p = head;
        while(p != NULL && p->next != NULL){
            if(p->val == p->next->val){ //just skip that node and point to the node after it
                node *tmp = p->next;
                p->next = p->next->next;
                free(tmp);
                tmp = NULL;
            }
            else{
                p = p->next;
            }
        }
        return head;
    }
}

node *create(){
    int count = sizeof(arr)/sizeof(arr[0]); //number of nodes
    node *head = calloc(1,sizeof(*head));
    if(!head){
        perror("Error");
        exit(1);
    }
    head->val = arr[0];
    node *p = head;
    for(int i=1;i<count;i++){
        node *p1 = calloc(1,sizeof(*p1));
        if(!p1){
            perror("Error");
            exit(2);
        }
        p1->val = arr[i];
        p->next = p1;
        p = p->next;
    }
    return head;
}

void traverse(node *p){
    while(p != NULL){
        printf("%d %p\n",p->val,p->next);
        p = p->next;
    }
    printf("\n");
}

void free_ll(node **p){
    node *tmp;
    while(*p != NULL){
        tmp = *p;
        (*p) = (*p)->next;
        free(tmp);
    }
}
