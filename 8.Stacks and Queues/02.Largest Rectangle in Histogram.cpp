

Given an array of integers A of size N. A represents a histogram i.e A[i] denotes height of
the ith histogram’s bar. Width of each bar is 1.

Largest Rectangle in Histogram: Example 1

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

Largest Rectangle in Histogram: Example 2

The largest rectangle is shown in the shaded area, which has area = 10 unit.

Find the area of largest rectangle in the histogram.



Input Format

The only argument given is the integer array A.

Output Format

Return the area of largest rectangle in the histogram.

For Example

Input 1:
    A = [2, 1, 5, 6, 2, 3]
Output 1:
    10
    Explanation 1:
        The largest rectangle is shown in the shaded area, which has area = 10 unit.


_________________________________________________________________________________________________________________________________________________________________________________________


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
int Solution::largestRectangleArea(vector<int> &A) {
    
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
