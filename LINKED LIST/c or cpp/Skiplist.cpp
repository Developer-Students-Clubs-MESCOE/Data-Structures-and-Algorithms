

#include<iostream>
using namespace std;
class SkipList
{
	struct node
	{
		node *next;
		int d;
	}*head;
	struct node1
	{
		node1 *next1;
		int d1;
	}*head1;
	struct node2
	{
		node2 *next2;
		int d2;
	}*head2;
	struct node3
	{
		node3 *next3;
		int d3;
	}*head3;
	static int n,max,min;
public:
	SkipList()
	{
		head=NULL;
		head1=NULL;
		head2=NULL;
		head3=NULL;
	}
	void create();
	void display();
	void search_v();
	void sl();
};

int SkipList::n;
int SkipList::min;
int SkipList::max;

void SkipList::create()
{
	node *p,*q,*t;
	int x,i;

	cout<<"\nHow many Numbers have you want : ";
	cin>>x;
	cout<<"\nEnter the numbers\n";

	for(i=0;i<x;i++)
	{
		p=new node;
		p->next=NULL;
		cout<<"\n"<<i+1<<" : ";
		cin>>p->d;
		if(min==0)
                min=p->d;
		if(p->d>max)
                max=p->d;
       
		if(head==NULL)
		{
			head=p;
			t=head;
		}
		else
		{    
		       while(t->next!=NULL)
                     {
                       t=t->next;
                     }

                   t->next=p;
                  
                 }
                 n++;
	}
	
	sl();
}

void SkipList::search_v()
{
    if(head==NULL)
    {
        cout<<"\n\n***List not yet created!!!";
        return;
    }
	int key,x=0;
	node *p;
	node1 *p1;
	node2 *p2;
	node3 *p3;
	cout<<"\nEnter the number to search : ";
	cin>>key;
	if(key>max || key<min)
    {
        cout<<"\n\n**No such entry!!!\n\nComparisons required "<<x<<"\n\n";
        return;
    }
	p3=head3;
	p2=head2;
	p1=head1;
	p=head;
	while(p!=NULL)
	{
        if(p3!=NULL)
        {
            if(p3->d3==key || p2->d2==key || p1->d1==key || p->d==key)
            {
                cout<<"\n\nFound it . Comparisons required "<<x;
                return;
            }
            if(p3->d3<key && p3->next3!=NULL)
            {
                p3=p3->next3;
            }
            if(p3!=NULL && p3->d3<key)
            {
				p2=p2->next2;
				p1=p1->next1->next1;
				p=p->next->next->next->next;
			}
        }
        if(p2!=NULL)
        {
            if(p2->d2==key || p1->d1==key || p->d==key)
            {
                cout<<"\n\nFound it . Comparisons required "<<x;
                return;
            }
            if(p2->d2<key && p2->next2!=NULL)
            {
                p2=p2->next2;
            }
            if(p2!=NULL && p2->d2<key)
            {
            	p1=p1->next1;
				p=p->next->next;
            }
        }
        if(p1!=NULL)
        {
            if(p1->d1==key || p->d==key)
            {
                cout<<"\n\nFound it . Comparisons required "<<x;
                return;
            }
            if(p1->d1<key && p1->next1!=NULL)
            {
                p1=p1->next1;
            }
            if(p1!=NULL && p1->d1<key)
            {
            	p=p->next;
            }
        }
        if(p!=NULL)
        {
            if(p->d<key)
            {
                p=p->next;
            }

        }
        if(p==NULL || p->d>key)
        {
            cout<<"\n\n**No such entry!!!\n\nComparisons required "<<x<<"\n\n";
            return;
        }
        x++;
	}

}

void SkipList::sl()
{
    int x=3,y;

    for(int i=0;i<x;i++)
    {
        y=0;

        if(i==0)
        {
            node *p;
            node1 *q;
            p=head;
            while(p!=NULL)
            {
                if(y%2==0)
                {
                    node1 *t=new node1;
                    t->next1=NULL;
                    t->d1=p->d;
                    if(head1==NULL)
                    {
                        head1=t;
                        q=head1;
                    }
                    else
                    {
                        q->next1=t;
                        q=q->next1;
                    }
                }
                p=p->next;
                y++;
            }
            cout<<"\n1st Level completed\n";
        }
        else if(i==1 && n>8)
        {
            node1 *p;
            node2 *q;
            p=head1;
            while(p!=NULL)
            {
                if(y%2==0)
                {
                    node2 *t=new node2;
                    t->next2=NULL;
                    t->d2=p->d1;
                    if(head2==NULL)
                    {
                        head2=t;
                        q=head2;
                    }
                    else
                    {
                        q->next2=t;
                        q=q->next2;
                    }
                }
                p=p->next1;
                y++;
            }
            cout<<"\n2nd level completed\n";
        }
        else if(i==2 && n>15)
        {
            node2 *p;
            node3 *q;
            p=head2;
            while(p!=NULL)
            {
                if(y%2==0)
                {
                    node3 *t=new node3;
                    t->next3=NULL;
                    t->d3=p->d2;
                    if(head3==NULL)
                    {
                        head3=t;
                        q=head3;
                    }
                    else
                    {
                        q->next3=t;
                        q=q->next3;
                    }
                }
                p=p->next2;
                y++;
            }
            cout<<"\n3rd level completed\n";
        }
    }
    
}

void SkipList::display()
{
	node3* p3=head3;
	while(p3!=NULL)
	{
	    if(p3==head3)
            cout<<"\n\nLevel 3 ->     ";
	    cout<<p3->d3<<"\t \t \t \t";
	    p3=p3->next3;
	}

	node2* p2=head2;

	while(p2!=NULL)
	{
	    if(p2==head2)
            cout<<"\n\nLevel 2 ->     ";
	    cout<<p2->d2<<"\t \t \t \t";
	    p2=p2->next2;
	}
	
	node1 *p1=head1;

	while(p1!=NULL)
	{
	    if(p1==head1)
            cout<<"\n\nLevel 1 ->     ";
	    cout<<p1->d1<<"\t \t";
	    p1=p1->next1;
	}
	node *p=head;
	while(p!=NULL)
	{
	   if(p==head)
	    cout<<"\n\nLevel 0 ->     ";
	    cout<<p->d<<"\t";
	    p=p->next;
        }



	
}

int main()
{
	SkipList L;
	int ch;
	do
	{
		cout<<"\n\n____________MENU____________\n\n\n1.Create\n2.Display\n3.Search\nPress 0 to exit\nChoice : ";
		cin>>ch;
		switch(ch)
		{
                case 0: 
                break;
		case 1:
			L.create();
			break;
		case 2:
			L.display();
			break;
		case 3:
            		L.search_v();
           	         break;
        	default:
            		cout<<"\n\n\n***Invalid Choice!!!\n\n\n";
		}
	}while(ch!=0);
	return 0;
}

/*OUTPUT:

rushabh@ubuntu:~$ g++ Skiplist.cpp
rushabh@ubuntu:~$ ./a.out


____________MENU____________


1.Create
2.Display
3.Search
Press 0 to exit
Choice : 1

How many Numbers have you want : 9

Enter the numbers

1 : 5

2 : 10

3 : 15

4 : 20

5 : 25

6 : 30

7 : 35

8 : 40

9 : 45

1st Level completed

2nd level completed


____________MENU____________


1.Create
2.Display
3.Search
Press 0 to exit
Choice : 2


Level 2 ->     5	 	 	 	25	 	 	 	45	 	 	 	

Level 1 ->     5	 	15	 	25	 	35	 	45	 	

Level 0 ->     5	10	15	20	25	30	35	40	45	

____________MENU____________


1.Create
2.Display
3.Search
Press 0 to exit
Choice : 3

Enter the number to search : 30


Found it . Comparisons required 2

____________MENU____________


1.Create
2.Display
3.Search
Press 0 to exit
Choice : 3

Enter the number to search : 15


Found it . Comparisons required 1

____________MENU____________


1.Create
2.Display
3.Search
Press 0 to exit
Choice : 3

Enter the number to search : 45


Found it . Comparisons required 2

____________MENU____________


1.Create
2.Display
3.Search
Press 0 to exit
Choice : 3

Enter the number to search : 5


Found it . Comparisons required 0

____________MENU____________


1.Create
2.Display
3.Search
Press 0 to exit
Choice : 3

Enter the number to search : 35


Found it . Comparisons required 2

____________MENU____________


1.Create
2.Display
3.Search
Press 0 to exit
Choice : 0
rushabh@ubuntu:~$ 



*/
