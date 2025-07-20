#include <stdio.h>
#include <stdlib.h>

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
                printf("입력 오류: 형식을 확인하세요.\n");
                return 1;
            }

            switch (op) {
                case '+': result = hap(a, b); break;
                case '-': result = minus(a, b); break;
                case '*': result = mul(a, b); break;
                case '/': result = divide(a, b); break;
                case '^': result = squ(a, b); break;
                default:
                    printf("Error: Invalid operator '%c'.\n", op);
                    return 1;
            }

            printf("= %.2f\n", result);
            first = 0;
        } else {
            printf("계산기 (초기화 c, 종료 q): ");
            scanf(" %c", &op);
            if (op == 'q' || op == 'Q') {
                printf("계산기를 종료합니다.\n");
                break;
            }
            else if (op == 'c' || op == 'C') {
                first = 1;
                printf("초기화 되었습니다.\n");
                continue;
            }

            if (scanf("%lf", &b) != 1) {
                printf("입력 오류: 숫자를 입력하세요.\n");
                break;
            }

            switch (op) {
                case '+': result = hap(result, b); break;
                case '-': result = minus(result, b); break;
                case '*': result = mul(result, b); break;
                case '/': result = divide(result, b); break;
                case '^': result = squ(result, b); break;
                default:
                    printf("Error: Invalid operator '%c'.\n", op);
                    continue;
            }

            printf("= %.2f\n", result);
        }
    }

    return 0;
}