#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#define BUF_SIZE 1024

int main(void)
{
    system("chcp 1251 > nul");
    setlocale(LC_ALL, "Russian");

    char str[BUF_SIZE];
    int len = 0;

    printf("=== Вариант 1: Массив символов ===\n");
    printf("Введите строку: ");

    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 0;
    }

    while (str[len] != '\0' && str[len] != '\n') {
        len++;
    }
    str[len] = '\0';

    printf("Исходная строка: %s\n", str);

    for (int i = 0; i < len; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            int digit = str[i] - '0';

            if (digit % 2 == 0) {
                const char* word = "";
                int wlen = 0;

                switch (digit) {
                case 0: word = "zero";  wlen = 4; break;
                case 2: word = "two";   wlen = 3; break;
                case 4: word = "four";  wlen = 4; break;
                case 6: word = "six";   wlen = 3; break;
                case 8: word = "eight"; wlen = 5; break;
                default: break;
                }

                int shift = wlen - 1;
                for (int j = len; j > i; j--) {
                    str[j + shift] = str[j];
                }

                for (int k = 0; k < wlen; k++) {
                    str[i + k] = word[k];
                }

                len += shift;
                i += shift;
            }
            else {
                char digit_char = str[i];
                int shift = 2;

                for (int j = len; j > i; j--) {
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

    printf("Результат:       %s\n", str);
    return 0;
}