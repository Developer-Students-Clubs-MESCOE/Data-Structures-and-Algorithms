# Python Program to Implement Bubble Sort
# Written by Lisha Ray

# Function to calculate Factorial of a number
def bubble_sort(lst):
    for i in range(len(lst)):
        for j in range(len(lst)-1):
            if lst[j] > lst[j+1]:
                temp=lst[j]
                lst[j]=lst[j+1]
                lst[j+1]=temp
    return lst

lst = [int(item) for item in input("Enter the list items : ").split()] 
print("Sorted list = ",bubble_sort(lst)) 

#Output:
#Enter the list items : 1 3 5 7 9 2 4 6 8 0
#Sorted list =  [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
