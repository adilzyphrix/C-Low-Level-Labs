#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *next;
}node;

void traverse(node *); //printing the LL
node *create(int); //creating the LL
node *delete(node *,int);
void free_ll(node **);
int main()
{
    int count,val,x;
    printf("Enter the number of nodes: ");
    scanf("%d",&count);
    if(count <= 0){
        printf("At least one node required\n");
        return 1;
    }
    node *head = create(count);
    traverse(head);

    printf("Enter the value to delete: ");
    scanf("%d",&x);
    head = delete(head,x);

    printf("\nAfter deletion\n\n");
    traverse(head);

    free_ll(&head);
    return 0;
}

node *delete(node *p,int x){
    if(!p){
        printf("Empty list\n");
        return NULL;
    }
    else if(!(p->next)){
        if(p->val == x){
            free(p);
            p==NULL;
            return NULL;
        }
        else{
            printf("Node not found\n");
            return p;
        }
    }
    else{
        node *head = p;
        while(p->next->next && p->next->val != x)
            p = p->next;

        if(p->next->val == x){
            node *p1 = p->next;
            p->next = p->next->next;
            free(p1);
            p1 = NULL;

            return head;
        }
        else{
            printf("Node not found\n");
            return head;
        }
        
    }
}

void free_ll(node **p){
    node *tmp;
    while(*p){
        tmp = *p;
        (*p) = (*p)->next;
        free(tmp);
    }
}

void traverse(node *p){
    while(p != NULL){
        printf("%d\t%p\n",p->val,p->next);
        p = p->next;
    }
    printf("\n");
}

node *create(int count){
    node *head = calloc(1,sizeof(*head));
    if(!head){
        perror("Error");
        exit(1);
    }
    head->val = 10;
    node *p = calloc(1,sizeof(*p));
    if(!p){
        perror("Error");
        exit(1);
    }
    p = head;
    for(int i=1;i<count;i++){
        node *p1 = calloc(1,sizeof(*p1));
        if(!p1){
            perror("Error");
            exit(1);
        }
        p1->val = (i+1)*10;
        p->next = p1;
        p = p->next;
    }
    p = head;
    return head;
}
