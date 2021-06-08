#include <stdio.h>

int nhapmang() {
	int n;
	printf("Nhap so phan tu trong mang: ");
	scanf("%d",&n);
	return n;
}

void inmang(int a[], int size) {
	for (int i=1;i<=size;i++) {
		printf("%d ", a[i]);
	}
}



void sapxepnoibot (int a[],int n) {
	bool doicho=false;
	int t;
	for (int i=1;i<=n-1;i++) {
		doicho=false;
		for (int j=n-1;j>=i;j--) {
			if (a[j]>a[j+1]) {
				doicho=true;
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}		}
		if (doicho=false) {
		break;
	}
	}
	
}

int timkiemnhiphan(int a[], int n, int x) {
	int r=n,l=1;
	while (r>l) {
		int mid = l + (r-l)/2;
		if (a[mid]==x) {
			return mid;
		}
		if (a[mid]>x) {
			r=mid-1;
		}
		if (a[mid]<x) {
			l=mid+1;
		}
	}
	return -1;
}

int main() {
	int x,y,z,a[100];
	x=nhapmang();
	for (int i=1;i<=x;i++) {
		printf("Nhap so thu %d: ",i);
		scanf("%d",&a[i]);
	}
	printf("%d",sizeof(a)/sizeof(a[0]));
	printf("\nMang ban vua nhap:    ");
	inmang(a,x);
	sapxepnoibot(a,x);
	printf("\nMang sau khi sap xep: ");
	inmang(a,x);
	printf("\nNhap phan tu can tim: ");
	scanf("%d",&y);
	z=timkiemnhiphan(a,x,y);
	printf("\nSo can tim nam o vi tri thu %d.",z);
}
