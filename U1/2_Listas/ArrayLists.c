#include "ArrayLists.h"


int main()
{
  struct array_list *arr = initialize(3);

  insert_element(arr, 3);
  insert_element(arr, 5);
  insert_element(arr, 6);
  insert_element(arr, 2);
  insert_element(arr, -2);

  print_elements(arr);

  insert_element_in_position(arr, 10, 4);

  print_elements(arr);

  update_element(arr, -1, 4);

  print_elements(arr);

  reverse(arr);

  print_elements(arr);

  return 0;
};