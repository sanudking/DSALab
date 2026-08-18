#include <stdio.h>

int main(void) {
    printf("Enter size of array: \n");
    int size;
    scanf("%d",&size);
    int arr[size];

    for(int i=0;i<size;i++){
        printf("enter price on day %d : ",i);
        scanf("%d",&arr[i]);
    }
    int min=arr[0];
    int profit=0;


    for(int i=0;i<size;i++){
        if(arr[i]<min){
            min=arr[i];
        }
        else if((arr[i]-min)>profit)
        profit=arr[i]-min;
    }
    printf("max profit = %d",profit);


    


    return 0;
}
