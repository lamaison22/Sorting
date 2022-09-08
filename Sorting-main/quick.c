#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void sort(int *vet, int first, int last){
   int i, j, pivot, tmp;

   if(first < last) {
    pivot = first;
    i = first;
    j = last;

    while(i < j) {
      while (vet[i] <= vet[pivot] && i < last) i++;
      while (vet[j] > vet[pivot]) j--;

      if (i < j) {
        tmp = vet[i];
        vet[i] = vet[j];
        vet[j] = tmp;
      }
    }

    tmp = vet[pivot];
    vet[pivot] = vet[j];
    vet[j] = tmp;

    sort(vet, first, j - 1);
    sort(vet, j + 1, last);
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

  sort(vet, 0, n - 1);

  gettimeofday(&stop, NULL);
  printf("Time: %f\n", (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec)); 

  return 0;
}