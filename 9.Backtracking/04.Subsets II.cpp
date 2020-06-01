

Given a collection of integers that might contain duplicates, S, return all possible subsets.

    Note:

        Elements in a subset must be in non-descending order.
        The solution set must not contain duplicate subsets.
        The subsets must be sorted lexicographically.

Example :
If S = [1,2,2], the solution is:

[
[],
[1],
[1,2],
[1,2,2],
[2],
[2, 2]
]


_______________________________________________________________________________________________________________________________________________________________________________________

void solve(vector <vector <int>> &ans , vector <int> temp , vector <int> A , int curr)
{
    if(curr > A.size())
    return ;
    
    if(find(ans.begin() , ans.end() , temp) == ans.end())
       ans.push_back(temp);
      
    for(int i=curr;i<A.size();i++)
    {
        temp.push_back(A[i]);
        solve(ans, temp , A , i+1);
        temp.pop_back();
    }
}
vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    sort(A.begin() , A.end());
    vector <vector <int> > ans;
    vector <int> temp;
    solve(ans, temp , A , 0);
    return ans;
}
