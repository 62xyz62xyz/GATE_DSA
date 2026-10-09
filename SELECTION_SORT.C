#include <stdio.h>

int main()
{
    // Declare an array to store up to 100 elements.
    // n stores the number of elements.
    // i and j are loop variables.
    // minIndex stores the index of the smallest element.
    // temp is used for swapping two elements.
    int arr[100], n, i, j, minIndex, temp;

    // Ask the user to enter the number of elements.
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Check whether the number of elements is valid.
    // The array can store a maximum of 100 elements.
    if (n < 1 || n > 100)
    {
        printf("Please enter a size between 1 and 100.\n");
        return 1;
    }

    // Read all the elements into the array.
    printf("Enter the elements:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // SELECTION SORT:
    // The outer loop selects the position where
    // the next smallest element should be placed.
    // We use n - 1 because the last element will
    // automatically be in its correct position.
    for (i = 0; i < n - 1; i++)
    {
        // Assume that the current element is the smallest.
        // minIndex stores its index, not its value.
        minIndex = i;

        // Search for a smaller element in the unsorted part.
        // Start from i + 1 because arr[i] is already
        // considered the current minimum.
        for (j = i + 1; j < n; j++)
        {
            // If the current element is smaller than
            // the element at minIndex, update minIndex.
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        // After the inner loop, minIndex contains
        // the index of the smallest remaining element.

        // Swap arr[i] and arr[minIndex] using temp.
        // First, save arr[i] in temp.
        temp = arr[i];

        // Place the smallest element at position i.
        arr[i] = arr[minIndex];

        // Move the original arr[i] to minIndex.
        arr[minIndex] = temp;

        // Now, the element at position i is sorted.
        // The sorted portion grows by one element
        // after every pass of the outer loop.
    }

    // Display the array after sorting in ascending order.
    printf("Sorted array in ascending order:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    // Return 0 to indicate successful execution.
    return 0;
}
