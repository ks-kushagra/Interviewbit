

Given a set of distinct integers, S, return all possible subsets.

    Note:

        Elements in a subset must be in non-descending order.
        The solution set must not contain duplicate subsets.
        Also, the subsets should be sorted in ascending ( lexicographic ) order.
        The list is not necessarily sorted.

Example :

If S = [1,2,3], a solution is:

[
  [],
  [1],
  [1, 2],
  [1, 2, 3],
  [1, 3],
  [2],
  [2, 3],
  [3],
]

_________________________________________________________________________________________________________________________________________________________________________________________________________


void make(vector<int>& A, vector<int> temp, int curr, vector<vector<int> >& ans){
    int n = A.size();
    
    ans.push_back(temp);
    
    if(curr == n){
        return;
    }
    
    for(int i = curr; i < n; i++){
        temp.push_back(A[i]);                            // If include
        make(A, temp, i+1, ans);
        temp.pop_back();                                  // If not included
    }
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    vector<vector<int> > ans;
    vector<int> temp;
    
    if(A.size()){
       sort(A.begin(), A.end()); 
    }
    
    make(A, temp, 0, ans);
    
    return ans;
}
