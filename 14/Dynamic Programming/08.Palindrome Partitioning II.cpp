

Given a string A, partition A such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of A.


Input Format:

The first and the only argument contains the string A.

Output Format:

Return an integer, representing the answer as described in the problem statement.

Constraints:

1 <= length(A) <= 501

Examples:

Input 1:
    A = "aba"

Output 1:
    0

Explanation 1:
    "aba" is already a palindrome, so no cuts are needed.

Input 2:
    A = "aab"
    
Output 2:
    1

Explanation 2:
    Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.


_____________________________________________________________________________________________________________________________________________________________________________________________________


int isPalindrome(string A , int i ,int j)
{
    while(i <j)
    {
        if(A[i]!= A[j])
            return 0;
            
        i++;
        j--;
    }
    
    return 1;
}
int solve(string A , int i , int j , vector<vector<int> > &t)
{
    if(t[i][j] != -1)
    return t[i][j];
    
    if(i >= j || isPalindrome(A,i,j))
      return t[i][j] = 0;
      
    int ans = INT_MAX;  
    for(int k=i;k<j;k++)
      {
          int left,right;
          if(t[i][k]!=-1)
           left = t[i][k];
           else
           left = solve(A , i, k, t);
           
           if(t[k+1][j] !=-1)
           right = t[k+1][j];
           
           else
           right = solve(A,k+1 ,j,t);
           
          int temp = 1 + left + right;
          ans = min(ans , temp);
      }
      
      return t[i][j] = ans;
}
int Solution::minCut(string A) {
    vector <vector <int> > t(A.length()+1 , vector <int> (A.length()+1 , -1));
    return solve(A , 0 , A.length()-1,t);
}
