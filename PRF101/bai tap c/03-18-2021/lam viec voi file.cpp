#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<string.h>

struct employ
{
	int EmID;
	char EmName[50];
	float Emsalarylevel;
};
int Readfile (employ a[],int n,int i)
{
	i =0;
	FILE *fpt;
	fpt = fopen("E:\\3020\\Nguyen Pham Huu Minh.txt", "r");
	while(fscanf(fpt,"\n%d\t\t%s\t\t%.f\n",&a[i].EmID,&a[i].EmName,&a[i].Emsalarylevel) != EOF) 
	{
		i++;
	}
	printf("\nThe file has been read!");
	fclose (fpt);
}
void Writefile(employ a[],int n)
{
	FILE * fpt;
    fpt = fopen("E:\\3020\\Nguyen Pham Huu Minh.txt","w");
    fprintf(fpt,"EmID\t\tEmName\t\tEmsalarylevel");
    for(int i = 1;i <=n;i++)
	{
    	fprintf(fpt,"\n%d\t\t%s\t\t%.1f",a[i].EmID,a[i].EmName,a[i].Emsalarylevel);
	}

	fclose (fpt);
	
	FILE * data;
	data = fopen("E:\\3020\\data.txt","w");
    for(int i = 1;i <=n;i++)
	{
    	fprintf(data,"%d\n%s\n%.1f\n",a[i].EmID,a[i].EmName,a[i].Emsalarylevel);
	}
	fclose (data);
}

void printmenu(int &c)
{
	printf("\n============================================================\n");
	printf("=	What do you want to do? 	                   =\n");
	printf("=		1) Total of employers.                     =\n");
	printf("=		2) Same name employers.                    =\n");
	printf("=		3) Maximum salary level.                   =\n");
	printf("=		4) Print  list                             =\n");
	printf("=		5) Soft list.                              =\n");
	printf("=		6) Rewrite list.                           =\n");
	printf("=		7) Edit an employer.                       =\n");
	printf("=		8) Add an employer.                        =\n");
	printf("=		9) Delete an employer.                     =\n");
	printf("=   	       10) Save and exit.                          =\n");
	printf("============================================================\n");
	printf("\n    	Your answer: ");
	scanf("%d", &c);
	printf("\n");
}
void samename(employ a[], int n)
{
	int c=0;
	char x[50];
	for (int i=1; i<=n; i++)
	{
		strcpy(x,a[i].EmName);
		for (int j=1; j<=n; j++)
		{
			if (strcmp(x,a[j].EmName)==0&& i<j)
			{
				printf("ID %d and %d have same name: %s\n",i,j, a[i].EmName);
				c++;
			}
		}
	}
	if (c==0)
	{
		printf("No name same same!");
	}
}

void maxsalary(employ a[], int n)
{
	employ x;
	x.EmID=a[1].EmID;
	strcpy(x.EmName,a[1].EmName);
	x.Emsalarylevel=a[1].Emsalarylevel;
	for (int i=2; i<=n; i++)
	{
		if (x.Emsalarylevel<a[i].Emsalarylevel)
		{
			x.EmID=a[i].EmID;
			strcpy(x.EmName,a[i].EmName);
			x.Emsalarylevel=a[i].Emsalarylevel;
		}
	}
	printf("Employ %s have the highest salary level: %.1f", x.EmName, x.Emsalarylevel);
	
}

int demSoDong(const char *data) 
{
    char buff[500];
    FILE *f = fopen(data, "r");

    int row = 0;
    while (fgets(buff, 500, (FILE*)f)) {
        row++;
    }

    fclose(f);
    return row;
}

void save(employ a[],int n)
{
	FILE * data;
	data = fopen("E:\\3020\\data.txt","w");
    for(int i = 1;i <=n;i++)
	{
    	fprintf(data,"%d\n%s\n%.1f\n",a[i].EmID,a[i].EmName,a[i].Emsalarylevel);
	}
	fclose (data);
}
void nhapfile(employ a[],int &n)
{

	do
	{
		printf("Enter number of employers: ");
		scanf("%d",&n);
		if (n<=0)
		{
			printf("Please input an integer number!");
		}
	}
	while (n<=0);
	for (int i=1; i<=n; i++)
	{
		a[i].EmID=i;
		printf("\nEmID: %d\n", a[i].EmID);
        fflush(stdin);
		printf("EmName: ");
        scanf("%s", &a[i].EmName);
        fflush(stdin);
        do
        {
			printf("EmsalaryLevel: ");
        	scanf("%f", &a[i].Emsalarylevel);
        	fflush(stdin);
        	if (a[i].Emsalarylevel<=0 || a[i].Emsalarylevel>10)
        	{
        		printf("Please input a float number between 1 and 10!\n");
			}
        }
		while (a[i].Emsalarylevel==0);
	}
	Writefile(a, n);
}

void infile(employ a[],int n)
{
	printf("\nEmID\tEmName\t\tEmsalarylevel\n");
	for (int i=1; i<=n; i++)
	{	
		printf("%d\t",a[i].EmID);
		printf("%s\t\t",a[i].EmName);
		printf("%.1f\n",a[i].Emsalarylevel);
	}
}

void swap(employ &a,employ &b)
{
	employ t;
	t=a;
	a=b;
	b=t;	
}

void soft(employ a[], int n)
{
    for (int i = n; i >= 0; i--) {
        for (int j = 1; j <= i; j++){
            if (a[j-1].Emsalarylevel > a[j].Emsalarylevel)
            swap(a[j-1],a[j]);
        }
    }
    printf("List after soft:");
    infile(a,n);
    Writefile(a,n);
}
void edit(employ a[], int n)
{
	int x, c=0;
	printf("\nInput ID: ");
	scanf("%d",&x);
	for (int i=1; i<=n; i++)
	{
		if (x==a[i].EmID)
		{
			printf("Input new name: ");
			scanf("%s",&a[i].EmName);
			do
		    {
				printf("EmsalaryLevel: ");
        		scanf("%f", &a[i].Emsalarylevel);
        		fflush(stdin);
       		 	if (a[i].Emsalarylevel<=0 || a[i].Emsalarylevel>10)
        		{
        			printf("Please input a float number between 1 and 10!\n");
				}
        	}
			while (a[i].Emsalarylevel<=0||a[i].Emsalarylevel>10);	
			printf("\n\nYour new list: ");
			infile(a,n);
			c++;
		}	
	}
	if (c==0) printf("Employer not found!");
	Writefile(a,n);
}
void del(employ a[], int &n)
{
	int x, c=0;
	printf("Input ID: ");
	scanf("%d",&x);
	for (int i=1; i<=n; i++)
	{
		if (x==a[i].EmID)
		{
			for (int j=i; j<=n; j++)
			{
				a[j]=a[j+1];
			}
			c++;
			n--;
			printf("\n\nYour new list: ");
			infile(a,n);
		}
	}
	if (c==0)
	{
		printf("Employer not found!");
	}
	Writefile(a,n);
}

void add(employ a[], int &n)
{
	int c;
	n++;
	do
	{
		c=0;
		printf("Input ID: ");
		scanf("%d", &a[n].EmID);
		for (int i=1; i<=n; i++)
		{
			if (a[n].EmID==a[i].EmID)
			{
				c++;
			}
		}
	}
	while (c==0);
	printf("Input Name: ");
	scanf("%s",&a[n].EmName);
	do
    {
		printf("EmsalaryLevel: ");
   		scanf("%f", &a[n].Emsalarylevel);
   		fflush(stdin);
   		 	if (a[n].Emsalarylevel<=0 || a[n].Emsalarylevel>10)
       		{
       			printf("Please input a float number between 1 and 10!\n");
			}
    }
	while (a[n].Emsalarylevel<=0||a[n].Emsalarylevel>10);	
	
	printf("Your new list: ");
	infile(a,n);
	Writefile(a,n);
}

void xuat(employ a[],int n)
{
	char x[1], y[50], z[51];
	printf("Input Disk (D/E): ");
	scanf("%s",&x);
	fflush(stdin);
	printf("Input File name: ");
	gets(y);
	fflush(stdin);
	strcpy(z,x);
	strcat(z,":\\");
	strcat(y,".txt");
	strcat(z,y);
	//============
	save(a,n);
	FILE * fpt;
    fpt = fopen(z,"w");
    fprintf(fpt,"EmID\t\tEmName\t\tEmsalarylevel");
    for(int i = 1;i <=n;i++)
	{
    	fprintf(fpt,"\n%d\t\t%s\t\t%.f",a[i].EmID,a[i].EmName,a[i].Emsalarylevel);
	}
	printf("\nSave file successful!\n");
	fclose (fpt);
	
}

int main() 
{
	FILE *data;
	int n,i,c;
	int sd=demSoDong("E:\\3020\\data.txt");
	n=sd/3;
	employ a[100];
	//lay du lieu ra
	data=fopen("E:\\3020\\data.txt","r");
	for (int i=1; i<=sd; i++)
	{
		fscanf(data,"%d\n",&a[i].EmID);	
		fscanf(data,"%s\n",&a[i].EmName);
		fscanf(data,"%f\n",&a[i].Emsalarylevel);
	}
	fclose(data);
	//-------------------------
	
	//=========================
	while (true)
	{
		system("cls");
		printmenu(c);
		switch (c)
		{
			case 1:
				printf("Total of employers: %d",n);
				printf("\n\nPress any key to continue!");
				getch();
				break;
			case 2:
				samename(a,n);
				printf("\n\nPress any key to continue!");
				getch();
				break;
			case 3:
				maxsalary(a,n);
				printf("\n\nPress any key to continue!");
				getch();
				break;
			case 4:
				infile(a,n);
				printf("\n\nPress any key to continue!");
				getch();
				break;
			case 5: 
				soft(a,n);
				printf("\n\nPress any key to continue!");
				getch();
				break;
			case 6:
				nhapfile(a,n);
				printf("File has been rewritten!");
				printf("\n\nPress any key to continue!");
				getch();
				break;
			case 7:
				edit(a,n);
				printf("\n\nPress any key to continue!");
				getch();
				break;
			case 8:
				add(a,n);
				printf("\n\nPress any key to continue!");
				getch();
				break;
			case 9:
				del(a,n);
				printf("\n\nPress any key to continue!");
				getch();
				break;
			case 10:
				xuat(a,n);
				printf("\n\nPress any key to exit!");
				getch();
				exit(0);
				break;
		}
		
	}
}
