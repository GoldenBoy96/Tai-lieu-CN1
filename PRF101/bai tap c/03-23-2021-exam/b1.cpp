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


int main()
{
	// doc file
	int n;
	readfile(a, n);
	//mo file xuat
	FILE *out;
	out = fopen(xuat, "w");
	//sapxep
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
	
	//xuat hien thuong xuyen nhat	
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
	fprintf(out, "\n%d most frequent",c);
	if(max==1)
	fprintf(out,"\nAll appear one!");
	
	//so chan va le
		int count=0;
	for (int i=1; i<=n; i++)
	{
		if (a[i]%2==1)
		{
			count++;
		}
	}
	if (count==0)
	{
		fprintf(out,"\nNo odd numbers found.");
	}
	else fprintf(out,"\nNumber of odd numbers: %d",count);
	count=0;
	for (int i=1; i<=n; i++)
	{
		if (a[i]%2==0)
		{
			count++;
		}
	}
	if (count==0)
	{
		fprintf(out,"\nNo even numbers found.");
	}
	else fprintf(out,"\nNumber of even numbers: %d",count);
	//binh phuong cua 1 so
	int d=0;
	fprintf(out,"\nLocation of square number: ");
	for (int i=1; i<=n; i++)
	{
		for(int j=1; j<=a[i]/2;j++)
		{
			if (j*j==a[i])
			{
				fprintf(out,"%d ",i);
				d++;
			}
		}
	}
	if (d==0)
	{
		fprintf(out,"NULL!");
	}
	fclose(out);
	//done
	printf("Process done!\nGo out and check you file!");
}

