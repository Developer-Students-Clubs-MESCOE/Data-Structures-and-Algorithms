# Python Program to search a number using Binary search
# Written by Lisha Ray

# Function to implement Binary search
def binary_search(lst,number_search):#lst is List: 
    low = 0
    high = len(lst) - 1
    mid = 0
  
    while low <= high: 
  
        mid = (high + low) // 2
  
        # Check if  number_search is present at mid 
        if lst[mid] < number_search : 
            low = mid + 1
  
        # If number_search is greater, ignore left half 
        elif lst[mid] > number_search : 
            high = mid - 1
  
        # If number_search is smaller, ignore right half 
        else: 
            print("Element is present at ",mid+1," position in Sorted List." ) 
            return 1
  
    # If we reach here, then the element was not present 
    print("Element is not present.")  


lst = [int(item) for item in input("Enter the list items : ").split()] 
print("Sorted Array is")
lst.sort()
print(lst)
number_search=int(input("Enter the number to be searched ="))
binary_search(lst,number_search)


#Enter the list items : 1 2 3 0
#Sorted Array is
#[0, 1, 2, 3]
#Enter the number to be searched =3
#Element is present at  4  position in Sorted List.