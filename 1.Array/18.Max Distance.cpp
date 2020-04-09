

Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].

If there is no solution possible, return -1.

Example :

A : [3 5 4 2]

Output : 2 
for the pair (3, 4)


------------------------------------------------------------------------------------------------------------------------------------------------------------


int Solution::maximumGap(const vector<int> &A) {
    
  int n=A.size();
  int sol=0;
    if(n==1) 
    return 0;
    vector<pair<int,int> >v;
    
    for(int i=0;i<n;i++){
        v.push_back(make_pair(A[i],i));
    }
    
    sort(v.begin(),v.end());
    
    int rmax=v[n-1].second;
    for(int i=n-2;i>=0;i--){
        sol=max(sol,rmax-v[i].second);
        rmax=max(rmax,v[i].second);
    }
    return sol;
}

