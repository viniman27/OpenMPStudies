#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


/*


- O número de iterações e o número de threads são definidos.
- Um vetor counters é alocado para armazenar a contagem de iterações para cada thread.
- Dentro da região paralela, cada thread executa um loop sobre o número de iterações. A diretiva #pragma omp for distribui automaticamente as iterações entre as threads disponíveis.
- Cada thread tem um ID exclusivo, que é usado para indexar o vetor counters e incrementar a contagem de suas iterações.
- Após a região paralela, o programa imprime quantas iterações cada thread processou.
- Por fim, a memória alocada para os contadores é liberada.


Para compilar e executar este programa, você usaria um compilador que suporte OpenMP, como o GCC, com a flag -fopenmp:

gcc -fopenmp -o count_iterations count_iterations.c
./count_iterations

*/




int main(int argc, char *argv[]) {
    // Defina o número de iterações e o número de threads.
    int num_iterations = 1000000; // 1 milhão de iterações para exemplo
    int num_threads;

    // Obter o número de threads do ambiente ou definir um padrão.
    char* env_threads = getenv("OMP_NUM_THREADS");
    if (env_threads) {
        num_threads = atoi(env_threads);
    } else {
        num_threads = 4; // Número padrão de threads se OMP_NUM_THREADS não estiver definido
    }

    // Aloca memória para armazenar a contagem de iterações de cada thread.
    int *counters = calloc(num_threads, sizeof(int));
    if (counters == NULL) {
        fprintf(stderr, "Falha ao alocar memória para contadores\n");
        return 1;
    }

    // Região paralela onde cada thread incrementará seu contador.
    #pragma omp parallel num_threads(num_threads)
    {
        int thread_id = omp_get_thread_num();
        #pragma omp for
        for (int i = 0; i < num_iterations; ++i) {
            // Simulando uma operação qualquer
            // ...

            // Incrementa o contador da thread.
            counters[thread_id]++;
        }
    }

    // Imprime o número de iterações que cada thread processou.
    for (int i = 0; i < num_threads; ++i) {
        printf("Thread %d processou %d iterações\n", i, counters[i]);
    }

    // Libera a memória dos contadores.
    free(counters);

    return 0;
}
