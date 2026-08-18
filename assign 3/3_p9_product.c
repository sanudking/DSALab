#include <stdio.h>
int main(){
    int size;
    printf("enter size : ");
    scanf("%d",&size);
    int arr[size];
    for(int i=0;i<size;i++){
        printf("enter element no %d : ",i);
        scanf("%d",&arr[i]);
    }
    int prefix[size];
    int suffix[size];
    prefix[0]=1;
    int product=1;
    for(int i=0;i<size;i++){
        prefix[i]=product;
        product*=arr[i];   
    }
    int product2=1;
    suffix[size-1]=1;
    for(int i=size-1;i>=0;i--){
        suffix[i]=product2;
        product2*=arr[i];  
    }
    for(int i=0;i<size;i++){
       arr[i]=prefix[i]*suffix[i];
    }
    printf("product of array except self: ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}