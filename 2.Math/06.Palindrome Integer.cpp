

Determine whether an integer is a palindrome. Do this without extra space.

A palindrome integer is an integer x for which reverse(x) = x where reverse(x) is x with its digit reversed.
Negative numbers are not palindromic.

Example :

Input : 12121
Output : True

Input : 123
Output : False

___________________________________________________________________________________________________________________________________________________________________________________



int Solution::isPalindrome(int A) {
    if(A<0)
     return 0;
     if(A==0)
      return 1;
      
    int n = A;
    string s="";
    while(n>0)
     {
         s=s+to_string(n%10);
         n=n/10;
     }
     
     string t = to_string(A);
     if(t.compare(s)==0)
      return 1;
     
    return 0;
}
