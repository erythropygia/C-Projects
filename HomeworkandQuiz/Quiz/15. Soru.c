#include <stdio.h>


void main(){
	char dizi[10][10];
	int i,j,k;
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			dizi[i][j]='*';
		}
	}
	

for(i=0;i<10;i++){
	for(j=0;j<10;j++){
		if(i<8){
			j=j+4;
			printf("%c",dizi[i][j]);
		}
		else{
			printf("%c",dizi[i][j]);
		}
		
	}
	printf("\n");

}
}

