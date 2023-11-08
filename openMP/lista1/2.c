#include <stdio.h>
#include <omp.h>


// a diretiva #pragma omp atomic é usada para proteger a operação i += 10. Isso garante que cada thread complete essa operação de forma atômica antes que outra thread tente executá-la. Dessa forma, se você estiver usando 4 threads (OMP_NUM_THREADS=4), i será incrementado corretamente para 40, já que cada thread adicionará 10 de forma segura à variável compartilhada i.


int main(int argc, char *argv[]) {
  int i = 0;
  
  #pragma omp parallel shared(i)
  {
    #pragma omp atomic
    i += 10;
  }
  
  printf("i=%d\n", i);
  return 0;
}
