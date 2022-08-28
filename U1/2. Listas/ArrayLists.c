#include <stdio.h>
#include <stdlib.h>

struct ArrayList
{
  int *vector; // Ponteiro para endereço
  int lenght; // "Slots" ocupados
  int size;   // Capacidade
};

struct ArrayList *initialize(int size)
{
  struct ArrayList *list = (struct ArrayList *)malloc(sizeof(struct ArrayList));

  list->vector = (int *)calloc(size, sizeof(int));
  list->lenght = 0;
  list->size   = size;

  return list; 
};

void double_size()
{

};

int main()
{


  return 0;
};