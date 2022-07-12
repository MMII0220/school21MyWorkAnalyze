/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/
#include <stdio.h>
#include <math.h>
#define NMAX 30

int input(int *a, int *n);
int even(int *a, int n);
double mean(int *a, int n);
int search(int *a, int n);
int search(int *a, int n);
void output_result(int search_v);


int main() {
    int n, data[NMAX];
    if (input(data, &n) == 1) {
        printf("n/a\n");
    } else {
        output_result(search(data, n));
    }
    return 0;
}

int input(int *a, int *n) {
    char ch1, ch2;
    int i = 1;
    int indicator = 0;
    if (scanf("%d%c", n, &ch1) == 2 && ch1 == '\n' && *n <= NMAX && *n > 0) {
        for (int *p = a; (p - a < *n) && ch2 != '\n'; p++) {
        if (scanf("%d%c", p, &ch2) != 2 || (ch2 != ' ' && i < *n)) indicator = 1;
        else if (ch2 != '\n' && i == *n) indicator = 1;
        else if (i > NMAX) indicator = 1;
        else if (ch2 != '\n' && i == *n) indicator = 1;
        i++;
        }
    } else {
        indicator = 1;
    }
    return indicator;
}

double mean(int *a, int n) {
    double sum = 0, res;
    for (int *p = a; p - a < n; p++) {
    sum = sum + *p;
    }
    res = sum / n;
    return res;
}

double variance(int *a, int n) {
    double var = 0;
    for (int *p = a; p - a < n; p++) {
    var += (*p) * (*p);
    }
    var = (var / n) - (mean(a, n) * mean(a, n));
    return var;
}

int search(int *a, int n) {
    int *p = a;
    int indicator = 0;
    while ((p - a < n)) {
        if ((*p % 2) == 0 && *p >= mean(a, n) && (*p <= mean(a, n) + 3 * sqrt(variance(a, n))) && *p != 0)
        indicator = *p;
        p++;
    }
    return indicator;
}

void output_result(int search_v) {
    printf("%d\n", search_v);
}

/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/
