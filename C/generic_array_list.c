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

int int_comparator(const void *a, const void *b){
  return (*(int*)a - *(int*)b);
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

void print_integer_list(List *list){
  size_t i;
  for(i = 0; i < list->length; i++){
    printf("%d ", *(int*)((char*)list->data + (i * list->item_size)));
  }
  puts("");
}

void free_list(List *list){
  free(list->data);
  list->data = NULL;
  list->length = 0;
  list->capacity = 0;
}

int main(){
  List numbers;
  int choice,n;
  int *found,*item;
  size_t i;
  init_list(&numbers, sizeof(int));

  do{
    printf("Menu:\n1. Add Item\n2. Remove Item\n3. Get Item\n4. Sort List\n5. Binary Search\n6. Print\n7. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice){
      case 1:
        printf("Enter integer to add: ");
        scanf("%d", &n);
        add_item(&numbers, &n);
        break;
      case 2:
        printf("Enter index to remove: ");
        scanf("%d", &n);
        remove_item(&numbers, n);
        break;
      case 3:
        printf("Enter index to get: ");
        scanf("%d", &n);
        item = get_item(&numbers, n);
        if(item) printf("Item at index %d: %d\n", n, *item);
        else printf("Index out of bounds\n");
        break;
      case 4:
        sort_list(&numbers, int_comparator);
        printf("List sorted.\n");
        break;
      case 5:
        printf("Enter integer to search: ");
        scanf("%d", &n);
        found = binary_search(&numbers, &n, int_comparator);
        if(found) printf("Item %d found.\n", n);
        else printf("Item %d not found.\n", n);
        break;
      case 6:
        printf("List items: ");
        print_integer_list(&numbers);
        break;
      case 7:
        free_list(&numbers);
        printf("Exiting...\n");
        break;
      default:
        printf("Invalid choice. Try again.\n");
        break;
    }

  }while(choice != 7);

}
