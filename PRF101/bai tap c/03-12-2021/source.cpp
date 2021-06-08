#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include <stdlib.h>
#include "source.h"
void inputID(student &p)
{
	printf("ID: ");
	checkID=scanf("%d",&p.ID);	
	fflush(stdin);
}

void inputname(student &p)
{
	printf("Name: ");
	fflush(stdin);
	scanf("%s",&p.name);
}

void inputGPA(student &p)
{
	printf("GPA: ");
	fflush(stdin);
	checkGPA = scanf("%f",&p.GPA);
	fflush(stdin);
}
void inputonestudent(student &p)
{
	inputID(p);
	inputname(p);
	inputGPA(p);
}

void outputonestudent(student &p)
{
	printf("\n\nID: %d\nName: %s\nGPA: %.1f", p.ID,p.name,p.GPA);
}

void inputnumber(int &n)
{
	printf("Number of student: ");
	check = scanf("%d",&n);
	fflush(stdin);
}

void inputstudent(student p[],int &n)
{
	inputnumber(n);
	while (check==0 || n<=0)
	{
		printf("Please enter an integer greater than 0!\n\n");
		inputnumber(n);
	}
	for (int i=1; i<=n; i++)
	{
		printf("\nStudent %d: \n",i);
		inputID(p[i]);
		while (checkID==0)
		{
			printf("Please input an integer ID\n");
			inputID(p[i]);
		}
		for (int j=1;j<i;j++)
		{
			while (p[j].ID==p[i].ID)
			{
				printf("Duplicated ID, please try again\n\n");
				fflush(stdin);
				printf("Retype student %d:\n",i);
				inputID(p[i]);
			}
		}
		inputname(p[i]);
		inputGPA(p[i]);
		while (checkGPA==0 || p[i].GPA<0 || p[i].GPA>10)
		{
			printf("Please input a float number between 0 and 10!\n");
			inputGPA(p[i]);
		}
	}
}

void outputstudent(student p[], int n)
{
	printf("List of students:");
	for (int i=1; i<=n; i++)
	{
		outputonestudent(p[i]);
	}
}

void findastudent(student p[], int n)
{
	int a, c=0;
	printf("Enter ID of the student you want to find: ");
	scanf("%d",&a);
	fflush(stdin);
	for (int i=1; i<=n; i++)
	{
		if (a==p[i].ID)
		{
			c++;
			if (p[i].GPA>=8&& p[i].GPA<=10)
			{
				printf("Student %s is Very good!",p[i].name);
			}
			if (p[i].GPA>=7 && p[i].GPA<8)
			{
				printf("Student %s is Good!",p[i].name);
			}
			if (p[i].GPA>=6 && p[i].GPA<7)
			{
				printf("Student %s is Above average!",p[i].name);
			}
			if (p[i].GPA>=5 && p[i].GPA<6)
			{
				printf("Student %s is Average!",p[i].name);
			}			
			if (p[i].GPA>=0 && p[i].GPA<5)
			{
				printf("Student %s is Weak!",p[i].name);
			}
			printf("\nPress Enter to continue!");
			getch();
		}
	}
	
	if (c==0)
	{
			printf("That student ID doesn't exist!");
			printf("\nPress Enter to continue!");
			getch();
	}
}

void swap(student &a, student &b)
{
	student t;
	t=a;
	a=b;
	b=t;
}


void soft(student p[],int n)
{
	int x=p[1].GPA;
	for (int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++)
		{
			if (p[i].GPA>p[j].GPA)
			{
				swap(p[i],p[j]);
			}
		}
	}
	outputstudent(p,n);
	printf("\nPress Enter to continue!");
	getch();
}

void showtop3(student p[], int n)
{
	if (n>3)
	{
		student x,y,z;
		x=p[1];
		y=x; z=x;
		for (int i=1; i<=n; i++)
		{
			if (p[i].GPA>x.GPA)
			{
				x=p[i];
			}
		}	
		printf("\nThe best student is student %s", x.name);
		for (int i=1; i<=n; i++)
		{
			if (p[i].GPA>y.GPA && p[i].GPA<=x.GPA && p[i].ID!=x.ID) 
			{
				y=p[i];
			}
		}
		printf("\nThe second best student is student %s", y.name);
		for (int i=1; i<=n; i++)
		{
			if (p[i].GPA>y.GPA && p[i].GPA<=y.GPA&& p[i].ID!=x.ID&&p[i].ID!=y.ID)
			{
				z=p[i];
			}
		}
		printf("\nThe third best student is student %s", z.name);
		printf("\nPress Enter to continue!");
		getch();
	}	
	else 
	{
		printf("There's not enough data to rank!");
		printf("\nPress Enter to continue!");
		getch();
	}
}
void edit(student p[], int n)
{
	int x;
	char c;
	int dem=0;
		printf("Input student ID you want to edit: ");
		scanf("%d", &x);
		fflush(stdin);
		for (int i=1;i<=n; i++)
		{
			if (x==p[i].ID)
			{
				dem++;
				inputID(p[i]);
				while (checkID==0)
				{
					printf("Please input an integer ID\n");
					inputID(p[i]);
				}
				for (int j=1;j<i;j++)
				{
					while (p[j].ID==p[i].ID)
					{
						printf("Duplicated ID, please try again\n\n");
						fflush(stdin);
						printf("Retype student %d:\n",i);
						inputID(p[i]);
					}
			}
				inputname(p[i]);
				inputGPA(p[i]);
				while (checkGPA==0 || p[i].GPA<0 || p[i].GPA>10)
				{
					printf("Please input a float number between 0 and 10!\n");
					inputGPA(p[i]);
				}	
			}	
			
		}
		if (dem=0)
		{
			printf("That student doesn't exist!\nPress Enter to continue!");
		}
	
}
