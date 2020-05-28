

Given a singly linked list and an integer K, reverses the nodes of the

list K at a time and returns modified linked list.

    NOTE : The length of the list is divisible by K 

Example :

Given linked list 1 -> 2 -> 3 -> 4 -> 5 -> 6 and K=2,

You should return 2 -> 1 -> 4 -> 3 -> 6 -> 5

Try to solve the problem using constant extra space.

_______________________________________________________________________________________________________________________________________________________________________________________
ListNode *reverse(ListNode *head,int k)
{
    if(head== NULL)
    return head;
    ListNode *p=NULL,*q = head, *r = q->next;
    while( r != NULL && k-- > 0)
    {
        q->next = p;
        p=q;
        q=r;
        r=r->next;
    }
    
    q->next = p;
    
    return q;
}
ListNode* Solution::reverseList(ListNode* A, int B) {
    
    if(B <= 1)
    return A;
    
    if(A == NULL)
    return A;
    
    ListNode *p = A;
    ListNode *q = A;
    for(int i=1;i<=B;i++)
      q=q->next;
      
    ListNode *start = reverse(p,B-1);
    p->next = reverseList(q,B);
    return start;
}

________________________________________________________________________________________________________________________________________________________________________________________

ListNode* Solution::reverseList(ListNode* A, int B) {
    ListNode *curr = A, *prev = NULL, *next = NULL;
    int cnt =0;
     while(cnt<B && curr) {
         next = curr->next;
         curr->next = prev;
         prev = curr;
         curr = next;
         cnt++;
     }
     if(next) {
         A->next = reverseList(next, B);
     }
     return prev;
}
