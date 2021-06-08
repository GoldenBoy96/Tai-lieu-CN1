#include<stdio.h>
int main() 
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
