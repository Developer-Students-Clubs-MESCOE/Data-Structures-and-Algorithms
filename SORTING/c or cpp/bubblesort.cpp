// Bubble sort using template functions for both assending and descending 

#include <iostream>
using namespace std;

template<class t>
void assending(t list[], int n) 
{
    int i, j;
    t a;
    for (i = 0; i < n; ++i) 
    {
 
        for (j = i + 1; j < n; ++j)
        {
            if (list[i] > list[j]) 
            {
                a =  list[i];
                list[i] = list[j];
                list[j] = a;
            }
        }
    }
}

template <class T>
void descending(T list[], int n) 
{
    int i, j;
    T a;
    for (i = 0; i < n; ++i) 
    {
 
        for (j = i + 1; j < n; ++j)
        {
            if (list[i] < list[j]) 
            {
                a =  list[i];
                list[i] = list[j];
                list[j] = a;
            }
        }
    }
}


int main()
{
    int i, n, list[10];
    float List[10];
    
    cout<<"how many numbers you want to sort \n";
    cin>>n;
 
    cout<<"Enter the numbers \n";
    for (i = 0; i < n; ++i)
        cin>>list[i];
    
    assending(list, n);
    
    cout<<"assending order is\n";
    for (i = 0; i < n; ++i)
        cout<<"\t"<<list[i];
    
    cout<<"\n";
        
    descending(list, n);
    
    cout<<"descending order is\n";
    for (i = 0; i < n; ++i)
        cout<<"\t"<<list[i];

    cout<<"\n Enter the numbers \n";
    for (i = 0; i < n; ++i)
        cin>>List[i];

    assending(List, n);
    
    cout<<"assending order of float is\n";
    for (i = 0; i < n; ++i)
        cout<<"\t"<<List[i];
    
    cout<<"\n";
        
    descending(List, n);
    
    cout<<"descending order of float is\n";
    for (i = 0; i < n; ++i)
        cout<<"\t"<<List[i];
 
}
