#include<stdio.h>
#include<stdlib.h>

int compare(const void *a, const void *b){
  return (*(int*)a - *(int*)b);
}

int main(){
  int n, *arr, i;

  printf("Enter the number of elements: ");
  scanf("%d", &n);

  arr = (int*)malloc(n * sizeof(int));
  printf("Enter the elements:\n");

  for(i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }
  
  qsort(arr,n,sizeof(int),compare);

  printf("Sorted elements:\n");
  for(i = 0; i < n; i++){
    printf("%d ", arr[i]);
  }

  printf("\n");
  free(arr);
  return 0;
}
