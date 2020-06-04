

Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Example :

Input : 

   1       1
  / \     / \
 2   3   2   3

Output : 
  1 or True


______________________________________________________________________________________________________________________________________________________________


int Solution::isSameTree(TreeNode* A, TreeNode* B) {

    if(A==NULL && B == NULL)
    return 1;
    
    if((A==NULL && B != NULL) || (A != NULL && B == NULL) || (A->val != B->val))
     return 0;
     
     
     int left = isSameTree(A->left , B->left);
     int right = isSameTree(A->right , B->right);
     
     return (left & right );

}
