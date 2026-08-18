#include <stdio.h>
#include <time.h>
void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}
int main() {
    int arr1[10000];
    int n=sizeof(arr1)/sizeof(arr1[0]);
    for(int i=0;i<n;i++){
        arr1[i]=n-i;
    }
    clock_t start,end;
    double time_used;
    start=clock();
    bubble_sort(arr1,n);
    end=clock();
    time_used=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Time for bubble sort: %lf",time_used);
    insertion_sort(arr1,n);
    double time_used1;
    start=clock();
    end=clock();
    time_used1=((double)(end-start))/CLOCKS_PER_SEC;
    printf("\nTime for insertion sort: %lf",time_used1);
    return 0;
}
