

Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details.

Example:

		
Input: 	

1 2 3
4 5 6
7 8 9

Return the following :

[ 
  [1],
  [2, 4],
  [3, 5, 7],
  [6, 8],
  [9]
]


Input : 
1 2
3 4

Return the following  : 

[
  [1],
  [2, 3],
  [4]
]

------------------------------------------------------------------------------------------------------------------------------------------------------------------------


vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    
    int n = A.size();
    
    if(n==0)
    return vector <vector<int> >();
    
    
    vector <vector<int> > ans(2*n -1);
    
    for(int i=0;i<n;i++)
     {
         for(int j =0 ;j<n;j++)
           {
               ans[(i+j)].push_back(A[i][j]);
           }
     }
     
     return ans;
}




_____________________________________________________________________________________________________________________________________________________________________________________
vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    vector<vector <int>> hash;
    int n = A[0].size();
    if(n==0){
        return hash;
    }
    if(n==1){
        vector<int> M;
        M.push_back(A[0][0]);
         hash.push_back(M);
         return hash;
    }
    vector<vector<int> > ha((2*A.size()-1)+1);
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            ha[i+j].push_back(A[i][j]);
        }
    }
   
    return ha;
}

