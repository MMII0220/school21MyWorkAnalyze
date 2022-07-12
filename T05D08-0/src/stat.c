#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n, double *sum);

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v);

int main() {
    int n, data[NMAX];

    short flag = input(data, &n);

    if (flag) {
        max(data, n);
        min(data, n);
        double sum = mean(data, n);
        variance(data, n, &sum);
        output(data, n);
        output_result(max(data, n),
                  min(data, n),
                  mean(data, n),
                  variance(data, n, &sum));
    } else {
        printf("n/a");
    }

    return 0;
}

int input(int *a, int *n) {
    short flag = 1;
    char c;

    // если ввод равен 2, длина массива больше 1 и меньше 10 и 2 ввод равен Enter

    if ((scanf("%d%c", n, &c) == 2) && (*n >= 1 && *n <= NMAX) && c == '\n') {
        // Проверяем массивы на неправильные значения

        for (int *p = a; p - a < *n; p++) {
            if (scanf("%d%c", p, &c) != 2 || (p - a < *n - 1 && c != ' ') || (p - a == *n - 1 && c != '\n')) {
                flag = 0;
                break;
            }
        }

    } else { flag = 0; }

    return flag;
}

int max(int *a, int n) {
    int maxNum = *a;

    for (int *p = a; p - a < n; p++) {
        if (*p > maxNum) {
            maxNum = *p;
        }
    }

    return maxNum;
}

int min(int *a, int n) {
    int minNum = *a;

    for (int *p = a; p - a < n; p++) {
        if (*p < minNum) {
            minNum = *p;
        }
    }

    return minNum;
}

double mean(int *a, int n) {
    double sum = 0;

    for (int i = 0; i < n; i++) {
        sum += a[i];
    }

    sum = sum / n;

    return sum;
}

double variance(int *a, int n, double *sum) {
    double D = 0;
    for (int i = 0; i < n; i++) {
        D += a[i]*a[i];
    }

    D = D / n - *sum * *sum;

    return D;
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);

        if (i < n - 1) {
            printf(" ");
        }
    }

    printf("\n");
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
}
