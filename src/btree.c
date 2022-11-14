#include "btree.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct tree_node *Insert(int x, struct tree_node *t) {
  //Rootpointer and value in the node struct
  // Insert item x into the tree t
// 1: All children to the left of the root has to less than the value of  the root
// 2: All children to the right of the root has to be larger than the root value
// 3: These two rules also include the value of the childrens children

if (t == NULL){ //if value is Null, create root
struct tree_node *new_node = malloc(sizeof(struct tree_node));
new_node->item = x;
new_node->left = NULL;
new_node->right = NULL;
return new_node;
}

if (x<=t->item){
  t->left = Insert(x,t->left);
  return t;
}

if (x>=t->item){
  t->right = Insert(x,t->right);
  return t;
}
}

struct tree_node *Remove(int x, struct tree_node *t) { 
  // Remove one item from the tree t

  return NULL;
}

int Contains(int x, struct tree_node *t) {

  // Return true if the tree t contains item x. Return false otherwise.

  if (t->item == NULL){ //Base case in case the element doesn't exist
    return 0;
  }

if (t->item == x){
  return 1;
}

if (x<t->item){
  return Contains(x,t->left);
}
if (x<t->item){
  return Contains(x,t->right);
}
}



struct tree_node *Initialize(struct tree_node *t) {
   t = NULL;
  return t;
}

int Empty(struct tree_node *t) {
  // Tree is empty when root is NULL
  return t == NULL;
}

int Full(struct tree_node *t) {
  return 0;
}
