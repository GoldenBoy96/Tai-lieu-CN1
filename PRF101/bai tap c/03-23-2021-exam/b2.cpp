#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<string.h>

char file[50]="D:\\As4in.txt";
char xuat[50]="D:\\As4out.txt";
int a[100];

void readfile(int a[],int &n)
{
	char x[100];
	FILE *fpt;
	fpt = fopen(file, "r");
	fscanf(fpt,"%d",&n);
	int i=0;
	do
	{
		if (i<=n)
		{
			i++;
		}
	}
	while (fscanf(fpt,"%d",&a[i])==1);
	fclose (fpt);
}

void printfile(int a[], int &n)
{
	for (int i=1; i<=n; i++)
	{
		printf(" %d",a[i]);
	}
}
void swap(int a,int b)
{
	int t;
	t=a;
	a=b;
	b=t;	
}
FILE *out=fopen(xuat, "w");
void sort(int a[], int n){
	int t=0;
	for(int i=0;i<n;i++)
	for(int j=i+1;j<=n;j++)
	{
		if(a[i]>a[j])
		{
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
		
	}
	fprintf(out,"List after sorted: ");
	for (int i=1; i<=n; i++)
	{
		fprintf(out,"%d ",a[i]);
	}

}

void findsquarenumber(int a[], int n)
{
	int c=0;
	fprintf(out,"\nSquare number: ");
	for (int i=1; i<=n; i++)
	{
		for(int j=1; j<=a[i]/2;j++)
		{
			if (j*j==a[i])
			{
				printf("%d ",a[i]);
				c++;
			}
		}
	}
	if (c==0)
	{
		fprintf(out,"NULL!");
	}
	fclose(out);
}

void mostfrequent(int a[], int n)
{
	sort(a,n);
	int max=1;
	int c;
	int dem=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]==a[i+1])
		{	
		
		dem++;
		if(dem>max)
		{
					max=dem;
					c=a[i];
				}	
			
		}
		else
		{
			
           dem=1;
           
		}
	}
	if(max>1)
	printf("%d lap nhieu nhat\n",c);
	if(max==1)
	printf("tat ca chi lap 1 lan");
}

void oddandeven(int a[], int n)
{

	int count=0;
	fprintf(out,"\nOdd number: ");
	for (int i=1; i<=n; i++)
	{
		if (a[i]%2==1)
		{
			fprintf(out, "%d ",a[i]);
			count++;
		}
	}
	if (count==0)
	{
		fprintf(out,"NULL!");
	}
	count=0;
	fprintf(out,"\nEven number: ");
	for (int i=1; i<=n; i++)
	{
		if (a[i]%2==0)
		{
			fprintf(out,"%d ",a[i]);
			count++;
		}
	}
	if (count==0)
	{
		fprintf(out,"NULL!");
	}

}
int fclose(out*);
int main()
{
	int n;
	readfile(a, n);
	

}

