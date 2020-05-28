

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

________________________________________________________________________________________________________________________________________________________________________________________________

ListNode* Solution::swapPairs(ListNode* A) {
    
    if(A==NULL || A->next == NULL)
     return A;
     
     ListNode *p=A, *q = p->next , *r=q->next;
     q->next =p;
     p->next = swapPairs(r);
     
     return q;
}
