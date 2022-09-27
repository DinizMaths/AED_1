#include <stdio.h>
#include <stdlib.h>

typedef int bool;
struct array_queue
{
  int *vector;
  int size;
  int lenght;
  int front;
  int back;
};

struct array_queue *initialize(int size)
{
  struct array_queue *queue = (struct array_queue *)malloc(sizeof(struct array_queue));

  queue->vector = (int *)calloc(size, sizeof(int));
  queue->size   = size;
  queue->lenght =  0;
  queue->front  = -1;
  queue->back   = -1;

  return queue;
}

//Inserir um elemento na traseira da fila
void push(struct array_queue *queue)//@audit
{
  
}

//Remover um elemento do frente da fila
void pop(struct array_queue *queue)//@audit
{}

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
  return (queue->back == -1 && queue->front == -1);
}

//Perguntar se a fila está cheia (caso haja limite):
bool full(struct array_queue *queue)//@audit-info
{
  return (queue->lenght == queue->size);
}