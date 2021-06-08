#include<stdio.h>
#include<math.h>
#include <conio.h>
#include <unistd.h>
#include <windows.h>
void doisonhiphansangthapphan() 
{
	long int bi,count=0,di=0;
	printf("Nhap so nhi phan: ");
	scanf("%d",bi);
	
	while (bi>0)
	{
		di=di+(bi%10)*pow(2,count);
		count++;
		bi=bi/10;
	}
	printf("So thap phan: %d",di);
	getchar();
	getchar();
}

void doisothapphansangnhiphan() 
{
	int di,bi[100], count=0 ;
	printf("Nhap so thap phan: ");
	scanf("%d",&di);
	for (int i=1; di>0; i++) {
		bi[i]=di%2;
		di=di/2;
		count++;
	}
	printf("So nhi phan: ");
	for (int i=count; i>=1;i--)
	{
		printf("%d",bi[i]);
	}
}

void xuatrabangcuuchuong()
{
	for (int i=1;i<=9;i++)
	{
		for (int j=1;j<=9;j++)
		{ 
			printf("\t%d x %d = %d\n",i,j,i*j);
			
		}
		printf("\n");
	}
}

void timsochuso() 
{
	int a,b;
	printf("Nhap so: ");
	scanf("%d",&a);
	while (a>0)
	{
		a/=10;
		b++;
	}
	printf("So ban nhap co %d chu so.",b);
	
}

void daonguocso()
{
	int a,b=0,c,d=0;
	printf("Type an integer: ");
	scanf("%d",&a);
	c=a;
	for (int i=0; c>0;i++)
	{
		c=c/10;
		++d;
	}
	for (int i=d-1;i>=0;i--)
	{
		b+=(a%10)*pow(10,i);
		a=a/10;
	}
	printf("Invert: %d",b);
	
}

int main()
{
	int quest,count=0;
	char help;
	while (true)
	{	
		system("cls");
		if (count>=3) {
			count=0;
			printf("\a\aDo you need help? (y/n)\n");
			fflush(stdin);
			scanf("%c",&help);
			fflush(stdin);
			if (help=='y'||help=='Y') {
				printf("\aType a number from 1 to 5 to run the program!");
				getch();
			}
			else if(help=='n'||help=='N')
			{
				printf("\aOk honey!");
				sleep(1);
			}
			else 
			{
			printf("WTF are you typing?");
			sleep(1);
			}
		}
		else
		{
		printf("\aWhat do you want to do?\n1) Change binary to demacia.\n2) Change decima to binary.\n3) Print multiplication table.\n4) Find the number of a natural number.\n5) Invert number.\n");
		printf("Put your command here: ");
		scanf("%d",&quest);
		if (quest<1 || quest >5) {
			printf("Command not exist, please try again!\n\n");
			count++;
		}
	
		else
		switch (quest)
		{
			case 1:
				count=0;
				doisonhiphansangthapphan();
				printf("\n");
				break;
			case 2: 
				count=0;
				doisothapphansangnhiphan();
				printf("\n");
				break;	
			case 3:
				count=0;
				xuatrabangcuuchuong();
				printf("\n");
				getch();
				break;
			case 4:
				count=0;
				timsochuso();
				printf("\n");
				break;
			case 5:
				count=0;
				daonguocso();
				printf("\n");
				break;
		}
			sleep(1);
		}
		}
		
	
	}

