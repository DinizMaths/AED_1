#include <stdio.h>
#include <stdlib.h>

struct node
{
  struct node *previous;
  int val;
  struct node *next;
};

struct doubly_linked_list
{
  struct node *head;
  struct node *tail;
  int lenght;
};

struct node *initialize_node(int value)
{
  struct node *new_node = (struct node *)malloc(sizeof(struct node));

  new_node->previous = NULL;
  new_node->val = value;
  new_node->next = NULL;

  return new_node;
}

struct doubly_linked_list *initialize_list()
{
  struct doubly_linked_list *new_list = (struct doubly_linked_list *)malloc(sizeof(struct doubly_linked_list));

  new_list->head = NULL;
  new_list->lenght = 0;
  new_list->tail = NULL;

  return new_list;
}

void print_elements(struct doubly_linked_list *list)
{
  if (list->head != NULL)
  {
    struct node *aux = list->head;

    printf("[");

    do
    {
      printf("%d", aux->val);
      aux = aux->next;

      if (aux != NULL)
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

void insert_element_at_end(struct doubly_linked_list *list, int value)
{
  struct node *new_node = initialize_node(value);

  if (list->head == NULL)
  {
    list->head = new_node;
    list->tail = new_node;
  }
  else
  {
    list->tail->next = new_node;
    new_node->previous = list->tail;
    list->tail = new_node;
  }

  list->lenght++;
}

void insert_element_at_start(struct doubly_linked_list *list, int value)
{
  struct node *new_node = initialize_node(value);

  new_node->next = list->head;
  list->head = new_node;

  list->lenght++;
}

void insert_element_in_position(struct doubly_linked_list *list, int value, int position)
{
  if (position >= 0 && position < list->lenght)
  {
    struct node *new_node = initialize_node(value), *prev, *curr;
    curr = list->head;

    for (int i = 0; i < position; i++)
    {
      prev = curr;
      curr = curr->next;
    }

    curr->previous = new_node;
    new_node->next = curr;

    prev->next = new_node;
    new_node->previous = prev;

    list->lenght++;
  }
}

int get_element(struct doubly_linked_list *list, int position)
{
  if (position >= 0 && position < list->lenght)
  {
    struct node *new_node = list->head;

    for (int i = 0; i < position; i++)
    {
      new_node = new_node->next;
    }

    return new_node->val;
  }
}

void remove_element_in_position(struct doubly_linked_list *list, int position)
{
  if (position >= 0 && position < list->lenght)
  {
    struct node *temp;

    if (position == 0)
    {
      temp = list->head;
      list->head = list->head->next;
      list->head->previous = NULL;

      free(temp);
    }
    else if (position == list->lenght - 1)
    {
      temp = list->tail;
      list->tail = list->tail->previous;
      list->tail->next = NULL;

      free(temp);
    }
    else
    {
      struct node *curr = list->head;

      for (int i = 0; i < position; i++)
      {
        curr = curr->next;
      }

      curr->next->previous = curr->previous;
      curr->previous->next = curr->next;

      free(curr);
      list->lenght--;
    }
  }
}

void reverse(struct doubly_linked_list *list)//@audit
{
  struct node *temp;
  struct node *curr = list->head;

  while(curr != NULL)
  {
    temp = curr->previous;
    curr->previous = curr->next;
    curr->next = temp;
    curr = curr->previous;
  }

  if(temp != NULL)
  {
    list->head = temp->previous;
  }
}