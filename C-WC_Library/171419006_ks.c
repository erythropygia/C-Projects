#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

int count_info(char data_path[], int *line_sum, int *word_sum, int *char_sum) {
    FILE* fp;
    int i;
    char line;
    char word[10000];
    int counter_line = 0;
    int counter_word = 0;
    int counter_char = -1;

    if (1) {
        if ((fp = fopen(data_path, "r")) == NULL) { // file is opened
            printf("File not found\n");
            return 1;
        }

        while (!feof(fp)) {
            // Find the line
            line = getc(fp);
            if (line == '\n') {
                counter_line++;
            }
            // Find the word
            if (line == ' ' || line == '\n') {
                counter_word++;
            }
            // Find the character
            if (line != ' ' && line != '\n') {
                counter_char++;
            }
        }

        *line_sum = counter_line;
        *word_sum = counter_word;
        *char_sum = counter_char;
        printf("File Name: %s. Line = %d, Word = %d, Character = %d\n", data_path, counter_line, counter_word, counter_char);
        fclose(fp);
    }
}

int create_random(char data_path[]) {
    FILE* fp;
    int i, j, k;
    char text[] = "A";
    srand(time(NULL));
    int counter_line = rand() % 100;
    int counter_char = rand() % 100;
    int random = rand() % 35;
    int line_sum, word_sum, char_sum;

    if ((fp = fopen(data_path, "w+")) == NULL) { // file is opened
        printf("File not found\n");
        return 1;
    }

    for (i = 0; i < counter_line; i++) {
        for (k = 0; k < counter_char; k++) {
            fprintf(fp, "%s", text);
            if (k % random == 0) {
                fprintf(fp, "%s", " ");
            }
        }
        fprintf(fp, "%s", "\n");
    }

    fclose(fp);
    count_info(data_path, &line_sum, &word_sum, &char_sum);
}

// line word character 
int main(int argc, char* argv[]) {
    int line_sum, word_sum, char_sum;
    char* randomize = "random.txt";
    char* data_path = argv[1];
    char* data_path_1 = argv[2];
    int sum[2][3];

    if (argc == 2) { // Check the parameter received from the user
        if (strcmp(data_path, randomize) != 0) {
            count_info(data_path, &line_sum, &word_sum, &char_sum);
        } else {
            create_random(data_path);
        }
    } else if (argc == 3) { // Check the parameter received from the user
        count_info(data_path, &line_sum, &word_sum, &char_sum);
        sum[0][0] = line_sum;
        sum[0][1] = word_sum;
        sum[0][2] = char_sum;
        count_info(data_path_1, &line_sum, &word_sum, &char_sum);
        sum[1][0] = line_sum;
        sum[1][1] = word_sum;
        sum[1][2] = char_sum;

        printf("SUMS: Line:%d , Word:%d, Character:%d\n", sum[0][0] + sum[1][0], sum[0][1] + sum[1][1], sum[0][2] + sum[1][2]);
    }
}
