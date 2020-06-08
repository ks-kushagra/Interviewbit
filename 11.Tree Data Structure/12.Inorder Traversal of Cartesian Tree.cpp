

Given an inorder traversal of a cartesian tree, construct the tree.

    Cartesian tree : is a heap ordered binary tree, where the root is greater than all the elements in the subtree. 

    Note: You may assume that duplicates do not exist in the tree. 

Example :

Input : [1 2 3]

Return :   
          3
         /
        2
       /
      1


_____________________________________________________________________________________________________________________________________________________________________________________


TreeNode *create(TreeNode *root, int x)
{
    TreeNode *p = (TreeNode *)malloc(sizeof(TreeNode));
    p->val =x;
    p->left = NULL;
    p->right = NULL;
    
    if(root == NULL)
     return p;

     if(root->val < x)
     {
         p->left = root;
         return p;
     }
     
     else
      root->right = create(root->right , x);
      
    return root;
}
TreeNode* Solution::buildTree(vector<int> &A) {
TreeNode *root = NULL;

 for(int i=0;i<A.size();i++)
     root = create(root , A[i]);
     
return root;
}
