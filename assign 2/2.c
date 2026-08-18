#include <stdio.h>

int main(void) {
    printf("Hello, World!\n");
    int nums[100];

    printf("enter no of values : ");
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter val %d : ",i );
        scanf("%d",&nums[i]);
    }
    int l1=nums[0]>nums[1]?nums[0]:nums[1];
    int l2=nums[0]<nums[1]?nums[0]:nums[1];
    for(int i=2;i<n;i++){
        if(nums[i]>l1){
            l2=l1;
            l1=nums[i];
            
        }
        else if(nums[i]<l1 && nums[i]>l2){
            l2=nums[i];
            
        }
    }
    printf("second largest : %d",l2);

    int s1=nums[0]<nums[1]?nums[0]:nums[1];
    int s2=nums[0]>nums[1]?nums[0]:nums[1];
    
    for(int i=2;i<n;i++){
        if(nums[i]<s1){
            s2=s1;
            s1=nums[i];
           
        }
        else if (nums[i] < s2 && nums[i] > s1) {
            s2 = nums[i];
        }
    }
    printf("\nsecond smallest : %d",s2);
    






    return 0;
}
