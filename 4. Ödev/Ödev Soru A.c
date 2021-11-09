#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void diziyihesapla();
static int kontrol=0;

struct sayihesap{
    char basamak1[9][9];
    char basamak2[9][9];
    char basamak3[9][9];
    int girilen;
    
	
}sayi;

void diziyihesapla(){
	char basamak10[9][9]={"yuz","ikiyuz","ucyuz","dortyuz","besyuz","altiyuz","yediyuz","sekizyuz","dokuzyuz"};
	char basamak11[9][9]={"on","yirmi","otuz","kirk","elli","altmis","yetmis","seksen","doksan"};
	char basamak12[9][9]={"bir","iki","uc","dort","bes","alti","yedi","sekiz","dokuz"};
	
	int i,j;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
		sayi.basamak1[i][j]=basamak10[i][j];
		sayi.basamak2[i][j]=basamak11[i][j];
		sayi.basamak3[i][j]=basamak12[i][j];
		}
	
		
			}
}
	

int main(){
    diziyihesapla();
    don:
	printf("Lutfen 6 Basamakli Bir Sayi Giriniz=");
	scanf("%d",&sayi.girilen);
	int gecici = sayi.girilen;
	int basamakdeger=0;
	int basamak[6];
	int kalan,i;
    

    while ( gecici > 0 ){
        
        kalan = gecici % 10;
        gecici /= 10;    
        basamak[basamakdeger]=kalan;
        basamakdeger++;
        
    }
	if(basamakdeger<6){
		printf("Hatali Giris!!! \n");
		goto don;
		
	}
    
    printf("%s %s %s bin %s %s %s",sayi.basamak1[basamak[5]-1],sayi.basamak2[basamak[4]-1],sayi.basamak3[basamak[3]-1],sayi.basamak1[basamak[2]-1],sayi.basamak2[basamak[1]-1],sayi.basamak3[basamak[0]-1]);
	
	
	
	
}
