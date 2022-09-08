#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void countSort(int n, int exp, int *vet) {
  int *a = malloc(n*sizeof(int));
  int count[10] = { 0 };

  for (int i = 0; i < n; i++)
    count[(vet[i] / exp) % 10]++;

  for (int i = 1; i < 10; i++)
    count[i] += count[i - 1];

  for (int i = n - 1; i >= 0; i--) {
    count[(vet[i] / exp) % 10]--;
    a[count[(vet[i] / exp) % 10]] = vet[i];
  }

  for (int i = 0; i < n; i++)
    vet[i] = a[i];
}

void sort(int n, int *vet) {
  int max = vet[0];

  for (int i = 1; i < n; i++)
    if (vet[i] > max) max = vet[i];

  for (int exp = 1; max / exp > 0; exp *= 10)
    countSort(n, exp, vet);
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