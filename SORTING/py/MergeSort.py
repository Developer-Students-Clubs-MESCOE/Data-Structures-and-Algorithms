# Python program to implementation of Merge Sort Algorithm
# Time Complexity : Ω(n log(n))


def mergeSort(array):
    if (len(array) > 1):
        mid = len(array) // 2
        # Dividing the array elements into two sub arrays
        left = array[:mid]
        right = array[mid:]

        #Sorting Two Half of arrays seperately
        mergeSort(left)
        mergeSort(right)

        i = j = k = 0

        # Copy data to temp arrays L[] and R[]
        while (i < len(left) and j < len(right)):
            if (left[i] < right[j]):
                array[k] = left[i]
                i += 1
            else:
                array[k] = right[j]
                j += 1
            k += 1

        # Checking if any element was left
        while (i < len(left)):
            array[k] = left[i]
            i += 1
            k += 1

        while (j < len(right)):
            array[k] = right[j]
            j += 1
            k += 1



# driver code for testing
if __name__ == "__main__":
    array = [ 4, 10, 15, 35, -30, 23, -9, 50, 0]

    print ("Before Sorting : ", array)
    mergeSort(array)
    print ("After Sorting : ", array)

