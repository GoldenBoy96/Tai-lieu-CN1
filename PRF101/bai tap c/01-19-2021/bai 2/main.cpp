#include <stdio.h>

int main() 
{
	int di, bi[100], count=0 ;
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
