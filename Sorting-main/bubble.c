#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void sort(int n, int *vet) {
  int tmp;
  int isOrdered = 0;
  long ifs = 0, swaps = 0;

  for (int i = n-1; i > 0; i--) {
    for (int j = 0; j < i; j++) {
      ifs += 1;
      if (vet[j] > vet[j+1]) {
        swaps += 1;
        tmp = vet[j];
        vet[j] = vet[j+1];
        vet[j+1] = tmp;
        isOrdered = 1;
      }
    }

    ifs += 1;
    if (isOrdered == 0) {
      break;
    }
  }

  printf("Comparações: %ld\n", ifs); 
  printf("Swaps: %ld\n", swaps); 
}

int main() {
  struct timeval start, stop;
  gettimeofday(&start, NULL);

  int n;
  int *vet;

  scanf("%d", &n);

  vet = malloc(n*sizeof(int));

  for (int i = 0; i < n; i++) scanf("%d", &vet[i]);

  sort(n, vet);

  gettimeofday(&stop, NULL);
  printf("Time: %f\n", (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec)); 

  return 0;
}