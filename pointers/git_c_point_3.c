#include <stdio.h>
#include <string.h>
#define MAX_LEN 20
#define NUM_STRINGS 3
void makeStringsUppercase(char (*array)[MAX_LEN],int count){
    for(int i=0;i<count;i++){
        for(int j=0;array[i][j]!='\0';j++){
            if(array[i][j] >= 'a' && array[i][j] <= 'z'){
                array[i][j]-=32;
            }
        }
    }
    printf("\n");
}
int main()
{
    char arr[NUM_STRINGS][MAX_LEN] = {
        "Systems programming",
        "linux internals",
        "c language"
    };
    for(int i=0;i<NUM_STRINGS;i++) printf("%s\n",arr[i]);
    makeStringsUppercase(arr,NUM_STRINGS);
    for(int i=0;i<NUM_STRINGS;i++) printf("%s\n",arr[i]);
    return 0;
}
