

Given a column title as appears in an Excel sheet, return its corresponding column number.

Example:

    A -> 1
    
    B -> 2
    
    C -> 3
    
    ...
    
    Z -> 26
    
    AA -> 27
    
    AB -> 28 


______________________________________________________________________________________________________________________________________________________________



int Solution::titleToNumber(string A) {
    
    int sum=0;
    int n = A.length();
    for(int i=A.length()-1;i>=0;i--)
      {
          int val=A[i]-65+1;
           sum = sum + val*pow(26,n-i-1);
           
      }
      return sum;
}
