#include <stdio.h>
int main(void) {
    int loads[6]={2,0,0,0,0,2};
    int eqb[6];
    int n=6;
    int j=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=loads[i];
    }
    int left_sum=0;
    int right_sum=0;
    for(int i=0;i<n;i++){
        right_sum=sum-left_sum-loads[i];
        if(left_sum==right_sum){
            eqb[j]=i;
            j++;
        }
        left_sum+=loads[i];
    }
    printf("eqb index at : ");
    for(int i=0;i<j;i++){
        printf("%d ",eqb[i]);
    }
    return 0;
}
