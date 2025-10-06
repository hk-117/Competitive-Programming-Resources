#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INITIAL_CAPACITY 2

typedef struct List{
  void *data;
  size_t item_size;
  size_t length;
  size_t capacity;
}List;

void init_list(List *list, size_t item_size){
  list->data = malloc(item_size * INITIAL_CAPACITY);
  list->item_size = item_size;
  list->length = 0;
  list->capacity = 2;
}

int string_comparator(const void *a, const void *b){
  return strcmp((char*)a, (char *)b);
}

void add_item(List *list, void *item){
  if(list->length == list->capacity){
    list->capacity *= 2;
    list->data = realloc(list->data, list->item_size * list->capacity);
  }
  memcpy((char*)list->data + (list->length * list->item_size), item, list->item_size);
  list->length++;
}

void remove_item(List *list, size_t index){
  if(index >= list->length) return;
  memmove((char*)list->data + (index * list->item_size), 
          (char*)list->data + ((index + 1) * list->item_size), 
          (list->length - index - 1) * list->item_size);
  list->length--;
}

void *get_item(List *list, size_t index){
  if(index >= list->length) return NULL;
  return (char*)list->data + (index * list->item_size);
}

void sort_list(List *list, int (*comparator)(const void*, const void*)){
  qsort(list->data, list->length, list->item_size, comparator);
}

void *binary_search(List *list, void *key, int (*comparator)(const void*, const void*)){
  return bsearch(key, list->data, list->length, list->item_size, comparator);
}

void print_string_list(List *list){
  size_t i;
  for(i = 0; i < list->length; i++){
    char *item = (char*)list->data + (i * list->item_size);
    printf("%s ", item);
  }
  printf("\n");
}

void free_list(List *list){
  free(list->data);
  list->data = NULL;
  list->length = 0;
  list->capacity = 0;
}

int main(){
  List words;
  int choice,n;
  char word[50];
  char *found,*item;
  size_t i;
  init_list(&words, sizeof(char *));

  do{
    printf("Menu:\n1. Add Item\n2. Remove Item\n3. Get Item\n4. Sort List\n5. Binary Search\n6. Print\n7. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice){
      case 1:
        printf("Enter string to add: ");
        getchar();
        scanf("%s", word);
        add_item(&words, &word);
        break;
      case 2:
        printf("Enter index to remove: ");
        scanf("%d", &n);
        remove_item(&words, n);
        break;
      case 3:
        printf("Enter index to get: ");
        scanf("%d", &n);
        item = get_item(&words, n);
        if(item) printf("Item at index %d: %s\n", n, item);
        else printf("Index out of bounds\n");
        break;
      case 4:
        sort_list(&words, string_comparator);
        printf("List sorted.\n");
        break;
      case 5:
        printf("Enter word to search: ");
        getchar();
        scanf("%s", word);
        found = binary_search(&words, word, string_comparator);
        if(found) printf("Item %s found.\n", word);
        else printf("Item %s not found.\n", word);
        break;
      case 6:
        printf("List items: ");
        print_string_list(&words);
        break;
      case 7:
        free_list(&words);
        printf("Exiting...\n");
        break;
      default:
        printf("Invalid choice. Try again.\n");
        break;
    }

  }while(choice != 7);

}
