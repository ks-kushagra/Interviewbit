

Given a binary tree, invert the binary tree and return it.
Look at the example for more details.

Example :
Given binary tree

     1
   /   \
  2     3
 / \   / \
4   5 6   7

invert and return

     1
   /   \
  3     2
 / \   / \
7   6 5   4


____________________________________________________________________________________________________________________________________________________________________________

TreeNode* Solution::invertTree(TreeNode* A) {
  if(A== NULL)
    return NULL;
    
    TreeNode *p = (TreeNode *)malloc(sizeof(TreeNode));
    p->val = A->val;
    p->left = invertTree(A->right);
    p->right= invertTree(A->left);
    
    return p;
}
