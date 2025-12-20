#include <stdio.h>
#define ROW 3
#define COL 4
void show(int (*)[COL],int);
int main()
{
    int arr[ROW][COL] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    show(arr,ROW);
    return 0;
}
void show(int(*arr)[COL],int row){
    int i=0,*p;
    for(;i<row;i++){
        p = (int *)(arr+i);
        for(int j=0;j<COL;j++) printf("%d ",p[j]);
        printf("\n");
    }
}