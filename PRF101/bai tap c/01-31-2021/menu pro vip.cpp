#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <unistd.h>
#include <windows.h>
#include <stdlib.h>

void doisonhiphansangthapphan() 
{
	
	printf("Change binary to demacia.\n");
	int bi,count=0,di=0;
	printf("Input binary: ");
	scanf("%d",&bi);
	
	while (bi>0)
	{
		di=di+(bi%10)*pow(2,count);
		count++;
		bi=bi/10;
	}
	printf("Decimal: %d",di);
	getch();
}

void doisothapphansangnhiphan() 
{
	printf("Change decima to binary\n");
	int di,bi[100], count=0 ;
	printf("Input decimal: ");
	scanf("%d",&di);
	for (int i=1; di>0; i++) {
		bi[i]=di%2;
		di=di/2;
		count++;
	}
	printf("Binary: ");
	for (int i=count; i>=1;i--)
	{
		printf("%d",bi[i]);
	}
}

void xuatrabangcuuchuong()
{
	printf("Print multiplication table\n");
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
	printf("Find the number of a natural number.\n");
	int a,b=0;
	printf("Type a natural number: ");
	scanf("%d",&a);
	while (a>0)
	{
		a/=10;
		b++;
	}
	printf("Your number has %d numbers.",b);
	
}

void daonguocso()
{
	printf("Invert number.\n");
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

void gotoxy(int x, int y)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}

int main() {
	char phim;
	int y=2;
	while (true) 
	{	
		system("cls");
		printf("What do you want to do?\n  Change binary to demacia.\n  Change decima to binary.\n  Print multiplication table.\n  Find the number of a natural number.\n  Invert number.\n");
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
				if (y>=6) y--;
				gotoxy(1,y);
			}
		}
		if(phim==13)
		{	
			
			switch (y) 
			{
				case 1:
					system("cls");
					doisonhiphansangthapphan();
					getch();
					break; 
				case 2:
					system("cls");
					doisothapphansangnhiphan();
					getch();
					break;
				case 3:
					system("cls");
					xuatrabangcuuchuong();
					getch();
					break;
				case 4:
					system("cls");
					timsochuso();
					getch();
					break;
				case 5:
					system("cls");
					daonguocso();
					getch();
					break;	
			}
		}
	
		
	}
	return 0;

}
