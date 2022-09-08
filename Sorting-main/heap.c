#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void swap(int *vet, int a, int b) {
  int tmp = vet[b];
  vet[b] = vet[a];
  vet[a] = tmp;
}

void heap(int *vet, int i, int n) {
  int top = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && vet[left] > vet[top])
    top = left;

  if (right < n && vet[right] > vet[top])
    top = right;

  if (top != i){
    swap(vet, i, top);
    heap(vet, top, n);
  }
}

void sort(int *vet, int n){
  for (int k = n / 2 - 1; k >= 0; k--)
    heap(vet, k, n);

  for (int k = n-1; k >= 1; k--) {
    swap(vet, 0, k);
    heap(vet, 0, k);
  }
}

int main() {
  struct timeval start, stop;
  gettimeofday(&start, NULL);

  int n;
  int *vet;

  scanf("%d", &n);

  vet = malloc(n*sizeof(int));

  for (int i = 0; i < n; i++) scanf("%d", &vet[i]);

  sort(vet, n);

  gettimeofday(&stop, NULL);
  printf("Time: %f\n", (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec)); 

  return 0;
}