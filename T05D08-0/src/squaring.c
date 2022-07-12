#include <stdio.h>

#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];
    int flag = input(data, &n);
    if (flag) {
        squaring(data, n);
        output(data, n);
    } else {
        printf("n/a");
    }

    return 0;
}

int input(int *a, int *n) {
    int flag = 1;
    char c;

    if ((scanf("%d%c", n, &c) == 2) && (*n >= 1 && *n <= 10) && c == '\n') {
        for (int *p = a; p - a < *n; p++) {
            if (scanf("%d%c", p, &c) != 2 || (p - a < *n - 1 && c != ' ') ||
            (p - a == *n - 1 && c != '\n')) {
                flag = 0;
                break;
            }
        }
    } else { flag = 0; }
    return flag;
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);

        if (i < n - 1) {
            printf(" ");
        }
    }
}

void squaring(int *a, int n) {
    for (int i = 0; i < n; i++) {
        a[i] = a[i] * a[i];
    }
}
