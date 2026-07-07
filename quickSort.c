#include <stdio.h>
#include <stdbool.h>

/* Ordenamiento utilizando pivotes y Two Pointers */
int partition(int *arr, int low, int high) {
    int pivot = arr[high];

    int i = low - 1;
    for (size_t j = low; j < high; j++) {
        if (arr[j]<pivot) {
            i++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    int temp = arr[high];
    arr[high] = arr[i+1];
    arr[i+1] = temp;
    
    return i+1;
}
void quickSort(int *arr, int low, int high) {
    if (low > high) {
        return;
    }
    
    int pivot = partition(arr, low, high);

    // Left
    quickSort(arr, low, pivot-1);
    quickSort(arr, pivot+1, high);
}

bool sortTest(int *arr, int len) {
    for (size_t i = 0; i < len-1; i++) {
        if (arr[i] > arr[i+1]) {
            puts("The array is not sorted!");
            return false;
        }
    }
    puts("The array is sorted!");
    return true;
}

int main (int argv, char *argc[argv+1]) {
    int arr[7] = {10, 6, 3, 4, 9, 10, 7};
    int len = 7;
    quickSort(arr, 0, len-1);
    
    for (int i = 0; i < len; i++) {
        printf("Element %d:%d\n", i, arr[i]);
    }
    
   sortTest(arr, len-1);
}
 
