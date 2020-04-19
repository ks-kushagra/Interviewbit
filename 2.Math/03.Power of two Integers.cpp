

Given a positive integer which fits in a 32 bit signed integer, find if it can be expressed as A^P where P > 1 and A > 0.
A and P both should be integers.

Example

Input : 4
Output : True  
as 2^2 = 4. 

______________________________________________________________________________________________________________________________________________________________

int Solution::isPower(int A) {
    if(A==1)
      return 1;
     
    for(int p=2;p<=A;p++)
      {
         float s = pow(A,1.0/p);
      
         int t =s;
          if(s-t==0)
             {
                 return 1;
             }
      }
      return 0;
}

