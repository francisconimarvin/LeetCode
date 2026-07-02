#include <stdio.h>

// Challenge 1: Hacer un Merge Sort
/*
 * MergeSort es dividir un arreglo en 2 mitades de forma repetida hasta que solo queden numeros individuales
 * La idea es que luego los números se comparen unos con otros para que luego puedan ser ordenado.
 * */

/* Un arreglo o lista tiene un tamaño n.
 * La parte izquierda de la primera división va desde arr[left] hasta arr[mid]
 * La parte derecha de la primera división va desde arr[mid+1] hasta arr[right]
 *
 * Donde:
 *  left = 0
 *  right = n - 1
 *  mid = (right + left)/2
 *
 *  */


void merge(int *arr, int left, int mid, int right) {
    // Get lengths
    int n1 = mid - left + 1;
    int n2 = right -  mid;

    // Temp arrays
    int tempL[n1];
    int tempR[n2];

    int i, j, k;

    for (size_t i = 0; i<n1; i++) {
        tempL[i] = arr[left + i];
    }

    for (size_t j = 0; j<n2; j++) {
        tempR[j] = arr[mid+1+j];
    }

    // Comparisons and merge the two temps
    i = 0;
    j = 0;
    k = left;

    while (i<n1 && j<n2) {
        if (tempL[i]<=tempR[j]) {
            arr[k] = tempL[i];
            i++;
        } else {
            arr[k] = tempR[j];
            j++;
        }
        k++;
    }

    // Remaining (in case there are not even data to compare) 
    while (i < n1) {
        arr[k] = tempL[i];
        k++;
        i++;
    }

    while (j < n2) {
        arr[k] = tempR[j];
        k++;
        j++;
    }


}

void mergeSort(int *arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = (left + right) / 2;

    // Left
    mergeSort(arr, left, mid);
    // Right
    mergeSort(arr, mid+1, right);

    merge(arr, left, mid, right);
}
int main (int argv, char *argc[argv + 1]) {
    int arr[7] = {5, 6, 3, 4, 9, 10, 7};
    int len = 7;
    mergeSort(arr, 0, len-1);
    
    for (int i = 0; i < len; i++) {
        printf("Element %d:%d\n", i, arr[i]);
    }
}



