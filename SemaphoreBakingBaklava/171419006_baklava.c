#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<semaphore.h>

//ŞEKER:G, UN:U, FISTIK:F, SÜT:S

//thread sayısı tanımlanıyor
#define NUM_THREADS 7
pthread_t threads[NUM_THREADS];
char satir[2];
int satir_counter=0;
int control_counter=0;

// 0=ŞEKER, 1=UN , 2=FISTIK, 3=SÜT
int dukkan1[4]={0,0,10,10}; //FISTIK SÜT SINIRSIZ
int dukkan2[4]={0,10,0,10}; //UN SÜT SINIRSIZ
int dukkan3[4]={0,10,10,0}; //UN FISTIK SINIRSIZ 
int dukkan4[4]={10,0,0,10}; //ŞEKER SÜT SINIRSIZ
int dukkan5[4]={10,0,10,0}; //ŞEKER FISTIK SINIRSIZ
int dukkan6[4]={10,10,0,0}; //ŞEKER UN SINIRSIZ

//SEMAPHORE
sem_t sem;

void *thread_cagir(void *threadid);
void *dukkani_ac(void *threadid);
void *sevkiyata_basla(void *threadid);
void *malzeme_belirle(void *threadid);
void *malzeme_dagit(void *threadid);
void *baklava_yap(void *threadid);

//thread_cagir
void *thread_cagir(void *thread_id){
   sem_wait(&sem); 
   pthread_create(&threads[(intptr_t) thread_id],NULL, malzeme_dagit, (void *) (intptr_t) thread_id);
   pthread_join(threads[(intptr_t) thread_id],NULL);  
   sem_destroy(&sem);
}
 
//DÜKKANLAR AÇILIYOR 
void *dukkani_ac(void *threadid) {
   sem_post(&sem);
   while(1){
   long tid;
   tid = (long)threadid;
   printf("Dükkan(Thread ID):%ld Açıldı Malzeme Bekliyor\n", tid);
   sleep(1);
   pthread_exit(NULL);
   sem_destroy(&sem);
   
   }
}

//SEVKİYATÇI İŞE BAŞLIYOR
void *sevkiyata_basla(void *threadid){
   long tid;
   tid = (long)threadid;
   if(control_counter==0){
   	printf("Sevkiyat(Thread ID):%ld Başladı\n",tid);
   	control_counter++;
   }
   else{
        printf("Malzeme Bitti. Tekrar Sevkiyat(Thread ID):%ld Başladı\n",tid);
   }
   
   sleep(1); 
   
   pthread_create(&threads[6],NULL, malzeme_belirle, (void *) (intptr_t) 6);
   pthread_join(threads[6],NULL);  
   
   
   pthread_create(&threads[6],NULL, malzeme_dagit, (void *) (intptr_t) 6);
   pthread_join(threads[6],NULL);
   
   }
//SEVKİYATÇI MALZEME BELİRLİYOR 
void *malzeme_belirle(void *threadid){
  
   FILE* fp;
   int sn=0;
   int i=0;
   srand(time(NULL));
   satir_counter=rand() % 6 + 1;
   //printf("Satir: %d\n", satir_counter);
   if((fp=fopen("malzeme.txt","r")) == NULL){ //dosya açılıyor
		printf("malzeme.txt Dosya Bulunamadi\n");
		return 0;	
	}
   while(!feof(fp)){
      if(satir_counter==sn){
      	  break;
      }
      fgets(satir,5, fp);
      sn++;
   }
   
}
//SEVKİYATÇI DAĞITIMA ÇIKIYOR
void *malzeme_dagit(void *threadid){
   long tid;
   tid = (long)threadid;
   
   printf("               Dağıtıma Çıkan Malzeme:%s               \n",satir);
   
   
   
   if(satir[0]=='G' || satir[1]=='U'){
     
       if(satir[0]=='G'){
          dukkan1[0]=1;
          printf("Dükkan(Thread ID):0 Şeker Malzemesini Aldı\n");
          sleep(1);
       }
       if(satir[1]=='U'){
          dukkan1[1]=1;
          printf("Dükkan(Thread ID):0 Un Malzemesini Aldı\n");
          sleep(1);
       }
     
       if(dukkan1[0]==1 && dukkan1[1]==1){
          pthread_create(&threads[0], NULL,baklava_yap,(void *) (intptr_t) 0);
     	  pthread_join(threads[0],NULL);
     	  dukkan1[0]=0;
     	  dukkan1[1]=0;
     	  
       }
       
       
   }
   
   if(satir[0]=='G' || satir[1]=='F'){
       if(satir[0]=='G'){
          dukkan2[0]=1;
          printf("Dükkan(Thread ID):1 Şeker Malzemesini Aldı\n");
          sleep(1);
       }
       if(satir[1]=='F'){
          dukkan2[2]=1;
          printf("Dükkan(Thread ID):1 Fıstık Malzemesini Aldı\n");
          sleep(1);
       }
     
       if(dukkan2[0]==1 && dukkan2[2]==1){
          pthread_create(&threads[1], NULL,baklava_yap,(void *) (intptr_t) 1);
     	  pthread_join(threads[1],NULL);
     	  dukkan2[0]=0;
     	  dukkan2[2]=0;
       }
   }
   
   if(satir[0]=='G' || satir[1]=='S'){
       if(satir[0]=='G'){
          dukkan3[0]=1;
          printf("Dükkan(Thread ID):2 Şeker Malzemesini Aldı\n");
          sleep(1);
       }
       if(satir[1]=='S'){
          dukkan3[3]=1;
          printf("Dükkan(Thread ID):2 Süt Malzemesini Aldı\n");
          sleep(1);
       }
     
       if(dukkan3[0]==1 && dukkan3[3]==1){
          pthread_create(&threads[2], NULL,baklava_yap,(void *) (intptr_t) 2);
     	  pthread_join(threads[2],NULL);
     	  dukkan3[0]=0;
     	  dukkan3[3]=0;
       }
   }
   
   if(satir[0]=='U' || satir[1]=='F'){
       if(satir[0]=='U'){
          dukkan4[1]=1;
          printf("Dükkan(Thread ID):3 Un Malzemesini Aldı\n");
          sleep(1);
       }
       if(satir[1]=='F'){
          dukkan4[2]=1;
          printf("Dükkan(Thread ID):3 Fıstık Malzemesini Aldı\n");
          sleep(1);
       }
     
       if(dukkan4[1]==1 && dukkan4[2]==1){
          pthread_create(&threads[3], NULL,baklava_yap,(void *) (intptr_t) 3);
     	  pthread_join(threads[3],NULL);
     	  dukkan4[1]=0;
     	  dukkan4[2]=0;
       }
   }
   
   if(satir[0]=='U' || satir[1]=='S'){
       if(satir[0]=='U'){
          dukkan5[1]=1;
          printf("Dükkan(Thread ID):4 Un Malzemesini Aldı\n");
          sleep(1);
       }
       if(satir[1]=='S'){
          dukkan5[3]=1;
          printf("Dükkan(Thread ID):4 Süt Malzemesini Aldı\n");
          sleep(1);
       }
     
       if(dukkan5[1]==1 && dukkan5[3]==1){
          pthread_create(&threads[4], NULL,baklava_yap,(void *) (intptr_t) 4);
     	  pthread_join(threads[4],NULL);
     	  dukkan5[1]=0;
     	  dukkan5[3]=0;
       }
   }
   
   if(satir[0]=='F' || satir[1]=='S'){
       if(satir[0]=='F'){
          dukkan6[2]=1;
          printf("Dükkan(Thread ID):5 Fıstık Malzemesini Aldı\n");
          sleep(1);
       }
       if(satir[1]=='S'){
          dukkan6[3]=1;
          printf("Dükkan(Thread ID):5 Süt Malzemesini Aldı\n");
          sleep(1);
       }
     
       if(dukkan6[2]==1 && dukkan6[3]==1){
          pthread_create(&threads[5], NULL,baklava_yap,(void *) (intptr_t) 5);
     	  pthread_join(threads[5],NULL);
     	  dukkan6[2]=0;
     	  dukkan6[3]=0;
       }
   }
   //sleep(3);
   pthread_create(&threads[6], NULL,sevkiyata_basla,(void *) (intptr_t) 6);
   pthread_join(threads[6],NULL);
   
   
    
    
}

void *baklava_yap(void *threadid){
  sem_post(&sem);
  long tid;
  tid = (long)threadid;
  printf("Dükkan(Thread ID):%ld Baklava Yapıyor.\n", tid);
  sleep(1);
  printf("Sevkiyatçı, Dükkan(Thread ID):%ld'den Baklavayı Aldı.\n",tid);
  sleep(1);
  printf("Sevkiyatçı, Baklavayı Satmaya Götürüyor.\n");
  sleep(1);
  printf("Sevkiyatçı, Baklavayı Sattı. Dağıtıma Devam Ediyor.\n");
  printf("--------------------------------------------------------\n");
  
  sleep(3);
  sem_destroy(&sem);
  
}


int main () {
   int rc;
   int i;
   sem_init(&sem,0,1);
   
   for(i = 0; i < NUM_THREADS; i++) {
      if(i==6){
      	rc = pthread_create(&threads[i], NULL,sevkiyata_basla,(void *) (intptr_t) i);
      	printf("--------------------------------------------------------\n");
      }
      else{
        rc = pthread_create(&threads[i], NULL, dukkani_ac,(void *) (intptr_t) i);
        printf("--------------------------------------------------------\n");
      }  
      pthread_join(threads[i],NULL);
   sem_destroy(&sem);
      
      //thread oluşturulamazsa
      if (rc) {
         printf("Thread Oluşturulamadı, %d\n", rc);
         exit(-1);
      }
   }
      
   pthread_exit(NULL);
}
