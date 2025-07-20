#include <stdio.h>
#include <math.h>

int main() {
    double num;
    printf("루트를 계산할 숫자를 입력하세요: ");
    scanf("%lf", &num);

    if (num < 0) {
        printf("음수의 제곱근은 실수 범위에서 정의되지 않습니다.\n");
    } else {
        printf("√%.2f = %.4f\n", num, sqrt(num));
    }

    return 0;
}
