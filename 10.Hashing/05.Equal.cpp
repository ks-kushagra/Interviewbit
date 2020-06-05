

Given an array A of integers, find the index of values that satisfy A + B = C + D, where A,B,C & D are integers values in the array

Note:

1) Return the indices `A1 B1 C1 D1`, so that 
  A[A1] + A[B1] = A[C1] + A[D1]
  A1 < B1, C1 < D1
  A1 < C1, B1 != D1, B1 != C1 

2) If there are more than one solutions, 
   then return the tuple of values which are lexicographical smallest. 

Assume we have two solutions
S1 : A1 B1 C1 D1 ( these are values of indices int the array )  
S2 : A2 B2 C2 D2

S1 is lexicographically smaller than S2 iff
  A1 < A2 OR
  A1 = A2 AND B1 < B2 OR
  A1 = A2 AND B1 = B2 AND C1 < C2 OR 
  A1 = A2 AND B1 = B2 AND C1 = C2 AND D1 < D2

Example:

Input: [3, 4, 7, 1, 2, 9, 8]
Output: [0, 2, 3, 5] (O index)

If no solution is possible, return an empty list.

_________________________________________________________________________________________________________________________________________________________________________


vector<int> Solution::equal(vector<int> &A) {
    
    map<int , pair<int,int> > mp;
    vector<vector<int> > ans;
    for(int i=0;i<A.size();i++)
      for(int j=i+1;j<A.size();j++)
         {
             if(mp.find(A[i]+A[j]) != mp.end())
             {
                 if(i !=mp[A[i]+A[j]].first && j != mp[A[i]+A[j]].first && i !=mp[A[i]+A[j]].second&& j != mp[A[i]+A[j]].second )
                { vector <int> temp(4);
                 temp[2]=i;
                 temp[3] =j;
                 temp[0] = mp[A[i]+A[j]].first;
                 temp[1] =mp[A[i]+A[j]].second;
                 //sort(temp.begin(),temp.end());
                 ans.push_back(temp);
                }
             }
             
             else
              mp[A[i]+A[j]] = {i,j};
         }
        
        
        if(ans.size() == 0)
         return vector <int> ();
        
        sort(ans.begin(),ans.end());
        return ans[0];

}
