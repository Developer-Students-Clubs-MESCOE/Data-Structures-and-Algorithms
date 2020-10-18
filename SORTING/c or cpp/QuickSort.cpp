#include<iostream>
using namespace std;


int partition(int a[],int p,int r){
	int x=a[r],temp;
	int i=p-1;
	for(int j=p;j<r;j++){
	if(a[j]<=x)
	{
		i=i+1;
		temp=a[i];
        a[i]=a[j];
        a[j]=temp;

	}
	}
	a[r]=a[i+1];
	a[i+1]=x;
	return (i+1);
}

void quicksort(int a[],int p,int r){
	if(p<r){
		int q=partition(a,p,r);
		quicksort(a,p,q-1);
		quicksort(a,q+1,r);
	}

}

int main()
{
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];}
	quicksort(a,0,n-1);
	
	
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";

	return 0;
}
