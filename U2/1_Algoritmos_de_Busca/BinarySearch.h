#include <stdio.h>
#include <stdlib.h>
#include "../../U1/2_Listas/ArrayLists.h"

typedef int bool;

int binary_search(struct array_list *list, int value, bool find_position)
{
  int start = 0;
  int end   = list->lenght - 1;
  int half;

  while(start <= end)
  {
    half = (start + end) / 2;

    if(value == list->vector[half])
    {
      if(find_position)
      {
        printf("Nova Posicao: ");

        return half + 1;
      }
      else
      {
        return 1;
      }
    }
    else if(value > list->vector[half])
    {
      start = half + 1;
    }
    else
    {
      end = half - 1;
    }
  }

  if(find_position)//@audit
  {
    if(value > list->vector[half])
    {
      printf("Nova Posicao: ");

      return half + 1;
    }
    else
    {
      printf("Nova Posicao: ");

      return half - 1;
    }
  }
  else
  {
    return 0;
  }
}

