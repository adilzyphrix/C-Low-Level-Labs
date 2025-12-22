/*
    Implementing dynamic memory allocation
    to allocate space for 3 jagged arrays(of different sizes).
    Taking input from the user and then printing the array elements.
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *arr[3] = {NULL}; //initializing to NULL
    int sizes[] = {3,4,5}; //sizes of each jagged arrays

    for(int i=0;i<3;i++){
        arr[i] = (int *)malloc(sizes[i] * sizeof(int)); //dynamic memory allocation
        if(arr[i]==NULL) return 1; //in case of unsuccessful allocation
    }

    for(int i=0;i<3;i++){
        printf("Row %d elements(maximum %d integers allowed): ",i,sizes[i]);
        for(int j=0;j<sizes[i];j++){
            scanf(" %d",&arr[i][j]); //taking integers as inputs for each jagged array
        }
    }

    printf("The jagged arrays are as follows\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<sizes[i];j++)
            printf("%d ",arr[i][j]);
        printf("\n");
    }

    for(int i=3-1;i>=0;i--){
        free(arr[i]); //freeing memory in reverse order
        arr[i] = NULL; //preventing dangling pointers
    }

>>>>>>> 21ca3bd (Implementing jagged integer arrays using array of pointers)
    return 0;
}
