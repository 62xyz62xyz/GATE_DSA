#include <stdio.h>

// Recursive function to perform Bubble Sort
void bubbleSort(int arr[], int n)
{
    int i, temp;

    // BASE CASE:
    // If the array has 0 or 1 element,
    // it is already sorted, so stop recursion.
    if (n <= 1)
    {
        return;
    }

    // STEP 1:
    // Compare adjacent elements in one pass.
    // Move the largest element to the end.
    for (i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            // Swap adjacent elements
            temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }

    // STEP 2:
    // The largest element is now at index n - 1.
    // Recursively sort the remaining n - 1 elements.
    bubbleSort(arr, n - 1);
}

int main()
{
    int arr[100], n, i;

    // Read the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Validate the array size
    if (n < 1 || n > 100)
    {
        printf("Please enter a size between 1 and 100.\n");
        return 1;
    }

    // Read array elements
    printf("Enter %d elements:\n", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Call the recursive Bubble Sort function
    bubbleSort(arr, n);

    // Display the sorted array
    printf("Sorted array in ascending order:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}
