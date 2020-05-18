
Given two binary strings, return their sum (also a binary string).

Example:

a = "100"

b = "11"

Return a + b = “111”.

__________________________________________________________________________________________________________________________________________________________________________


string Solution::addBinary(string A, string B) {
    
    int i = A.length()-1;
    int j = B.length()-1;
    
    string s = "";
    int carry = 0;
    while( i>=0 && j >=0)
    {
        int t = ((A[i]-'0') ^ (B[j] - '0')) ^ carry;
        if( (A[i] == '1' && B[j] == '1') || (A[i] == '1' && carry == 1) || B[j] == '1' && carry ==1)
           carry =1;
          
         else carry =0;
         
         s =  to_string(t) + s;
         i--;
         j--;
    }
    
    while(i >=0)
    {
        int t = (A[i]-'0') ^ carry;
        
        if(A[i]=='1' && carry == 1)
          carry =1;
          
          else
          carry =0;
          
        s = to_string(t) + s;
        i--;
    }
    
     while(j >=0)
    {
        int t = (B[j]-'0') ^ carry;
        
        if(B[j]=='1' && carry == 1)
          carry =1;
          
         else
          carry =0;
          
        s = to_string(t) + s;
        j--;
    }
    if(carry == 1)
     s = "1"+s;
     
    return s;
}
