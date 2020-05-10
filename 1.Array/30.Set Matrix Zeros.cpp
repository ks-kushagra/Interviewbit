

Given a matrix, A of size M x N of 0s and 1s. If an element is 0, set its entire row and column to 0.

Note: This will be evaluated on the extra memory used. Try to minimize the space and time complexity.


Input Format:

The first and the only argument of input contains a 2-d integer matrix, A, of size M x N.

Output Format:

Return a 2-d matrix that satisfies the given conditions.

Constraints:

1 <= N, M <= 1000
0 <= A[i][j] <= 1

Examples:

Input 1:
    [   [1, 0, 1],
        [1, 1, 1], 
        [1, 1, 1]   ]

Output 1:
    [   [0, 0, 0],
        [1, 0, 1],
        [1, 0, 1]   ]

Input 2:
    [   [1, 0, 1],
        [1, 1, 1],
        [1, 0, 1]   ]

Output 2:
    [   [0, 0, 0],
        [1, 0, 1],
        [0, 0, 0]   ]



_____________________________________________________________________________________________________________________________________________________________________________



void Solution::setZeroes(vector<vector<int> > &A) {
    
    int n = A.size();
    int m = A[0].size();
     vector <pair<int,int> > v;
     vector <int> row(n,1);
     vector <int> col(m,1);
     
     for(int i=0;i<n;i++)
       for(int j =0;j<m;j++)
           if(A[i][j] == 0)
            v.push_back({i,j});
            
            
    for(int i=0;i<v.size();i++)
    {
        int x = v[i].first;
        int y = v[i].second;
        
        if(row[x] == 1)
        {
            vector <int> t(m,0);
            A[x] = t;
            row[x]=0;
        }
        
        if(col[y]==1)
        {
            for(int k=0;k<n;k++)
                 A[k][y]=0;
                 
            col[y]=0;
        }
    }
}
