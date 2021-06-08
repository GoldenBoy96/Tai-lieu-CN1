#include<stdio.h>
#include<conio.h>
#include<windows.h>
int main() {
	while (true) {

if(kbhit())
{
	char c = getch();
	printf("\nNguoi dung dang nhan vao phim %d", c);
}
}}
