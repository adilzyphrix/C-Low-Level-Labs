#include <stdio.h>
#define ROW 3
#define COL 4 

void display(int *,int);
int main()
{
    int arr[ROW][COL] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    display((int *)arr,ROW);
    return 0;
}
void display(int *q,int row){
    int i=0,j=0;
    for(;i<row;i++){
        for(j=0;j<COL;j++) printf("%d ",*(q + i*COL + j));
        printf("\n");
    }
}
