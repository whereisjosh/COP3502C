#include <stdio.h>
#include <stdlib.h>

// QUESTION #1

struct present { 
  char *present_name;
  float price;
};

struct present *delete_present_list(struct present *present_list, int num) {
  
  if (present_list == NULL) { //checks if present_list is NULL
    return NULL;
  }
  
  for (int i = 0; i < num; i++) {
    free(present_list[i].present_name);
  }
  
  free(present_list); //deallocates memory
  return NULL;
}

// QUESTION #2
// if we call whatDoesItDo(head) on the following list,
// the function would appear like this...

// head -> 7 -> 6 -> 5 -> 4 -> 3 -> 2 -> 1