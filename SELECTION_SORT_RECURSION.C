#include <stdio.h>

// Recursive function to perform Selection Sort.
// arr[] is the array and n is its size.
// index represents the current position to be sorted.
void selectionSort(int arr[], int n, int index)
{
    // BASE CASE:
    // If index reaches n - 1, only one element remains.
    // That element must already be in its correct position.
    // Return to stop the recursion.
    if (index >= n - 1)
    {
        return;
    }

    // Assume the current element is the smallest.
    // Store its index in minIndex.
    int minIndex = index;

    // Search for the smallest element in the
    // unsorted portion of the array.
    for (int j = index + 1; j < n; j++)
    {
        // If a smaller element is found,
        // update minIndex to its position.
        if (arr[j] < arr[minIndex])
        {
            minIndex = j;
        }
    }

    // Swap the smallest element with the element
    // at the current index.
    int temp = arr[index];
    arr[index] = arr[minIndex];
    arr[minIndex] = temp;

    // RECURSIVE CALL:
    // The element at index is now in its correct place.
    // Recursively sort the remaining portion by
    // moving to the next index.
    selectionSort(arr, n, index + 1);
}

int main()
{
    // Declare an array of maximum size 100.
    // n stores the number of elements.
    int arr[100], n;

    // Read the number of elements.
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Validate the array size to prevent invalid access.
    if (n < 1 || n > 100)
    {
        printf("Please enter a size between 1 and 100.\n");
        return 1;
    }

    // Read the array elements.
    printf("Enter the elements:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Call the recursive Selection Sort function.
    // Start at index 0 because the first position
    // is the first position that needs sorting.
    selectionSort(arr, n, 0);

    // Print the sorted array in ascending order.
    printf("Sorted array in ascending order:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    // End the program successfully.
    return 0;
}
