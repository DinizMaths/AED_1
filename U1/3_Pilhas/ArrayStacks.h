#include <stdio.h>
#include <stdlib.h>

typedef int bool;

struct array_stack
{
  int *vector;
  int lenght;
  int size;
};

struct array_stack *initialize(int size)
{
  struct array_stack *stack = (struct array_stack *) malloc(sizeof(struct array_stack));
  
  stack->vector = (int *)calloc(size, sizeof(int));
  stack->lenght = 0;
  stack->size   = size;

  return stack;
}

void double_size(struct array_stack *stack)
{
  stack->vector = (int *)realloc(stack->vector, 2 * stack->size * sizeof(int));
  stack->size   = 2 * stack->size;
};

void push(struct array_stack *stack, int value)
{
  int top_position = stack->lenght - 1;

  if(stack->lenght == stack->size)
  {
    double_size(stack);
  }

  stack->vector[top_position] = value;
  stack->lenght++;
}

void pop(struct array_stack *stack)
{
  stack->lenght--;
}

int top(struct array_stack *stack)
{
  int top_position = stack->lenght - 1;

  return stack->vector[top_position];
}

int len(struct array_stack *stack)
{
  return stack->lenght;
}

bool empty(struct array_stack *stack)
{
  return stack->lenght == 0;
}

void print_elements(struct array_stack *stack)
{
  int lenght = stack->lenght;

  printf("Elementos:\n");
  for(int i = 0; i < lenght; i++)
  {
    printf("%d", stack->vector[i]);
    printf("\n");
  }
}