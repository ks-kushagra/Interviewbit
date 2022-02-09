Given an integer array, find if an integer p exists in the array such that the number of integers greater than p in the array equals to p
If such an integer is found return 1 else return -1.
    
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    
int Solution::solve(vector<int> &A) {
    sort(A.begin(),A.end());
    
    for(auto it = A.begin();it != A.end();it++){
        auto up = upper_bound(A.begin() , A.end() , *it);
        if(*it == distance(up , A.end())){
            return 1; 
        }
    }
    return -1;
}

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------



int Solution::solve(vector<int> &A) {
    sort(A.begin(),A.end());
     int n = A.size();
     if(A[n-1]==0){
         return 1;
     }
    for(int i=0;i<n-1;i++){
        if(A[i]>=0){
        if(A[i]==(n-i-1)&&A[i]!=A[i+1]){
            return 1;
         }
        }
    }
    return -1;
}
