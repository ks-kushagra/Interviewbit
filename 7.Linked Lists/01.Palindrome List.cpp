

Given a singly linked list, determine if its a palindrome. Return 1 or 0 denoting if its a palindrome or not, respectively.

Notes:

    Expected solution is linear in time and constant in space.

For example,

List 1-->2-->1 is a palindrome.
List 1-->2-->3 is not a palindrome.


________________________________________________________________________________________________________________________________________________________________________________________________________________



ListNode * head;

int palindrome(ListNode *p)
{
    if(p==NULL)
        return 1;
        
        
    bool isPal = palindrome(p->next) & (head->val == p->val);
    head = head->next;
    
    return isPal;
}

int Solution::lPalin(ListNode* A) {
    
    head = A;
    return palindrome(A);
    
}
