#include <stdio.h>
#define SIZE 10

int max(int,int);

int main()
{
    int arr[SIZE] = {7,2,1,5,3,7,0,2,4,8};
    int k = 10;
    int l=0,r=0,max_len=0,sum=0;

    while(r < SIZE){
        sum+=arr[r];
        if(sum > k){
            sum-=arr[l];
            ++l;
        }
        if(sum <= k) max_len = max(max_len,r-l+1);
        ++r;
    }
    printf("Maximum length of subarray where sum<=%d is %d\n",k,max_len);
    return 0;
}
int max(int max_len,int arr_len){
    return (max_len > arr_len) ? max_len : arr_len;
}