

Given a binary tree, return the inorder traversal of its nodes’ values.

Example :
Given binary tree

   1
    \
     2
    /
   3

return [1,3,2].

Using recursion is not allowed.

_____________________________________________________________________________________________________________________________________________________________

vector<int> Solution::inorderTraversal(TreeNode* A) {

    if(A== NULL)
    return vector <int> ();
    
    vector <int> ans;
    
    stack<TreeNode *> s;
    
    TreeNode *p=A;
    while(p!= NULL)
     {
         s.push(p);
         p=p->left;
     }
     
    while(!s.empty())
    {
        TreeNode *q = s.top();
        s.pop();
        ans.push_back(q->val);
        
      if(q->right != NULL)
      {
          q=q->right;
          s.push(q);
          while(q->left != NULL)
           {
               s.push(q->left);
               q=q->left;
           }
      }
    }
    
    return ans;
}
