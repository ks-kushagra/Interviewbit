

Given a linked list, remove the nth node from the end of list and return its head.

For example,
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.

    Note:

        If n is greater than the size of the list, remove the first node of the list.

Try doing it using constant additional space.

______________________________________________________________________________________________________________________________________________________________


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 int size(ListNode *head)
 {
     int n =0;
     
     ListNode *p=head;
     while(p!=NULL)
      {
          p=p->next;
          n++;
      }
      
      return n;
 }
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    
    int n = size(A);
    if(n<=B)
    {
        A=A->next;
        return A;
    }
    
    int k = n-B-1;ListNode*p=A;
    while(k-- >0)
         p=p->next;
     
     p->next = p->next->next;
     
     return A;
     
    
}
