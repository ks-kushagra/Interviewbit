

Given two sorted integer arrays A and B, merge B into A as one sorted array.

    Note: You have to modify the array A to contain the merge of A and B. Do not output anything in your code.
    TIP: C users, please malloc the result into a new array and return the result. 

If the number of elements initialized in A and B are m and n respectively, the resulting size of array A after your code is 
executed should be m + n

Example :

Input : 
         A : [1 5 8]
         B : [6 9]

Modified A : [1 5 6 8 9]


___________________________________________________________________________________________________________________________________________________________________________________________________________

void Solution::merge(vector<int> &A, vector<int> &B) {

    int i=0;
    int j=0;
    vector <int> c;
    while(i<A.size() && j<B.size())
    {
        if(A[i] < B[j])
          {
              c.push_back(A[i]);
              i++;
          }
          
         else if(A[i] > B[j])
         {
             c.push_back(B[j]);
             j++;
         }
         
         else
          {
              c.push_back(A[i]);
              c.push_back(A[i]);
              i++;
              j++;
          }
    }
    
    while(i < A.size())
       c.push_back(A[i++]);
       
    while(j < B.size())
     c.push_back(B[j++]);
     
     
     A = vector <int> ();
     
     for(i=0;i<c.size();i++)
      A.push_back(c[i]);
}
