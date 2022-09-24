#include "ArrayStacks.h"

int main()
{
  struct array_stack *stack = initialize(2);

  push(stack, 5);
  push(stack, 9);
  push(stack, 25);

  print_elements(stack);

  printf("%d\n", top(stack));

  pop(stack);
  pop(stack);

  print_elements(stack);

  printf("%d\n", empty(stack));
  printf("%d\n", len(stack));

  printf("%d\n", top(stack));

  pop(stack);
  print_elements(stack);

  return 0;
}