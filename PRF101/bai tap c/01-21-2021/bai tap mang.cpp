#include<stdio.h>
int main ()
{
	int n,x,c=0,b=0;
	int a[100];
	printf("Nhap so phan tu trong mang: ");
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		printf("Nhap so thu %d: ",i);
		scanf("%d",&a[i]);
	}
	printf("\nNhap phan tu can tim: ");
	scanf("%d",&x);
	printf("\n");
	//xac dinh x va tim kiem vi tri dau tien cua x
	for (int i=1;i<=n;i++)
	{
		if (c<1)
		{
			b++;
		}
		if (x==a[i])
		{
			c++;
			
		}
	
	}
	if (c>0) 
	{
		printf("%d co ton tai trong mang",x);
		printf("\nVi tri dau tien cua %d la %d.",x,b);
	
	//tim kiem tat ca cac vi tri cua x
		printf("\nCac vi tri cua %d la:",x);
		for (int i=1;i<=n;i++)
		{
			if (x==a[i])
			{
				printf(" %d",i);
			}
		}
	}
	else 
	{
		printf("%d khong ton tai trong mang",x);
	}
	
	//sap xem phan tu
	int t;
	
	do
	{
		c=0;
		for (int i=1;i<=n-1;i++)
		{
			if(a[i]<a[i+1])
			{
				t=a[i];
				a[i]=a[i+1];
				a[i+1]=t;
				c++;
			}
		
		}
	}
	while (c!=0);
	printf("\nMang sau khi sap xep: ");
	for (int i=1; i<=n; i++)
	{
		printf(" %d", a[i]);
	}
}
