def merge_sort(arr):
    # Base case: A list of 0 or 1 elements is already sorted
    if len(arr) <= 1:
        return arr

    # Divide: Find the midpoint and split the array into halves
    mid = len(arr) // 2
    left_half = arr[:mid]
    right_half = arr[mid:]

    # Conquer: Recursively sort both halves
    left_sorted = merge_sort(left_half)
    right_sorted = merge_sort(right_half)

    # Merge: Combine the sorted halves
    return merge(left_sorted, right_sorted)


def merge(left, right):
    sorted_array = []
    i = j = 0

    # Compare elements from both lists and merge them in order
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            sorted_array.append(left[i])
            i += 1
        else:
            sorted_array.append(right[j])
            j += 1

    # Append any remaining elements left over from either list
    sorted_array.extend(left[i:])
    sorted_array.extend(right[j:])
    
    return sorted_array

# Example usage:
data = [38, 27, 43, 3, 9, 82, 10]
print("Original:", data)
print("Sorted:  ", merge_sort(data))
