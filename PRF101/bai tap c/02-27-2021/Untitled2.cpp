#include<stdio.h>

struct student 
{
	int ID;
	float marks;
};


void InputOneStd (student *);
void OutputOnestd (student);
void InputList (struct student *, int *);
void OutputList (struct student *, int );

int main ()
{
	student a[10];
	int n;
	InputList (a,&n);
	OutputList (a,n);
}

void InputOneStd (struct student &p)
{
	printf("Input student ID: \n");
	scanf("%d",&p.ID);
	printf("Input student's marks: \n");
	scanf("%f",&p.marks);
	
}

void OutputOnestd (struct student p)
{
	printf("%d has %.1f mark",p.ID,p.marks);
}

void InputList(struct student *p, int *n)
{
	printf("Input the number of student: ");
	scanf("%d",n);
	for (int i=0; i<*n; i++)
	{
		printf("Input data for student %d: ", i);
		InputOneStd(p[i]);
	}
}

void OutputList (struct student *p, int m )
{
	for (int i = 0; i<m; i++)
	{
		OutputOnestd(p[i]);
	}
}

