#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VECTOR_COUNT 6   // Количество векторов
#define VECTOR_SIZE  5   // Размер каждого вектора (координат)

/*
 * Функция dotProduct вычисляет скалярное произведение двух векторов.
 * Принимает два массива (вектора) и их размер.
 * Возвращает скалярное произведение (сумму произведений координат).
 */
double dotProduct(double *vectorA, double *vectorB, int size) {
    double result = 0.0;
    for (int i = 0; i < size; i++) {
        result += vectorA[i] * vectorB[i];
    }
    return result;
}

/*
 * Функция fillVectorRandomly заполняет вектор случайными числами.
 * Принимает массив (вектор) и его размер.
 * Записывает случайные числа от -10 до 10 в массив.
 */
void fillVectorRandomly(double *vector, int size) {
    for (int i = 0; i < size; i++) {
        // Случайное число от -10.0 до 10.0
        vector[i] = -10.0 + (rand() % 2001) / 100.0;
    }
}

/*
 * Главная функция main.
 * Создает 6 случайных векторов, находит все попарные
 * скалярные произведения и выводит результат в файл.
 */
int main() {
    // Инициализируем генератор случайных чисел
    srand(time(NULL));

    // Создаем массив из 6 векторов, каждый по 5 координат
    double vectors[VECTOR_COUNT][VECTOR_SIZE];

    // Заполняем каждый вектор случайными числами
    for (int i = 0; i < VECTOR_COUNT; i++) {
        fillVectorRandomly(vectors[i], VECTOR_SIZE);
    }

    // Открываем файл для записи результатов
    FILE *outputFile = fopen("vectors_output.txt", "w");
    if (outputFile == NULL) {
        printf("Error: cannot create vectors_output.txt\n");
        return 1;
    }

    // Выводим все векторы в файл (для наглядности)
    fprintf(outputFile, "=== Generated vectors ===\n");
    for (int i = 0; i < VECTOR_COUNT; i++) {
        fprintf(outputFile, "Vector %d: (", i + 1);
        for (int j = 0; j < VECTOR_SIZE; j++) {
            fprintf(outputFile, "%.2lf", vectors[i][j]);
            if (j < VECTOR_SIZE - 1) fprintf(outputFile, ", ");
        }
        fprintf(outputFile, ")\n");
    }
    fprintf(outputFile, "\n=== All pairwise dot products ===\n");

    // Находим все попарные скалярные произведения
    for (int i = 0; i < VECTOR_COUNT; i++) {
        for (int j = i + 1; j < VECTOR_COUNT; j++) {
            double result = dotProduct(vectors[i], vectors[j], VECTOR_SIZE);
            fprintf(outputFile, "dot(Vector %d, Vector %d) = %.4lf\n", 
                    i + 1, j + 1, result);
        }
    }

    // Закрываем файл
    fclose(outputFile);

    printf("Done! Results in vectors_output.txt\n");
    return 0;
}