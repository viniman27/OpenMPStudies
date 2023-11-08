#include <stdio.h>
#include <omp.h>
#define N 300000

int is_prime(int num) {
    if (num <= 1) return 0;
    if (num % 2 == 0 && num > 2) return 0;
    for (int j = 3; j < num / 2; j += 2) {
        if (num % j == 0) return 0;
    }
    return 1;
}

int main(void) {
    int primos = 0;
    double start_time, end_time;

    start_time = omp_get_wtime();

    #pragma omp parallel for reduction(+:primos)
    for (int i = N; i > 1; i--) {
        if (is_prime(i)) {
            primos++;
        }
    }

    end_time = omp_get_wtime();
    printf("%d primos!\n", primos);
    printf("Tempo de resposta paralelo: %f segundos\n", end_time - start_time);

    return 0;
}
