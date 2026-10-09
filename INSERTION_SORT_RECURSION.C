#include <stdio.h>

// This function inserts the key into its correct
// position in the already-sorted portion of the array.
void insert(int arr[], int n, int key)
{
    // BASE CASE:
    // If n becomes 0, there are no more elements
    // to compare with key. Place key at index 0.
    if (n == 0 || arr[n - 1] <= key)
    {
        arr[n] = key;
        return;
    }

    // If the last element of the sorted portion
    // is greater than key, shift it one position right.
    arr[n] = arr[n - 1];

    // RECURSIVE CALL:
    // Continue searching for the correct position
    // of key in the remaining sorted portion.
    insert(arr, n - 1, key);
}

// This function recursively sorts the array.
void insertionSort(int arr[], int n)
{
    // BASE CASE:
    // An array with 0 or 1 element is already sorted.
    if (n <= 1)
    {
        return;
    }

    // RECURSIVE CALL:
    // First sort the first n - 1 elements.
    insertionSort(arr, n - 1);

    // Store the last element of the current portion.
    // This element must be inserted into its correct place.
    int key = arr[n - 1];

    // Insert key into the sorted first n - 1 elements.
    insert(arr, n - 1, key);
}

int main()
{
    // Declare and initialize the array.
    int arr[] = {5, 3, 4, 1, 2};

    // Calculate the number of elements in the array.
    int n = sizeof(arr) / sizeof(arr[0]);

    // Print the original array.
    printf("Original array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    // Call the recursive insertion sort function.
    insertionSort(arr, n);

    // Print the sorted array.
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0; // End the program successfully.
}
