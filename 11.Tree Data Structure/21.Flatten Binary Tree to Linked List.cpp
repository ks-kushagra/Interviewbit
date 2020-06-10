

Given a binary tree, flatten it to a linked list in-place.

Example :
Given


         1
        / \
       2   5
      / \   \
     3   4   6

The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

Note that the left child of all nodes should be NULL.

____________________________________________________________________________________________________________________________________________________________________________________________


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::flatten(TreeNode* A) {

if(A == NULL || (A->left == NULL && A->right == NULL))
return A;


TreeNode *left = flatten(A->left);
TreeNode *right = flatten(A->right);

if(left == NULL)
return A;

if(right == NULL)
  {
      A->right = left;
      A->left = NULL;
      return A;
  }
  
 A->left =NULL;
 A->right = left;
 TreeNode *q = left;
 
 while(q->right != NULL)
   q=q->right;
   
  q->right = right;
  
  return A;
    
}
