#include <stdio.h>
#include <stdlib.h>

/*
 * Функция mySquareRoot вычисляет квадратный корень числа методом Ньютона.
 * Используется вместо стандартной функции sqrt() из библиотеки math.h.
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
 * Функция solveQuadraticEquation решает квадратное уравнение вида ax^2 + bx + c = 0.
 * Принимает три коэффициента и указатель на файл для записи результата.
 * Записывает в файл количество корней и сами корни (если они есть).
 */
void solveQuadraticEquation(double coefficientA, double coefficientB, double coefficientC, FILE *outputFile) {
    if (coefficientA == 0) {
        if (coefficientB == 0) {
            if (coefficientC == 0) {
                fprintf(outputFile, "Уравнение имеет бесконечно много решений.\n");
            } else {
                fprintf(outputFile, "Уравнение не имеет решений.\n");
            }
        } else {
            double singleRoot = -coefficientC / coefficientB;
            fprintf(outputFile, "Это линейное уравнение. Один корень: x = %.2lf\n", singleRoot);
        }
        return;
    }

    double discriminant = coefficientB * coefficientB - 4 * coefficientA * coefficientC;

    if (discriminant > 0) {
        double firstRoot = (-coefficientB + mySquareRoot(discriminant)) / (2 * coefficientA);
        double secondRoot = (-coefficientB - mySquareRoot(discriminant)) / (2 * coefficientA);
        fprintf(outputFile, "Уравнение имеет два корня:\n");
        fprintf(outputFile, "x1 = %.2lf\n", firstRoot);
        fprintf(outputFile, "x2 = %.2lf\n", secondRoot);
    } else if (discriminant == 0) {
        double singleRoot = -coefficientB / (2 * coefficientA);
        fprintf(outputFile, "Уравнение имеет один корень (кратный):\n");
        fprintf(outputFile, "x = %.2lf\n", singleRoot);
    } else {
        fprintf(outputFile, "Уравнение не имеет действительных корней (D < 0).\n");
    }
}

/*
 * Главная функция main для варианта Б.
 * Считывает коэффициенты из файла input.txt, решает уравнение
 * и записывает результат в файл output.txt.
 */
int main() {
    // Открываем файл для чтения
    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Ошибка: не удалось открыть файл input.txt\n");
        return 1;
    }

    // Открываем файл для записи
    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Ошибка: не удалось создать файл output.txt\n");
        fclose(inputFile);
        return 1;
    }

    double coefficientA, coefficientB, coefficientC;

    // Считываем три коэффициента из файла
    if (fscanf(inputFile, "%lf %lf %lf", &coefficientA, &coefficientB, &coefficientC) != 3) {
        fprintf(outputFile, "Ошибка: в файле input.txt должно быть три числа.\n");
        fclose(inputFile);
        fclose(outputFile);
        return 1;
    }

    // Записываем в файл исходные данные (для наглядности)
    fprintf(outputFile, "Входные данные: a = %.2lf, b = %.2lf, c = %.2lf\n", 
            coefficientA, coefficientB, coefficientC);

    // Решаем уравнение и записываем результат в файл
    solveQuadraticEquation(coefficientA, coefficientB, coefficientC, outputFile);

    // Закрываем файлы
    fclose(inputFile);
    fclose(outputFile);

    printf("Готово! Результат записан в файл output.txt\n");
    return 0;
}