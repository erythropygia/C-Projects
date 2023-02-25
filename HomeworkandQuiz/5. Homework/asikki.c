#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



int main(){
FILE *giris;
giris=fopen("asikki.txt","w");

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
printf("IDLER VE ISIMLER OLUSTURULDU!");
exit(0);
}

