


Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Try solving it using constant additional space.

Example :

Input : 

                  ______
                 |     |
                 \/    |
        1 -> 2 -> 3 -> 4

Return the node corresponding to node 3. 


__________________________________________________________________________________________________________________________________________________________________


ListNode* Solution::detectCycle(ListNode* A) {

    ListNode *p = A;
    while(p!=NULL)
    {
        if(p->val < 0)
        break;
        p->val = (-1)*abs(p->val);
        p=p->next;
    }
    
    if(p!=NULL)
          p->val = abs(p->val);
      
      return p;
}
