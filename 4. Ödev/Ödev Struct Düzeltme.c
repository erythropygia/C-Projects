#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void kelimeislemleri();
int benzerlikhesapla(char girilenkelime[10]);
void chardizisiatama();
static int indis=1;
static int indis1=2;
static int uzunluk=0;

struct kelimehesap{	
    char liste[15][15];
    char kont_list[15][15];
	int sesli;
	int sessiz;
	int uzunluk;
	int benzerlik;
}kelime;


int main(){
	
	chardizisiatama();
	kelimeislemleri();
	int i,sonuc,tekrar,enbuyuk=0;
	int max1,max2;
	int max2i;
	int enbuyuk2[15];
    char girilenkelime[10];
	a:
	for(i=0;i<15;i++){
		kelime.benzerlik=benzerlikhesapla(kelime.kont_list[i]);
		    enbuyuk2[i]=kelime.benzerlik;
		    if(enbuyuk<kelime.benzerlik){
		    enbuyuk=kelime.benzerlik;
			sonuc=i;
		    }
		    
		    if(indis1==16){
		    	
		    	max1=enbuyuk2[0];
		    	max2=enbuyuk2[1];
		    	for(i=1;i<15;i++){
		    		if(enbuyuk2[i]>max1){
		    			max2=max1;
		    			max1=enbuyuk2[i];
					}
					else if(enbuyuk2[i]>max2){
						max2=enbuyuk2[i];
						max2i=i;
					}
				}
				
				
		    		if(indis==sonuc+1){
					printf("////**** %d. Indise En Fazla Benzesme %s Kelimesi, Kelime %d. Indistedir ****//// \n",indis,kelime.liste[max2i],max2i+1);
				}
				else{
			
				   printf("////**** %d. Indise En Fazla Benzesme %s Kelimesi, Kelime %d. Indistedir ****//// \n",indis,kelime.liste[sonuc],sonuc+1);	
			}
			
	   	    sonuc=0;
	   	    enbuyuk=0;
			i=0;
			uzunluk++;
			indis++;
			indis1=1;
			tekrar++;
			if(tekrar!=15){
				goto a;
			}
			else{
				break;
			}
			
		}
		}
		return 0;
	
	
}


int benzerlikhesapla(char girilenkelime[10]){
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
	
	
	
	if(indis1 !=indis ){
	toplampuan=kosul3+kosul2+kosul1;
	printf("%d.Indisin %d. Indise Benzerlik Puani: %d\n",indis,indis1,toplampuan);	
	}
	
    indis1++;
    
    
	
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
	memcpy(kelime.kont_list,kelime.liste,sizeof(kelime.kont_list));
	printf("********************\n");	
}


