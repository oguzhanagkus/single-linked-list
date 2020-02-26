/*

  Created by Oğuzhan Agkuş.
  Last edit: 29.07.2018

  This library created by Oguzhan Agkus.
  You can use it in your project.
  If you find a bug, you can contact me from agkusoguzhan@gmail.com
  Necessary explanation are given in .c file. Example code is exist in the folder.

*/

#ifndef SINGLE_LINKED_LIST_H_
#define SINGLE_LINKED_LIST_H_

typedef struct node
{
  double value;
  struct node *next;

} node_t;

node_t *create(double value);
void reverse(node_t **head);
void sort(node_t **head);
void print(node_t *head);
void print_reverse(node_t *head);
int find_node_count(node_t *head);
int add_to_end(node_t *head, double value);
int add_to_head(node_t **head, double value);
int add_after(node_t *head, double value, double target);
int add_before(node_t **head, double value, double target);
int add_by_index(node_t **head, double value, int index);
int remove_by_value(node_t **head, double value, int mode);
int remove_by_index(node_t **head, int index);
int delete(node_t *head);

#endif /* SINGLE_LINKED_LIST_H_ */
