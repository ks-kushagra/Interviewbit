

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Example:
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.

________________________________________________________________________________________________________________________________________

int Solution::longestConsecutive(const vector<int> &A) {
    
    map <int,int> mp;
    
    for(int i=0;i<A.size();i++)
     mp[A[i]] =1;
     
     int cur=0;
     int max_len = 0;
     for(auto i = mp.begin() ; i!= mp.end() ;)
     {
         if((i->first) +1 == (((++i)->first)))
          {
              cur++;
              max_len = max(max_len , cur);
          }
          else
          cur=0;
     }
     
     return max_len+1;
}
