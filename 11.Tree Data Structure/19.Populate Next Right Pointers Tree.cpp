

Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

    Note:

        You may only use constant extra space.

Example :

Given the following binary tree,

         1
       /  \
      2    3
     / \  / \
    4  5  6  7

After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL

    Note 1: that using recursion has memory overhead and does not qualify for constant space.
    Note 2: The tree need not be a perfect binary tree. 


_____________________________________________________________________________________________________________________________________________________________________________________________________


/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 
TreeLinkNode *connectRight(TreeLinkNode * A)
{
    TreeLinkNode *temp = A->next;
    
    while(temp!=NULL)
    {
        if(temp->left != NULL)
        return temp->left;
        
        if(temp->right != NULL)
        return temp->right;
        
        temp = temp->next;
    }
    return NULL;
}


void Solution::connect(TreeLinkNode* A) {

    if(A == NULL)
    return;
    
    TreeLinkNode *q=NULL , *p=A;
    A->next = NULL;
    
    while(p != NULL)
    {
        q = p;
        
        while(q != NULL)
        {
            if(q->left)
            {
                if(q->right)
                    q->left->next = q->right;
                
                else
                 q->left->next = connectRight(q);
            }
            
           if(q->right)
                q->right->next = connectRight(q);
            
            q=q->next;
        }
        
        
        if(p->left)
        p=p->left;
        
        else if(p->right)
        p=p->right;
        
        
        else
         p=connectRight(p);
    }
}
