

Given an expression, A, with operands and operators (OR , AND , XOR), in how many ways can you evaluate the expression to true, by grouping in different ways?

Operands are only true and false.

Return the number of ways to evaluate the expression modulo 103 + 3.


Input Format:

The first and the only argument of input will contain a string, A.

The string A, may contain these characters:
    '|' will represent or operator 
    '&' will represent and operator
    '^' will represent xor operator
    'T' will represent true operand
    'F' will false

Output:

Return an integer, representing the number of ways to evaluate the string.

Constraints:

1 <= length(A) <= 150

Example:

Input 1:
    A = "T|F"

Output 1:
    1

Explanation 1:
    The only way to evaluate the expression is:
        => (T|F) = T 

Input 2:
    A = "T^T^F"
    
Output 2:
    0
    
Explanation 2:
    There is no way to evaluate A to a true statement.


_______________________________________________________________________________________________________________________________________________________________________________________________________


int solve(string A , int i ,int j , bool isTrue,unordered_map<string,int> &mp)
{   
    string s = "";
    if(isTrue)
     s="T";
     
     else
      s = "F";
      
     s = to_string(i)+" "+to_string(j)+" "+s;
     
    if(mp.find(s) != mp.end())
    return mp[s];
    
    if(i>j)
    return 0;
    
    if(i == j)
     {
         if(isTrue == true)
           return A[i] == 'T';
          
          else
           return A[i] == 'F';
     }
     
     int ans = 0;
     for(int k = i+1;k<=j-1;k+=2)
     {
         int lt = solve(A , i , k-1 ,true,mp);
         int lf = solve(A , i , k-1 ,false,mp);
         int rt = solve(A , k+1 , j ,true,mp);
         int rf = solve(A , k+1 , j ,false,mp);
         
         if(A[k] == '|')
         {
             if(isTrue == true)
             {
                 ans = (ans + (lt*rt)+(lt*rf)+(lf*rt))%1003;
             }
             
             else
             {
                 ans = (ans + (lf*rf))%1003;
             }
         }
         
        else if(A[k]=='&')
         {
             if(isTrue == true)
             {
                 ans = (ans + (lt *rt))%1003;
             }
             
             else
             {
                 ans = (ans + (lf*rt) + (lt*rf) + (lf*rf))%1003;
             }             
         }
         
         else
         {
             if(isTrue == true)
             {
                 ans = (ans + (lt*rf) + (rt*lf))%1003;
             }
             
             else
             {
                 ans = (ans + (lt*rt)+(lf*rf))%1003;
             }             
         }
     }
     
     return mp[s] = (ans)%1003;
}
int Solution::cnttrue(string A) {
    unordered_map<string,int> mp;
    return solve(A,0,A.length()-1,true,mp);
}
