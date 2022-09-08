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
  list->vector = (int *)realloc(list->vector, 2 * list->size * sizeof(int));
  list->size   = 2 * list->size;
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

void insert_element_in_position(struct array_list *list, int value, int position)
{
  if(position >= 0 && position < list->lenght)
  {
    if(list->lenght == list->size)
    {
      double_size(list);
    }

    for(int i = list->lenght; i > position; i--)
    {
      list->vector[i] = list->vector[i - 1];
    }

    list->vector[position] = value;
    list->lenght++;
  }
}

void update_element(struct array_list *list, int value, int position)
{
  if(position >= 0 && position < list->lenght)
  {
    list->vector[position] = value;
  }
}

int get_lenght(struct array_list *list)
{
  return list->lenght;
}

void remove_element(struct array_list *list)
{
  list->lenght--;
}

void remove_element_in_position(struct array_list *list, int position)
{
  if(position < list->lenght && position >= 0)
  {
    while(position < list->lenght - 1)
    {
      list->vector[position] = list->vector[position + 1];
      position++;
    }

    remove_element(list);
  }
}

int get_element(struct array_list *list, int position)
{
  if(position >= 0 && position < list->lenght)
  {
    return list->vector[position];
  }
}

void print_elements(struct array_list *list)
{
  int lenght = list->lenght;

  printf("Elementos:\n");
  for(int i = 0; i < lenght; i++)
  {
    printf("%d", get_element(list, i));
    printf("\n");
  }
}

int main()
{
  struct array_list *arr = initialize(3);

  insert_element(arr, 3);
  insert_element(arr, 5);
  insert_element(arr, 6);
  insert_element(arr, 2);
  insert_element(arr, -2);

  print_elements(arr);

  insert_element_in_position(arr, 10, 4);

  print_elements(arr);

  update_element(arr, -1, 4);

  print_elements(arr);

  return 0;
};