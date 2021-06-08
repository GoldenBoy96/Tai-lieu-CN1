#include <stdio.h>
char file[50]="D:\\myfile.txt";
void samename(em v[], int n){
    readfile(v, n);
	int kt[100];
	int count =0;
	int dem;
	kt[0]=-1;
	printf ("\nYour file data: \n");
	showfile ();
	printf ("\n\nAll the ID of employee who have the same name: ");
	for ( int i=0; i<n-1; i++){
		dem=0;
		for (int k1=0; k1<= count; k1++){
			if (kt[k1]==i){
				dem ++;
			}
		}
		if (dem ==0){

		for ( int j=i; j<n; j++){

			if (strcmp(v[i].Name, v[j].Name)== 0){
				kt[count] = j;
				count++;
				dem ++;
			}
		    
		}
		if ( dem >1){
		    for (int k=count - dem; k<= count-1 ; k++){
		    	printf ("%d", v[kt[k]].ID);
		    	if (k< count-1 ){
		    		printf (",");
				}
				else printf ("; ");
			}	
		}
	}
	}
	edit();
}
int main() {  
	samename
}
