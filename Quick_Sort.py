def quick_sort(arr, low=0, high=None):
    """
    Main Quick Sort function. 
    It follows the Divide and Conquer strategy to sort an array in-place.
    
    Time Complexity: O(n log n) average, O(n²) worst-case.
    Space Complexity: O(log n) due to the recursive call stack.
    """
    # Initialize the high pointer to the last index on the first call
    if high is None:
        high = len(arr) - 1

    # BASE CASE: If the subarray has 0 or 1 elements, it is already sorted
    if low >= high:
        return arr

    # DIVIDE: Partition the array and get the final sorted index of the pivot
    pivot_index = partition(arr, low, high)

    # CONQUER: Recursively sort the left partition (elements smaller than pivot)
    quick_sort(arr, low, pivot_index - 1)

    # CONQUER: Recursively sort the right partition (elements larger than pivot)
    quick_sort(arr, pivot_index + 1, high)

    return arr


def partition(arr, low, high):
    """
    Rearranges the array around a pivot element.
    All elements smaller than the pivot go to its left.
    All elements greater than the pivot go to its right.
    """
    # 1. PIVOT SELECTION: Pick the rightmost element as the pivot
    pivot = arr[high]
    
    # 2. TRACKER: 'i' marks the boundary for elements smaller than the pivot.
    # It starts just before the first element of the current window.
    i = low - 1

    # 3. SCAN: Iterate through the array from 'low' to 'high - 1'
    for j in range(low, high):
        # If the current element is smaller than or equal to the pivot...
        if arr[j] <= pivot:
            # Move the boundary forward
            i += 1
            # Swap the smaller element into its correct left-side zone
            arr[i], arr[j] = arr[j], arr[i]

    # 4. PLACE PIVOT: Swap the pivot element with the element at index (i + 1).
    # This places the pivot exactly between the smaller and larger elements.
    arr[i + 1], arr[high] = arr[high], arr[i + 1]

    # Return the final index of the pivot so the main function knows where to split
    return i + 1


# --- Example Execution ---
if __name__ == "__main__":
    data = [24, 9, 2, 15, 82, 13, 24, 7]
    print("Original array:", data)
    
    quick_sort(data)
    print("Sorted array:  ", data)
