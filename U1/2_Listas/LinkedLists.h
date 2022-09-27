#include <stdio.h>
#include <stdlib.h>


struct node
{
  int val;
  struct node *next;
};

struct linked_list
{
  struct node *head;
  int lenght;
};

struct node *initialize_node(int value)
{
  struct node *new_node = (struct node *)malloc(sizeof(struct node));

  new_node->val  = value;
  new_node->next = NULL;

  return new_node;
}

struct linked_list *initialize_list()
{
  struct linked_list *new_list = (struct linked_list *)malloc(sizeof(struct linked_list));

  new_list->head = NULL;
  new_list->lenght = 0;

  return new_list;
}

void print_elements(struct linked_list *list)
{
  if(list->head != NULL)
  {
    struct node *aux = list->head;

    printf("[");

    do
    {
      printf("%d", aux->val);
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

void insert_element_at_end(struct linked_list *list, int value)
{
  struct node *new_node = initialize_node(value);

  if(list->head == NULL)
  {
    list->head = new_node;
  }
  else
  {
    struct node *aux = list->head;

    while(aux->next != NULL)
    {
      aux = aux->next;
    }

    aux->next = new_node;
  }

  list->lenght++;
}

void insert_element_at_start(struct linked_list *list, int value)
{
  struct node *new_node = initialize_node(value);

  new_node->next = list->head;
  list->head     = new_node;

  list->lenght++;
}

void insert_element_in_position(struct linked_list *list, int value, int position)
{
  if(position >= 0 && position < list->lenght)
  {
    struct node *new_node = initialize_node(value), *prev, *curr;
    curr = list->head;

    for (int i = 0; i < position; i++)
    {
      prev = curr;
      curr = curr->next;
    }
    new_node->next = curr;
    prev->next = new_node;

    list->lenght++;
  }
}

int get_element(struct linked_list *list, int position)
{
  if(position >= 0 && position < list->lenght)
  {
    struct node *new_node = list->head;

    for (int i = 0; i < position; i++)
    {
      new_node = new_node->next;
    }
    
    return new_node->val;
  }
}

void remove_element_in_position(struct linked_list *list, int position)
{
  if(position >= 0 && position < list->lenght)
  {
    if(position == 0)
    {
      list->head = list->head->next;
    }
    else
    {
      struct node *curr = list->head, *prev;
      prev = curr;

      for (int i = 0; i < position; i++)
      {
        prev = curr;
        curr = curr->next;
      }

      prev->next = curr->next;

      free(curr);
      list->lenght--;
    }
  }
}

void reverse(struct linked_list *list)
{
  struct node *prev = NULL;
  struct node *curr = list->head;
  struct node *next = NULL;

  while (curr != NULL) 
  {
      next = curr->next;
      curr->next = prev;

      prev = curr;
      curr = next;
  }

  list->head = prev;
}