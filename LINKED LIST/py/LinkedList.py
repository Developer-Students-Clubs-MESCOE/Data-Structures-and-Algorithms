#Program to implement Linked List in python and to remove Duplicate elements
class Node:
    def __init__(self,data):
        self.data = data
        self.next = None 
class Solution: 
    def insert(self,head,data):
            p = Node(data)           
            if head==None:
                head=p
            elif head.next==None:
                head.next=p
            else:
                start=head
                while(start.next!=None):
                    start=start.next
                start.next=p
            return head  
    def display(self,head):
        current = head
        while current:
            print(current.data,end=' ')
            current = current.next

    def removeDuplicates(self,head):
        current = head
        nxt=current.next
        while current.next!=None:
            nxt=current.next
            if(current.data==nxt.data):
                current.next = nxt.next
            else:
                current=current.next
        return head

mylist= Solution()
T=int(input("Enter a list of number to be added in Linked List:"))
head=None
for i in range(T):
    data=int(input())
    head=mylist.insert(head,data)  
print("Original Linked List : ")  
mylist.display(head);    
head=mylist.removeDuplicates(head)
print("Updated Linked List : ")
mylist.display(head); 
# Implemented by Vivek Ray
