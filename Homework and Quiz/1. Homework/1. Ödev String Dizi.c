#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void ilkkez(char girilen[], char aranan);
void kackez(char girilen[], char aranan);
void nerede(char girilen[], char aranan);


int main(){
	
	char girilen[20];
	char aranan;
	printf("Lutfen String Kelime Giriniz:");
	gets(girilen);
    printf("Lutfen Stringde Aranacak Harf Giriniz:");
	scanf("%c",&aranan);
	ilkkez(girilen,aranan);
	kackez(girilen,aranan);
	nerede(girilen,aranan);
	
	
}

void ilkkez(char girilen[], char aranan){
   int i=0;
   int sayac=0;
   for(i=0;i<20;i++){
   	if(girilen[i]==aranan){
   		sayac++;
   		break;
	   }
   }
   if(sayac==0){
   	printf("Dizide Aranan Harf Yoktur");
   	return 0;
   }
  
   printf("String Dizide Aranan %c Harfine Ilk Olarak %d . Elemanda Rastlandi\n",aranan,i+1);
   return 0;
}
	
	

void kackez(char girilen[], char aranan){
	int i=0;
	int sayac=0;
	for(i=0;i<20;i++){
		if(girilen[i]==aranan){
			sayac++;
		}
	}
	if(sayac==0){
		return 0;
	}
   printf("String Dizide Aranan %c Harfi %d Kez Tekrar Etmektedir\n",aranan,sayac);
   return 0;
}	

void nerede(char girilen[], char aranan){
	int i,a=0,sayac=0;
	int nerede[20];
    for(i=0;i<20;i++){
    	if(girilen[i]==aranan){
    		sayac++;
    		nerede[a]=i;
    		a++;
		}
	}
	
	if(sayac==0){
		
		return 0;
	}
	printf("String Dizide Aranan %c Harfi String Metinde:",aranan);
	for(i=0;i<a;i++){
		printf("%d  ",nerede[i]+1);
	}
	printf("Numarali Harflerde Bulunmaktadir");
}

	


