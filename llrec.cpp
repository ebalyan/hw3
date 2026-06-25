#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot_helper(Node*& head, Node*& smaller, Node*& larger, int pivot)
{
  if (head == NULL) {
    smaller = NULL;
    larger = NULL;
    return;
  }

  Node* curr = head;
  head = head->next;
  curr->next = NULL;

  if (curr->val <= pivot) {
    smaller = curr;
    llpivot_helper(head, smaller->next, larger, pivot);
  }
  else {
    larger = curr;
    llpivot_helper(head, smaller, larger->next, pivot);
  }
}

void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot)
{
  smaller = NULL;
  larger = NULL;

  llpivot_helper(head, smaller, larger, pivot);
}
