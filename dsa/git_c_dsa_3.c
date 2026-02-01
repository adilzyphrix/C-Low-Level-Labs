#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#define COUNT 10

struct node{
    int val;
    struct node *next;
}ll[COUNT];

void traverse(struct node *);
int main()
{
    struct node *head = NULL;
    for(int i=0;i<COUNT;i++){
        ll[i].val = (i+1)*10;
        if(i<COUNT-1) ll[i].next = &ll[i+1];
    }
    head = &ll[0];
    traverse(head);
    return 0;
}
void traverse(struct node *trv){
    while(trv != NULL){
        printf("%d %p\n",trv->val,trv->next);
        trv = trv->next;
    }
}
