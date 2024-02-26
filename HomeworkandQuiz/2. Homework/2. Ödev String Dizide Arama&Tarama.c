#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static int index = 1;

int calculateSimilarity(char enteredWord[10], int length);

int main() {
    char words[10][10] = {"diamond", "foot", "scissors", "glove", "phone", "slipper", "cassette", "record", "battery", "cage"};
    int i, result, score = 0, maxScore = 0, maxIndex = 0;
    char enteredWord[10];

    printf("Enter a word for comparison with strings in the array:");
    scanf("%s", &enteredWord);

    for (i = 0; i < 10; i++) {
        result = calculateSimilarity(enteredWord, i);
        if (maxScore < result) {
            maxScore = result;
            maxIndex = i;
        }
    }

    printf("The word with the highest similarity is %s at index %d.\n", words[maxIndex], maxIndex + 1);

    return 0;
}

int calculateSimilarity(char enteredWord[10], int length) {
    char words[10][10] = {"diamond", "foot", "scissors", "glove", "phone", "slipper", "cassette", "record", "battery", "cage"};
    int i, j, condition3 = 0, condition2 = 0, condition1 = 0, totalScore = 0;

    for (i = 0; i < 10; i++) {
        if (words[length][i] == '\0') {
            break;
        }
    }
    int length1 = i;

    for (i = 0; i < 10; i++) {
        if (enteredWord[i] == '\0') {
            break;
        }
    }
    int length2 = i;

    for (i = 0; i < length1; i++) {
        for (j = 0; j < length2; j++) {
            if (words[length][i] == enteredWord[j] && i == j) {
                condition3 += 3;
            }
        }
    }

    for (i = 0; i < length1; i++) {
        for (j = 0; j < length2; j++) {
            if (words[length][i] == enteredWord[j] && (i == j - 1 || i == j + 1)) {
                condition2 += 2;
            }
        }
    }

    for (i = 0; i < length1; i++) {
        for (j = 0; j < length2; j++) {
            if (words[length][i] == enteredWord[j] && (i == j - 1 || i == j + 1)) {
                continue;
            } else if (words[length][i] == enteredWord[j] && i == j) {
                continue;
            }
            if (words[length][i] == enteredWord[j]) {
                condition1++;
            }
        }
    }

    totalScore = condition3 + condition2 + condition1;

    printf("%d. Index Similarity Score: %d\n", index, totalScore);
    index++;
    return totalScore;
}
