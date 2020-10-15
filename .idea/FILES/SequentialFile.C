//Program to implement primitive operation on sequential file
#include<stdio.h>
#include<conio.h>

//create a student record
typedef struct student
{
	int rollno;
	char name[20];
	float marks;
}student;

void search();
void insert();
void del();
void print();
void modify();

FILE *master, *temp;

void main()
{
	int op, rollno;
	student x;
	clrscr();

	if(!(master = fopen("master.txt","r+")))
		master = fopen("master.txt","w+");
	fclose(master);

	do{
		printf("\n 1. Insert a record");
		printf("\n 2. Delete a record");
		printf("\n 3. Modify a record");
		printf("\n 4. Search a record");
		printf("\n 5. Print a record");
		printf("\n 6. Quit");

		printf("\n\n Enter your choice : ");
		scanf("%d", &op);

		switch(op)
		{
			case 1:
				insert();
				break;
			case 2:
				del();
				break;
			case 3:
				modify();
				break;
			case 4:
				search();
				break;
			case 5:
				print();
				break;
		}
	}while(op != 6);
	//getch();
}
void insert()
{
	student st;
	master = fopen("master.txt", "r+");

	fseek(master, 0, 2);	//go to end of the file

	printf("\n Enter the record : \n");
	printf("\n Roll No. : Name : Marks\n");
	scanf("%d%s%f",&st.rollno, st.name, &st.marks);

	//Now write a record into file
	fprintf(master,"\n%d %s %6.2f", st.rollno, st.name, st.marks);

	fclose(master);
}
void print()
{
	student st;
	master = fopen("master.txt", "r+");

	//rewind(master);	//set the position at the beginning of file

	while(!feof(master))
	{
		//read a record from file & print
		fscanf(master, "%d%s%f",&st.rollno, st.name, &st.marks);
		printf("\n %d %s %6.2f",st.rollno, st.name, st.marks);
	}
	printf("\n");
	fclose(master);
}
void modify()
{
//function copy the all records to file "temp.txt" except
//the record to be modified & place new record instead.
//Then copy the all the record from file "temp.txt" to
//"master.txt" in "w+" mode.
	student st;
	int rollno, flag = 0;
	master = fopen("master.txt", "r+");	//original file
	temp = fopen("temp.txt", "w+");		//file to keep copy

	printf("\n Enter the roll no whose record to be modified : ");
	scanf("%d",&rollno);

	while(!feof(master))
	{
		fscanf(master, "%d%s%f",&st.rollno, st.name, &st.marks);
		if(st.rollno == rollno)
		{
			flag = 1;
			printf("\n record found \n ");
			printf("\n %d %s %6.2f",st.rollno, st.name, st.marks);

			printf("\n Enter the record : \n");
			printf("\n Roll No. : Name : Marks\n");
			scanf("%d%s%f",&st.rollno, st.name, &st.marks);

			//Now update the record into file
			fprintf(temp,"\n%d %s %6.2f", st.rollno, st.name, st.marks);
		}
		else
			fprintf(temp,"\n%d %s %6.2f", st.rollno, st.name, st.marks);
	}
	fclose(master);
	fclose(temp);

	if(flag == 0)
		printf("\n Record does not exist \n ");
	else
	{
		master = fopen("master.txt", "w+");	//update file
		temp = fopen("temp.txt", "r+");
		while(!feof(temp))
		{
			fscanf(temp, "%d%s%f",&st.rollno, st.name, &st.marks);
			fprintf(master,"\n%d %s %6.2f", st.rollno, st.name, st.marks);
		}
		fclose(temp);
		fclose(master);
	}
	printf("\n");
}
void search()
{
	student st;
	int rollno, flag = 0;

	master = fopen("master.txt", "r+");

	printf("\n Enter the roll no to be searched : ");
	scanf("%d", &rollno);

	//rewind(master);
	while(!feof(master))
	{
		fscanf(master, "%d%s%f",&st.rollno, st.name, &st.marks);
		if(st.rollno == rollno)
		{
			flag = 1;
			printf("\n record found \n ");
			printf("\n %d %s %6.2f",st.rollno, st.name, st.marks);
			break;
		}
	}
	if(flag == 0)
		printf("\n Record does not exist \n");
	printf("\n");
	fclose(master);
}
void del()
{
//function copy the all records to file "temp.txt" except
//the record to be deleted.
//Then copy the all the record from file "temp.txt" to
//"master.txt" in "w+" mode.

	student st;
	int rollno, flag = 0;
	master = fopen("master.txt", "r+");
	temp = fopen("temp.txt", "w+");

	printf("\n Enter the roll no to be deleted : ");
	scanf("%d", &rollno);

	rewind(master);
	while(!feof(master))
	{
		fscanf(master, "%d%s%f",&st.rollno, st.name, &st.marks);
		if(st.rollno == rollno)
		{
			flag = 1;
			printf("\n record found \n ");
			printf("\n %d %s %6.2f",st.rollno, st.name, st.marks);
			//break;
		}
		else
			fprintf(temp,"\n%d %s %6.2f", st.rollno, st.name, st.marks);
	}
	fclose(master);
	fclose(temp);

	if(flag == 0)
		printf("\n Record does not exist \n ");
	else
	{
		master = fopen("master.txt", "w+");
		temp = fopen("temp.txt", "r+");
		while(!feof(temp))
		{
			fscanf(temp, "%d%s%f",&st.rollno, st.name, &st.marks);
			fprintf(master,"\n%d %s %6.2f", st.rollno, st.name, st.marks);
		}
		fclose(temp);
		fclose(master);
	}
	printf("\n");
}