Implement strStr().

    strstr - locate a substring ( needle ) in a string ( haystack ). 

Try not to use standard library string functions for this question.

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

    NOTE:

    Good clarification questions:

        What should be the return value if the needle is empty?

        What if both haystack and needle are empty?

    For the purpose of this problem, assume that the return value should be -1 in both cases. 
    
    ________________________________________________________________________________________________________________________________________________________________________________
    
    int Solution::strStr(const string A, const string B) {
    
    int i=0,ii=0;
    int j=0;
    while(i < A.length() && j < B.length())
    {
        if(A[ii]==B[j])
        {
            ii++;
            j++;
        }
        
        else
        {
            j=0;
            ii= ++i;
        }
    }
    
    if(j == B.length())
    return  i;
    
    
    return -1;
      

}

    
    
    ______________________________________________________________________________________________________________________________________________________________________________________________
    
    int Solution::strStr(const string A, const string B) {
    
    if(A == "" || B == "")
     return 0;
     
     
     int n = A.length();
     int m = B.length();
     
     if(n < m)
      return -1;
      
      
      if(n == m)
       {
           if( A == B)
             return 0;
             
            return -1;
       }
      
      vector <char> window;
      int i;
      for(i=0;i<m;i++)
        window.push_back(A[i]);
        
     while(i < n )
     {
         int flag =1;
         for(int j =0;j<m;j++)
         { 
             if(B[j]!=window[j])
                 flag =0;
         }
         
         if(flag)
          return i-m;
          
        window.erase(window.begin());
        window.push_back(A[i]);
        i++;
     }
     
     return -1;
}
