"""Jump Search can only be used on a Sorted Array.
Jump Search is technique that aims at doing lesser iterations for searching an element.
It keeps searching the element at an interval depending on jump size.
If the iteration reaches till end or the element appears to be greater than the element to find,
then it use linear search from that index to the beginning of the array and gets the element."""

import math
class JumpSearch:
    def __init__(self,arr):
        print("Enter Elements of array, press q to stop entering elements:")
        c = 1
        while c == 1:
            n = input()
            if n == 'q':
                c = 0
                break
            try:
                n = int(n)
                arr.append(n)
            except:
                print("Invalid Input")
    
    def sort(self,arr):
        n = len(arr)
        # looping through all elements of the array
        # using n-1 because at last iteration the loop will run even if the data is sorted
        # and increase time required unnecessarily
        for i in range(n-1):
            # using n-i-1 because the last element would be in the place after loop runs
            # one time so we can proceed with only remaining elements
            for j in range(n-i-1):
                if arr[j]>arr[j+1]:
                    t = arr[j]
                    arr[j] = arr[j+1]
                    arr[j+1] = t
        print("Sorted Array:")
        print(arr)
    def jump(self,arr):
        c = 0
        n = len(arr)
        ns = int(input("Enter Number to search:"))
        js = int(math.sqrt(n))# Jump Size
        for i in range(0,n,js):# jump search till end of array
            if ns == arr[i]:
                print(str(ns)+" found at index "+str(i))
            elif ns < arr[i]:
                bs = i;
        for j in range(n-1,0,-1):# linear search till start of array
            if  ns == arr[j]:
                print(str(ns)+" found at index "+str(i))
                c += 1
        if c == 0:
            print("Not Found")
arr = list()
obj = JumpSearch(arr)
obj.sort(arr)
obj.jump(arr)
