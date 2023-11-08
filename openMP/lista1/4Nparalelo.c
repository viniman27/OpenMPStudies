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
    int i;
    int primos = 0;

    double start_time = omp_get_wtime();

    for (i = N; i > 1; i--) {
        if (is_prime(i)) {
            primos++;
        }
    } /* fim-for */

    double end_time = omp_get_wtime();
    printf("%d primos!\n", primos);
    printf("Tempo de resposta: %f segundos\n", end_time - start_time);

    return 0;
} /* fim-main */
