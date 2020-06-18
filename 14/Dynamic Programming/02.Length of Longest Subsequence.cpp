

Given an array of integers, A of length N, find the length of longest subsequence which is first increasing then decreasing.

Input Format:

The first and the only argument contains an integer array, A.

Output Format:

Return an integer representing the answer as described in the problem statement.

Constraints:

1 <= N <= 3000
1 <= A[i] <= 1e7

Example:

Input 1:
    A = [1, 2, 1]

Output 1:
    3

Explanation 1:
    [1, 2, 1] is the longest subsequence.

Input 2:
    [1, 11, 2, 10, 4, 5, 2, 1]

Output 2:
    6
    
Explanation 2:
    [1 2 10 4 2 1] is the longest subsequence.


________________________________________________________________________________________________________________________________________________________________________________________


int Solution::longestSubsequenceLength(const vector<int> &A) {
    int n = A.size();
    vector <int> LIS(n,1);
    vector <int> LDS(n ,1);
    
    for(int i=0;i<n;i++)
    {
        for(int j =0;j<i;j++)
             if(A[j] < A[i] && LIS[i] < LIS[j]+1)
                  LIS[i]= LIS[j]+1;
    }
    
    
    for(int i=n-2;i>=0;i--)
      for(int j=n-1;j>i;j--)
          if(A[j] < A[i] && LDS[i] < LDS[j]+1)
              LDS[i]=LDS[j]+1;
              
              
    int ans=0;
    for(int i=0;i<n;i++)
     ans = max(ans, (LDS[i]+LIS[i]-1));
     
     
     return ans;
}
