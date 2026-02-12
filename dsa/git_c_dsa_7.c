/*Leetcode 21 - Merge two sorted lists*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#define COUNT 10 //no of nodes in list1 and list2
typedef struct node{
    int val;
    struct node *next;
}node;

node *create1(); //creating 1st list
node *create2(); //creating 2nd list
void traverse(node *); //printing the list
void free_ll(node **); //freeing the list
node *merge(node *,node *); //merging the two lists

int main()
{
    node *list1 = create1(); //head of 1st list
    node *list2 = create2(); //head of 2nd list
    traverse(list1);
    traverse(list2);

    node *head = merge(list1,list2);
    traverse(head);

    free_ll(&head);
    return 0;
}
node *merge(node *list1,node *list2){
    if(list1 == NULL && list2 == NULL) return NULL;
    else if(list1 == NULL && list2 != NULL) return list2;
    else if(list1 != NULL && list2 == NULL) return list1;
    else{
        node dummy; //a dummy node
        node *tail = &dummy; // a tail pointer that'll point to the end of out growing merged list
        dummy.next = NULL;

        while(list1 != NULL && list2 != NULL){
            if(list1->val <= list2->val){
                tail->next = list1;
                list1 = list1->next;
            }
            else{
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        if(!list1) tail->next = list2; // if list1 runs out then attach list2 to the end
        else tail->next = list1;

        return dummy.next;
    }
}

node *create1(){
    node *head = calloc(1,sizeof(*head));
    if(!head){
        perror("Error");
        exit(1);
    }
    node *p = head;
    for(int i=0;i<COUNT;i++){
        node *p1 = calloc(1,sizeof(*p1));
        if(!p1){
            perror("Error");
            exit(2);
        }
        p1->val = (i+1)*10;
        p->next = p1;
        p = p->next;
    }
    p = head;
    return head;
}

node *create2(){
    node *head = calloc(1,sizeof(*head));
    if(!head){
        perror("Error");
        exit(1);
    }
    node *p = head;
    for(int i=0;i<COUNT;i++){
        node *p1 = calloc(1,sizeof(*p1));
        if(!p1){
            perror("Error");
            exit(2);
        }
        p1->val = (i+1.5)*10;
        p->next = p1;
        p = p->next;
    }
    p = head;
    return head;
}

void traverse(node *p){
    while(p!=NULL){
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
