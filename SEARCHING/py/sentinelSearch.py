List = []

def entry():
    global num
    num=int(input("Enter len of list"))
    for i in range(num):
        rollno=int(input("Enter values"))
        List.append(rollno)
    print(List)


def sentinelSearch():
    x= int(input("enter search element"))
    temp = List[num-1]
    List[num-1]=x
    i=0
    for j in range(num):
        if List[i]!=x:
            i+=1

    List[num-1]=temp
    if (i< num-1 or temp==x):
        print("Element found, index: ",i)

       