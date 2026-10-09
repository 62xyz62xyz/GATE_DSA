#include <stdio.h>

/*
    MERGE SORT IN C
    ----------------
    Merge Sort uses the Divide and Conquer technique.

    STEP 1: DIVIDE
    Split the array into two halves until each part
    contains only one element.

    STEP 2: SORT
    A single-element array is already sorted.

    STEP 3: MERGE
    Compare elements from both sorted halves and
    combine them into one sorted array.

    TIME COMPLEXITY:
        Best Case    : O(n log n)
        Average Case : O(n log n)
        Worst Case   : O(n log n)

    EXTRA SPACE:
        O(n), because a temporary array is used.
*/

// This function merges two already-sorted parts
// of the original array.
//
// First part:  arr[left ... mid]
// Second part: arr[mid + 1 ... right]
void merge(int arr[], int left, int mid, int right)
{
    // i points to the first half.
    // j points to the second half.
    // k points to the temporary array.
    int i = left;
    int j = mid + 1;
    int k = 0;

    // Maximum number of elements in this section.
    int size = right - left + 1;

    // Temporary array stores the merged result.
    int temp[size];

    /*
       Compare the current elements of both halves.
       Copy the smaller element into temp[].
       Move the corresponding pointer forward.
    */
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }

        k++;
    }

    // If elements remain in the first half,
    // copy all of them into temp[].
    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    // If elements remain in the second half,
    // copy all of them into temp[].
    while (j <= right)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    /*
       Copy the merged, sorted elements back
       into their correct positions in arr[].
    */
    for (i = 0; i < size; i++)
    {
        arr[left + i] = temp[i];
    }
}

// Recursive function that performs Merge Sort.
void mergeSort(int arr[], int left, int right)
{
    /*
       BASE CASE:
       If left >= right, the section has zero
       or one element, so it is already sorted.
       Returning here also stops recursion.
    */
    if (left >= right)
    {
        return;
    }

    /*
       Find the middle index.
       This formula avoids possible overflow that
       can occur with (left + right) / 2.
    */
    int mid = left + (right - left) / 2;

    // DIVIDE AND SORT THE LEFT HALF.
    // Recursively sort arr[left ... mid].
    mergeSort(arr, left, mid);

    // DIVIDE AND SORT THE RIGHT HALF.
    // Recursively sort arr[mid + 1 ... right].
    mergeSort(arr, mid + 1, right);

    /*
       MERGE:
       Both halves are now sorted.
       Combine them into one sorted section.
    */
    merge(arr, left, mid, right);
}

// Main function: execution starts here.
int main(void)
{
    int n;

    // Ask the user how many elements to sort.
    printf("Enter the number of elements: ");

    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid array size.\n");
        return 1;
    }

    // Variable-length array: supported in C99.
    int arr[n];

    // Read the array elements.
    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &arr[i]) != 1)
        {
            printf("Invalid input.\n");
            return 1;
        }
    }

    // Call Merge Sort on the entire array.
    // Index 0 is the first element.
    // Index n - 1 is the last element.
    mergeSort(arr, 0, n - 1);

    // Display the sorted array.
    printf("Sorted array in ascending order:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0; // Program finished successfully.
}
