//Implementation of SLL
#include<iostream.h>
#include<conio.h>
struct list
{
	int data;
	struct list *next;
};

typedef struct list ll;

class sll
{
public:
	ll *create(ll *);
	void display(ll *);
	ll *insert(ll *);
	ll *Delete(ll *);
};

void main()
{
	sll l;
	ll *node;
	clrscr();
	node = l.create(node);
	cout<<"\n List is : ";
	l.display(node);
	cout<<"\n *****************";
	cout<<"\n\n Node Insertion ";
	cout<<"\n *****************\n";
	node = l.insert(node);
	cout<<"\n List after insertion : ";
	l.display(node);
	//insertL(node);
	//insertM(node);
	cout<<"\n ****************";
	cout<<"\n\n Node Deletion ";
	cout<<"\n *****************\n";
	node = l.Delete(node);
	cout<<"\n List after deletion : ";
	l.display(node);
	getch();
}

ll *sll::create(ll *node)
{
	char ch;
	ll *start;
	start = node;
	do{
		cout<<"\n Enter the node : ";
		cin>>node->data;
		node->next = new ll;
		node = node->next;
		node->next = NULL;
		//fflush(stdin);
		cout<<"\n Do you want to another node (y/n) ";
		cin>>ch;
	}while(ch != 'n');
	return start;
}
void sll::display(ll *node)
{
	while(node->next)
	{
		cout<<" "<<node->data;
		node = node->next;
	}
}
ll *sll::insert(ll *node)
{
	ll *F, *h;
	int pos, i = 1;
	F = new ll;
	h = node;
	if(node)
	{
		cout<<"\n Enter position, where node to be inserted: ";
		cin>>pos;

		cout<<"\n Enter the node :";
		cin>>F->data;

		if(pos == 1)
		{
			F->next = h;
			h = F;
		}
		else
		{
			while(i<pos-1)
			{
				node = node->next;
				i++;
			}
			F->next = node->next;
			node->next = F;
		}
	}
	return h;
}

ll *sll::Delete(ll *node)
{
	ll *start, *d;
	int pos, i = 1;
	start = node;
	cout<<"\n Enter the position, from where node to be deleted : ";
	cin>>pos;
	while(i<pos-1)
	{
		node = node->next;
		i++;
	}
	d = node->next;
	node->next = d->next;
	delete(d);
	return start;
}



