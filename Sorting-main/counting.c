#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void sort(int n, int k, int *vet) {
  int *a = (int*)calloc(k + 1, sizeof(int));

  for (int i = 0; i < n; i++) a[vet[i]]++;

  for (int i = 0; i < k + 1; i++) {
    for (int j = 0; j < a[i]; j++) {
      printf("%d ", i);
    }
  }
}

int main() {
  struct timeval start, stop;
  gettimeofday(&start, NULL);

  int n;
  int k;
  int *vet;

  scanf("%d", &n);
  scanf("%d", &k);

  vet = malloc(n*sizeof(int));

  for (int i = 0; i < n; i++) scanf("%d", &vet[i]);

  sort(n, k, vet);

  gettimeofday(&stop, NULL);
  printf("\nTime: %f\n", (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec)); 

  return 0;
}