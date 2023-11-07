#include <stdio.h>

int binarySearch(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid; // Element found, return its index
        }
        if (arr[mid] < key) {
            left = mid + 1; // Update the left boundary
        } else {
            right = mid - 1; // Update the right boundary
        }
    }
    return -1; // Element not found
}

int main() {
    int size, key;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Array size should be a positive integer.\n");
        return 1;
    }

    int array[size];

    printf("Enter %d sorted elements of the array:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    int index = binarySearch(array, size, key);

    if (index != -1) {
        printf("Element %d found at index: %d\n", key, index);
    } else {
        printf("Element %d not found in the array.\n", key);
    }

    return 0;
}
