#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <stdlib.h>

#define BUF_SIZE 1024

void process_cstring(char* str) {
    size_t len = strlen(str);

    for (size_t i = 0; i < len; i++) {
        if (isdigit((unsigned char)str[i])) {
            int digit = str[i] - '0';

            if (digit % 2 == 0) {
                const char* word = "";
                switch (digit) {
                case 0: word = "zero"; break;
                case 2: word = "two"; break;
                case 4: word = "four"; break;
                case 6: word = "six"; break;
                case 8: word = "eight"; break;
                default: word = ""; break;
                }

                size_t word_len = strlen(word);
                int shift = (int)word_len - 1;

                for (size_t j = len; j > i; j--) {
                    str[j + shift] = str[j];
                }

                for (size_t k = 0; k < word_len; k++) {
                    str[i + k] = word[k];
                }

                len += shift;
                i += word_len - 1;
            }
            else {
                char digit_char = str[i];
                int shift = 2;

                for (size_t j = len; j > i; j--) {
                    str[j + shift] = str[j];
                }

                str[i] = '#';
                str[i + 1] = digit_char;
                str[i + 2] = digit_char;

                len += shift;
                i += 2;
            }
        }
    }
}

int main(void) {
    system("chcp 1251 > nul");
    setlocale(LC_ALL, "Russian");

    char str[BUF_SIZE];

    printf("=== Вариант 2: Си-строка ===\n");
    printf("Введите строку: ");

    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 0;
    }

    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    printf("Исходная строка: %s\n", str);
    process_cstring(str);
    printf("Результат:       %s\n", str);

    return 0;
}