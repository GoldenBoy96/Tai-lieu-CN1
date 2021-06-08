#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include <stdlib.h>
#include "source.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main()
{
	inputstudent(a,n);
	while (true)
	{
		system("cls");
		printf("What do you want to do?\n1) Print out the student list\n2) Find a student\n3) Soft the list\n4) Show top 3 of the best student\n5) Edit a student\n6) Exit");
		printf("\nYour choice: ");
		scanf("%d",&c);
		if (c>=1&&c<=6)
		{
			switch (c)
			{
				case 1:
					system("cls");
					outputstudent(a,n);
					printf("\nPress Enter to continue!");
					getch();
					break;
				case 2:
					system("cls");
					findastudent(a,n);
					break;
				case 3:
					system("cls");
					soft(a,n);
					break;
				case 4:
					system("cls");
					showtop3(a,n);
					break;
				case 5: 
					system("cls");
					edit(a,n);
					break;
				case 6:
					system("cls");
					exit(0);
					break;
			}
		}
		else 
		{
			system("cls");
			printf("Please type a number between 1 and 5!");
			printf("\nPress Enter to continue!");
			getch();
		}
	}
}
