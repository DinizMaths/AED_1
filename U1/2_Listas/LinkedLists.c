#include "LinkedLists.h"

int main()
{
  struct linked_list* list = initialize_list();

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