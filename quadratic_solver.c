#include <stdio.h>
#include <math.h>   // Нужна для функции sqrt() (квадратный корень)

/*
 * Функция solveQuadraticEquation решает квадратное уравнение вида ax^2 + bx + c = 0.
 * Принимает три коэффициента: coefficientA, coefficientB, coefficientC.
 * Выводит на экран количество корней и сами корни (если они есть).
 */
void solveQuadraticEquation(double coefficientA, double coefficientB, double coefficientC) {
    // Проверка: если a = 0, то это не квадратное уравнение, а линейное
    if (coefficientA == 0) {
        if (coefficientB == 0) {
            // Уравнение вида 0 = c (либо бесконечно много решений, либо нет)
            if (coefficientC == 0) {
                printf("Уравнение имеет бесконечно много решений.\n");
            } else {
                printf("Уравнение не имеет решений.\n");
            }
        } else {
            // Линейное уравнение bx + c = 0 -> x = -c / b
            double singleRoot = -coefficientC / coefficientB;
            printf("Это линейное уравнение. Один корень: x = %.2lf\n", singleRoot);
        }
        return; // Выходим из функции, дальше считать дискриминант нет смысла
    }

    // Вычисляем дискриминант по формуле D = b^2 - 4ac
    double discriminant = coefficientB * coefficientB - 4 * coefficientA * coefficientC;

    // Проверяем значение дискриминанта
    if (discriminant > 0) {
        // Два различных действительных корня
        double firstRoot = (-coefficientB + sqrt(discriminant)) / (2 * coefficientA);
        double secondRoot = (-coefficientB - sqrt(discriminant)) / (2 * coefficientA);
        printf("Уравнение имеет два корня:\n");
        printf("x1 = %.2lf\n", firstRoot);
        printf("x2 = %.2lf\n", secondRoot);
    } else if (discriminant == 0) {
        // Один корень (кратный)
        double singleRoot = -coefficientB / (2 * coefficientA);
        printf("Уравнение имеет один корень (кратный):\n");
        printf("x = %.2lf\n", singleRoot);
    } else {
        // Дискриминант меньше нуля — действительных корней нет
        printf("Уравнение не имеет действительных корней (D < 0).\n");
    }
}

/*
 * Главная функция main.
 * Запрашивает у пользователя коэффициенты и вызывает функцию решения.
 */
int main() {
    double coefficientA, coefficientB, coefficientC;

    // Запрашиваем ввод у пользователя
    printf("Введите коэффициенты квадратного уравнения (a, b, c):\n");
    printf("a = ");
    scanf("%lf", &coefficientA);
    printf("b = ");
    scanf("%lf", &coefficientB);
    printf("c = ");
    scanf("%lf", &coefficientC);

    // Вызываем функцию решения
    solveQuadraticEquation(coefficientA, coefficientB, coefficientC);

    return 0;
}