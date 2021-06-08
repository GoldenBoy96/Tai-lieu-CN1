#include<stdio.h>
#include<math.h>
#include<windows.h>
#include<conio.h>
int main() 
{
	long int bi,count=0,di=0;
	printf("Nhap so nhi phan: ");
	scanf("%d",bi);
	
	while (bi>0)
	{
		di=di+((bi%10)*pow(2,count));
		count++;
		bi=bi/10;
	}
	printf("So thap phan: %d",di);
	getch();
	getch();
}

