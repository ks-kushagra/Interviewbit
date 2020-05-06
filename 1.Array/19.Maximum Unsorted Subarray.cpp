

You are given an array (zero indexed) of N non-negative integers, A0, A1 ,…, AN-1.
Find the minimum sub array Al, Al+1 ,…, Ar so if we sort(in ascending order) that sub array, then the whole array should get sorted.
If A is already sorted, output -1.

Example :

Input 1:

A = [1, 3, 2, 4, 5]

Return: [1, 2]

Input 2:

A = [1, 2, 3, 4, 5]

Return: [-1]

In the above example(Input 1), if we sort the subarray A1, A2, then whole array A should get sorted.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

vector<int> Solution::subUnsort(vector<int> &A) {
    
    int n = A.size();
    vector <int> ans;
    
    int l=0;
    int r = n-1;
    while(l < n-1 && A[l]<= A[l+1])
     l++;
     
     while(r>0 && A[r-1] <= A[r])
       r--;
       
    
    if(l > r){
     ans.push_back(-1);
     return ans;
    }
       
    int max_between=INT_MIN;
    int min_between=INT_MAX;
    for(int i=l;i<=r;i++)
    {
        max_between = max(max_between,A[i]);
        min_between = min(min_between , A[i]);
    }
    
    int l1=-1;
    int r1=-1;
    int max_left=INT_MIN;
    int min_right = INT_MAX;
    
    for(int i=0;i<l;i++)
      {
          if(min_between < A[i])
             {
                 l =i;
                 break;
             }
      }
      
      for(int i=n-1;i>r;i--)
      {
          if(max_between > A[i])
          {
              r = i;
              break;
          }
      }

    ans.push_back(l);
    ans.push_back(r);
    
    return ans;
     
}

____________________________________________________________________________________________________________________________________________________________________________________________________________
int sorted(vector<int> &A){
    for(int i =0;i<A.size()-1;i++){
        if(A[i]>A[i+1]){
            return 0;
        }
    }
    return 1;
}
int MAX(vector<int> &A,int l,int r){
    int max = A[l];
    for(int i=l;i<=r;i++){
        if(max<A[i]){
            max = A[i];
        }
    }
    return max;
}
int MIN(vector<int> &A,int l,int r){
    int min = A[l];
    for(int i=l;i<=r;i++){
        if(A[i]<min){
            min=A[i];
        }
    }
    return min;
}
vector<int> Solution::subUnsort(vector<int> &A) {
     vector<int> v1;
    if(A.size()==0){
        v1.push_back(-1);
        return v1;
    }
     if(sorted(A)){
        v1.push_back(-1);
        return v1;
    }
    
    
    vector<int> v;
    int n = A.size();
    int l=0;
    int r = A.size()-1;
    while(l<n-1&&A[l+1]>=A[l]){
        l++;
    }
    
    while(r>0&&A[r]>=A[r-1]){
        r--;
    }
    
    
    int max = MAX(A,l,r);
    int min = MIN(A,l,r);
    for(int i=0;i<l;i++){
        if(A[i]>min){
            l=i;
            break;
        }
    }
    for(int i=n-1;i>r;i--){
        if(A[i]<max){
            r=i;
            break;
        }
    }
    v.push_back(l);
    v.push_back(r);
    return v;
}
