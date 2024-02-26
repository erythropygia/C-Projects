#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<semaphore.h>

#define NUM_THREADS 7

pthread_t threads[NUM_THREADS];
char ingredient[2];
int row_counter = 0;
int control_counter = 0;

int shop1[4] = {0, 0, 10, 10}; // FISTIK SÜT UNLIMITED
int shop2[4] = {0, 10, 0, 10}; // UN SÜT UNLIMITED
int shop3[4] = {0, 10, 10, 0}; // UN FISTIK UNLIMITED 
int shop4[4] = {10, 0, 0, 10}; // ŞEKER SÜT UNLIMITED
int shop5[4] = {10, 0, 10, 0}; // ŞEKER FISTIK UNLIMITED
int shop6[4] = {10, 10, 0, 0}; // ŞEKER UN UNLIMITED

sem_t sem;

void *invoke_thread(void *threadid);
void *open_shop(void *threadid);
void *start_shipping(void *threadid);
void *determine_ingredient(void *threadid);
void *distribute_ingredient(void *threadid);
void *make_baklava(void *threadid);

void *invoke_thread(void *thread_id) {
    sem_wait(&sem);
    pthread_create(&threads[(intptr_t) thread_id], NULL, distribute_ingredient, (void *) (intptr_t) thread_id);
    pthread_join(threads[(intptr_t) thread_id], NULL);
    sem_destroy(&sem);
}

void *open_shop(void *threadid) {
    sem_post(&sem);
    while (1) {
        long tid;
        tid = (long)threadid;
        printf("Shop(Thread ID):%ld Opened, Waiting for Ingredients\n", tid);
        sleep(1);
        pthread_exit(NULL);
        sem_destroy(&sem);
    }
}

void *start_shipping(void *threadid) {
    long tid;
    tid = (long)threadid;
    if (control_counter == 0) {
        printf("Shipping(Thread ID):%ld Started\n", tid);
        control_counter++;
    } else {
        printf("Ingredients Finished. Shipping(Thread ID):%ld Started Again\n", tid);
    }

    sleep(1);

    pthread_create(&threads[6], NULL, determine_ingredient, (void *) (intptr_t) 6);
    pthread_join(threads[6], NULL);

    pthread_create(&threads[6], NULL, distribute_ingredient, (void *) (intptr_t) 6);
    pthread_join(threads[6], NULL);
}

void *determine_ingredient(void *threadid) {
    FILE* fp;
    int seconds = 0;
    int i = 0;
    srand(time(NULL));
    row_counter = rand() % 6 + 1;

    if ((fp = fopen("ingredients.txt", "r")) == NULL) {
        printf("ingredients.txt Not Found\n");
        return 0;	
    }

    while (!feof(fp)) {
        if (row_counter == seconds) {
            break;
        }
        fgets(ingredient, 5, fp);
        seconds++;
    }
}

void *distribute_ingredient(void *threadid) {
    long tid;
    tid = (long)threadid;

    printf("               Distributed Ingredient:%s               \n", ingredient);

    if (ingredient[0] == 'G' || ingredient[1] == 'U') {
        if (ingredient[0] == 'G') {
            shop1[0] = 1;
            printf("Shop(Thread ID):0 Received Sugar Ingredient\n");
            sleep(1);
        }
        if (ingredient[1] == 'U') {
            shop1[1] = 1;
            printf("Shop(Thread ID):0 Received Flour Ingredient\n");
            sleep(1);
        }

        if (shop1[0] == 1 && shop1[1] == 1) {
            pthread_create(&threads[0], NULL, make_baklava, (void *) (intptr_t) 0);
            pthread_join(threads[0], NULL);
            shop1[0] = 0;
            shop1[1] = 0;
        }
    }

    if (ingredient[0] == 'G' || ingredient[1] == 'F') {
        if (ingredient[0] == 'G') {
            shop2[0] = 1;
            printf("Shop(Thread ID):1 Received Sugar Ingredient\n");
            sleep(1);
        }
        if (ingredient[1] == 'F') {
            shop2[2] = 1;
            printf("Shop(Thread ID):1 Received Pistachio Ingredient\n");
            sleep(1);
        }

        if (shop2[0] == 1 && shop2[2] == 1) {
            pthread_create(&threads[1], NULL, make_baklava, (void *) (intptr_t) 1);
            pthread_join(threads[1], NULL);
            shop2[0] = 0;
            shop2[2] = 0;
        }
    }

    if (ingredient[0] == 'G' || ingredient[1] == 'S') {
        if (ingredient[0] == 'G') {
            shop3[0] = 1;
            printf("Shop(Thread ID):2 Received Sugar Ingredient\n");
            sleep(1);
        }
        if (ingredient[1] == 'S') {
            shop3[3] = 1;
            printf("Shop(Thread ID):2 Received Milk Ingredient\n");
            sleep(1);
        }

        if (shop3[0] == 1 && shop3[3] == 1) {
            pthread_create(&threads[2], NULL, make_baklava, (void *) (intptr_t) 2);
            pthread_join(threads[2], NULL);
            shop3[0] = 0;
            shop3[3] = 0;
        }
    }

    if (ingredient[0] == 'U' || ingredient[1] == 'F') {
        if (ingredient[0] == 'U') {
            shop4[1] = 1;
            printf("Shop(Thread ID):3 Received Flour Ingredient\n");
            sleep(1);
        }
        if (ingredient[1] == 'F') {
            shop4[2] = 1;
            printf("Shop(Thread ID):3 Received Pistachio Ingredient\n");
            sleep(1);
        }

        if (shop4[1] == 1 && shop4[2] == 1) {
            pthread_create(&threads[3], NULL, make_baklava, (void *) (intptr_t) 3);
            pthread_join(threads[3], NULL);
            shop4[1] = 0;
            shop4[2] = 0;
        }
    }

    if (ingredient[0] == 'U' || ingredient[1] == 'S') {
        if (ingredient[0] == 'U') {
            shop5[1] = 1;
            printf("Shop(Thread ID):4 Received Flour Ingredient\n");
            sleep(1);
        }
        if (ingredient[1] == 'S') {
            shop5[3] = 1;
            printf("Shop(Thread ID):4 Received Milk Ingredient\n");
            sleep(1);
        }

        if (shop5[1] == 1 && shop5[3] == 1) {
            pthread_create(&threads[4], NULL, make_baklava, (void *) (intptr_t) 4);
            pthread_join(threads[4], NULL);
            shop5[1] = 0;
            shop5[3] = 0;
        }
    }

    if (ingredient[0] == 'F' || ingredient[1] == 'S') {
        if (ingredient[0] == 'F') {
            shop6[2] = 1;
            printf("Shop(Thread ID):5 Received Pistachio Ingredient\n");
            sleep(1);
        }
        if (ingredient[1] == 'S') {
            shop6[3] = 1;
            printf("Shop(Thread ID):5 Received Milk Ingredient\n");
            sleep(1);
        }

        if (shop6[2] == 1 && shop6[3] == 1) {
            pthread_create(&threads[5], NULL, make_baklava, (void *) (intptr_t) 5);
            pthread_join(threads[5], NULL);
            shop6[2] = 0;
            shop6[3] = 0;
        }
    }
    pthread_create(&threads[6], NULL, start_shipping, (void *) (intptr_t) 6);
    pthread_join(threads[6], NULL);
}

void *make_baklava(void *threadid) {
    sem_post(&sem);
    long tid;
    tid = (long)threadid;
    printf("Shop(Thread ID):%ld Making Baklava.\n", tid);
    sleep(1);
    printf("Shipping, Shop(Thread ID):%ld Took the Baklava.\n", tid);
    sleep(1);
    printf("Shipping, Takes the Baklava to Sell.\n");
    sleep(1);
    printf("Shipping, Sold the Baklava. Continuing the Distribution.\n");
    printf("--------------------------------------------------------\n");

    sleep(3);
    sem_destroy(&sem);
}

int main() {
    int rc;
    int i;
    sem_init(&sem, 0, 1);

    for (i = 0; i < NUM_THREADS; i++) {
        if (i == 6) {
            rc = pthread_create(&threads[i], NULL, start_shipping, (void *) (intptr_t) i);
            printf("--------------------------------------------------------\n");
        } else {
            rc = pthread_create(&threads[i], NULL, open_shop, (void *) (intptr_t) i);
            printf("--------------------------------------------------------\n");
        }

        pthread_join(threads[i], NULL);
        sem_destroy(&sem);

        if (rc) {
            printf("Thread Creation Failed, %d\n", rc);
            exit(-1);
        }
    }

    pthread_exit(NULL);
}
