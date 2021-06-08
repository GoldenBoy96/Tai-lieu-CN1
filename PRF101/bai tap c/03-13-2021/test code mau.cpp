#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
#include<iostream>
using namespace std;

int main() {
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

	printf("%s",z);
}
