

Merge two sorted linked lists and return it as a new list.
The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.

For example, given following linked lists :

  5 -> 8 -> 20 
  4 -> 11 -> 15

The merged list should be :

4 -> 5 -> 8 -> 11 -> 15 -> 20

__________________________________________________________________________________________________________________________________________________



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    
    ListNode *head = NULL;
    ListNode *p=head;
    
    while( A!= NULL && B != NULL)
    {
        ListNode *q = ( ListNode *)malloc(sizeof(ListNode));
        q->next = NULL;
        
        if(A->val <= B->val)
        {
            q->val = A->val;
            A=A->next;
        }
        
        else
        {
            q->val = B->val;
            B=B->next;
        }
        
        if(head == NULL)
          {
              head = q;
              p=head;
          }
          
         else
         {
             p->next = q;
             p=p->next;
         }
          
    }
    
    
    if(A!=NULL)
    {
        p->next = A; 
    }
    
    if(B!= NULL)
     p->next = B;
     
    return head;
}
