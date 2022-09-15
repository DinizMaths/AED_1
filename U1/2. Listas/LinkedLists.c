#include <stdio.h>
#include <stdlib.h>


struct node
{
  int val;
  struct node* next;
};

struct linked_list
{
  struct node* head;
  int lenght;
};

struct node* initialize_node(int value)
{
  struct node* new_node = (struct node*)malloc(sizeof(struct node));

  new_node->val  = value;
  new_node->next = NULL;

  return new_node;
}

struct linked_list* initialize_list()
{
  struct linked_list* new_list = (struct linked_list*) malloc(sizeof(struct linked_list));

  new_list->head = NULL;
  new_list->lenght = 0;

  return new_list;
}

void print_elements(struct linked_list* list)
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

void insert_element_at_end(struct linked_list* list, int value)
{
  struct node* new_node = initialize_node(value);

  if(list->head == NULL)
  {
    list->head = new_node;
  }
  else
  {
    struct node* aux = list->head;

    while(aux->next != NULL)
    {
      aux = aux->next;
    }

    aux->next = new_node;

    list->lenght++;
  }
}

void insert_element_at_start(struct linked_list *list, int value)
{
  struct node* new_node = initialize_node(value);

  new_node->next = list->head;
  list->head     = new_node;
}

void insert_element_in_position(struct linked_list *list, int value, int position)//@audit
{
  if(position >= 0 && position < list->lenght)
  {
    struct node* new_node = initialize_node(value), *aux;
    new_node = list->head;

    for (int i = 0; i < position; i++)
    {
      aux = new_node;
      new_node = new_node->next;
    }
    new_node->next = new_node;
    aux->next = new_node;

    list->lenght++;
  }
}

void get_element(struct linked_list *list, int position)//@audit
{

}

void remove_element_in_position(struct linked_list *list, int position)//@audit
{

}

int main()
{
  struct linked_list* list = initialize_list();

  insert_element_at_end(list, 2);
  insert_element_at_end(list, 3);

  print_elements(list);

  insert_element_at_start(list, 1);

  print_elements(list);

  insert_element_in_position(list, 7, 2);

  print_elements(list);

  return 0;
};