

Given a binary tree, return the level order traversal of its nodes’ values. (ie, from left to right, level by level).

Example :
Given binary tree

    3
   / \
  9  20
    /  \
   15   7

return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]

Also think about a version of the question where you are asked to do a level order traversal of the tree when depth of the tree is
much greater than number of nodes on a level.

_________________________________________________________________________________________________________________________________________________________________________________________________________________________


vector<vector<int> > Solution::levelOrder(TreeNode* A) {

    vector <vector <int> > ans;
    if(A == NULL)
    return ans;
    
    map <int , vector<int> > mp;
    
    queue<pair<TreeNode *, int > > q;
    q.push({A,0});
    while(!q.empty())
    {
        auto p = q.front();
        q.pop();
        mp[p.second].push_back(p.first->val);
        if(p.first->left)
        q.push({p.first->left,p.second+1});
        
        if(p.first->right)
        q.push({p.first->right,p.second+1});
    }
    

    for(auto it = mp.begin();it!=mp.end();it++)
     ans.push_back(it->second);
     
    return ans;
}
