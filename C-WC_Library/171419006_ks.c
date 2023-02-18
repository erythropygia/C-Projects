#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

int bilgi_say(char data_path[], int *satir_sum,int *kelime_sum, int *harf_sum){
FILE* fp;
int i;
char satir;
char kelime[10000];
int counter_satir=0;
int counter_kelime=0;
int counter_karakter=-1;


if(1){
	if((fp=fopen(data_path,"r")) == NULL){ //dosya açılıyor
		printf("Dosya Bulunamadi\n");
		return 1;	
	}
	
	while(!feof(fp)){
	// Satırı bul
		satir=getc(fp);
		if(satir=='\n'){
			counter_satir++;
		}
	// Kelimeyi bul
		
		if(satir == ' ' || satir =='\n'){
			counter_kelime++;
		}
		
		
	// Karakteri bul
		if(satir != ' ' && satir !='\n'){
			counter_karakter++;

		}
	}
	*satir_sum=counter_satir;
	*kelime_sum=counter_kelime;
	*harf_sum=counter_karakter;
	printf("Dosya Adi:%s . Satir = %d , Kelime = %d , Karakter = %d\n",data_path, counter_satir,counter_kelime,counter_karakter);
	fclose(fp);
	
	
}


}

int random_olustur(char data_path[]){
FILE* fp;
int i,j,k;
char text[]="A";
srand(time(NULL));
int counter_satir=rand() % 100 ;
int counter_karakter=rand() % 100;
int random=rand()%35;
int satir_sum,kelime_sum,harf_sum;

if((fp=fopen(data_path,"w+")) == NULL){ //dosya açılıyor
		printf("Dosya Bulunamadi\n");
		return 1;	
		}

for(i=0; i<counter_satir;i++){
	
		for(k=0;k<counter_karakter;k++){
				
				fprintf(fp,"%s",text);
				if(k % random ==0){
					
					fprintf(fp,"%s"," ");
				}
			}
		
		fprintf(fp,"%s","\n");
	

}
	fclose(fp);
	bilgi_say(data_path,&satir_sum,&kelime_sum,&harf_sum);
		
}



// satır kelime karakter 
int main (int argc, char * argv[])
{	
	int satir_sum,kelime_sum,harf_sum;
	char *randomize ="random.txt";
	char *data_path = argv[1];	
	char *data_path_1 = argv[2];
	int topla[2][3];
		
	if(argc==2){ //Kullanıcıdan alınan parametre kontrol ediliyor
		if(strcmp(data_path,randomize)!=0){
			bilgi_say(data_path,&satir_sum,&kelime_sum,&harf_sum);
			
		}
		else{
			random_olustur(data_path);
		}
		
	}
	
	else if(argc==3){ //Kullanıcıdan alınan parametre kontrol ediliyor
		
		bilgi_say(data_path,&satir_sum,&kelime_sum,&harf_sum);
		topla[0][0]=satir_sum;
		topla[0][1]=kelime_sum;
		topla[0][2]=harf_sum;
		bilgi_say(data_path_1,&satir_sum,&kelime_sum,&harf_sum);
		topla[1][0]=satir_sum;
		topla[1][1]=kelime_sum;
		topla[1][2]=harf_sum;
		
		printf("TOPLAMLARI: Satir:%d , Kelime:%d, Karakter:%d\n",topla[0][0]+topla[1][0],topla[0][1]+topla[1][1],topla[0][2]+topla[1][2]);
	}
	
	

}

















