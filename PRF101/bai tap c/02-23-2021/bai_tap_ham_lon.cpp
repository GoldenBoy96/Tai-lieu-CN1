#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


int a[100];

void input(int n){
	for (int i=0; i<n; i++){
		printf ("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}

void output( int n){
	printf ("\nThe array after modifying is: \n");
	for ( int i=0; i<n; i++){
		printf ("a[%d] = %d\n",i, a[i]);
	}
	printf ("\n\n");
}

void find (int a[], int n){
	int v, dem=0;
	printf("Please enter the value that you want to find: ");
	scanf("%d", &v);
	for (int i=0; i<n; i++){
		if(a[i] == v){
			dem++;
		}
	}
	if(dem==0){
		printf ("The array doesn't have any elements that have value %d.", v);
	}else {
		printf("The position in array has value %d is/are: ", v);
		for (int i=0; i<n; i++){
		if(a[i] == v){
			printf("%d\t", i);
		}
	}
	}
		printf ("\n\n");
}

void add(int a[], int &n){
	int p, v;
	printf("\nEnter the position that you want to add: ");
	scanf("%d", &p);
	if (p<0 || p>=n){
		while(p<0 || p>=n){
			printf ("\nPlease retype an legal position (0 <= p <= %d): ", n-1);
			scanf("%d", &p);
		}
	}
	printf ("\nEnput the value that you want to add: ");
	scanf("%d", &v);
	n++;
	for (int i=n-1; i>p; i--){
		a[i]=a[i-1];
	}
	a[p]= v;
	output(n);
}

void Delete(int a[], int &n){
	int p;
	do{
	printf("\nEnter the position that you want to delete: ");
	scanf("%d", &p);
	if (p<0 || p>=n){
		while(p<0 || p>=n){
			printf ("\nPlease retype an legal position (0 <= p <= %d): ", n-1);
			scanf("%d", &p);
		}
	}
	for (int i=p; i<n-1; i++){
		a[i]=a[i+1];
	}
	n--;
	}
	while(p>=0 && p<n);
	output(n);
} 

 void menu(){
 	printf("\nMENU:\n");
 	printf("1. Find.\n2. Add. \n3. Delete.");
 	printf("\n4. Exit.\n5. Help.");
 }
 
 void check(int *c){
	while(*c <=0 || *c >5){
		printf("Please retype an legal number (1 <= n <= 5): "); scanf("%d", c);
		printf("\n");
	}
}
 
void ask(){
	char ans;
	printf("Do you want to continue? (Y/N):  ");	fflush(stdin); scanf("%c", &ans);
		if(ans=='Y'||ans=='y'){
		printf("\n\n");
		menu();
	}else if(ans=='N'||ans=='n'){
			exit(0);
		}else {
			printf ("Please retype a legal option.\n");
			ask();
		}
}


 int main(){
 	int choose;
 	int n;
 	printf("Fisrt, you must create a new array. \n");
	printf("\nEnter the number of element in the array: ");
	scanf("%d", &n);
 	input(n);
	menu();
	
 	do{
	printf("\nEnter your choose: "); scanf("%d", &choose);
	check(&choose);
	printf("\n");
	if (choose == 1){
		find(a,n);
		ask();
	}
	if (choose == 2){
		add(a,n);
		ask();
	}
	if(choose == 3){
		Delete(a,n);
		ask();
	}
	if (choose == 4){
		exit(0);
	}
	if (choose ==5){
		printf("Enter a number from 1 to 5 to choose the option. \n\n");
	    ask();	
	}
}
while(1<= choose <=5);    
  getch();
 }
