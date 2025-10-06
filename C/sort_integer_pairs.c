#include<stdio.h>
#include<stdlib.h>

typedef struct Point{
  int x;
  int y;
} Point;

int compare(const void *a, const void *b){
  Point *pointA = (Point*)a;
  Point *pointB = (Point*)b;

  if(pointA->x != pointB->x){
    return pointA->x - pointB->x;
  } else {
    return pointA->y - pointB->y;
  }
}

int main(){
  int n, i;
  Point *points;
  printf("Enter the number of points: ");
  scanf("%d", &n);

  points = (Point*)malloc(n * sizeof(Point));
  printf("Enter the points:\n");

  for(i = 0; i < n; i++){
    scanf("%d %d", &points[i].x, &points[i].y);
  }
  
  qsort(points,n,sizeof(Point),compare);

  printf("Sorted elements:\n");
  for(i = 0; i < n; i++){
    printf("(%d, %d)\n", points[i].x, points[i].y);
  }

  free(points);
  return 0;
}
