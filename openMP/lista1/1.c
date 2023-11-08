#include <stdio.h>
#include <omp.h>


// A cláusula private(nthreads) foi substituída por shared(nthreads) para que a variável nthreads seja compartilhada entre todas as threads.

int main(void) {
  int myid, nthreads;
  #pragma omp parallel private(myid) shared(nthreads)
  {
    myid = omp_get_thread_num();
    #pragma omp single
    {
      nthreads = omp_get_num_threads();
    }
    printf("%d de %d - Hello, World!\n", myid, nthreads);
  }
  return 0;
} /* fim-main */
