#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node_bst {
  int value;
  struct node_bst *left;
  struct node_bst *right;
};

struct binary_search_tree {
  struct node_bst *root;
  int lenght;
};

struct node_bst *initialize_node_bst(int value)
{
  struct node_bst *new_node_bst = (struct binary_search_tree *)malloc(sizeof(struct node_bst));

  new_node_bst->value = value;
  new_node_bst->left  = NULL;
  new_node_bst->right = NULL;

  return new_node_bst;
}

struct binary_search_tree *initialize_binary_search_tree()
{
  struct binary_search_tree *new_binary_search_tree = (struct binary_search_tree *)malloc(sizeof(struct binary_search_tree));

  new_binary_search_tree->root   = NULL;
  new_binary_search_tree->lenght = 0;

  return new_binary_search_tree;
}

//Problema com duplicatas
//Problema com tamanho
void insert_node_bst(struct binary_search_tree *tree, struct node_bst *node)//@audit
{
  if(tree->root == NULL)
  {
    tree->root = node;
  }
  else
  {
    struct node_bst *aux = tree->root;
    int value_to_insert  = node->value;

    while(aux != NULL)
    {
      if(value_to_insert >= aux->value)
      {
        aux = aux->right;
      }
      else
      {
        aux = aux->left;
      }
    }

    aux = node;
  }
}

bool search_value(struct binary_search_tree *tree, int value_to_find)
{
  bool founded         = false;
  struct node_bst *aux = tree->root;

  printf("TESTE: %d\n", aux == NULL);

  while(aux != NULL)
  {
    if(aux->value == value_to_find)
    {
      founded = true;

      break;
    }
    else if(value_to_find > aux->value)
    {
      printf("DIR");
      aux = aux->right;
    }
    else
    {
      printf("ESQ");
      aux = aux->left;
    }
  }

  return founded;
}

void navigate(struct node_bst *node)
{
  struct node_bst *aux = node;

  if(aux != NULL)
  {
    //PRE linhas de cima para baixo
    printf("%d, ", aux->value);
    navigate(aux->left);
    navigate(aux->left);

    //IN menor para maior
    // navigate(aux->left);
    // printf("%d, ", aux->valu);
    // navigate(aux->left);

    //POS linhas de baixo pra cima
    // navigate(aux->left);
    // navigate(aux->left);
    // printf("%d, ", aux->valu);
  }
}

int main()
{
  struct binary_search_tree *tree = initialize_binary_search_tree();
  struct node_bst *node_bst = initialize_node_bst(3);

  insert_node_bst(tree, node_bst);

  navigate(tree->root);

  printf("%d\n", search_value(tree, 4));
  printf("%d\n", search_value(tree, 3));

  return 0;
}