#include <stdio.h>

int main()
{
    int arr[100], n, i, j, temp;
    int swapped;

    // Step 1: Read the number of elements from the user
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Step 2: Read the array elements
    printf("Enter %d elements:\n", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Step 3: Apply Bubble Sort
    // The outer loop controls the number of passes.
    // After each pass, the largest unsorted element
    // moves to its correct position at the end.
    for (i = 0; i < n - 1; i++)
    {
        // Initially assume that no swapping is needed.
        // If no swap occurs, the array is already sorted.
        swapped = 0;

        // Compare adjacent elements.
        // The - i part avoids checking elements that
        // are already in their correct positions.
        for (j = 0; j < n - 1 - i; j++)
        {
            // If the current element is greater than
            // the next element, they are in the wrong order.
            if (arr[j] > arr[j + 1])
            {
                // Store the current element temporarily.
                temp = arr[j];

                // Move the next element to the current position.
                arr[j] = arr[j + 1];

                // Put the stored element in the next position.
                arr[j + 1] = temp;

                // Record that a swap has occurred.
                swapped = 1;
            }
        }

        // If no swaps occurred during this pass,
        // the array is already sorted, so stop early.
        if (swapped == 0)
        {
            break;
        }
    }

    // Step 4: Display the sorted array
    printf("Sorted array in ascending order:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;  // End the program successfully
}
