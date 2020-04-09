/*
Given a non-negative number represented as an array of digits,

add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.

Example:

If the vector has [1, 2, 3]

the returned vector should be [1, 2, 4]

as 123 + 1 = 124
*/

--------------------------------------------------------------------------------------------------------------------------------------------------


vector<int> Solution::plusOne(vector<int> &A) {
    
    if(A.size()==0)
      {
          A.push_back(1);
          return A;
      }
      
      int carry =1;
      
      for(int i=A.size()-1;i>=0;i--)
      {
          int sum = A[i]+ carry;
          A[i] = sum %10;
          carry = sum/10;
          
      }
      
      
      if(carry == 1)
      {
          A.insert(A.begin(),1);
      }
      
      
      //Removing Trailing zeros
      while(A[0]==0)
       {
           A.erase(A.begin());
       }
      
      
      return A;
      
}
