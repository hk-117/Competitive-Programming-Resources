#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int compare(const void *a, const void *b){
  return strcmp(*(const char **)a, *(const char **)b);
}

int main(){
  int n, i;
  char **arr;
  char buff[1005];
  printf("Enter the number of elements: ");
  scanf("%d", &n);

  arr = (char**)malloc(n * sizeof(char*));
  printf("Enter the elements:\n");

  for(i = 0; i < n; i++){
    scanf("%s", buff);
    arr[i] = (char*)malloc((strlen(buff) + 1) * sizeof(char));
    strcpy(arr[i], buff);
  }
  
  qsort(arr,n,sizeof(char*),compare);

  printf("Sorted elements:\n");
  for(i = 0; i < n; i++){
    printf("%s ", arr[i]);
  }

  printf("\n");
  free(arr);
  return 0;
}
