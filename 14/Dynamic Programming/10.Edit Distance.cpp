

Given two strings A and B, find the minimum number of steps required to convert A to B. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

    Insert a character
    Delete a character
    Replace a character


Input Format:

The first argument of input contains a string, A.
The second argument of input contains a string, B.

Output Format:

Return an integer, representing the minimum number of steps required.

Constraints:

1 <= length(A), length(B) <= 450

Examples:

Input 1:
    A = "abad"
    B = "abac"

Output 1:
    1

Explanation 1:
    Operation 1: Replace d with c.

Input 2:
    A = "Anshuman"
    B = "Antihuman"

Output 2:
    2

Explanation 2:
    => Operation 1: Replace s with t.
    => Operation 2: Insert i.


_____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________


int solve(string a, string b , int n , int m ,vector<vector<int> > &t)
{
    if(t[n][m]!=-1)
    return t[n][m];
    
    if(n == 0)
    return t[n][m]=m;
    
    if(m == 0)
    return t[n][m]=n;
    
    if(a[n-1]==b[m-1])
       return t[n][m]=solve(a,b,n-1,m-1,t);
       
     return t[n][m]=min(solve(a,b,n,m-1,t),min(solve(a,b,n-1,m,t),solve(a,b,n-1,m-1,t))) +1;
}
int Solution::minDistance(string A, string B) {

  while(A.length()>0 && A[0]==' ')
    A.erase(A.begin());
    
     while(B.length()>0 && B[0]==' ')
    B.erase(A.begin());
    
   while(A.length()>0 && A[A.length()-1]==' ')
     A.erase(A.begin()+A.length()-1);
     
        while(B.length()>0 && B[B.length()-1]==' ')
     B.erase(B.begin()+B.length()-1);
     
    int n = A.length();
    int m = B.length();
    vector<vector<int> > t(n+1 , vector <int> (m+1 , -1)); 
    return solve(A,B,n,m,t);
}
