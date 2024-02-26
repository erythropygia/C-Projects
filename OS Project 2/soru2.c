#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include "sorting.h"
#include <sys/wait.h>
#include <semaphore.h>
#include <fcntl.h>

#define SEM_NAME "semaphore"

int *numbers;
sem_t finish_sem;
int shared_index;

void* create_shared_memory(size_t size) {
    int protection = PROT_READ | PROT_WRITE;
    int visibility = MAP_SHARED | MAP_ANONYMOUS;

    return mmap(NULL, size, protection, visibility, -1, 0);
}

int main(int argc, char* argv[]) {
    int k = atoi(argv[1]);
    int n = atoi(argv[2]);
    int files = argc - 3;
    int i, value, index[1];
    index[0] = 0;
    int *array;
    sem_init(&finish_sem, 1, 0);
    array = (int*)malloc(k * sizeof(int) * n);
    sem_t *sem_id = sem_open(SEM_NAME, O_CREAT, 0644, 2);
    void *shared_memory = create_shared_memory(k * sizeof(int));
    void *index_memory = create_shared_memory(sizeof(int));
    memcpy(index_memory, index, sizeof(int));

    for (i = 0; i < n; i++) {
        int pid = fork();

        if (pid == 0) {
            int smallest, buffer, size, current_index = 0;
            numbers = (int*)malloc(k * sizeof(int));
            numbers[0] = 0;
            sem_t *sem_id = sem_open(SEM_NAME, 1);
            printf("%d ---> Child process is starting\n", getpid());

            FILE* file;
            if (file = fopen(argv[3 + i], "r"))
                printf("File reading successful\n");
            else
                printf("File cannot be read\n");

            while (fscanf(file, "%d\n", &buffer) != EOF) {
                mergeSort(numbers, 0, current_index);
                reverse(numbers, 0, current_index);

                smallest = numbers[current_index];

                if (buffer > smallest)
                    numbers[current_index] = buffer;

                if (current_index < k)
                    current_index++;
            }

            memcpy(shared_memory + (k * i), numbers, current_index * sizeof(int));
            sem_post(sem_id);
            exit(0);
        } else {
            sem_wait(sem_id);
            wait(NULL);
            memcpy(index, index_memory, sizeof(int));
            memcpy(array + index[0] * k, shared_memory + (k * index[0]), (k * n) * sizeof(int));
            index[0]++;
            memcpy(index_memory, index, sizeof(int));
            printf("Last: ");
            printArray(array, k * index[0]);
        }
        sem_post(&finish_sem);
        sem_getvalue(&finish_sem, &shared_index);

        if (shared_index == n) {
            mergeSort(array, 0, (k * index[0]) - 1);
            reverse(array, 0, k * index[0] - 1);

            FILE* write_file;
            write_file = fopen(argv[n + 3], "w");
            for (i = 0; i < k * index[0]; i++)
                fprintf(write_file, "%d\n", array[i]);
            printf("\nProcesses completed! Parent process wrote the sorted array to the %s file!\n", argv[n + 3]);
            exit(0);
        }
    }

    return 0;
}
