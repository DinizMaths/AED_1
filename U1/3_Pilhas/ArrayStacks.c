#include "ArrayStacks.h"

int main()
{
  struct array_stack *stack = initialize(2);

  push(stack, 5);
  push(stack, 9);
  push(stack, 25);

  print_elements(stack);

  printf("%d", top(stack));

  pop(stack);
  pop(stack);

  print_elements(stack);

  printf("%d", empty(stack));
  printf("%d", len(stack));

  printf("%d", top(stack));

  pop(stack);
  print_elements(stack);

  return 0;
}