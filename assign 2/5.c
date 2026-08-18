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
    int n = 10000;
    int arr1[10000];
    int arr2[10000];
    for (int i = 0; i < n; i++) {
        arr1[i] = n - i;
        arr2[i] = n - i;
    }
    clock_t start, end;
    start = clock();
    bubble_sort(arr1, n);
    end = clock();
    double time_bubble = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time for Bubble Sort:    %f seconds\n", time_bubble);
    start = clock();
    insertion_sort(arr2, n);
    end = clock();
    double time_insertion = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time for Insertion Sort: %f seconds\n", time_insertion);
    return 0;
}