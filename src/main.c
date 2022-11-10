#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"



// File for sandboxing and trying out code
int main(int argc, char **argv) {
  // Add your code
  int sum;
    node *ns = make_node(
        1, make_node(2, make_node(3, make_node(4, make_node(5, NULL)))));

    sum = sum_squares(ns);
    REQUIRE(sum == 55);
    free_list(ns);
    // dangling pointer we need to set it to null
    ns = NULL;

    sum = sum_squares(ns);
    REQUIRE(sum == 0);

    ns = make_node(1, NULL);
    sum = sum_squares(ns);
    REQUIRE(sum == 1);
    free_list(ns);
    ns = NULL;
  return 0;
}