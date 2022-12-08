#include "btree.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct tree_node* Insert(int x, struct tree_node* t) {
	// Rootpointer and value in the node struct
	//  Insert item x into the tree t
	// 1: All children to the left of the root has to less than the value of  the root
	// 2: All children to the right of the root has to be larger than the root value
	// 3: These two rules also include the value of the childrens children

	if (t == NULL) { // if value is Null, create root
		struct tree_node* new_node = malloc(sizeof(struct tree_node));
		new_node->item = x;
		new_node->left = NULL;
		new_node->right = NULL;
		t = new_node;
		return new_node;
	}

	if (x <= t->item) { // If value is lower than root value, we insert the value in the left child
						// of the root
		t->left = Insert(x, t->left);
		return t;
	}

	if (x >= t->item) { // if value is higher than root, we insert it in right child
		t->right = Insert(x, t->right);
		return t;
	}
}

struct tree_node* Remove(int x, struct tree_node* t) {
	// Remove one item from the tree t

	if ((Contains(x, t) == 0)) {
		return t;
	}
	// base case: Traverse the tree
	if (t == NULL) {
		return t;
	}
	// recursive case
	else if (t->item < x) // we have found our node to be removed, and will try to remove it
	{
		t->right = Remove(x, t->right);
	} else if (t->item > x) {
		t->left = Remove(x, t->left);
	}


	else if (t->item == x) {
		// Case 1: if node has no children
		if (t->right == NULL && t->left == NULL) {
			free(t);
			t = NULL;
			return t;
		}

		// Case 2: If the node to be removed only has one child, the child takes it's place.
		if (t->right == NULL && t->left != NULL) // If right child is epmpty and left is not.
		{
			struct tree_node* temp = t->left;
			free(t);
			return temp;
		}

    if (t->right != NULL && t->left == NULL) // If left child is epmpty and right is not.
		{
			struct tree_node* temp = t->right;
			free(t);
			return temp;
		}
		// Case 3: if the node has two children the, the removed nodes value is replaced with the
		// minimum value in its own right tree.
		if (t->right != NULL && t->left != NULL) {
			struct tree_node* temp = t->right; // pointer to traverse tree, searching for node to replace

			while (temp->left != NULL) {
				temp = temp->left;
			}
			t->item = temp->item;

			if (temp->right == NULL) // if leaf node
			{
				free(temp);
				temp = NULL;
				return t;
			}
		}
	}
}

int Contains(int x, struct tree_node* t) {

	// Return true if the tree t contains item x. Return false otherwise.
	// Base case in case the element doesn't exist

	if (t == NULL) {
		return 0;
	}

	if (t->item == x) {
		return 1; // True if item has data
	}

	if (x < t->item) {
		return Contains(x, t->left);
	}
	if (x > t->item) {
		return Contains(x, t->right);
	}
}

struct tree_node* Initialize(struct tree_node* t) {
	t = NULL;
	return t;
}

int Empty(struct tree_node* t) {
	// Tree is empty when root is NULL
	return t == NULL;
}

int Full(struct tree_node* t) {
	return 0;
}
