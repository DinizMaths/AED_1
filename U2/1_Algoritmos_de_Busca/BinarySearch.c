#include "BinarySearch.h"

int main()
{
  struct array_list *list = initialize(5);
  
  insert_element(list, 2);
  insert_element(list, 5);
  insert_element(list, 7);
  insert_element(list, 9);
  insert_element(list, 20);

  print_elements(list);

  printf("%d\n", binary_search(list,  2));
  printf("%d\n", binary_search(list, 20));
  printf("%d\n", binary_search(list, 11));
  printf("%d\n", binary_search(list, 30));
  printf("%d\n", binary_search(list,  9));

  printf("%d\n", new_position(list,  11));
  printf("%d\n", new_position(list,   3));
  printf("%d\n", new_position(list,   5));
  printf("%d\n", new_position(list,   1));
  printf("%d\n", new_position(list,  30));

  return 0;
}