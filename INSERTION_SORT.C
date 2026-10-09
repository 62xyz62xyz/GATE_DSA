#include <stdio.h>

int main()
{
    int arr[5] = {5, 3, 4, 1, 2};
    int i, j, key;

    // Print the original array before sorting
    printf("Original array: ");
    for (i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }

    // Start from the second element (index 1),
    // because the first element alone is already sorted.
    for (i = 1; i < 5; i++)
    {
        // Store the current element in key.
        // This is the element we want to insert
        // into its correct position.
        key = arr[i];

        // j points to the element immediately
        // to the left of key.
        j = i - 1;

        // Compare key with elements on its left.
        // If an element is greater than key,
        // shift that element one position to the right.
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];

            // Move one position to the left
            // to check the previous element.
            j--;
        }

        // Insert key into its correct position.
        // j + 1 is used because j may become -1
        // or stop at an element smaller than key.
        arr[j + 1] = key;
    }

    // Print the sorted array
    printf("\nSorted array: ");
    for (i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0; // End the program successfully
}
