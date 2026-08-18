#include <stdio.h>

void reverse(int arr[],int n,int a,int b){
    int start=a;
    int end=b;
    while(start<end){
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }

}
int main(void) {
    printf("Hello, World!\n");

    printf("enter no of values : ");
    int n;
    scanf("%d",&n);
    int nums[n];

    for(int i=0;i<n;i++){
        printf("enter val %d : ",i );
        scanf("%d",&nums[i]);
    }
    reverse(nums,n,0,n-1);
    printf("enter no of rotation : ");
    int rotate;
    scanf("%d",&rotate);
    reverse(nums,n,0,rotate-1);
    reverse(nums,n,rotate,n-1);
     printf("new array (after rotation): ");
    for(int i=0;i<n;i++){
        printf("%d ",nums[i] );
        
    }










    return 0;
}
