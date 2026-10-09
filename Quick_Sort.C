#include <stdio.h>

// Function to place the pivot in its correct position
// and arrange smaller elements on the left and larger on the right
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];  // Choose the last element as pivot
    int i = low - 1;         // Tracks the position of smaller elements

    for (int j = low; j < high; j++)
    {
        // If the current element is smaller than or equal to pivot
        if (arr[j] <= pivot)
        {
            i++;  // Move the smaller-element boundary forward

            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Place the pivot immediately after the smaller elements
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    // Return the pivot's correct position
    return i + 1;
}

// Function to sort the array using Quick Sort
void quickSort(int arr[], int low, int high)
{
    // Continue only if the subarray has at least two elements
    if (low < high)
    {
        // Partition the array and get the pivot's position
        int pi = partition(arr, low, high);

        // Sort the elements to the left of the pivot
        quickSort(arr, low, pi - 1);

        // Sort the elements to the right of the pivot
        quickSort(arr, pi + 1, high);
    }
}

// Main function
int main()
{
    int arr[] = { 8, 3, 1, 7, 0, 10, 2 };

    // Calculate the number of elements in the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Call Quick Sort for the entire array
    quickSort(arr, 0, n - 1);

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
