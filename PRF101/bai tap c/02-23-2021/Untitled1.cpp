#include<stdio.h>
#include<conio.h>
#include<windows.h>

void gotoxy(int x, int y)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}
void input(int a[1000],int n)
{
	for (int i=1;i<=n;i++)	
	{
		system("cls");
		printf("Nhap so thu %d: ", i);
		scanf("%d",&a[i]);

	}
}
void output(int a[1000], int n)
{
	system("cls");
	printf("Your array: ");
	for (int i=1;i<=n;i++)
	{
		printf("%d ", a[i]);
	}
}
void sapxep(int a[1000],int n)
{

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
}
void find(int a[1000],int n) 
{
	output(a,n);
	int x,c=0;
	printf("\nWhat do you want to find: ");
	scanf("%d",&x);
	for (int i=1;i<=n;i++)
	{
		if (a[i]==x)
		{	
			c++;
			printf("You number is at the %d position\n",i);
		}
		if (c=0)
		{
			printf("The number doesn't exist in your array.'");
		}
	}
}
void deleteanumber(int a[1000],int &n)
{
	output(a,n);
	int x;
	while (true)
	{
		printf("\nWhich position do you want to delete? ");
		scanf("%d",&x);
		if (x>0 && x<=n)
		{
			for (int i=x; i<n; i++)
			{
				a[i]=a[i+1];
			}
			printf("Your new array: ");
			for (int i=1; i<=n-1;i++)
			{
				printf("%d ",a[i]);
			}
			n--;
			break;
		}
		else
		{
			printf("Please type a number between 1 and %d",n);
			getch();
		}
	}
}
void add(int a[],int &n)
{
	int x,y;
	while (true)
	{
		system("cls");
		output(a,n);
		printf("\nWhich position do you want to add? ");
		scanf("%d",&x);
		if (x>0 && x<=n)
		{
			printf("What do you want to add? ");
			scanf("%d",&y);
			n++;
			for (int i=n; i>x; i--){
				a[i]=a[i-1];
			}
			a[x]= y;
			printf("Your new array: ");
			for (int i=1; i<=n;i++)
			{
				printf("%d ",a[i]);
			}
			break;
		}
		else
		{
			printf("Please type a number between 1 and %d",n);
			getch();
		}
	}
}

int main() 
{
		int a[1000],n;
		int y=2;
		char phim;
		while (true)
		{
				printf("Type your array.\n");
				printf("The number of elements: ");
				if(phim==27){
					system("cls");
            		break;
       			}
				scanf("%d",&n);
				input(a,n);
				break;
		}
		while (a[n]!=a[0])
		{
			system("cls");
			output(a,n);
			printf("\nWhat do you want to do?\n1)Rewrite the array.\n2)Delete an element.\n3)Add an element.\n4)Find an elements.\n5)Exit.");
			gotoxy(1,y);
			phim=getch();
			if(phim==27){
				system("cls");
            	break;
       		}
			if(phim==-32)
			{
				phim=getch();
				if (phim==72)
				{
					y--;
					if (y<=0) y++;
					gotoxy(1,y);			
				}
				if (phim==80)
				{
					y++;
					if (y>=7) y--;
					gotoxy(1,y);
				}
			}
			if(phim==13)
			{	
			
				switch (y) 
				{
					case 2:
						system("cls");
						input(a,n);
						break;
					case 3:
						system("cls");
						deleteanumber(a,n);
						getch();
						break;
					case 4:
						system("cls");
						add(a,n);
						getch();
						break;
					case 5:
						system("cls");
						find(a,n);
						getch();
						break;
					case 6:
						system("cls");
						exit(0);
						break;
				}		
		
			}
	}
}
