/*

  Created by Oğuzhan Agkuş.
  Last edit: 29.07.2018

  This library created by Oguzhan Agkus.
  You can use it in your project.
  If you find a bug, you can contact me from "agkusoguzhan@gmail.com"
  Necessary explanation are given below. Example code is exist in the folder.
  Informations about each function are given above the function.

*/

#include <stdio.h>
#include <stdlib.h>
#include "single_linked_list.h"

/*

  "create" function basicly create a head for linked_list.
  It takes a value as parameter.

  Firstly it allocates memory for first node.
  Then assign the parameter to first node's value.
  Finally returns head's adress.

  You must use this function!

*/

node_t *create(double value)
{
  node_t *head;
  head = (node_t *)malloc(sizeof(node_t));

  head->value = value;
  head->next = NULL;

  return head;
}

/*

  "reverse" function reverse the list.
  It takes adress of head as parameter.

  Head node becomes end node, end node becomes head node.
  For example at the beginngig the list is : 2-14-3-5-1-7
  Then it becomes : 7-1-5-3-14-2

  You can use it after sort the list.
  You can make it smallest to biggest or biggest to smallest.

*/

void reverse(node_t **head)
{
  node_t *current, *next, *previous;
  current = *head;
  previous = NULL; // It is null firstly, beacuse the first node has no previous node.

  while(current != NULL)
  {
    next = current->next;
    current->next = previous;
    previous = current;
    current = next;
  }

  *head = previous;
}

/*

  "sort" function sorts the list from smallest to biggest.
  It takes adress of head as parameter.

  It works with helper fucntions.
  Working principle is :
  Finds the smallest node in the list. Adds it to a new list.
  Then it is deleted from current list.
  It continues until all nodes are added to new list and deleted from old list.
  Finally the old list became empty. Then the new head should the new list's head.

  If you want to sort biggest to smallest, after this function you should use "reverse" function

*/

void sort(node_t **head)
{
  node_t *current, *sorted_head;
  current = *head;
  sorted_head = NULL;

  int node_count, i;
  node_count = find_node_count(current);

  double smallest;

  for(i = 0; i < node_count; i++)
  {
      smallest = current->value;

      while(current != NULL)
      {
        if(current->value < smallest)
          smallest = current->value;

        current = current->next;
      }

      if(sorted_head == NULL)
        sorted_head = create(smallest);

      else
        add_to_end(sorted_head, smallest);

      remove_by_value(&(*head), smallest, 1);

      current = *head;
  }

  *head = sorted_head;
}

/*

  "print" function prints the list.
  It takes head as parameter.

*/

void print(node_t *head)
{
  if(head == NULL)
    return;

  printf("%.2lf\n",head->value);

  print(head->next);
}

/*

  "print_reverse" function prints the list from reverse.
  It takes head as parameter.

  First node is printed last.
  End node is printed first.

*/

void print_reverse(node_t *head)
{
  if(head == NULL)
    return;

  print_reverse(head->next);

  printf("%.2lf\n",head->value);
}

/*

  "find_node_count" function finds count of nodes in the list and returns the count.
  It takes head as parameter.

*/

int find_node_count(node_t *head)
{
  int count = 0;

  node_t *current;
  current = head;

  while(current != NULL)
  {
    count++;
    current = current->next;
  }

  return count;
}

/*

  "add_to_end" function add a node to end of the list.
  It takes head and a value as parameters respectively.
  If the operation is successful, it returns "0", otherwise "1";
  If the head is null, it returns "1" too.

*/

int add_to_end(node_t *head, double value)
{
  if(head == NULL)
    return 1;

  node_t *current;
  current = head;

  while(current->next != NULL)
    current = current->next;

  current->next = (node_t *)malloc(sizeof(node_t));
  current->next->value = value;
  current->next->next = NULL;

  return 0;
}

/*

  "add_to_head" function add a node to head of the list.
  It takes adress of head and a value as parameters respectively.
  If the operation is successful, it returns "0", otherwise "1";
  If the head is null, it returns "1" too.

*/

int add_to_head(node_t **head, double value)
{
  if(*head == NULL)
    return 1;

  node_t *new;
  new = (node_t *)malloc(sizeof(node_t));
  new->value = value;
  new->next = *head;

  *head = new;

  return 0;
}

/*

  "add_after" function add a node just after the first node that has the given value.
  It takes head, a value and target as parameters respectively.
  If the operation is successful, it returns "0", otherwise "1";
  If the head is null, it returns "1" too.
  If the target does not exist in the list, it returns "1".

*/

int add_after(node_t *head, double value, double target)
{
  if(head == NULL)
    return 1;

  node_t *current, *new;
  current = head;

  while(current != NULL)
  {
    if(current->value == target)
    {
      new = (node_t *)malloc(sizeof(node_t));
      new->value = value;
      new->next = current->next;
      current->next = new;

      return 0;
    }

    current = current->next;
  }

  return 1;
}

/*

  "add_before" function add a node just before the first node that has the given value.
  It takes adress of head, a value and target as parameters respectively.
  If the operation is successful, it returns "0", otherwise "1";
  If the head is null, it returns "1" too.
  If the target does not exist in the list, it returns "1".

*/

int add_before(node_t **head, double value, double target)
{
  if(*head == NULL)
    return 1;

  node_t *current, *new, *previous;
  current = *head;
  previous = NULL; // It is null firstly, beacuse the first node has no previous node.

  while(current != NULL)
  {
    if(current->value == target)
    {
      new = (node_t *)malloc(sizeof(node_t));
      new->value = value;
      new->next = current;

      if(previous == NULL) // It means, you want to add before head. Head node would change.
        *head = new;

      else
        previous->next = new;

      return 0;
    }

    previous = current;
    current = current->next;
  }

  return 1;
}

/*

  "add_by_index" function add a node to given index.
  It takes adress of head, a value and index as parameters respectively.
  If the operation is successful, it returns "0", otherwise "1";
  If the head is null, it returns "1" too.
  If the index does not exist in the list, it adds to end.

*/

int add_by_index(node_t **head, double value, int index)
{
  if(*head == NULL || index < 0)
    return 1;

  if(index == 0)
    return add_to_head(&(*head), value);

  else if(index >= find_node_count(*head))
    return add_to_end(*head, value);

  else
  {
    int current_index;
    current_index = 1;

    node_t *current, *new;
    current = *head;

    while(current_index != index)
    {
      current_index++;
      current = current->next;
    }

    new = (node_t *)malloc(sizeof(node_t));
    new->value = value;
    new->next = current->next;
    current->next = new;

    return 0;
  }
}

/*

  "remove_by_value" function removes the node/s from the list that have the given value.
  It takes adress of head, a value and mode  as parameters respectively.
  If the operation is successful, it returns "0", otherwise "1";
  If the head is null, it returns "1" too.
  If the value does not exist, it return "1"

  If "mode" is "0", it removes the first node that has the value.
  If "mode" is not "0", it removes all nodes that have the value.

*/

int remove_by_value(node_t **head, double value, int mode)
{
  if(*head == NULL)
    return 1;

  int flag; // To check if a node is deleted.
  flag = 1;

  node_t *current, *previous, *temp;
  current = *head;
  previous = NULL;

  while(current != NULL)
  {
    if(current->value == value)
    {
      flag = 0; // At least one node is deleted.

      temp = current->next;
      free(current);

      if(previous == NULL)
        *head = temp;

      else
        previous->next = temp;

      if(mode == 0) // It would not to examine the left nodes.
        break;
    }

    previous = current;
    current = current->next;
  }

  if(flag == 0)
    return 0;

  else
    return 1;
}

/*

  "remove_by_index" function removes the node that is in the given node.
  It takes adress head and index as parameters respectively.
  If the operation is successful, it returns "0", otherwise "1";
  If the head is null, it returns "1" too.
  If the index does not exist in the list, it returns "1".

*/

int remove_by_index(node_t **head, int index)
{
  if(*head == NULL)
    return 1;

  node_t *current, *temp;

  if(index == 0)
  {
    temp = (*head)->next;
    free(*head);
    *head = temp;
  }

  else if(index >= find_node_count(*head))
    return 1;

  else
  {
    int current_index;
    current_index = 1;

    current = *head;

    while(current_index != index)
    {
      current_index++;
      current = current->next;
    }

    temp = current->next;
    current->next = current->next->next;
    free(temp);

    return 0;
  }
}

/*

  "delete" funciton deletes all nodes in the list.
  It takes head as parameters.
  If the operation is successful, it returns "0", otherwise "1";
  If the head is null, it returns "1" too.

*/

int delete(node_t *head)
{
  if(head == NULL)
    return 1;

  node_t *current;

  while (head != NULL)
  {
    current = head;
    head = head->next;
    free(current);
  }

  return 0;
}
