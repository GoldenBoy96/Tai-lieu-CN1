struct student 
{
	int ID;
	char name[40];
	float GPA;
};
int checkID=0, checkGPA=0, check=0;
int n,c;
student a[10];

void inputID(student &p);
void inputname(student &p);
void inputGPA(student &p);
void inputonestudent(student &p);
void outputonestudent(student &p);
void inputnumber(int &n);
void inputstudent(student p[],int &n);
void outputstudent(student p[], int n);
void findastudent(student p[], int n);
void swap(student &a, student &b);
void soft(student p[],int n);
void showtop3(student p[], int n);
void edit(student p[], int n);
