#include <stdio.h>
#include <stdlib.h>

struct array_list
{
  int *vector; // Ponteiro para endereço
  int lenght;  // "Slots" ocupados
  int size;    // Capacidade
};

struct array_list *initialize(int size)
{
  struct array_list *list = (struct array_list *)malloc(sizeof(struct array_list));

  list->vector = (int *)calloc(size, sizeof(int));
  list->lenght = 0;
  list->size   = size;

  return list; 
};

void double_size(struct array_list *list)
{
  struct array_list *new_list = initialize(list->size);

  for(int i = 0; i < list->size; i++)
  {
    new_list[i] = list[i];
  }

  free(list);
  list = new_list;
  free(new_list);
};

void insert_element(struct array_list *list, int value)
{
  if(list->lenght == list->size)
  {
    double_size(list);
  }

  list->vector[list->lenght] = value;
  list->lenght++;
}

int get_element(struct array_list *list, int position)
{
  return list->vector[position];
}

int main()
{
  struct array_list *arr = initialize(10);

  insert_element(arr, 3);
  insert_element(arr, 5);
  insert_element(arr, 6);
  insert_element(arr, 2);
  insert_element(arr, -2);

  int lenght = arr->lenght;
  for(int i = 0; i < lenght; i++)
  {
    printf("%d", get_element(arr, i));
    printf("\n");
  }

  return 0;
};