#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void sort(int *vet, int len){
  long ifs = 0, swaps = 0;

  for (int i = 1; i < len; i++) {
    int temp = vet[i];
    int j = i-1;

    ifs += 1;
    while(j >= 0 && vet[j] > temp) {
      ifs += 1;
      vet[j+1] = vet[j];
      j--;
    }
    
    vet[j+1] = temp;
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

  sort(vet, n);

  gettimeofday(&stop, NULL);
  printf("Time: %f\n", (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec)); 

  return 0;
}