#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void wordOperations();
int calculateSimilarity(char enteredWord[10], int length);
void initializeCharArray();
static int index = 1;

struct WordAnalysis {
    char list[15][15];
    int vowels;
    int consonants;
    int length;
    int similarity;
} word;

int main() {
    initializeCharArray();
    wordOperations();
    int i, result, maxSimilarity = 0, maxIndex = 0;
    char enteredWord[10];

    printf("Enter a word for comparison with strings in the array:");
    scanf("%s", enteredWord);

    for (i = 0; i < 15; i++) {
        word.similarity = calculateSimilarity(enteredWord, i);
        if (maxSimilarity < word.similarity) {
            maxSimilarity = word.similarity;
            maxIndex = i;
        }
    }

    printf("The word with the highest similarity is %s at index %d.\n", word.list[maxIndex], maxIndex + 1);

    return 0;
}

int calculateSimilarity(char enteredWord[10], int length) {
    int condition3 = 0, condition2 = 0, condition1 = 0, totalScore = 0;

    int i, j;
    for (i = 0; i < 15; i++) {
        if (word.list[length][i] == '\0') {
            break;
        }
    }
    int length1 = i;

    for (i = 0; i < 15; i++) {
        if (enteredWord[i] == '\0') {
            break;
        }
    }
    int length2 = i;

    for (i = 0; i < length1; i++) {
        for (j = 0; j < length2; j++) {
            if (word.list[length][i] == enteredWord[j] && i == j) {
                condition3 += 3;
            }
        }
    }

    for (i = 0; i < length1; i++) {
        for (j = 0; j < length2; j++) {
            if (word.list[length][i] == enteredWord[j] && (i == j - 1 || i == j + 1)) {
                condition2 += 2;
            }
        }
    }

    for (i = 0; i < length1; i++) {
        for (j = 0; j < length2; j++) {
            if (word.list[length][i] == enteredWord[j] && (i == j - 1 || i == j + 1)) {
                continue;
            } else if (word.list[length][i] == enteredWord[j] && i == j) {
                continue;
            }
            if (word.list[length][i] == enteredWord[j]) {
                condition1++;
            }
        }
    }

    totalScore = condition3 + condition2 + condition1;

    printf("%d. Index Similarity Score: %d\n", index, totalScore);
    index++;
    return totalScore;
}

void wordOperations() {
    int i, j;

    for (i = 0; i < 15; i++) {
        printf("%d - %s \n", i + 1, word.list[i]);
    }
    printf("********************\n");

    for (i = 0; i < 15; i++) {
        for (j = 0; j < 15; j++) {
            if (word.list[i][j] == 'a' || word.list[i][j] == 'e' || word.list[i][j] == 'i' || word.list[i][j] == 'o' ||
                word.list[i][j] == 'u') {
                word.vowels++;
            }
        }

        word.length = strlen(word.list[i]);
        word.consonants = word.length - word.vowels;

        printf("%d. Word length is %d, and it has %d vowels and %d consonants.\n", i + 1, word.length, word.vowels,
               word.consonants);

        word.consonants = 0;
        word.vowels = 0;
    }
    printf("********************\n");
}

void initializeCharArray() {
    int counter = 0;

    for (counter = 0; counter < 15; counter++) {
        printf("Enter a string with at most 15 words for %d. Array Element:", counter + 1);
        scanf("%s", word.list[counter]);
    }

    printf("********************\n");
}
