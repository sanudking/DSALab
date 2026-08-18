#include <stdio.h>
int main(void) {
    printf("Hello, World!\n");
    int n ;   
    printf("size: ");
    scanf("%d",&n);
    int arr[n+1];
    int sum=0;
    for(int i=0;i<=n;i++){
        printf("enter element no %d : ",i);
        scanf("%d",&arr[i]);
        sum+=arr[i];
    }
    int total=(n*(n+1))/2;
    printf("%d %d ",sum,total);
    int res=sum-total;
    printf("duplicate number is: %d",res);
    return 0;
}
