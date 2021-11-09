#include <stdio.h>
int main(){
	char  dizi[10][10];
	int i,j;
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			dizi[i][j]='*';
		}
	}
	for(i=0;i<10;i++){
		for(j=0;j<i;j++){
			printf("%c",dizi[i][j]);
		}
	
	printf("\n");
}
}
