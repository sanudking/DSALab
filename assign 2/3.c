#include <stdio.h>
int main(void) {
    printf("Hello, World!\n");
    int m,n;
    printf("enter (row col) : ");
    scanf("%d %d",&m,&n);
    int arr[m][n];
    int row[100];
    int col[100];
    int val[100];
    int idx=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("enter matrix [%d %d]: ",i,j);
            scanf("%d",&arr[i][j]);
            if(arr[i][j]!=0){
                row[idx]=i;
                col[idx]=j;
                val[idx]=arr[i][j];
                idx++;
            }
        }
    }
    printf("Row: ");
    for(int i=0;i<idx;i++){
        printf("%d ",row[i]);
    }
    printf("\nCol: ");
    for(int i=0;i<idx;i++){
        printf("%d ",col[i]);
    }
    printf("\nVal: ");
    for(int i=0;i<idx;i++){
        printf("%d ",val[i]);
    }
    return 0;
}


