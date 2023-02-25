#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void kelimeislemleri();
int benzerlikhesapla(char girilenkelime[10],int uzunluk);
void chardizisiatama();
static int indis=1;

struct kelimehesap{	
    char liste[15][15];
	int sesli;
	int sessiz;
	int uzunluk;
	int benzerlik;
}kelime;


int main(){
	
	chardizisiatama();
	kelimeislemleri();
	int i,sonuc,enbuyuk=0;
    char girilenkelime[10];
	printf("Dizideki Stringlerle Karsilastirma Icin Kelime Giriniz:");
	scanf("%s",&girilenkelime);
	for(i=0;i<15;i++){
		kelime.benzerlik=benzerlikhesapla(girilenkelime, i);
		if(enbuyuk<kelime.benzerlik){
			enbuyuk=kelime.benzerlik;
			sonuc=i;	
		}
	}
	printf("En Fazla Benzesme %s Kelimesi, Kelime %d. Indistedir \n ",kelime.liste[sonuc],sonuc+1);
	return 0;
}


int benzerlikhesapla(char girilenkelime[10],int uzunluk){
	int kosul3=0,kosul2=0,kosul1=0,toplampuan=0;
	
	int i,j;
	for (i=0; i<15; i++){
		if(kelime.liste[uzunluk][i]=='\0'){
			break;
		}
	}
	int uzunluk1=i;	
	for(i=0; i<15;i++){
		if(girilenkelime[i]=='\0'){
			break;
		}
	}
	int uzunluk2=i;
	
	for (i=0; i<uzunluk1; i++){
		for(j=0; j<uzunluk2;j++){
			if (kelime.liste[uzunluk][i]==girilenkelime[j] && i==j){
				kosul3+=3;
			}
		}
	}
	
	for (i=0; i<uzunluk1; i++){
		for(j=0; j<uzunluk2; j++){
			if (kelime.liste[uzunluk][i]==girilenkelime[j] && (i==j-1 || i==j+1)){
				kosul2+=2;
			}
		}
	}
	
	for(i=0; i<uzunluk1; i++){
		for(j=0; j<uzunluk2; j++){
			
			if (kelime.liste[uzunluk][i]==girilenkelime[j] && (i==j-1 || i==j+1)){
				continue;			
			}
			else if (kelime.liste[uzunluk][i]==girilenkelime[j] && i==j){
				continue;
			}
			if (kelime.liste[uzunluk][i]==girilenkelime[j]){
				kosul1++;
			}
		
		}	
	}
	
	toplampuan=kosul3+kosul2+kosul1;
	
	printf("%d.Indisin Benzerlik Puani: %d\n",indis,toplampuan);
    indis++;
	return toplampuan;
}
	
void kelimeislemleri(){
	
	int i,j;
	
	 for(i=0;i<15;i++){
    
    		   printf("%d - %s \n",i+1,kelime.liste[i]);
    		   
			   
			
		}
		printf("********************\n");
	
    
    for(i=0;i<15;i++){
    	for(j=0;j<15;j++){
    		if(kelime.liste[i][j]=='a' || kelime.liste[i][j]=='e'|| kelime.liste[i][j]=='ý'|| kelime.liste[i][j]=='i'|| kelime.liste[i][j]=='u'|| kelime.liste[i][j]=='ü'|| kelime.liste[i][j]=='o'|| kelime.liste[i][j]=='ö'){
    			kelime.sesli++;
			}
			
		}
		kelime.uzunluk=strlen(kelime.liste[i]);
		kelime.sessiz=kelime.uzunluk-kelime.sesli;
		printf("%d. dizi kelimesinin uzunlugu %d ve dizide %d tane sesli harf, %d tane sessiz harf vardir.\n",i+1,kelime.uzunluk,kelime.sesli,kelime.sessiz);
		kelime.sessiz=0;
		kelime.sesli=0;
	}
	printf("********************\n");
	
	
}

void chardizisiatama(){
	int sayac=0, kontrol=0;
	for(sayac=0;sayac<15;sayac++){
	
			printf("%d. Dizi Elemani Icin En fazla 15 Kelimeden Olusan String Giriniz:",sayac+1);
			scanf("%s",&kelime.liste[sayac]);
		
		
	}

	printf("********************\n");	
}


