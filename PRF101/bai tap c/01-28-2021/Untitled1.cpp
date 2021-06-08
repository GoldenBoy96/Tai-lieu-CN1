#include<stdio.h>

void input(int &x,int &y) //Luu dia chi cua a, b
{
	printf("Nhap a: ");
	scanf("%d",&x);
	printf("Nhap b: ");
	scanf("%d",&y);
}
void output(int x, int y)
{
	printf("Tong 2 so la: %d",x+y);
}
int main() 
{
	int a,b;
	input(a,b);
	output(a,b);
}
