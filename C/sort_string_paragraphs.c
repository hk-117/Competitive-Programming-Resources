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
  printf("Enter the number of paragraph: ");
  scanf("%d", &n);
  getchar();

  arr = (char**)malloc(n * sizeof(char*));
  printf("Enter the paragraphs:\n");

  for(i = 0; i < n; i++){
    int len;
    fgets(buff, sizeof(buff), stdin);
    len = strcspn(buff, "\n");
    buff[len] = '\0';
    arr[i] = (char*)malloc((len+ 1) * sizeof(char));
    strcpy(arr[i], buff);
  }
  
  qsort(arr,n,sizeof(char*),compare);

  printf("Sorted elements:\n");
  for(i = 0; i < n; i++){
    printf("%s\n", arr[i]);
  }

  free(arr);
  return 0;
}
