
/*

Consider a friends’ network on face book social web site. Model it as a graph to represent each node as a user and
a link to represent the fried relationship between them. Store data such as date of birth, number of comments for each user.
1. Find who is having maximum friends
2. Find who has post maximum and minimum comments
3. Find users having birthday in this month.
Hint: (Use adjacency list representation and perform DFS and BFS traversals)

*/


#include<iostream>
#include<string.h>

using namespace std;

class node
{
    int ver,dd,mm,yy,no_of_comments,total_friends;
    char name[50];
    node *next;

    friend class graph;
};

class queue1
{
    public:

    int b[20],r,f;

    queue1()
    {
        r=f=-1;
    }
    void enqueue(int i);
    int dequeue();

};

class graph
{
    int visited[30],noc[40],bd[40],by[40];
    char name1[40][20];
    node *a[30];

    public:

    int n,bm[40];
    void getdata();
    void create(int i,int j,char *name,int noc,int dd,int mm,int yy,int tot);
    void display();
    void display1(int i);
    void comments();
    int dfs_max_comments(int i);
    int dfs_min_comments(int i);
    void friends();
    int dfs_max_friends(int i);
    void  bfs_bday(int i,int month);

};


void graph::bfs_bday(int x,int mon)                       //function to search users having same birthday month using bfs traversal
{
    queue1 q;

    node *p;
    p=a[x];

    int j,k;

    for(j=0;j<n;j++)
    {
        visited[j]=0;
    }

    q.enqueue(x);

    visited[x]=1;

    if(bm[x]==mon)
      {
            cout<<"\n"<<name1[x];
      }

    while(q.r!=-1)
    {
        x=q.dequeue();

        for(p=a[x];p!=NULL;p=p->next)
        {
            k=p->ver;

            if(visited[k]==0)
            {
                q.enqueue(k);
                visited[k]=1;

              if(p->mm==mon)
             {
                cout<<"\n"<<name1[k];
             }
            }

        }
    }
}


void queue1::enqueue(int i)
{
    if(r==-1)
        r=f=0;

    else
        r++;

    b[r]=i;
}


int queue1::dequeue()
{
    int k;

    k=b[f];

    if(r==f)
        r=f=-1;

    else
        f++;

    return k;
}


void graph::friends()
{
    int i,fr;

    for(i=0;i<n;i++)
    {
        visited[i]=0;
    }

    fr=dfs_max_friends(0);

     for(i=0;i<n;i++)
    {
        if(a[i]->total_friends==fr)
            cout<<"\nUser having maximum friends :"<<a[i]->name;
    }

     cout<<"\nNo. of maximum friends: "<<fr;
}


int graph::dfs_max_friends(int i)                 //function to find out max no of friends using dfs traversal
{
    static int ma=0;

    node *p;
    p=a[i];
    visited[i]=1;

    while(p!=NULL)
    {
        if(p->total_friends > ma)
            ma=p->total_friends;

        i=p->ver;

        if(!visited[i])
            ma=dfs_max_friends(i);

        p=p->next;
    }
    return ma;
}


void graph::comments()                   //function for searching users having max and min comments
{
    int i,max1,min1;

    for(i=0;i<n;i++)
    {
        visited[i]=0;
    }

    max1=dfs_max_comments(0);

    for(i=0;i<n;i++)
    {
        if(noc[i]==max1)
            cout<<"\nUser having maximum comments :"<<name1[i];
    }

     cout<<"\nNo. of maximum comments: "<<max1;


     for(i=0;i<n;i++)
    {
        visited[i]=0;
    }

    min1=dfs_min_comments(0);

     for(i=0;i<n;i++)
    {
        if(noc[i]==min1)
            cout<<"\nUser having minimum comments :"<<name1[i];
    }

     cout<<"\nNo. of minimum comments: "<<min1;
}


int graph::dfs_max_comments(int i)                 //function to find out max no of comments using dfs traversal
{
    static int ma=0;

    node *p;
    p=a[i];
    visited[i]=1;

    while(p!=NULL)
    {
        if(p->no_of_comments > ma)
            ma=p->no_of_comments;

        i=p->ver;

        if(!visited[i])
            ma=dfs_max_comments(i);

        p=p->next;
    }
    return ma;
}


int graph::dfs_min_comments(int i)                 //function to find out min no of comments using dfs traversal
{
    static int ma=9999;

    node *p;
    p=a[i];
    visited[i]=1;

    while(p!=NULL)
    {
        if(p->no_of_comments < ma)
            ma=p->no_of_comments;

        i=p->ver;

        if(!visited[i])
            ma=dfs_min_comments(i);

        p=p->next;
    }
    return ma;
}


void graph::display()                    //function to search user
{
    char nm[30];
    int i,flag=0;

    cout<<"\nEnter name of user whose friend list u want to see :";
    cin>>nm;

    for(i=0;i<n;i++)
    {
        if(strcmp(name1[i],nm)==0)
        {
            flag=1;
            cout<<"\nFriend list of "<<name1[i];
            display1(i);
        }
    }

    if(flag==0)
       cout<<"\nUser is not in the network!";
}


void graph::display1(int i)             //function to display friend list
{
    node *p;

    p=a[i];

    while(p!=NULL)
    {
        cout<<"\n"<<p->name;
        p=p->next;
    }
}


void graph::getdata()                             //function to take input data
{
    int tot,i,j,b;

    cout<<"\nEnter total number of users:";
    cin>>n;


    for(i=0;i<n;i++)
    {
        cout<<"\nEnter name of user:";
        cin>>name1[i];

        cout<<"\nEnter total number of comments:";
        cin>>noc[i];

        while(noc[i]<=0)
        {
             cout<<"\nINVALID!!!  ENTER AGAIN ";
             cout<<"\nEnter total number of comments:";
             cin>>noc[i];
        }

        cout<<"\nEnter date of birth(Enter in the form of dd mm yy) :";
        cin>>bd[i];
        cin>>bm[i];
        cin>>by[i];

        while(bm[i]>12 || bm[i]<=0 || bd[i]<=0 || bd[i]>31)
        {
           cout<<"\nINVALID!!!  ENTER AGAIN ";
           cout<<"\nEnter date of birth(Enter in the form of dd mm yy) :";
           cin>>bd[i];
           cin>>bm[i];
           cin>>by[i];
        }

        a[i]=NULL;
    }


    for(i=0;i<n;i++)
    {
        tot=0;
        for(j=0;j<n;j++)
        {
            if(i<j)
            {
                cout<<"\nAre "<<name1[i]<<" and "<<name1[j]<<" friends? (0/1): " ;
                cin>>b;

                if(b==1)
                {
                    tot++;
                    create(i,j,name1[j],noc[j],bd[j],bm[j],by[j],tot);
                    create(j,i,name1[i],noc[i],bd[i],bm[i],by[i],tot);
                }
            }
        }
    }
}


void graph::create(int i,int j,char *name,int noc,int dd,int mm,int yy,int tot)      //function to create links
{
    node *temp,*p;

    temp=new node;

    temp->ver=j;
    strcpy(temp->name,name);
    temp->no_of_comments=noc;
    temp->dd=dd;
    temp->mm=mm;
    temp->yy=yy;
    temp->total_friends=tot;

    temp->next=NULL;

    if(a[i]==NULL)
        a[i]=temp;

    else
    {
        p=a[i];

        while(p->next!=NULL)
        {
            p=p->next;
        }

        p->next=temp;
    }
}


int main()
{
    graph g;
    g.getdata();

    int f,ch,k,mon,flag=0,i;

    do
    {
       cout<<"\n1.Display friend list";
       cout<<"\n2.User having maximum friends";
       cout<<"\n3.Users having maximum and minimum comments ";
       cout<<"\n4.Users having birthdays in same month ";
       cout<<"\n\nEnter yout choice:";
       cin>>ch;

       switch(ch)
       {
         case 1:

         g.display();
         break;


         case 2:

         g.friends();
         break;


         case 3:

         g.comments();
         break;


         case 4:

         cout<<"\nEnter month to check :";
         cin>>mon;

         for(i=0;i<g.n;i++)
         {
             if(g.bm[i]==mon)
                flag=1;
         }

         if(flag==0)
            cout<<"\nINVALID!!!  Month is not in the network";

          else
          {
             cout<<"\nUsers having birthdays in the month "<<mon<<" are ";

             g.bfs_bday(0,mon);
          }

         break;


         default:
         cout<<"\nINVALID CHOICE!!!  ENTER AGAIN ";

       }

       cout<<"\nDo u want to choose another option? (0/1) :";
       cin>>f;
    }

    while(f==1);

    return 0;
}

/*
OUTPUT:


Enter total number of users:5

Enter name of user:omkar

Enter total number of comments:20

Enter date of birth(Enter in the form of dd mm yy) :6 3 2001

Enter name of user:maitreya

Enter total number of comments:0

INVALID!!!  ENTER AGAIN
Enter total number of comments:-1

INVALID!!!  ENTER AGAIN
Enter total number of comments:40

Enter date of birth(Enter in the form of dd mm yy) :0 3 2

INVALID!!!  ENTER AGAIN
Enter date of birth(Enter in the form of dd mm yy) :-1 2 3

INVALID!!!  ENTER AGAIN
Enter date of birth(Enter in the form of dd mm yy) :1 0 3

INVALID!!!  ENTER AGAIN
Enter date of birth(Enter in the form of dd mm yy) :1 -2 3

INVALID!!!  ENTER AGAIN
Enter date of birth(Enter in the form of dd mm yy) :32 3 2

INVALID!!!  ENTER AGAIN
Enter date of birth(Enter in the form of dd mm yy) :12 13 23

INVALID!!!  ENTER AGAIN
Enter date of birth(Enter in the form of dd mm yy) :20 4 2000

Enter name of user:amey

Enter total number of comments:50

Enter date of birth(Enter in the form of dd mm yy) :10 3 2000

Enter name of user:yatish

Enter total number of comments:45

Enter date of birth(Enter in the form of dd mm yy) :12 4 2001

Enter name of user:shubham

Enter total number of comments:30

Enter date of birth(Enter in the form of dd mm yy) :25 3 2002

Are omkar and maitreya friends? (0/1): 1

Are omkar and amey friends? (0/1): 0

Are omkar and yatish friends? (0/1): 1

Are omkar and shubham friends? (0/1): 1

Are maitreya and amey friends? (0/1): 1

Are maitreya and yatish friends? (0/1): 1

Are maitreya and shubham friends? (0/1): 0

Are amey and yatish friends? (0/1): 0

Are amey and shubham friends? (0/1): 1

Are yatish and shubham friends? (0/1): 0

1.Display friend list
2.User having maximum friends
3.Users having maximum and minimum comments
4.Users having birthdays in same month

Enter yout choice:1

Enter name of user whose friend list u want to see :r

User is not in the network!
Do u want to choose another option? (0/1) :1

1.Display friend list
2.User having maximum friends
3.Users having maximum and minimum comments
4.Users having birthdays in same month

Enter yout choice:1

Enter name of user whose friend list u want to see :omkar

Friend list of omkar
maitreya
yatish
shubham
Do u want to choose another option? (0/1) :1

1.Display friend list
2.User having maximum friends
3.Users having maximum and minimum comments
4.Users having birthdays in same month

Enter yout choice:1

Enter name of user whose friend list u want to see :maitreya

Friend list of maitreya
omkar
amey
yatish
Do u want to choose another option? (0/1) :1

1.Display friend list
2.User having maximum friends
3.Users having maximum and minimum comments
4.Users having birthdays in same month

Enter yout choice:1

Enter name of user whose friend list u want to see :yatish

Friend list of yatish
omkar
maitreya
Do u want to choose another option? (0/1) :1

1.Display friend list
2.User having maximum friends
3.Users having maximum and minimum comments
4.Users having birthdays in same month

Enter yout choice:1

Enter name of user whose friend list u want to see :amey

Friend list of amey
maitreya
shubham
Do u want to choose another option? (0/1) :1

1.Display friend list
2.User having maximum friends
3.Users having maximum and minimum comments
4.Users having birthdays in same month

Enter yout choice:1

Enter name of user whose friend list u want to see :shubham

Friend list of shubham
omkar
amey
Do u want to choose another option? (0/1) :1

1.Display friend list
2.User having maximum friends
3.Users having maximum and minimum comments
4.Users having birthdays in same month

Enter yout choice:2

User having maximum friends :omkar
No. of maximum friends: 3
Do u want to choose another option? (0/1) :1

1.Display friend list
2.User having maximum friends
3.Users having maximum and minimum comments
4.Users having birthdays in same month

Enter yout choice:3

User having maximum comments :amey
No. of maximum comments: 50
User having minimum comments :omkar
No. of minimum comments: 20
Do u want to choose another option? (0/1) :1

1.Display friend list
2.User having maximum friends
3.Users having maximum and minimum comments
4.Users having birthdays in same month

Enter yout choice:4

Enter month to check :6

INVALID!!!  Month is not in the network
Do u want to choose another option? (0/1) :1

1.Display friend list
2.User having maximum friends
3.Users having maximum and minimum comments
4.Users having birthdays in same month

Enter yout choice:4

Enter month to check :3

Users having birthdays in the month 3 are
omkar
shubham
amey
Do u want to choose another option? (0/1) :1

1.Display friend list
2.User having maximum friends
3.Users having maximum and minimum comments
4.Users having birthdays in same month

Enter yout choice:4

Enter month to check :4

Users having birthdays in the month 4 are
maitreya
yatish
Do u want to choose another option? (0/1) :0


*/
