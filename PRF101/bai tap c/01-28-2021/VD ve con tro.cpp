#include<stdio.h>

int main () 
{
	int x=6;
	printf("%d",&x);
	int* p=&x;
	printf("\n%d",p);
	printf("\n%d", *p);
}
