#include <stdio.h>
#include <math.h>
int a,b,c;
void nhap() {
	printf("Nhap a: ");
	scanf("%d",&a);
	printf("Nhap b: ");
	scanf("%d",&b);
	printf("Nhap c: ");
	scanf("%d",&c);
}
int tinhdenta(int a,int b,int c){
	int denta=pow(b,2)-4*a*c;
	return denta;
}
int main() {
	nhap();
	printf("%d %d %d",a,b,c);
	tinhdenta(a,b,c);
}
