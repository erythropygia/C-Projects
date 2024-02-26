#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fillArray(int min, int max, int *ptr, int columns, int rows);
int calculateSecondLargest(int *ptr, int columns, int rows);
int calculateRowSum(int *ptr, int rows, int columns, int targetRow);

int main(){
    int rows, columns, targetRow;
    srand(time(NULL));
    printf("Please enter the number of rows: ");
    scanf("%d", &rows);
    printf("Please enter the number of columns: ");
    scanf("%d", &columns);
    int *ptr = calloc(rows * columns, sizeof(int)); // I allocated memory for my array. I initialized with calloc, so the addresses are set to 0.
    int min, max;

    inputCheck:
    printf("Please enter the minimum value: ");
    scanf("%d", &min);
    printf("Please enter the maximum value: ");
    scanf("%d", &max);
    if(min > max){
        printf("Invalid input! Please try again.\n");
        goto inputCheck;
    }

    fillArray(min, max, ptr, columns, rows);
    printf("\n\nThe second largest element in the array is: %d\n ", calculateSecondLargest(ptr, columns, rows));
    printf("\n\nPlease enter the row number you want to sum: ");
    scanf("%d", &targetRow);
    printf("The sum of the entered row is: %d", calculateRowSum(ptr, rows, columns, targetRow));
    free(ptr);
    return 0;
}

int fillArray(int min, int max, int *ptr, int columns, int rows){
    srand(time(0));
    int i, check;

    if(max - min < rows + columns){
        printf("It is impossible to generate distinct random numbers in this range.\n");
        return 0;
    }

    for(i = 0; i < rows * columns; i++){
        ptr[i] = rand() % (max - min) + min;
        for (check = 0; check < i; check++){
            if (ptr[check] == ptr[i]){
                i--;
                break;
            }
        }
    }

    printf("Array: \n");
    printf("**********");

    for(i = 0; i < rows * columns; i++){
        if(i % columns == 0){
            printf("\n");
        }
        printf("%d ", ptr[i]);
    }
}

int calculateSecondLargest(int *ptr, int columns, int rows){
    int *max1 = calloc(1, sizeof(int)); // I'm defining the arrays that will allow me to find the second largest
    int *max2 = calloc(1, sizeof(int));
    int i, j;
    max1[0] = ptr[0];
    max2[0] = ptr[1];

    for (i = 1; i < rows * columns; i++){
        if (ptr[i] > max1[0]){
            max2[0] = max1[0];
            max1[0] = ptr[i];
        } else if (ptr[i] > max2[0]){
            max2[0] = ptr[i];
        }
    }

    int result = max2[0];
    free(max1);
    free(max2);
    return result;
}

int calculateRowSum(int *ptr, int rows, int columns, int targetRow){
    int i;
    inputCheck1:
    if(targetRow > rows){
        printf("\nInvalid input! Please try again!");
        goto inputCheck1;
    }

    int sum = 0;
    targetRow = targetRow - 1; // I reduced it for array calculation, otherwise it causes a problem in array calculation.
    for(i = 0; i < columns; i++){
        sum = sum + *(ptr + targetRow * columns + i);
    }

    return sum;
}
