#include <stdio.h>
#include <stdlib.h>

struct node
{
  int value;
  struct node *next;
};
struct linked_stack
{
  struct node *head;
  int lenght;
};

struct node *initialize_node(int value)
{
  struct node *new_node;

  new_node->value = value;
  new_node->next  = NULL;

  return new_node;
}
struct linked_stack *initialize_stack()
{
  struct linked_stack *new_stack;

  new_stack->head   = NULL;
  new_stack->lenght = 0;

  return new_stack;
}

void push(struct linked_stack *stack, int value)//@audit
{
}

void pop(struct linked_stack *stack)//@audit
{
}

int top(struct linked_stack *stack)//@audit
{
}

int len(struct linked_stack *stack)//@audit
{
}

int empty(struct linked_stack *stack)//@audit
{
}

void print_elements(struct linked_stack* stack)
{
  if(stack->head != NULL)
  {
    struct node* aux = stack->head;

    printf("[");

    do
    {
      printf("%d", aux->value);
      aux = aux->next;

      if(aux != NULL)
      {
        printf(", ");
      }
    } while (aux != NULL);

    printf("]\n");
  }
  else
  {
    printf("A lista está vaiza");
  }
}