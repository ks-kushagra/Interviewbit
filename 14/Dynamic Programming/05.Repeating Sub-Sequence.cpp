Problem Description

Given a string A, find length of the longest repeating sub-sequence such that the two subsequence don’t have same string character at same position,

i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.

NOTE: Sub-sequence length should be greater than or equal to 2.


Problem Constraints

1 <= |A| <= 100


Input Format

The first and the only argument of input contains a string A.


Output Format

Return an integer, 0 or 1:

    => 0 : False
    => 1 : True



Example Input

Input 1:

 A = "abab"

Input 2:

 A = "abba"



Example Output

Output 1:

 1

Output 2:

 0

____________________________________________________________________________________________________________________________________________________________________________________


int lcs(string a , string b , int n , int m,vector < vector <int> > &t)
{
   /* if(n == 0 || m == 0)
     return t[n][m]=0;
     
     if(a[n-1]==b[m-1] && n != m)
          return t[n][m]=1 + lcs(a , b , n-1,m-1,t);
          
     return t[n][m]= max(lcs(a , b , n-1 ,m,t) , lcs( a , b , n , m-1,t));*/
     
     
     for(int i=1;i<=n;i++)
       for(int j=1;j<=m;j++)
       {
           if(i!= j && a[i-1]==b[j-1])
              t[i][j] = 1 + t[i-1][j-1];
              
            else
              t[i][j] = max(t[i-1][j] , t[i][j-1]);
       }
       
       return t[n][m];
}
int Solution::anytwo(string A) {
    int n = A.length();
    vector < vector <int> > t(n+1 , vector <int> (n+1 , 0));
    int k = lcs(A , A , A.length() , A.length(),t);
    
    if(k >= 2)
    return 1;
    
    return 0;
}
