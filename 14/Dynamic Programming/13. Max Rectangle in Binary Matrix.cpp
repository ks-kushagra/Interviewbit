
    Asked in:  
    Google
    Microsoft

Given a 2D binary matrix filled with 0’s and 1’s, find the largest rectangle containing all ones and return its area.

Bonus if you can solve it in O(n^2) or less.

Example :

A : [  1 1 1
       0 1 1
       1 0 0 
    ]

Output : 4 

As the max area rectangle is created by the 2x2 rectangle created by (0,1), (0,2), (1,1) and (1,2)
____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________


vector <int> nearestSmallerLeft(vector <int> A)
{
    stack <int> s;
    vector <int> left;
    
    for(int i=0;i<A.size();i++)
    {
        if(s.size() == 0)
         left.push_back(-1);
         
        else if(s.size() >0 && A[s.top()] < A[i])
            left.push_back(s.top());
            
        else if(s.size() > 0 && A[s.top()] >= A[i])
        {
            while(s.size() > 0 && A[s.top()] >= A[i])
             s.pop();
             
             if(s.size() == 0)
             left.push_back(-1);
             
             else
             left.push_back(s.top());
        }
        
        s.push(i);
    }
    
    return left;
    
}


vector <int> nearestSmallerRight(vector <int> A)
{
    stack <int> s;
    vector <int> right;
    
    for(int i=A.size()-1;i>=0;i--)
    {
        if(s.size() == 0)
         right.push_back(A.size());
         
         else if(s.size() >0 && A[s.top()] < A[i])
         right.push_back(s.top());
         
         else if(s.size() >0 && A[s.top()] >= A[i])
         {
             while(s.size() > 0 && A[s.top()] >= A[i])
             s.pop();
             
             if(s.size() == 0)
             right.push_back(A.size());
             
             else 
             right.push_back(s.top());
         }
         
         
         s.push(i);
    }
    
    reverse(right.begin() , right.end());
    
    return right;
}
int largestRectangleArea(vector<int> &A) {
    
    vector <int> nsl = nearestSmallerLeft(A);
    vector <int> nsr = nearestSmallerRight(A);
    
    vector <int> width;
    
    for(int i=0;i<A.size();i++)
        width.push_back(nsr[i] - nsl[i] -1);
        
    
    int ans = INT_MIN;
    
    for(int i=0;i<A.size();i++)
       ans = max(ans , width[i]*A[i]);
       
       
       return ans;
}
int Solution::maximalRectangle(vector<vector<int> > &A) {
   
   for(int i=1;i<A.size();i++)
    {
        for(int j=0;j<A[i].size();j++)
        {
            if(A[i][j]==0)
            continue;
            
            else
             A[i][j] = A[i][j]+A[i-1][j];
        }
    }
    
    int ans =0;
    
    for(int i=0;i<A.size();i++)
      ans = max(ans , largestRectangleArea(A[i]));
      
      
     return ans;
}


