#include<stdio.h>
#include<conio.h>
voidmain() 
{
int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
int n, value;
int temp, hash;
clrscr();
printf("\nEnter the value of n(table size):");scanf("%d", &n);
do
{
printf("\nEnter the hash value");
scanf("%d", &value);
hash = value % n;
if(a[hash] == 0) 
{
a[hash] = value;
printf("\na[%d]the value %d is stored", hash, value);
}
else
{
for(hash++; hash < n; hash++) 
{
if(a[hash] == 0) 
{
printf("Space is allocated give other value");a[hash] = value;
printf("\n a[%d]the value %d is stored", hash, value);
gotomenu;
}
}
for(hash = 0; hash < n; hash++) 
{
if(a[hash] == 0) 
{
printf("Space is allocated give other value");a[hash] = value;
printf("\n a[%d]the value %d is stored", hash, value);
gotomenu;
}
}
printf("\n\nERROR\n");
printf("\nEnter '0' and press 'Enter key' twice to exit");
}
menu:
printf("\n Do u want enter more");
scanf("%d", &temp);
}while(temp == 1);
getch();
}