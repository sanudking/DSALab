#include <stdio.h>
int main(void) {
    printf("Hello, World!\n");
    printf("Enter size of array: ");
    int size;
    scanf("%d",&size);
    int arr[size];
    for(int i=0;i<size;i++){
        printf("enter element no %d : ",i);
        scanf("%d",&arr[i]);
    }
    int arr2[1000]={0};
    for(int i=0;i<1;i++){
        arr2[i]=0;
    }
    for(int i=0;i<size;i++){
        arr2[arr[i]]+=1;
    }
    for(int i=0;i<1000;i++){
        if(arr2[i]!=0){
            printf("%d: %d \n",i,arr2[i]);
        }
    }
    return 0;
}
