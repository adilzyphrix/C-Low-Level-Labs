#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
typedef struct node{
    int val;
    struct node *next;
}node;
int main()
{
    int count; //number of nodes
    printf("Enter number of nodes: ");
    scanf("%d",&count);
    node *head = calloc(1,sizeof(node));
    if(!head) perror("Error");
    head->val = 10; //value of the first node
    node *p = head;
    for(int i=1;i<count;i++){
        node *p1 = calloc(1,sizeof(node));
        if(!p1) perror("Error");
        p1->val = (i+1)*10;
        p->next = p1;
        p = p->next;
    }
    p = head;

    while(p != NULL){
        printf("%d %p\n",p->val,p->next);
        p = p->next;
    }
    
    while(head != NULL){ //free every node
        node *tmp = head;
        head = head->next;
        free(tmp);
        tmp = NULL;
    }
    return 0;
}
