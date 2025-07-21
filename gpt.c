#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
        printf("0으로 나눌 수 없습니다.\n");
        exit(1);
    }
    return a / b;
}

double squ(double a, double b) {
    double result;
    result = pow(a, b);
    return result;
}

int main() {
    double a, b, result;
    char op;
    int first = 1;

    while (1) {
        if (first) {
            printf("계산기 : ");
            if (scanf("%lf %c %lf", &a, &op, &b) != 3) {
                printf("계산할 수 없습니다.\n");
                return 1;
            }

            switch (op) {
                case '+': result = hap(a, b); break;
                case '-': result = minus(a, b); break;
                case '*': result = mul(a, b); break;
                case '/': result = divide(a, b); break;
                case '^': result = squ(a, b); break;
                default:
                    printf("연산부호를 찾을 수 없습니다. '%c'.\n", op);
                    return 1;
            }

            printf("= %lf\n", result);
            first = 0;
        }
        else {
            printf("계산기 (초기화 c, 종료 q): ");
            scanf(" %c", &op);
            if (op == 'q' || op == 'Q') {
                printf("계산기를 종료합니다.\n");
                break;
            }
            else if (op == 'c' || op == 'C') {
                first = 1;
                printf("초기화되었습니다.\n");
                continue;
            }

            if (scanf("%lf", &b) != 1) {
                printf("계산할 수 없습니다.\n");
                break;
            }

            switch (op) {
                case '+': result = hap(result, b); break;
                case '-': result = minus(result, b); break;
                case '*': result = mul(result, b); break;
                case '/': result = divide(result, b); break;
                case '^': result = squ(result, b); break;
                default:
                    printf("연산부호를 찾을 수 없습니다. '%c'.\n", op);
                    continue;
            }

            printf("= %lf\n", result);
        }
    }

    return 0;
}