

Given a binary tree, return the zigzag level order traversal of its nodes’ values. (ie, from left to right, 
then right to left for the next level and alternate between).

Example :
Given binary tree

    3
   / \
  9  20
    /  \
   15   7

return

[
         [3],
         [20, 9],
         [15, 7]
]


__________________________________________________________________________________________________________________________________________________________________________________________________________________


vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {

    stack <TreeNode *> left;
    stack <TreeNode *> right;
    right.push(A);
    vector <vector <int> > ans;
    
    while(!right.empty() || !left.empty())
    {
        vector<int> temp;
        while(!right.empty())
        {
            TreeNode *p = right.top();
            right.pop();
            temp.push_back(p->val);
            if(p->left)
            left.push(p->left);
            
            if(p->right)
            left.push(p->right);
        }
        
        if(temp.size()>0){
        ans.push_back(temp);
        temp = vector <int> ();
        }
        
        while(!left.empty())
        {
            TreeNode *p = left.top();
            left.pop();
            temp.push_back(p->val);
            
            if(p->right)
            right.push(p->right);
            
            if(p->left)
            right.push(p->left);
        }
        
        
        if(temp.size() > 0)
        ans.push_back(temp);
    }
    
    return ans;
}
