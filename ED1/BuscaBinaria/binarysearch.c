#include "utils.h"

/* */
int binary_search (int *A, int n, int key, int explore_left) {
  int left = 0;
  int right = n-1;
  int index = NOT_FOUND;
  while (left <= right) {
    int middle = (left + right)/2;
    if (A[middle] < key) {
      left = middle + 1;
    }
    else if (A[middle] > key) {
      right = middle - 1;
    }
    else {
      if (explore_left) {
	right = middle - 1;      
      }	      
      else {
        left = middle + 1;
      }
      index = middle;
    }
  }
  if (index != NOT_FOUND) { return index; }
  else { return NOT_FOUND; };
}

/* Achar ocorrencias */
int find_occurrences (int *A, int n, int target) {
  int left  = binary_search (A, n, target, TRUE);
  int right = binary_search (A, n, target, FALSE);
  if (left != NOT_FOUND)
    return (right - left + 1);
  else
    return NOT_FOUND;
}

/* */
int main () {
  int i, n = 10;
  int targets[] = {0,2,8,5,6,9};
  int A[] = {2,5,5,5,6,6,8,9,9,9};
  print (A, n, "Input");
  for (i = 0; i < 6; i++) {
    int oc = find_occurrences (A, n, targets[i]);
    if (oc != NOT_FOUND)
      printf("Target %d found %d times.\n", targets[i], oc);
    else
      printf("Target %d not found.\n", targets[i]);
  }  
  return 0;
}
