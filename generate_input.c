#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Программа генерирует 100000 случайных чисел от 1 до 100
 * и записывает их в файл input.txt.
 * Используется для подготовки данных к заданию 8.
 */
int main() {
    // Инициализируем генератор случайных чисел текущим временем
    srand(time(NULL));

    // Открываем файл для записи
    FILE *file = fopen("input.txt", "w");
    if (file == NULL) {
        printf("Ошибка: не удалось создать файл input.txt\n");
        return 1;
    }

    int count = 100000;  // Количество чисел

    // Генерируем и записываем числа
    for (int i = 0; i < count; i++) {
        // Случайное число от 1 до 100 с двумя знаками после запятой
        double randomNumber = 1.0 + (rand() % 10000) / 100.0;
        fprintf(file, "%.2lf\n", randomNumber);
    }

    fclose(file);
    printf("Готово! Сгенерировано %d чисел в файле input.txt\n", count);

    return 0;
}