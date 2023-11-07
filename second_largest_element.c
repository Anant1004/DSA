#include <stdio.h>

void findSecondLargestAndSmallest(int arr[], int size) {
    if (size < 2) {
        printf("Array size should be at least 2.\n");
        return;
    }

    int first, second;
    if (arr[0] > arr[1]) {
        first = arr[0];
        second = arr[1];
    } else {
        first = arr[1];
        second = arr[0];
    }

    for (int i = 2; i < size; i++) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }

    int smallest, secondSmallest;
    if (arr[0] < arr[1]) {
        smallest = arr[0];
        secondSmallest = arr[1];
    } else {
        smallest = arr[1];
        secondSmallest = arr[0];
    }

    for (int i = 2; i < size; i++) {
        if (arr[i] < smallest) {
            secondSmallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < secondSmallest && arr[i] != smallest) {
            secondSmallest = arr[i];
        }
    }

    printf("The second largest element in the array: %d\n", second);
    printf("The second smallest element in the array: %d\n", secondSmallest);
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    if (size <= 0) {
        printf("Array size should be a positive integer.\n");
        return 1;
    }
    int array[size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    findSecondLargestAndSmallest(array, size);
    return 0;
}
