

Given a binary search tree, write a function to find the kth smallest element in the tree.

Example :

Input : 
  2
 / \
1   3

and k = 2

Return : 2

As 2 is the second smallest element in the tree.

    NOTE : You may assume 1 <= k <= Total number of nodes in BST 


_______________________________________________________________________________________________________________________________________________________________________________________________________

int node(TreeNode *A)
{
    if(A == NULL)
    return 0;
    
    return node(A->left)+node(A->right) +1;
}
int Solution::kthsmallest(TreeNode* A, int B) {
    
    int k = node(A->left)+1;
    if(k == B)
    return A->val;
    
    if(k > B)
     return kthsmallest(A->left , B);
     
    else
    return kthsmallest(A->right , B-k);
}

