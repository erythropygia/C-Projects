#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



int main(){
FILE *giris;
giris=fopen("csikki.txt","w");

srand(time(NULL));	
char sesli[6]="aeiou";
char sessiz[19]="bcdfghjklmnprstvyz";
int seslirand;
int sessizrand;
int kisinumara;
int i,tekrar=0;

while(tekrar<15){
	
	
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
	
	kisinumara=20+rand()%80;
	fprintf(giris,"%d",kisinumara);
	
	fprintf(giris,"\n");
	tekrar++;
}
fclose(giris);
     
     FILE *sirala;
     sirala=fopen("csikki.txt","r");
     
     

    int ametin=15;
    char Kelimeler[ametin][100], t[100];
    int x, y;
    printf("\nMetindeki Kelimeler(Metin Sonu Numaralar Id'dir): \n"); 
    for (x=0; x<ametin; x++)
    {
        fscanf(sirala,"%s",&Kelimeler[x]);
        fprintf(sirala,"\n");
    }
    for (x=0; x<ametin; x++)
    {
        printf("%s \n",&Kelimeler[x]);
    }
    
    for (x = 1; x < ametin; x++)
    {
        for (y = 1; y < ametin; y++)
        {
            if (strcmp(Kelimeler[y - 1], Kelimeler[y]) > 0)
            {
                strcpy(t, Kelimeler[y - 1]);
                strcpy(Kelimeler[y - 1], Kelimeler[y]);
                strcpy(Kelimeler[y], t);
            }
        }
    }
    printf("\n---------------------------------------------------\n");
    printf("\nMetindeki Kelimeler Alfabetik Olarak Siralandi\n ");
    printf("\n---------------------------------------------------\n");
    fclose(sirala);
    
    
    FILE *yazdir;
    printf("Duzenlenmis Hal Yeni Dosyaya Yazdirildi \n");
    yazdir=fopen("alfabetikduzenle.txt","w");
    for (x = 0; x < ametin; x++){
    	fprintf(yazdir,"\n%s", Kelimeler[x]);
    	
	}
	fclose(yazdir);
	
	FILE *sonoku;
	char Kelimeler1[ametin][100];
	sonoku=fopen("alfabetikduzenle.txt","r");
	printf("Duzenlenmis Hali Kaydedilen txt Dosyasindan Okunuyor...\n\n");
	
	for(i=0;i<15;i++){
		fscanf(sonoku,"%s",&Kelimeler1[i]);
		
	}
		for(i=0;i<15;i++){
		printf("%s\n",Kelimeler1[i]);

		
	}
	fclose(sonoku);
	        
    return 0;
    
}

