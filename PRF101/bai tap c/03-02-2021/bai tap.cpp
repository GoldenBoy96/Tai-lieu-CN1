#include <stdio.h>
#include <windows.h>
#include <conio.h>
float a[100];
int n;
char p;


void input(float a[],int &n)
{
	system("cls");
	printf("Length of the list: ");
	scanf("%d",&n);
	fflush(stdin);
	for (int i=1; i<=n; i++)
	{
		printf("Input a[%d]: ",i);
		scanf("%f",&a[i]);
	}
}
void output(float a[],int &n)
{
	printf("Your list: ");
	for (int i=1; i<=n; i++)
	{
		printf("%.1f ",a[i]);
	}
}
void maximum(float a[],int &n)
{
	output(a,n);
	float x;
	x=a[1];
	for (int i=1;i<=n;i++)
	{
		if (a[i]>x)
		{
			x=a[i];
		}
	}
	printf("\nMaximum is: %.1f",x);
}
void average(float a[],int &n)
{
	output(a,n);
	float S=0,c=0;
	for (int i=1; i<=n; i++)
	{
		S=S+a[i];
	}
	S=S/n;
	printf("\nAverager: %.1f",S);
	printf("\nNumbers that greater or equa to average: ");
	for (int i=1; i<=n; i++)
	{
		if (a[i]>S)
		{
			printf("%.1f ",a[i]);
		}
		if (a[i]==S)
		{
			
			if (c==0)
			{
				printf("%.1f ",a[i]);
				c++;
			}
		}
	}
}
void insert(float a[],int &n)
{
	output(a,n);
	int c=0;
	while (c<=3)
	{
		int x,y;
		printf("\nInsert location: ");
		scanf("%d",&x);
		if(x>0 && x<=n)
		{
			printf("Insert number: ");
			scanf("%d",&y);
			for (int i=n+1;i>x;i--)
			{
				a[i]=a[i-1];
			}
			a[x]=y;
			n++;
			printf("New list: ");
			for (int i=1;i<=n;i++)
			{
				printf("%.1f ",a[i]);
			}
		
		}
		else 
		{
			if (c<=3)
			{
				printf("Please type a number between 1 and %d!",n);
				c++;
			}
			else 
			{
				printf("You are so stupid, please try again later!");
				break;
			}
		}
		fflush(stdin);
		printf("\nDo you want to continue? \nY to continue or any key to come back:");
		scanf("%c", &p);
		if (p=='Y'||p=='y')
		{
		}
		else 
		{
			break;
		}
	}
}
void deletenumber(float a[],int &n)
{
	output(a,n);
	int c=0;
	while (c<=3)
	{
		int x;
		printf("\nInsert location: ");
		scanf("%d",&x);
		if(x>0 && x<=n)
		{
			for (int i=x;i<=n;i++)
			{
				a[i]=a[i+1];
			}
			n--;
			printf("New list: ");
			for (int i=1;i<=n;i++)
			{
				printf("%.1f ",a[i]);
			}
		}
		else 
		{
			if (c<=3)
			{
				printf("Please type a number between 1 and %d!",n);
				c++;
			}
			else 
			{
				printf("You are so stupid, please try again later!");
				break;
			}
		}
		fflush(stdin);
		printf("\nDo you want to continue? \nY to continue or any key to come back:");
		scanf("%c", &p);
		if (p=='Y'||p=='y')
		{
		}
		else 
		{
			break;
		}
	}	
}
void sort(float a[], int &n)
{
	output(a,n);
	for (int i=1;i<=n;i++)
	{
		for (int j=i+1; j<=n; j++)
		{
			if(a[i]>a[j])
			{
				int t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	printf("\nYour new list: ");
	for (int i=1;i<=n;i++)
	{
		printf("%.1f ",a[i]);
	}
}
void ab(float a[], int &n)
{
	output(a,n);
	int x,y;
	while (true)
	{	
		printf("\nInput a: ");
		scanf("%d",&x);
		printf("Input b: ");
		scanf("%d",&y);
		if (x<y)
		{
			printf("Number that are greater or equal to a and less than or equal to b: ");
			for (int i=1; i<=n;i++)
			{
				if (a[i]>=x&&a[i]<=y)	
				{
					printf("%.1f ",a[i]);
				}
			}
		}
		else printf("Please input a<b");
		fflush(stdin);
		printf("\nDo you want to continue? \nY to continue or any key to come back:");
		scanf("%c", &p);
		if (p=='Y'||p=='y')
		{
		}
		else 
		{
			break;
		}
	}
}

int main()
{
	int d;
	input(a,n);	
	while (true)
	{
		system("cls");
		output(a,n);
		printf("\nMenu:\n1) Insert a mark into the list\n2) Delete a mark from the array\n3) Sort the list\n4) Find maximum marks\n5) Find marks that are greater than or equal to the average of all the marks\n6) Input a and b (a<b), find x that a<=x<=b\n7) Reinput list\n8) Exit");
		printf("\nWhat do you want to do: ");
		scanf("%d",&d);
		if (d>0 && d<=8)
		{
			switch (d)
			{
				case 1:
					system("cls");
					insert(a,n);
					break;
				case 2:
					system("cls");
					deletenumber(a,n);
					break;
				case 3:
					system("cls");
					sort(a,n);
					getch();
					break;
				case 4:
					system("cls");
					maximum(a,n);
					getch();
					break;
				case 5:
					system("cls");
					average(a,n);
					getch();
					break;
				case 6:
					system("cls");
					ab(a,n);
					break;
				case 7:			
					input(a,n);
					getch();
					break;
				case 8:
					exit(0);
			}
		}
		else 
		{
			printf("Please input a number between 1 and 8");
		}
		
	}
}
