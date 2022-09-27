#include "ArrayQueues.h"

int main()
{
  struct array_queue *queue = initialize(2);

  enqueue(queue, 5);
  enqueue(queue, 9);
  enqueue(queue, 25);

  print_elements(queue);

  printf("%d\n", peek(queue));

  print_elements(queue);

  dequeue(queue);
  dequeue(queue);

  print_elements(queue);

  printf("%d\n", empty(queue));

  printf("%d\n", len(queue));

  printf("%d\n", peek(queue));

  dequeue(queue);

  print_elements(queue);
  
  return 0;
}