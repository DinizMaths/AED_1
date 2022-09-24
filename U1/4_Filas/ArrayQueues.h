#include <stdio.h>
#include <stdlib.h>

typedef int bool;
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

void double_size(struct array_queue *queue)
{
  queue->vector = (int *)realloc(queue->vector, 2 * queue->size * sizeof(int));
  queue->size   = 2 * queue->size;
}

void push(struct array_queue *queue, int value)
{
  if(queue->lenght == queue->size)
  {
    double_size(queue);
  }

  queue->vector[queue->lenght] = value;
  queue->lenght++;
}

void pop(struct array_queue *queue)
{
  for(int i = 0; i < queue->lenght - 1; i++)
  {
    queue->vector[i] = queue->vector[i + 1];
  }

  queue->lenght--;
}

int peek(struct array_queue *queue)
{
  return queue->vector[0];
}

int len(struct array_queue *queue)
{
  return queue->lenght;
}

bool empty(struct array_queue *queue)
{
  return queue->lenght == 0;
}

bool full(struct array_queue *queue)
{
  return queue->lenght == queue->size;
}

void print_elements(struct array_queue *queue)
{
  if(queue->lenght != 0)
  {
    printf("[");

    for(int i = 0; i < queue->lenght; i++)
    {
      printf("%d", queue->vector[i]);

      if(i != queue->lenght - 1)
      {
        printf(", ");
      }
    }

    printf("]\n");
  }
  else
  {
    printf("A fila está vazia\n");
  }
}