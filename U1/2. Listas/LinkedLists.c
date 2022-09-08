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

void print_elements(struct linked_list *list)
{
  if(list->head != NULL)
  {
    struct node *aux = list->head;

    printf("[");

    do
    {
        printf("%d\n", aux->val);
        printf(", ");

        aux = aux->next;
    } while (aux != NULL);

    printf("]");
  }
  else
  {
    printf("A lista está vaiza");
  }
}

void insert_element_at_end(struct linked_list *list, int value)
{

}

void insert_element_at_start(struct linked_list *list, int value)
{

}

void insert_element_in_position(struct linked_list *list, int value, int position)
{

}

void get_element(struct linked_list *list, int position)
{

}

void remove_element_in_position(struct linked_list *list, int position)
{

}

int main()
{

  return 0;
};