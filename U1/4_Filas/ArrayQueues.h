#include <stdio.h>
#include <stdlib.h>

typedef int bool;
struct array_queue
{
  int *vector;
  int size;
  int lenght;
  int front;
  int rear;
};

struct array_queue *initialize(int size)
{
  struct array_queue *queue = (struct array_queue *)malloc(sizeof(struct array_queue));

  queue->vector = (int *)calloc(size, sizeof(int));
  queue->size   = size;
  queue->lenght =  0;
  queue->front  = -1;
  queue->rear   = -1;

  return queue;
}

//Ler o elemento da frente da fila
int peek(struct array_queue *queue)//@audit-info
{
  return queue->vector[queue->front];
}

//Contar os elementos de uma fila: 
int len(struct array_queue *queue)//@audit-info
{
  return queue->lenght;
}

//Perguntar se a fila está vazia: 
bool empty(struct array_queue *queue)//@audit-info
{
  return (queue->rear == -1 && queue->front == -1);
}

//Perguntar se a fila está cheia (caso haja limite):
bool full(struct array_queue *queue)//@audit-info
{
  return (queue->lenght == queue->size);
}

//Remover um elemento do frente da fila
void dequeue(struct array_queue *queue)//@audit
{
  if(!empty(queue))
  {
    queue->lenght--;
    queue->front = (queue->front + 1) % queue->size;

    if(queue->lenght == 0)
    {
      queue->front = -1;
      queue->rear  = -1;
    }
  }
}

//Inserir um elemento na traseira da fila
void enqueue(struct array_queue *queue, int value)//@audit
{ 
  if(queue->front == -1)
  {
    queue->front = 0;
  }

  if(full(queue))
  {
    struct array_queue *aux_queue = initialize(2 * queue->size);
    
    aux_queue->front = 0;
    aux_queue->rear  = 0;

    while(!empty(queue))
    {
      aux_queue->vector[aux_queue->rear] = peek(queue);
      aux_queue->rear = (aux_queue->rear + 1) % aux_queue->size;
      aux_queue->lenght++;

      dequeue(queue);
    }

    queue->vector = aux_queue->vector;
    queue->lenght = aux_queue->lenght;
    queue->front  = aux_queue->front;
    queue->rear   = aux_queue->rear;
    queue->size   = aux_queue->size;
  }

  queue->vector[queue->lenght] = value;
  queue->lenght++;
  queue->rear = (queue->rear + 1) % queue->size;
 }

void print_elements(struct array_queue *queue)
{
  if(queue->lenght != 0)
  {
    printf("[");

    for(int i = 0; i < queue->lenght; i++)
    {
      printf("%d", queue->vector[i + queue->front % queue->size]);

      if(i != queue->lenght - 1)
      {
        printf(", ");
      }
    }

    printf("]\n");
  }
  else
  {
    printf("A Fila está vazia\n");
  }
}