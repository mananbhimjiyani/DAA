//
// Created by MANAN on 17/09/24.
//
#include <stdio.h>

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int bubble_sort_count(int arr[], int n, int ascending) {
    int swap_count = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if ((ascending && arr[j] > arr[j+1]) || (!ascending && arr[j] < arr[j+1])) {
                // Swap the elements
                swap(&arr[j], &arr[j+1]);
                swap_count++;
            }
        }
    }
    return swap_count;
}

int min_swaps_to_beautiful(int arr[], int n) {
    // Copy the array for ascending and descending sorts
    int ascending_arr[n], descending_arr[n];

    // Copy the original array into both ascending_arr and descending_arr
    for (int i = 0; i < n; i++) {
        ascending_arr[i] = arr[i];
        descending_arr[i] = arr[i];
    }

    // Count swaps for ascending order
    int ascending_swaps = bubble_sort_count(ascending_arr, n, 1);

    // Count swaps for descending order
    int descending_swaps = bubble_sort_count(descending_arr, n, 0);

    // Return the minimum of both
    return (ascending_swaps < descending_swaps) ? ascending_swaps : descending_swaps;
}

int main() {
    int n;

    // Input the number of elements
    scanf("%d", &n);

    // Input the array elements
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Output the minimum swaps required to make the array beautiful
    printf("%d\n", min_swaps_to_beautiful(arr, n));

    return 0;
}