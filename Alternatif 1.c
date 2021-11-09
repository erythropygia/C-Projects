#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int dizidoldur(int min, int max, int *ptr, int sutun, int satir);
int dizihesapla(int *ptr, int sutun, int satir);
int satirtopla(int *ptr, int satir, int sutun,int satirkontrol);

int main(){
	int satir,sutun,satirkontrol;
	srand(time(NULL));
	printf("Lutfen Satir Sayisini Giriniz=");
	scanf("%d",&satir);
	printf("Lutfen Sutun Sayisini Giriniz=");
	scanf("%d",&sutun);
	int *ptr=calloc(satir*sutun,sizeof(int)); // dizimi tuttum. calloc ile tuttuðum için adresileri 0 ladý
	int min,max;
	kontrol:
	printf("Lutfen Minimum Degeri Giriniz =");
	scanf("%d",&min);
	printf("Lutfen Maksimum Degeri Giriniz =");
	scanf("%d",&max);
	if(min>max){
		printf("Hatali giris!! Lutfen Tekrar Deneyin \n");
		goto kontrol;
	}
	dizidoldur(min,max,ptr,sutun,satir);
	printf("\n\nDizinin en buyuk ikinci elemani = %d\n ",dizihesapla(ptr,sutun,satir));
	printf("\n\n Lutfen Toplamak Istediginiz Satiri Giriniz= ");
	scanf("%d",&satirkontrol);
	printf("Girilen Satirin Toplami= %d",satirtopla(ptr,satir,sutun,satirkontrol));
	free(ptr);	
}

int dizidoldur(int min,int max, int *ptr, int sutun, int satir){
	srand(time(0));
    int i;
    int kontrol;
    
    if(max-min<satir+sutun){
    	printf("Bu Aralikta Birbirinden Farklý Random Uretmek Imkansizdir");
    	return 0;
	}
       for(i=0;i<satir*sutun;i++){
		ptr[i]=rand()%(max-min)+min;
		for (kontrol=0;kontrol<i;kontrol++)
                {
                    if (ptr[kontrol]==ptr[i])
                    {
                        i--;
                        break;
                    }
                    
                }
            }
	
	
	printf("Dizi: \n");
	printf("**********");
	
	for(i=0;i<satir*sutun;i++){
		if(i%sutun==0){
			printf("\n");
		}
		printf("%d ",ptr[i]);
	}
}
			


int dizihesapla(int *ptr, int sutun, int satir){
	int *max1=calloc(1,sizeof(int)); // 2. buyugu bulmamý saðlayacak dizileri tanýmlýyorum // static tanýmladým çünkü baþka bir fonksiyonda tekrar kullanmam gerek
	int *max2=calloc(1,sizeof(int));
	int i,j;
	max1[0]=ptr[0];
	max2[0]=ptr[1];
	 for (i=1;i<satir*sutun;i++) 
         if (ptr[i] > max1[0]) {
            max2[0]= max1[0];
            max1[0] = ptr[i];
         }
         else if (ptr[i] > max2[0]){
         	 max2[0] = ptr[i];
        }
	
    return(max2[0]);
    free(max1);
    free(max2);
 
   }
   
   
int satirtopla(int *ptr, int satir, int sutun, int satirkontrol){
	int i;
	kontrol1:
	if(satirkontrol>satir){
		printf("\nHatali Giris Lutfen Tekrar Deneyin!");
		goto kontrol1;
	}
	
	int toplam=0;
	satirkontrol=satirkontrol-1; // dizi hesaplamasý için azalttým yoksa dizi hesaplamasýnda problem yaþatýyor
	for(i=0;i<sutun;i++){
			toplam=toplam+*(ptr + satirkontrol*sutun + i);
		}
	   
	return(toplam);

}


	









