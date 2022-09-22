#include <stdio.h>
#include <stdlib.h>
#include "../../U1/2_Listas/ArrayLists.h"


int binary_search(struct array_list *list, int value)
{
  int start = 0;
  int end   = list->lenght - 1;
  int half;

  while(start <= end)
  {
    half = (start + end) / 2;

    if(value == list->vector[half])
    {
      return 1;
    }
    else if(value > list->vector[half])
    {;
      start = half + 1;
    }
    else
    {
      end = half - 1;
    }
  }

  return 0;
}
