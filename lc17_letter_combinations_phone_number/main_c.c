#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void letters_from_digit(int digit, char* dest);

int letters_per_digit(int digit) {
    if (digit == 7 || digit == 9) {
        return 4;
    } else {
        return 3;
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    int n_digits = strlen(digits);

    int n_rows;
    if (n_digits == 0) {
        n_rows = 0;
    } else {
        n_rows = 1;
    }

    int comb_arr[4];
    char key_arr[4][5];

    for (int i = 0; i < n_digits; i++) {
        int letters_for_digit = letters_per_digit((int) digits[i] - '0');
        letters_from_digit((int) digits[i] - '0', key_arr[i]);
        n_rows *= letters_for_digit;
        comb_arr[i] = letters_for_digit;
    }

    int period_arr[5] = {1, 1, 1, 1, 1};
    for (int i = n_digits - 1; i > 0; i--) {
        period_arr[i - 1] *= period_arr[i] * comb_arr[i];
    }

    *returnSize = n_rows;

    char** output = malloc(sizeof(char*) * n_rows);

    for (int i = 0; i < n_rows; i++) {
        output[i] = malloc(sizeof(char) * (n_digits + 1));
        output[i][n_digits] = '\0';
        for (int j = 0; j < n_digits; j++) {
            int k_idx = (i / period_arr[j]) % comb_arr[j];
            output[i][j] = key_arr[j][k_idx];
        }
    }
    return output;
}

// copies 3 or 4 letters depending on digit
void letters_from_digit(int digit, char* dest) {
    switch (digit)
    {
    case 2:
        strcpy(dest, "abc");
        break;

    case 3:
        strcpy(dest, "def");
        break;

    case 4:
        strcpy(dest, "ghi");
        break;

    case 5:
        strcpy(dest, "jkl");
        break;

    case 6:
        strcpy(dest, "mno");
        break;

    case 7:
        strcpy(dest, "pqrs");
        break;

    case 8:
        strcpy(dest, "tuv");
        break;

    case 9:
        strcpy(dest, "wxyz");
        break;
    
    default:
        strcpy(dest, "");
        break;
    }
}

int main(void) {
    char test[] = "2976";
    int res_size;
    char** res = letterCombinations(test, &res_size);
    for (int i = 0; i < res_size; i++) {
        printf("%s\n", res[i]);
        free(res[i]);
    }
    free(res);
}