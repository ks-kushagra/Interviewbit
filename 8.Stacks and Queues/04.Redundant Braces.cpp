

Given a string A denoting an expression. It contains the following operators ’+’, ‘-‘, ‘*’, ‘/’.

Chech whether A has redundant braces or not.

Return 1 if A has redundant braces, else return 0.

Note: A will be always a valid expression.



Input Format

The only argument given is string A.

Output Format

Return 1 if string has redundant braces, else return 0.

For Example

Input 1:
    A = "((a + b))"
Output 1:
    1
    Explanation 1:
        ((a + b)) has redundant braces so answer will be 1.

Input 2:
    A = "(a + (a + b))"
Output 2:
    0
    Explanation 2:
        (a + (a + b)) doesn't have have any redundant braces so answer will be 0.


____________________________________________________________________________________________________________________________________________________________________


int Solution::braces(string s) {
 
 stack<char> A;
 
 for(int i=0;i<s.length();i++)
 {
     if(s[i] == '('|| s[i] == '+'|| s[i] == '/'|| s[i] == '-'|| s[i] == '*')
       A.push(s[i]);
       
       
     else if(s[i] == ')')
     {
         if(A.top() == '(')
          return 1;
          
         while(A.size() > 0 && A.top() != '(')
           A.pop();
           
          A.pop();
     }
 }
 
 return 0;

}
