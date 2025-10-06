#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Book{
  char *title;
  char *author;
} Book;

int compare(const void *a, const void *b){
  Book *bookA = (Book*)a;
  Book *bookB = (Book*)b;
  if(strcmp(bookA->title, bookB->title) == 0){
    return strcmp(bookA->author, bookB->author);
  }
  return strcmp(bookA->title, bookB->title);
}

int main(){
  int n, i;
  Book *books;
  char bffr[1005];
  printf("Enter the number of Books: ");
  scanf("%d", &n);
  getchar();

  books = (Book*)malloc(n * sizeof(Book));
  printf("Enter the Book Details:\n");

  for(i = 0; i < n; i++){
    char *pos;
    fgets(bffr, 1005 * sizeof(char), stdin);
    bffr[strcspn(bffr, "\n")] = 0;
    pos = strstr(bffr, " by ");
    *pos = '\0';
    pos += 4;
    books[i].title = (char*)malloc((strlen(bffr) + 1) * sizeof(char));
    books[i].author = (char*)malloc((strlen(pos) + 1) * sizeof(char));
    strcpy(books[i].title, bffr);
    strcpy(books[i].author, pos);
  }
  
  qsort(books,n,sizeof(Book),compare);

  printf("Sorted elements:\n");
  for(i = 0; i < n; i++){
    printf("%s :: %s\n", books[i].title, books[i].author);
    free(books[i].title);
    free(books[i].author);
  }
  free(books);
  return 0;
}
