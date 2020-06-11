

You are given an array of N integers, A1, A2 ,…, AN and an integer K. Return the of count of distinct numbers in all windows of size K.

Formally, return an array of size N-K+1 where i’th element in this array contains number of distinct elements in sequence Ai, Ai+1 ,…, Ai+k-1.

Note:

 If K > N, return empty array.
 A[i] is a signed integer

For example,

A=[1, 2, 1, 3, 4, 3] and K = 3

All windows of size K are

[1, 2, 1]
[2, 1, 3]
[1, 3, 4]
[3, 4, 3]

So, we return an array [2, 3, 3, 2].


_________________________________________________________________________________________________________________________________________________________________________________________________________________

vector<int> Solution::dNums(vector<int> &A, int B) {
    
    map<int,int>mp;
    queue<int> q;
    vector <int> ans;
    for(int i=0;i<B;i++)
        {
            q.push(A[i]);
            mp[A[i]]++;
        }
        
    ans.push_back(mp.size());
    for(int i=B;i<A.size();i++)
    {
        int t = q.front();
        q.pop();
        mp[t]--;
        if(mp[t] == 0)
          mp.erase(mp.find(t));
        q.push(A[i]);
        mp[A[i]]++;
        ans.push_back(mp.size());
    }
    
    return ans;
}
