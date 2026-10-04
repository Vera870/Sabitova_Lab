#include <stdio.h>
#include <stdlib.h>
#include <omp.h>   // Библиотека OpenMP

#define MAX_SIZE 10000000  // Максимальный размер массива

/*
 * Функция mySquareRoot вычисляет квадратный корень числа методом Ньютона.
 * Используется вместо стандартной sqrt() из библиотеки math.h,
 * чтобы избежать проблем с подключением внешних библиотек.
 * Принимает число number, возвращает его квадратный корень.
 */
double mySquareRoot(double number) {
    if (number < 0) return -1;
    if (number == 0) return 0;

    double result = number;
    for (int i = 0; i < 20; i++) {
        result = (result + number / result) / 2.0;
    }
    return result;
}

/*
 * Функция calculateMean вычисляет среднее арифметическое массива.
 * Принимает массив чисел и его размер.
 * Возвращает среднее арифметическое.
 */
double calculateMean(double *array, int size) {
    double sum = 0.0;

    // Параллельный цикл for с редукцией по переменной sum
    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }

    return sum / size;
}

/*
 * Функция calculateStdDev вычисляет среднеквадратическое отклонение массива.
 * Принимает массив чисел, его размер и уже вычисленное среднее.
 * Возвращает среднеквадратическое отклонение.
 */
double calculateStdDev(double *array, int size, double mean) {
    double sumOfSquares = 0.0;

    // Параллельный цикл for с редукцией
    #pragma omp parallel for reduction(+:sumOfSquares)
    for (int i = 0; i < size; i++) {
        double difference = array[i] - mean;
        sumOfSquares += difference * difference;
    }

    // Используем собственную функцию mySquareRoot вместо sqrt
    return mySquareRoot(sumOfSquares / size);
}

/*
 * Главная функция main.
 * Считывает массив из файла input.txt, вычисляет статистики,
 * записывает результат в файл output.txt и замеряет время
 * для 1, 2 и 4 потоков.
 */
int main() {
    // Открываем файл с данными
    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: cannot open input.txt\n");
        return 1;
    }

    // Выделяем память под массив
    double *array = (double*)malloc(MAX_SIZE * sizeof(double));
    if (array == NULL) {
        printf("Error: not enough memory\n");
        fclose(inputFile);
        return 1;
    }

    // Считываем числа из файла
    int size = 0;
    while (fscanf(inputFile, "%lf", &array[size]) == 1 && size < MAX_SIZE) {
        size++;
    }
    fclose(inputFile);

    printf("Numbers read: %d\n", size);

    // Открываем файл для записи результатов
    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error: cannot create output.txt\n");
        free(array);
        return 1;
    }

    // Замеряем время для 1, 2 и 4 потоков
    int threadCounts[] = {1, 2, 4};

    for (int t = 0; t < 3; t++) {
        int threads = threadCounts[t];
        omp_set_num_threads(threads);  // Устанавливаем число потоков

        double startTime = omp_get_wtime();  // Засекаем время

        // Вычисляем среднее и отклонение
        double mean = calculateMean(array, size);
        double stdDev = calculateStdDev(array, size, mean);

        double endTime = omp_get_wtime();  // Останавливаем время

        double elapsed = endTime - startTime;

        // Записываем результаты в файл
        fprintf(outputFile, "=== Threads: %d ===\n", threads);
        fprintf(outputFile, "Mean: %.4lf\n", mean);
        fprintf(outputFile, "Standard deviation: %.4lf\n", stdDev);
        fprintf(outputFile, "Time: %.6f seconds\n\n", elapsed);

        printf("Threads: %d, time: %.6f sec\n", threads, elapsed);
    }

    fclose(outputFile);
    free(array);

    printf("Done! Results in output.txt\n");
    return 0;
}