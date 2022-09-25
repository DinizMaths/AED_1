#include <stdio.h>
#include <stdlib.h>
#include "../../U1/2_Listas/ArrayLists.h"

typedef int bool;

int binary_search(struct array_list *list, int value)
{
  int start = 0;
  int end   = list->lenght - 1;

  while(start <= end)
  {
    int middle       = (start + end) / 2;
    int middle_value = list->vector[middle];

    if(value == middle_value)
    {
      return middle;
    }
    else if(value > middle_value)
    {
      start = middle + 1;
    }
    else{
      end = middle - 1;
    }
  }

  return -1;
}

int new_position(struct array_list *list, int value)
{
  if(binary_search(list, value) == -1)
  {
    int start = 0;
    int end   = list->lenght - 1;

    while(start <= end)
    {
      int start_value  = list->vector[start];
      int end_value    = list->vector[end];
      
      int middle       = (start + end) / 2;
      int middle_value = list->vector[middle];

      if(value < start_value)
      {
        return start;
      }
      else if(value > end_value)
      {
        return end + 1;
      }
      else if(value > middle_value)
      {
        start = middle + 1;
      }
      else{
        end = middle - 1;
      }
    }
  }
  else
  {
    return binary_search(list, value) + 1;
  }
}