


Given a list, rotate the list to the right by k places, where k is non-negative.

For example:

Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

____________________________________________________________________________________________________________________________________________________________________________


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
    
    ListNode *end =A;
    int size=1;
    if(A == NULL || A->next == NULL)
    return A;
    
    while(end->next != NULL)
     {
         end = end->next;
         size++;
     }
     
     if(B % size == 0)
      return A;
      
      B=B%size;
      
     int k = size - B -1;
     ListNode *p=A;
     
     while(k--)
     p=p->next;
     
     end->next = A;
     A=p->next;
     p->next= NULL;
     
     return A;
     
     
}
