#include <stdio.h>
#include <stdlib.h>

typedef int bool;

struct node 
{
  int value;
  struct node *next;
};

struct linked_queue 
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

struct linked_queue *initialize_list()
{
  struct linked_queue *new_list = (struct linked_queue *)malloc(sizeof(struct linked_queue));

  new_list->head   = NULL;
  new_list->lenght = 0;

  return new_list;
}

int peek(struct linked_queue *queue)
{}

bool empty(struct linked_queue *queue)
{}

bool full(struct linked_queue *queue)
{}

void dequeue(struct linked_queue *queue)
{}

void enqueue(struct linked_queue *queue, int value)
{}

void print_elements(struct linked_queue *queue)
{}