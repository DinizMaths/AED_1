#include <stdio.h>
#include <stdlib.h>


struct node
{
  struct node* previous;
  int val;
  struct node* next;
};
 
struct doubly_linked_list
{
  struct node* head;
  struct node* tail;
  int lenght;
};

struct node* initialize_node(int value)
{
  struct node* new_node = (struct node*)malloc(sizeof(struct node));

  new_node->previous = NULL;
  new_node->val      = value;
  new_node->next     = NULL;

  return new_node;
}

struct doubly_linked_list* initialize_list()
{
  struct doubly_linked_list* new_list = (struct doubly_linked_list*) malloc(sizeof(struct doubly_linked_list));

  new_list->head = NULL;
  new_list->lenght = 0;
  new_list->tail = NULL;

  return new_list;
}

void print_elements(struct doubly_linked_list* list)
{
  if(list->head != NULL)
  {
    struct node* aux = list->head;

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
    printf("A lista está vaiza");
  }
}

void insert_element_at_end(struct doubly_linked_list* list, int value)
{
  struct node *new_node = initialize_node(value);

  if(list->head == NULL)
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
  list->head     = new_node;

  list->lenght++;
}

void insert_element_in_position(struct doubly_linked_list *list, int value, int position)
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

    curr->previous = new_node;
    new_node->next = curr;

    prev->next = new_node;
    new_node->previous = prev;

    list->lenght++;
  }
}

int get_element(struct doubly_linked_list *list, int position)
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

void remove_element_in_position(struct doubly_linked_list *list, int position)//@audit
{
  if(position >= 0 && position < list->lenght)
  {
    if(position == 0)
    {
      list->head = list->head->next;
    }
    else
    {
      struct node* curr = list->head, *prev;
      prev = curr;

      for (int i = 0; i < position; i++)
      {
        prev = curr;
        curr = curr->next;
      }

      if(curr->next != NULL)
      {
        curr->next->previous = curr->previous;
      }

      prev->next = curr->next;

      free(curr);
      list->lenght--;
    }
  }
}

int main()
{
  struct doubly_linked_list* list = initialize_list();

  insert_element_at_end(list, 2);
  insert_element_at_end(list, 3);

  print_elements(list);

  insert_element_at_start(list, 1);

  print_elements(list);

  insert_element_in_position(list, 7, 1);

  print_elements(list);

  printf("%d\n", get_element(list, 0));

  remove_element_in_position(list, 3);

  print_elements(list);

  return 0;
};