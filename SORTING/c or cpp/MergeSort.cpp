#include<bits/stdc++.h>
using namespace std;

void merge_sort(int [],int ,int );
void merge(int [],int,int ,int );

int main()
{
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter the elements in the array"<<endl;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    cout<<"After sorting using merge sort"<<endl;
    int p=1,r=n;

    merge_sort(a,p,r);

   
   for(int i=1;i<=n;i++)
   {
       cout<<a[i]<<" ";
   }
     return 0;
}

void merge_sort(int a[],int p,int r)
    {
      
        if(p<r)
        {
         int q=(p+r)/2;
         merge_sort(a,p,q);
         merge_sort(a,q+1,r);
         merge(a,p,q,r);
        }
    }

 void merge(int a[],int p,int q,int r)
    {
        
        int n1=q-p+1;
        int n2=r-q;
        int L[n1+1];
        int R[n2+1];
        for(int i=1;i<=n1;i++)
        {
            L[i]=a[p+i-1];
        }
        for(int j=1;j<=n2;j++)
        {
            R[j]=a[q+j];
        }
        L[n1+1]=numeric_limits<int>::max();;
        R[n2+1]=numeric_limits<int>::max();;
        int i=1, j=1;
        for(int k=p;k<=r;k++)
        {
            if(L[i]<=R[j])
            {
                a[k]=L[i];
                i=i+1;
            }
            else
            {
                a[k]=R[j];
                j=j+1;
            }
        }
    }
