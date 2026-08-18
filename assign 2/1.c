#include <stdio.h>
//WAP to insert or delete an element from an array


int main(void) {
    int nums[100];

    printf("enter no of values : ");
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter val %d : ",i );
        scanf("%d",&nums[i]);
    }


    //insert
    printf("enter value to add: ");
    int num;
    scanf("%d",&num);
    printf("enter position to add: ");
    int pos;
    scanf("%d",&pos);
    for (int i=n;i>pos;i--){
        nums[i]=nums[i-1];
    }
    nums[pos]=num;
    printf("new array (insert): ");
    for(int i=0;i<n+1;i++){
        printf("%d ",nums[i] );
    }
    
    //delete
    printf("\nenter position to delete: ");
    int pos2;
    scanf("%d",&pos2);
    for (int i=pos2;i<n;i++){
        nums[i]=nums[i+1];
    }
    printf("new array (delete): ");
    for(int i=0;i<n;i++){
        printf("%d ",nums[i] );
        
    }





    return 0;
}
