

Given a singly linked list

    L: L0 → L1 → … → Ln-1 → Ln,

reorder it to:

    L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …

You must do this in-place without altering the nodes’ values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.

_____________________________________________________________________________________________________________________________________________________________________________________




ListNode* Solution::reorderList(ListNode* A) {
    
    
    vector <ListNode *> v;
    
    ListNode *p = A;
    while(p!= NULL)
      {
          v.push_back(p);
          p=p->next;
      }
      
    int i=0;
    int j=v.size()-1;
    ListNode *head= v[0];
    
    while( i < j)
    {
        v[i++]->next = v[j];

        v[j--]->next = v[i];
    }
    
    if(v.size()%2 !=0){
    v[i]->next=NULL;
    v[j]->next=NULL;
    }
    
    else
    {
        v[i]->next = v[v.size() /2];
        v[i]->next->next=NULL;
    }
    return head;
}



