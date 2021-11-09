#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#define enbuyuksatir 10000 
#define enbuyukkar 50 
typedef char* PtrChar; 

   
int karsilastir(const void* str1, const void* str2){ 
    return strcmp((*(PtrChar*) str1), (*(PtrChar*) str2)); 
    
} 
   
int satirlariSirala(const char* asikki){ 
    PtrChar satir[enbuyuksatir]; 
    FILE* dosya = fopen("bsikki.txt", "r"); 
       
    if(!dosya) { 
        printf("Dosya bulunamadi! \n"); 
        exit(0); 
    } 
       
    int i = 0; 
    do{ 
        satir[i] = (PtrChar) malloc(enbuyukkar); 
      } 
    while(fgets(satir[i++], enbuyukkar, dosya)); 
   
    fclose(dosya); 
    qsort(satir, i, sizeof(PtrChar), karsilastir); // quicksort parametre karþýlaþtýrma fonksiyonu 
    dosya = fopen("idyegoresiralanmis.txt", "w"); 
    int adet = i; 
	for(i = 0; i < adet; i++){ 
    	fprintf(dosya, "%s", satir[i]); 
        free(satir[i]); 
    } 
       
    fclose(dosya); 
}
 
int main(int argc, char *argv[]){
	FILE *giris;
giris=fopen("bsikki.txt","w");

srand(time(NULL));	
char sesli[6]="aeiou";
char sessiz[19]="bcdfghjklmnprstvyz";
int seslirand;
int sessizrand;
int kisinumara;
int i,tekrar=0;

while(tekrar<15){
	kisinumara=20+rand()%80;
	fprintf(giris,"%d ",kisinumara);
	for(i=0;i<6;i++){
		if(i%2==0){
			seslirand=rand()%5;
			fprintf(giris,"%c",sesli[seslirand]);
		}
		else{
			sessizrand=rand()%18;
			fprintf(giris,"%c",sessiz[sessizrand]);
		}
		
	}
	fprintf(giris,"\n");
	tekrar++;
}
fclose(giris);
printf("IDLER VE ISIMLER OLUSTURULDU! VE TXT DOSYASINA KAYDEDILDI\n");
	
	
	
	satirlariSirala(argv[1]); 
    printf("ID'ye Gore Siralama Yapilmis ve Yeni Metin Belgesine Yazilmistir.\n");
    printf("Siralanmis Metinler Yeni Metin Belgesinden Okunuyor: \n \n");
    FILE *oku=fopen("idyegoresiralanmis.txt","r");
    char dizioku[15][8];
    int idoku[15];
    i=0;
    for(i=0;i<15;i++){
    	fscanf(oku,"%d %s \n",&idoku[i],&dizioku[i]);
    	printf(" %d %s \n",idoku[i],dizioku[i]);
    
	
    	
	}
    
    
    return 0; 
}
