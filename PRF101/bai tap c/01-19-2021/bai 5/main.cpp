#include<stdio.h>
#include<math.h>
int main()
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
	return 0;
}
