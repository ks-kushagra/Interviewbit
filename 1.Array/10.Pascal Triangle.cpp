

Given numRows, generate the first numRows of Pascal’s triangle.

Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:

Given numRows = 5,

Return

[
     [1],
     [1,1],
     [1,2,1],
     [1,3,3,1],
     [1,4,6,4,1]
]

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



vector<vector<int> > Solution::solve(int A) {
    vector<vector<int> > pas;
    vector<int > V;
    if(A==0){
        return pas;
    }
     V.push_back(1);
    if(A==1){
    pas.push_back(V);
        return pas;
    }
    
   pas.push_back(V);
   vector<int> M;
        M.push_back(1);
        M.push_back(1);
    if(A==2){
        
        pas.push_back(M);
        return pas;
    }
    pas.push_back(M);
    for(int i=2;i<A;i++){
        vector<int> V1;
        for(int j =0;j<=i;j++){
            if(j==0){
                V1.push_back(pas[i-1][j]);
            }
            else if(j==i){
                V1.push_back(pas[i-1][j-1]);
            }
            else{
                V1.push_back(pas[i-1][j]+pas[i-1][j-1]);
            }
        }
        pas.push_back(V1);
    }
    return pas;
}
