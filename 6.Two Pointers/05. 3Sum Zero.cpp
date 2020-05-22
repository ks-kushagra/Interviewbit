


Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.

Note:

    Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
    The solution set must not contain duplicate triplets.

    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2) 


________________________________________________________________________________________________________________________________________________________________________________________

vector<vector<int> > Solution::threeSum(vector<int> &A) {

 vector <vector <int> > ans;
 int n = A.size();
 if(n <=2)
  return ans;
  
  sort(A.begin() , A.end());
  
 int i,j,k;
 i=0;
 while( i < n-2)
 {
     j = i+1;
     k = n-1;
     
     while( j < k)
     {
         long sum = (long)A[i] + (long)A[j] + (long)A[k];
         
         if(sum == 0)
         {
             vector <int> t(3);
             t[0]=A[i];
             t[1]=A[j];
             t[2]= A[k];
             if(find(ans.begin() , ans.end() , t) == ans.end())
             ans.push_back(t);
             
             j++;
         }
         
         else if(sum < 0)
           j++;
           
          else k--;
     }
     
     i++;
 }
    return ans;
}
