/*

  Created by Oğuzhan Agkuş.
  Last edit: 29.07.2018

  This is an example code to show how to use linked_list library.

*/

#include <stdio.h>
#include <stdlib.h>
#include "single_linked_list.h"

int main()
{
  node_t *head = NULL;
  head = create(6); // A head is created. It's first node has value "6".

  add_to_end(head, 5);        // Value "5" added to end.
  add_to_head(&head, 7);      // Value "7" added to head.
  add_after(head, 8, 5);      // Value "8" added after first value "5".
  add_before(&head, 3, 7);    // Value "3" added just before the first value "7".
  add_before(&head, 8, 3);    // Value "8" added just before the first value "3".
  add_after(head, 12, 5);     // Value "3" added just before the first value "7".
  add_by_index(&head, 10, 3); // Value "10" added to index "3".
  add_to_end(head, 12);       // Value "12" added to end.
  add_by_index(&head, 9, 10); // Value "20" added to index "10". This index does not exist, so it goes to end.

  printf("Count of nodes in the list : %d\n\n", find_node_count(head));

  printf("Default list :\n\n");
  print(head); // List printed.

  printf("\nReverse printed list :\n\n");
  print_reverse(head); // List printed as reversed.

  reverse(&head); // List reversed.
  printf("\nReversed list :\n\n");
  print(head);

  remove_by_value(&head, 12, 1);          // Removes all value "12".
  remove_by_value(&head, 8, 0);           // Removed first value "8".
  remove_by_index(&head, 0);              // Removed the value at in index "0".
  printf("\nSome nodes are removed.\n");

  sort(&head); // List sorted.
  printf("\nCount of nodes in the list : %d\n", find_node_count(head));
  printf("\nSorted list :\n\n");
  print(head);

  delete(head); // All nodes are free now.

  return 0;
}
