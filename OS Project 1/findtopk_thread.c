#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <pthread.h>
#include <time.h>

int k_numbers[5];

struct t_args {
    char* file;
    int index;
    int k;
};

void *sort(void *arguments) {
    int length = 1, a_length = 10, a_in = 0, fd, i, j, k, key;
    char* buffer = (char*)malloc(sizeof(char));
    char* fnumber = (char*)malloc(12 * sizeof(char));
    int* array = (int*)malloc(a_length * sizeof(int));

    fd = open(((struct t_args*)arguments)->file, O_RDWR);

    while (length != 0) {
        length = read(fd, buffer, sizeof(char));
        if (a_in == a_length - 2) {
            a_length += 10;
            array = realloc(array, a_length * sizeof(int));
        }
        if (strcmp(buffer, "\n") != 0) {
            strcat(fnumber, buffer);
        } else {
            sscanf(fnumber, "%d", array + a_in);
            strcpy(fnumber, "\0");
            a_in++;
        }
    }

    for (j = 0; j < a_in; j++) {
        key = array[j];
        k = j - 1;

        while (k >= 0 && key < array[k]) {
            array[k + 1] = array[k];
            k--;
        }
        array[k + 1] = key;
    }

    printf("Kth number: %d\n", array[((struct t_args*)arguments)->k]);
    k_numbers[((struct t_args*)arguments)->index] = array[((struct t_args*)arguments)->k];

    close(fd);
    free(buffer);
    free(fnumber);
    free(array);
    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        printf("Not enough parameters provided!\n");
        exit(1);
    }

    int i;
    int k = atoi(argv[1]);
    int n = atoi(argv[2]);

    pthread_t threads[n];
    struct t_args* arguments = (struct t_args*)malloc(sizeof(struct t_args));

    clock_t timer = clock();

    for (i = 0; i < n; i++) {
        printf("File sent: %s\n", argv[i + 3]);
        arguments->file = argv[i + 3];
        arguments->index = i;
        arguments->k = k;
        pthread_create(&threads[i], NULL, sort, (void*)arguments);
        pthread_join(threads[i], NULL);
    }

    timer = clock() - timer;
    printf("Threads finished! - Elapsed time: %f\n", ((double)timer) / CLOCKS_PER_SEC);

    int fd = open(argv[n + 3], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("r1");
        exit(1);
    }

    char cbuffer[12];
    int length;

    for (i = 0; i < n; i++) {
        strcpy(cbuffer, "\0");
        length = sprintf(cbuffer, "%d", k_numbers[i]);
        strcat(cbuffer, "\n");
        write(fd, cbuffer, length + 1);
    }

    close(fd);
}
