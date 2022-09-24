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
  struct node *new_node = (struct node *)malloc(sizeof(struct node));

  new_node->value = value;
  new_node->next  = NULL;

  return new_node;
}
struct linked_stack *initialize_stack()
{
  struct linked_stack *new_stack = (struct linked_stack *)malloc(sizeof(struct linked_stack));

  new_stack->head   = NULL;
  new_stack->lenght = 0;

  return new_stack;
}

void push(struct linked_stack *stack, int value)
{
  struct node *new_node = initialize_node(value);

  if(stack->head == NULL)
  {
    stack->head = new_node;
  }
  else{
    struct node *curr = stack->head;

    while(curr->next != NULL)
    {
      curr = curr->next;
    }

    curr->next = new_node;
  }

  stack->lenght++;
}

void pop(struct linked_stack *stack)
{
  if(stack->lenght == 1)
  {
    stack->head = NULL;
  }
  else
  {
    struct node *curr = stack->head, *prev;
    prev = curr;

    while(curr->next != NULL)
    {
      prev = curr;
      curr = curr->next;
    }

    prev->next = NULL;

    free(curr);
  }

  stack->lenght--;
}

int top(struct linked_stack *stack)
{
  if(stack->lenght != 0)
  {
    struct node *curr = stack->head;

    while(curr->next != NULL)
    {
      curr = curr->next;
    }

    return curr->value;
  }
}

int len(struct linked_stack *stack)
{
  return stack->lenght;
}

int empty(struct linked_stack *stack)
{
  return stack->lenght == 0;
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
    printf("A lista está vazia\n");
  }
}