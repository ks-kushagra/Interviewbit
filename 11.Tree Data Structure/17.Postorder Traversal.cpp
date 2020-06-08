

Given a binary tree, return the postorder traversal of its nodes’ values.

Example :

Given binary tree

   1
    \
     2
    /
   3

return [3,2,1].

Using recursion is not allowed.

_______________________________________________________________________________________________________________________________________________________________________________



vector<int> Solution::postorderTraversal(TreeNode* A) {

vector <int> ans;
if(A == NULL)
    return vector<int> ();
    
    stack <TreeNode *> s;
    s.push(A);
    int flag=0;
    while(!s.empty())
    {
        TreeNode *p = s.top();
        s.pop();
        ans.push_back(p->val);
        
        if(p->left)
        s.push(p->left);
        
        if(p->right)
         s.push(p->right);
    }
    
    reverse(ans.begin() , ans.end());
      
      return ans;
}
