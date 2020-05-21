

Given a string A representing a roman numeral.
Convert A into integer.

A is guaranteed to be within the range from 1 to 3999.

NOTE: Read more
details about roman numerals at Roman Numeric System



Input Format

The only argument given is string A.

Output Format

Return an integer which is the integer verison of roman numeral string.

For Example

Input 1:
    A = "XIV"
Output 1:
    14

Input 2:
    A = "XX"
Output 2:
    20

____________________________________________________________________________________________________________________________________________________________________________


int roman(char a)
{
  if(a == 'M')
     return 1000;
     
  if(a == 'D')
     return 500;
     
if(a == 'C')
     return 100;
     
     if(a == 'L')
     return 50;
     
     if(a == 'X')
     return 10;

     if(a == 'V')
      return 5;
      
     if(a == 'I')
     return 1;
     
     return 0;
}
int Solution::romanToInt(string A) {
    
    
    int ans =0;
    
    for(int i=0;i<A.length();i++)
    {
        if(i == 0)
        ans = ans + roman(A[i]);
        
        else if(roman(A[i]) > roman(A[i-1]))
        {
            ans = ans + (roman(A[i]) - roman(A[i-1])) - roman(A[i-1]);
        }
        
        else
        {
            ans += roman(A[i]);
        }
    }
    
    
    return ans;
}

