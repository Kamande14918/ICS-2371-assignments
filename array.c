#include <stdio.h>

void swap(int* xp, int* yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int marks[10] = { 12, 23, 34, 1, 22, 34, 56, 45, 33, 78 };
    int n = sizeof(marks) / sizeof(marks[0]);

    printf("Original array:\n");
    printArray(marks, n);
          Sort the array in ascending order
    selectionSort(marks, n);
      // Omit the middle element (fifth element)
    int omittedNumber = marks[n / 2];
    printf("\nOmitted number: %d\n", omittedNumber);

   // Insert the omitted number back
    marks[n / 2] = 0; // Replace with any desired value

     // Delete the inserted number
    // (We'll set it to 0 for demonstration purposes)
    printf("Deleted number: %d\n", omittedNumber);

    // Print the initial array
    printf("\nInitial array after modifications:\n");
    printArray(marks, n);

    return 0;
}
