#include <iostream>
using namespace std;

/*-------------------------List Item-------------------------*/
template <class T>
struct ListItem
{
    T value;               //Data Item
    ListItem<T> *next;     //Pointer to the next item of the List
    ListItem<T> *previous; //Pointer to the previous item of the list

    T &getValue() //I know the encapsulation is being violated here :/
    {
        return value;
    }
};

/*-------------------------Doubly Linked List-------------------------*/
template <class T>
class List
{

private:
    ListItem<T> *head;
    ListItem<T> *tail;

public:
    // Default Constructor
    List()
    {
        head = tail = NULL;
    }

    // Copy Constructor
    List(const List<T> &otherList)
    {
        //If the other list is empty then make the current list empty too.
        if (otherList.head == NULL)
        {
            head = NULL;
        }

        //If the other List isn't empty:
        else
        {
            ListItem<T> *current1 = otherList.head; //current1 points to the other list.

            head = tail = new ListItem<T>;
            head->previous = NULL;

            head->value = current1->value;

            current1 = current1->next;

            if (current1 == NULL)
                head->next = NULL;

            else
            {
                ListItem<T> *current2 = head; //current2 keeps track of the list being created.

                while (current1 != NULL)
                {
                    current2->next = new ListItem<T>;
                    current2->next->previous = current2;
                    current2 = current2->next;

                    current2->value = current1->value;
                    current1 = current1->next;
                }

                current2->next = NULL;
                tail = current2;
            }
        }
    }

    //Overloaded Assignment Operator
    List<T> operator=(const List<T> &otherList)
    {
        if (&otherList != this)
        {
            if (head != NULL) //If list isn't empty then delete the whole list.
            {
                ListItem<T> *current = head;

                while (current != NULL)
                {
                    ListItem<T> *temp = current;
                    current = current->next;
                    delete temp;
                }

                head = tail = NULL;
            }

            //If the other list is empty then make the current list empty too.
            if (otherList.head == NULL)
            {
                head = NULL;
            }

            //If the other List isn't empty:
            else
            {
                ListItem<T> *current1 = otherList.head; //current1 points to the other list.

                head = tail = new ListItem<T>;
                head->previous = NULL;

                head->value = current1->value;

                current1 = current1->next;

                if (current1 == NULL)
                    head->next = NULL;

                else
                {
                    ListItem<T> *current2 = head; //current2 keeps track of the list being created.

                    while (current1 != NULL)
                    {
                        current2->next = new ListItem<T>;
                        current2->next->previous = current2;
                        current2 = current2->next;

                        current2->value = current1->value;
                        current1 = current1->next;
                    }

                    current2->next = NULL;
                    tail = current2;
                }
            }
        }

        return *this;
    }

    // Destructor
    ~List()
    {
        if (head != NULL) //If list is empty then do nothing.
        {
            ListItem<T> *current = head;

            while (current != NULL)
            {
                ListItem<T> *temp = current;
                current = current->next;
                delete temp;
            }
        }
    }

    /*------------------- Insertion Functions -------------------*/
    void insertAtHead(T item)
    {
        ListItem<T> *temp = new ListItem<T>;
        temp->value = item;

        temp->next = head;
        temp->previous = NULL;

        if (head != NULL)
            temp->next->previous = temp;
        else
            tail = temp;

        head = temp;
    }

    void insertAtTail(T item)
    {
        ListItem<T> *temp = new ListItem<T>;
        temp->value = item;

        temp->previous = tail;
        temp->next = NULL;

        if (tail != NULL)
            temp->previous->next = temp;
        else
            head = temp;

        tail = temp;
    }

    ListItem<T> *insertSorted(T &item)
    {

        ListItem<T> *temp = new ListItem<T>;
        temp->value = item;

        if (head == NULL) //If the list is empty
        {
            temp->previous = temp->next = NULL;
            head = tail = temp;
        }

        else //List isn't empty
        {
            ListItem<T> *current = head;

            while (current->next != NULL && current->value < item)
            {
                current = current->next;
            }

            if (current == head)
            {
                if (temp->value > current->value)
                {
                    temp->previous = current;
                    temp->next = current->next;

                    if (current->next = NULL)
                        tail = temp;

                    current->next = temp;
                }

                else
                {
                    temp->previous = NULL;
                    temp->next = current;
                    current->previous = temp;
                    head = temp;
                }
            }

            else
            {
                if (temp->value > current->value)
                {
                    temp->next = NULL;
                    temp->previous = current;

                    current->next = temp;
                    tail = temp;
                }

                else
                {
                    temp->previous = current->previous;
                    temp->next = current;

                    current->previous->next = temp;
                    current->previous = temp;
                }
            }
        }

        return temp;
    }

    /*------------------- Lookup Functions -------------------*/
    ListItem<T> *getHead()
    {
        return head;
    }

    ListItem<T> *getTail()
    {
        return tail;
    }

    ListItem<T> *searchForL(T item)
    {
        if (head == NULL) //If the list is empty
        {
            return NULL;
        }

        else if (item > tail->value)
        {
            return NULL;
        }

        else
        {
            ListItem<T> *current = head;

            while (current != NULL && current->value <= item)
            {
                if (current->value == item)
                {
                    return current;
                }

                current = current->next;
            }

            return NULL;
        }
    }

    /*------------------- Deletion Functions -------------------*/

    void deleteElement(T &item)
    {
        if (head != NULL) //If the list isn't empty.
        {
            ListItem<T> *current = head;

            while (current->next != NULL && current->value < item)
            {
                current = current->next;
            }

            //If the element is found.
            if (current->value == item)
            {
                if (current == head)
                {
                    head = head->next;

                    if (head == NULL)
                        tail = NULL;
                    else
                        head->previous = NULL;
                }

                else
                {
                    current->previous->next = current->next;

                    if (current->next != NULL)
                        current->next->previous = current->previous;
                    else
                        tail = current->previous;
                }

                delete current;
            }
        }
    }

    void deleteHead()
    {
        if (head != NULL)
        {
            ListItem<T> *temp = head->next;
            delete head;
            head = temp;

            if (head == NULL)
                tail = NULL;

            else
                head->previous = NULL;
        }
    }

    void deleteTail()
    {
        if (head != NULL)
        {
            ListItem<T> *temp = tail->previous;
            delete tail;
            tail = temp;

            if (tail == NULL)
                head = NULL;

            else
                tail->next = NULL;
        }
    }

    //Deletes a particular node if given the node's address
    void deleteNode(ListItem<T> *node)
    {
        if (node == head)
        {
            head = head->next;
        }

        else if (node == tail)
        {
            tail = tail->previous;
        }

        else
        {
            node->previous->next = node->next;
            node->next->previous = node->previous;
        }

        if (head != NULL)
        {
            head->previous = NULL;
            tail->next = NULL;
        }

        else
            tail = NULL;

        delete node;
    }

    /*------------------- Utility Functions -------------------*/
    int length()
    {
        int length = 0;
        ListItem<T> *current = head;

        while (current != NULL)
        {
            length++;
            current = current->next;
        }

        return length;
    }

    void Print()
    {
        if (head != NULL)
        {
            ListItem<T> *current = head;

            // cout << endl << "The list contains: " << endl;

            while (current != NULL)
            {
                cout << current->value << endl;
                current = current->next;
            }
        }

        else
            cout << "\nList is empty.";
    }

    void printRange(ListItem<T> *startingNode, ListItem<T> *endingNode)
    {
        while (startingNode != endingNode)
        {
            cout << startingNode->value;

            startingNode = startingNode->next;
        }

        cout << endingNode->value;
    }

    void displayFunctions()
    {
        cout << "\n\n\nThis class Doubly Linked List has the following functionality : ";
        cout << "\n1)insertAtHead \n2)insertAtTail \n3)insertSorted \n4)getHead \n5)getTail"
             << "\n6)searchFor \n7)deleteElement \n8)deleteHead \n9)deleteTail \n10)Print List \n11)Length of List";
        cout << "\nEnter the option number. To exit, enter -1.\nOption Number : ";
    }

    //Get element at the desired position, eg 3rd element of list etc
    ListItem<T> *getDesiredElement(int n)
    {
        ListItem<T> *current = head;

        if (n <= length())
        {
            while (n != 1)
            {
                current = current->next;
                n--;
            }
        }

        return current;
    }
};

//--------------Ended List Class---------------------

void driver()
{
    List<int> list1;

    int userInput = 0;
    int data;

    while (userInput != -1)
    {
        list1.displayFunctions();
        cin >> userInput;

        if (userInput == 1)
        {
            cout << "\nEnter the data to be inserted into the List : ";
            cin >> data;

            list1.insertAtHead(data);
        }

        else if (userInput == 2)
        {
            cout << "\nEnter the data to be inserted into the List : ";
            cin >> data;

            list1.insertAtTail(data);
        }

        else if (userInput == 3)
        {
            cout << "\nEnter the data to be inserted into the List : ";
            cin >> data;

            list1.insertSorted(data);
        }

        else if (userInput == 4)
        {
            if (list1.getHead() != NULL)
                cout << "\nThe value at the head of the list is " << list1.getHead()->value;
            else
                cout << "\nThe list is empty.";
        }

        else if (userInput == 5)
        {
            if (list1.getTail() != NULL)
                cout << "\nThe value at the tail of the list is " << list1.getTail()->value;
            else
                cout << "\nThe list is empty.";
        }

        else if (userInput == 6)
        {
            cout << "\nEnter the data element which is to be searched : ";
            cin >> data;

            if (list1.searchForL(data) != NULL)
                cout << "\nThe element is found. ";
            else
                cout << "\nThe element is not found. ";
        }

        else if (userInput == 7)
        {
            cout << "\nEnter the data to be deleted from the List : ";
            cin >> data;

            list1.deleteElement(data);
        }

        else if (userInput == 8)
        {
            list1.deleteHead();
        }

        else if (userInput == 9)
        {
            list1.deleteTail();
        }

        else if (userInput == 10)
        {
            list1.Print();
        }

        else if (userInput == 11)
        {
            cout << "\n\nThe length of the list is : " << list1.length();
        }
    }

    cout << "\nTesting the copy constructor :";
    List<int> list2 = list1;

    cout << "\nList 2 is a copy of List 1 constructed through Copy Constructor.";

    cout << "\nList 1 : ";
    list1.Print();

    cout << "\nList 2 : ";
    list2.Print();
}

int main()
{
    driver();
    return 0;
}