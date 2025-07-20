#include <stdio.h>
#include <stdlib.h>

double hap(double a, double b);
double minus(double a, double b);
double mul(double a, double b);
double divide(double a, double b);


double hap(double a, double b) {
    return a + b;
}

double minus(double a, double b) {
    return a - b;
}

double mul(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        printf("Error: Division by zero.\n");
        return 0;
    }
    return (double)a / b;
}

int main() {
    double a, b;
    char op;
    printf("계산기 : ");
    scanf("%lf %s %lf", &a, &op, &b);
    if (op == '+') {
        printf("%.2f\n",hap(a, b));
    } else if (op == '-') {
        printf("%.2f\n",minus(a, b));
    } else if (op == '*') {
        printf("%.2f\n",mul(a, b));
    } else if (op == '/') {
        printf("%.2f\n",divide(a, b));
    } else {
        printf("Error: Invalid operator.\n");
    }
}