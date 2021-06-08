#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
char file[50]="D:\\data.txt";
struct employ
{
	int EmID;
	char EmName[50];
	float Emsalarylevel;
}; 

int demSoDong(const char *fpt) 
{
    char buff[500];
    FILE *f = fopen(fpt, "r");

    int row = 0;
    while (fgets(buff, 500, (FILE*)f)) {
        row++;
    }

    fclose(f);
    return row;
}


int readfile (employ a[],int n)
{
	char x[100];
	FILE *fpt;
	fpt = fopen(file, "r");
	fgets(x,100,fpt);
	for (int i=1; i<=n; i++)
	{
		fscanf(fpt,"%d",&a[i].EmID);
		fscanf(fpt,"%s",&a[i].EmName);
		fscanf(fpt,"%f",&a[i].Emsalarylevel);
	}
	fclose (fpt);
}

int writefile (employ a[], int n)
{
	FILE * fpt;
    fpt = fopen(file,"w");
    fprintf(fpt,"EmID\t\tEmName\t\tEmsalarylevel");
    for(int i = 1;i <=n;i++)
	{
    	fprintf(fpt,"\n%d\t\t%s\t\t%.1f",a[i].EmID,a[i].EmName,a[i].Emsalarylevel);
	}

	fclose (fpt);
}

void printmenu(int &c)
{
	printf("\n===================================================\n");
	printf("=	What do you want to do?	                  =\n");
	printf("=	1) Rewrite list.                          =\n");
	printf("=	2) Edit an employer.                      =\n");
	printf("=	3) Add an employer.                       =\n");
	printf("=	4) Delete an employer.                    =\n");
	printf("=	5) Find an employer.                      =\n");
	printf("=	6) Sortlist.                     	  =\n");
	printf("=	7) Export.				  =\n");
	printf("=	8) Exit.				  =\n");
	printf("===================================================\n");
	printf("\n    	Your answer: ");
	scanf("%d", &c);
	printf("\n");
}

int inra(employ a[], int n)
{
	printf("EmID\tEmName\t\tEmsalarylevel\n");
	for (int i=1; i<=n; i++)
	{
		printf("%d\t%s\t\t%.1f\n", a[i].EmID, a[i].EmName, a[i].Emsalarylevel);
	}
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
		printf("\nEmID: ");
		scanf("%d", a[i].EmID);
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
	writefile(a, n);
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
			printf("\n\nYour list has been updated! ");
			writefile(a, n);
			c++;
		}	
	}
	if (c==0) printf("Employer not found!");
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
			printf("\n\nYour list has been update!");
		}
	}
	if (c==0)
	{
		printf("Employer not found!");
	}
	writefile(a, n);
}

void add(employ a[], int &n)
{
	n++;
	int c;
	do
	{
		c=0;
		printf("Input ID: ");
		scanf("%d", &a[n].EmID);
		for (int i=1; i<n; i++)
		{
			if (a[n].EmID==a[i].EmID)
			{
				printf("Duplicated ID, please try again!\n");
				c++;
			}
		}
	}
	while (c!=0);
	printf("Input Name: ");
	scanf("%s",&a[n].EmName);
	fflush(stdin);
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
	
	printf("Your list has been updated! ");
	writefile(a, n);
}

void swap(employ &a,employ &b)
{
	employ t;
	t=a;
	a=b;
	b=t;	
}

void sort(employ a[], int n)
{
    for (int i = n; i >= 0; i--) {
	    for (int j = 1; j <= i; j++)
		{
            if (a[j-1].Emsalarylevel > a[j].Emsalarylevel)
            swap(a[j-1],a[j]);
        }
    }
	printf("\n\nList after sorted:\n");
	printf("EmID\t\tEmName\t\tEmsalarylevel");
    for(int i = 1;i <=n;i++)
	{
    	printf("\n%d\t\t%s\t\t%.1f",a[i].EmID,a[i].EmName,a[i].Emsalarylevel);
	}
	writefile(a, n);
}

void find(employ a[], int n)
{
	int x, c=0;
	printf("Input ID: ");
	scanf("%d",&x);
	for (int i=1; i<=n; i++)
	{
		if (x==a[i].EmID)
		{
			printf("ID %d name %s has %.1f salary level!", a[i].EmID,a[i].EmName,a[i].Emsalarylevel);
			c++;
		}
	}
	if (c==0) 
	{
		printf("ID %d not exist!",x);
	}
	
}



void xuatfile(employ a[], int n)
{
	//==========================
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
	FILE * fpt;
    fpt = fopen(z,"w");
    
	//fprintf(fpt,"EmID\t\tEmName\t\tEmsalarylevel");
    //for(int i = 1;i <=n;i++)
	//{
    //	fprintf(fpt,"\n%d\t\t%s\t\t%.1f",a[i].EmID,a[i].EmName,a[i].Emsalarylevel);
	//}

	
	//==========================
	fprintf(fpt, "Total of employees: %d",n);	
	//==========================
	fprintf(fpt,"\nSame name employers: ");
	employ b[50];
	for (int i=1; i<=n; i++)
	{
		b[i]=a[i];	
	}	
	int kt[100];
	int count =0;
	int dem;
	kt[0]=-1;
	for ( int i=1; i<=n-1; i++){
		dem=0;
		for (int k1=0; k1<= count; k1++){
			if (kt[k1]==i){
				dem ++;
			}
		}
		if (dem ==0){

		for ( int j=i; j<=n; j++){

			if (strcmp(b[i].EmName, b[j].EmName)== 0){
				kt[count] = j;
				count++;
				dem ++;
			}
		    
		}
		if ( dem >1){
		    for (int k=count - dem; k<= count-1 ; k++){
		    	fprintf (fpt,"%d", b[kt[k]].EmID);
		    	if (k< count-1 ){
		    		fprintf (fpt,",");
				}
				else fprintf (fpt,"; ");
			}	
		}
	}
	}
		
	//==========================
	employ g;
	g=a[1];
	for (int i=2; i<=n; i++)
	{
		if (g.Emsalarylevel<a[i].Emsalarylevel)
		{
			g=a[i];
		}
	}
	fprintf(fpt, "\nThe highest salary level belong to ID %.d: %.1f",g.EmID, g.Emsalarylevel);
	//==========================
	printf("\nFile has been exported!");
	fclose (fpt);
}

int main()
{
	FILE *fpt;
	employ a[30];
	int n=demSoDong(file),c;
	n--;

	readfile(a,n);

	while (true)
	{
		system("cls");
		inra(a,n);
		printmenu(c);
		switch (c)
		{

			case 1:
				nhapfile(a,n);
				printf("File has been rewritten!");
				printf("\n\nPress any key to continue!");
				getch();
				break;
			case 2:
				edit(a,n);
				printf("\n\nPress any key to continue!");
				getch();
				break;
			case 3:
				add(a,n);
				printf("\n\nPress any key to continue!");
				getch();
				break;
			case 4:
				del(a,n);
				printf("\n\nPress any key to continue!");
				getch();
				break;
			case 5:
				find(a,n);
				printf("\n\nPress any key to continue!");
				getch();
				break;
			case 6:
				sort(a,n);
				printf("\n\nPress any key to continue!");
				getch();
				break;
			case 7:
				xuatfile(a,n);
				printf("\n\nPress any key to continue!");
				getch();
				break;
			case 8:
				exit(0);
				break;
		}
		
	}	
}
