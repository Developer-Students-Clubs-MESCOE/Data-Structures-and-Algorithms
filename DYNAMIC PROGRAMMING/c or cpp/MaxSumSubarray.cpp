#include <bits/stdc++.h>

using namespace std;

int max(int a, int b){
    int m;
    m= (a>b)?a:b;
    return m;
}
int main()
{
    //int N=6;
    //int arr[]={1,2,3,4,5,6};
    int N;
    int m;
    //m=4;
    cout<<"Enter number of elements: ";
    cin>>N;
    int arr[N];
    cout<<"\nEnter elements of array: ";
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    cout<<"\nEnter subarray size: ";
    cin>>m;
    int i=0,j=0,sum=0,Max=-1;
    while(j<N){
        sum=sum+arr[j];
        if(j-i+1<m){
            j++;
        }else if(j-i+1==m){
            Max= max(sum,Max);
            sum=sum-arr[i];
            i++;
            j++;
        }
    }
    
    cout<<"Max Sum is:"<<Max;
    
}
