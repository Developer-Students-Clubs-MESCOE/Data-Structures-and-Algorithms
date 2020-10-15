class LinkedList:
    def __init__(self):
        self.head = None

    # method adds elements to the left of the Linked List
    def addToStart(self, data):
        # create a temporary node
        tempNode = Node(data)
        tempNode.setLink(self.head)
        self.head = tempNode
        del tempNode

    # method adds elements to the right of the Linked List
    def addToEnd(self, data):
        start = self.head
        tempNode = Node(data)
        while start.getNextNode():
            start = start.getNextNode()
        start.setLink(tempNode)
        del tempNode
        return True
    # method displays Linked List
    def display(self):
        start = self.head
        if start is None:
            print("Empty List!!!")
            return False

        while start:
            print(str(start.getData()), end=" ")
            start = start.link
            if start:
                print("-->", end=" ")
        print()

# to create linkedlist
myList = LinkedList()

# adding some elements to the start of LinkedList
myList.addToStart(5)
myList.addToStart(4)
myList.addToStart(3)
myList.addToStart(2)
myList.addToStart(1)
myList.display()

# adding some elements to the End of the LinkedList
myList.addToEnd(12)
myList.addToEnd(13)
myList.addToEnd(3)
myList.display()
=======
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

