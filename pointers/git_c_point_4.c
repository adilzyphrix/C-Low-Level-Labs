#include <stdio.h>
#define SIZE 10
int max(int,int);
int main()
{
    int arr[SIZE] = {-1,3,4,2,5,-2,5,0,3,-3};
    int k = 4;
    int *l = &arr[0];
    int *r = &arr[k-1];
    int sum = 0;

    for(int i=0;i<k;i++) sum+=arr[i];
    int max_sum = sum;
    
    while(r < &arr[SIZE-1]){
        sum = sum - *l;
        l++;
        r++;
        sum = sum + *r;
        max_sum = max(max_sum,sum);
    }
    printf("Maximum sum: %d\n",max_sum);
    return 0;
}
int max(int max_sum,int sum){
    return (max_sum >= sum) ? max_sum : sum;
}