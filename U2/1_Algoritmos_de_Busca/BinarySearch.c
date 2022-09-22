#include <stdio.h>
#include <stdlib.h>
#include "../../U1/2_Listas/ArrayLists.h"

typedef int bool;

bool binary_search(struct array_list *list, int value)
{
  int start = 0;
  int end   = list->lenght - 1;
  int half;

  while (start < end - 1)
  {
    half = (start + end) / 2;

    if(list->vector[half] == value)
    {
      return 1;
    }
    else if (value > list->vector[half])
    {
      start = half;
    }
    else
    {
      end = half;
    }
  }

  return 0;
}

int main()
{
  struct array_list *list = initialize(5);
  
  insert_element(list, 2);
  insert_element(list, 5);
  insert_element(list, 7);
  insert_element(list, 9);
  insert_element(list, 20);

  printf("%d", binary_search(list, 11));

  return 0;
}