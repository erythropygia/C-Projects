#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void diziyihesapla();
static int kontrol=0;

struct sayihesap{
    char basamak1[9][9];
    char basamak2[9][9];
    char basamak3[9][9];
    char basamak4[9][9];
   
    
    int girilen;
    
	
}sayi;

void diziyihesapla(){

	char basamak9[9][9]={"bin","ikibin","ucbin","dortbin","besbin","altibin","yedibin","sekizbin","dokuzbin"};
	char basamak10[9][9]={"yuz","ikiyuz","ucyuz","dortyuz","besyuz","altiyuz","yediyuz","sekizyuz","dokuzyuz"};
	char basamak11[9][9]={"on","yirmi","otuz","kirk","elli","altmis","yetmis","seksen","doksan"};
	char basamak12[9][9]={"bir","iki","uc","dort","bes","alti","yedi","sekiz","dokuz"};
	
	
	int i,j;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
		
		sayi.basamak1[i][j]=basamak10[i][j];
		sayi.basamak2[i][j]=basamak11[i][j];
		sayi.basamak3[i][j]=basamak12[i][j];
		sayi.basamak4[i][j]=basamak9[i][j];
		
		}
	
		
			}
}
	

int main(){
    diziyihesapla();
    don:
	printf("Lutfen en fazla 6 Basamakli Bir Sayi Giriniz=");
	scanf("%d",&sayi.girilen);
	int gecici = sayi.girilen;
	int gecici2=sayi.girilen;
	int basamakdeger=0;
	int basamak[6];
	int kalan,i,kacbasamak;
    

    while ( gecici > 0 ){
        
        kalan = gecici % 10;
        gecici /= 10;    
        basamak[basamakdeger]=kalan;
        basamakdeger++;
        kacbasamak++;
        
    }
    
    if(basamakdeger>6){
    	printf("Hatali Giris!!! \n");
    	goto don;
	}
	
    if(kacbasamak==1){
    	printf("%s",sayi.basamak3[basamak[0]-1]);
    	return 0;
	}
	if(kacbasamak==2 && gecici2%10!=0){
		printf("%s %s",sayi.basamak2[basamak[1]-1],sayi.basamak3[basamak[0]-1]);
		return 0;
	}
	else{
		printf("%s %s",sayi.basamak2[basamak[1]-1]);
		return 0;
	}
	
	if(kacbasamak==3){
		printf("%s %s %s",sayi.basamak1[basamak[2]-1],sayi.basamak2[basamak[1]-1],sayi.basamak3[basamak[0]-1]);
	}
	
	
	
	if(kacbasamak==4){
		printf("%s %s %s %s",sayi.basamak4[basamak[3]-1],sayi.basamak1[basamak[2]-1],sayi.basamak2[basamak[1]-1],sayi.basamak3[basamak[0]-1]);
	}
	if(kacbasamak==5){
		printf("%s %s bin %s %s %s",sayi.basamak2[basamak[4]-1],sayi.basamak3[basamak[3]-1],sayi.basamak1[basamak[2]-1],sayi.basamak2[basamak[1]-1],sayi.basamak3[basamak[0]-1]);
	}
	if(kacbasamak==6){
		printf("%s %s %s bin %s %s %s",sayi.basamak1[basamak[5]-1],sayi.basamak2[basamak[4]-1],sayi.basamak3[basamak[3]-1],sayi.basamak1[basamak[2]-1],sayi.basamak2[basamak[1]-1],sayi.basamak3[basamak[0]-1]);	
	}
    
    
    
	
	
	
	
}
