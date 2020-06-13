

Given an array of size n, find the majority element. The majority element is the element that appears more than floor(n/2) times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example :

Input : [2, 1, 2]
Return  : 2 which occurs 2 times which is greater than 3/2. 


______________________________________________________________________________________________________________________________________________________________________________


int Solution::majorityElement(const vector<int> &A) {
    
    map<int,int> mp;
    for(int i=0;i<A.size();i++)
     mp[A[i]]++;
     
     for(auto it=mp.begin();it != mp.end();it++)
         if((it->second) > (A.size() /2 ))
             return it->first;
             
    return -1;
}

