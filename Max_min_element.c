#include<stdio.h>
int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
int findMin(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}
int main() {
    int size, choice;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the elements of the array: \n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter 1 to find the maximum element or 2 to find the minimum element: ");
    scanf("%d", &choice);

    if (choice == 1) {
        int max = findMax(arr, size);
        printf("The maximum element in the array is: %d\n", max);
    } else if (choice == 2) {
        int min = findMin(arr, size);
        printf("The minimum element in the array is: %d\n", min);
    } else {
        printf("Invalid choice. Please enter 1 for maximum or 2 for minimum.\n");
    }

    return 0;
}
