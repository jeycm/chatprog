#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 기본 연산 함수
double hap(double a, double b) { return a + b; }
double minus(double a, double b) { return a - b; }
double mul(double a, double b) { return a * b; }
double divide(double a, double b) {
    if (b == 0) {
        printf("Error: Division by zero.\n");
        exit(1);
    }
    return a / b;
}
double squ(double a, double b) { return pow(a, b); }

// 분수 지수 계산: a^(m/n)
double frac_pow(double a, double m, double n) {
    if (n == 0) {
        printf("Error: 분모(n)는 0이 될 수 없습니다.\n");
        exit(1);
    }
    return pow(a, m / n);
}

int main() {
    double a, b, m, n, result;
    char op;
    int first = 1;

    while (1) {
        if (first) {
            printf("계산기 : ");
            if (scanf("%lf %c", &a, &op) != 2) {
                printf("입력 오류: 형식을 확인하세요.\n");
                return 1;
            }

            if (op == 'f' || op == 'F') {  
                // 분수 지수 연산일 경우
                printf("지수 분자(m)와 분모(n)를 입력하세요 (m n): ");
                if (scanf("%lf %lf", &m, &n) != 2) {
                    printf("입력 오류: 숫자를 입력하세요.\n");
                    return 1;
                }
                result = frac_pow(a, m, n);
            } else {
                // 일반 연산자일 때 b도 입력받기
                if (scanf("%lf", &b) != 1) {
                    printf("입력 오류: 두 번째 숫자를 입력하세요.\n");
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
            }
            printf("= %.6f\n", result);
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
            else if (op == 'f' || op == 'F') {
                // 분수 지수 계속 계산
                printf("지수 분자(m)와 분모(n)를 입력하세요 (m n): ");
                if (scanf("%lf %lf", &m, &n) != 2) {
                    printf("입력 오류: 숫자를 입력하세요.\n");
                    break;
                }
                result = frac_pow(result, m, n);
            } else {
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
            }
            printf("= %.6f\n", result);
        }
    }

    return 0;
}
