#include <stdio.h>
#include <stdlib.h>

struct array_queue
{
  int *vector;
  int size;
  int lenght;
};

struct array_queue *initialize(int size)
{
  struct array_queue *queue = (struct array_queue *)malloc(sizeof(struct array_queue));

  queue->vector = (int *)calloc(size, sizeof(int));
  queue->lenght = 0;
  queue->size   = size;

  return queue;
}