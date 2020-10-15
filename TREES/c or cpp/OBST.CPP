#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#define max 20

int i,j,k,n,min,r[max][max];
float p[max],q[max],w[max][max],c[max][max];
char leaf[max];
void OBST();
void print(int,int);
void print_tab();
void main()
{
	clrscr();
	cout<<"\nEnter no. of nodes :";
	cin>>n;
	cout<<"\nEnter successful probability :";
	for(i=1;i<=n;i++)
	{
		cin>>p[i];
	}
	cout<<"\nEnter unsuccessful probability :";
	for(i=0;i<=n;i++)
	{
		cin>>q[i];
	}
	OBST();
	print_tab();
	//print(0,n);
	getch();
}
void OBST()
{
	for(i=0;i<n;i++)
	{
		r[i][i] = 0;
		c[i][i] = 0;
		w[i][i] = q[i];

		w[i][i+1]=p[i+1]+q[i+1]+w[i][i];
		c[i][i+1]=w[i][i+1];
		r[i][i+1]=i+1;
	}
	c[n][n]=0.0;
	r[n][n]=0.0;
	w[n][n]=q[n];
	for(i=2;i<=n;i++)
	{
		for(j=0;j<=n-i;j++)
		{
			w[j][j+i]=w[j][j+i-1]+p[j+i]+q[j+i];
			c[j][j+i]=999;
			for(k=j+1;k<=j+i;k++)
			{
				if(c[j][j+i]>c[j][k-1]+c[k][j+i])
				{
					c[j][j+i]=c[j][k-1]+c[k][j+i];
					r[j][j+i]=k;
				}
			}
			c[j][j+i]+=w[j][j+i];
		}
	}
}
void print_tab()
{
	for(i=0;i<=n;i++)
		cout<<"w"<<i<<i<<"="<<w[i][i]<<"\t";
	cout<<endl;
	for(i=0;i<=n;i++)
		cout<<"c"<<i<<i<<"="<<c[i][i]<<"\t";
	cout<<endl;
	for(i=0;i<=n;i++)
		cout<<"r"<<i<<i<<"="<<r[i][i]<<"\t";
	cout<<endl;
	k=1;
	while(k<=n)
	{
		for(i=0,j=i+k;i<n,j<=n;i++,j++)
			cout<<"w"<<i<<j<<"="<<w[i][j]<<"\t";
		cout<<endl;
		for(i=0,j=i+k;i<n,j<=n;i++,j++)
			cout<<"c"<<i<<j<<"="<<c[i][j]<<"\t";
		cout<<endl;
		for(i=0,j=i+k;i<n,j<=n;i++,j++)
			cout<<"r"<<i<<j<<"="<<r[i][j]<<"\t";
		cout<<endl;
		k++;
	}
}