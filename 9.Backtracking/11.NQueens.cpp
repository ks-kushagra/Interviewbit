

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

N Queens: Example 1

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens’ placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]




_________________________________________________________________________________________________________________________________________________________________________________________________

int isSafe(vector<vector<string> > grid, int i,int j)
{
    int n = grid.size();
    int m = grid[0].size();
    
    
    //row attack
    for(int l = 0;l<n ;l++)
    {
        if(grid[l][j] == "Q")
         return 0;
    }
    
    //column attack
    for(int l = 0;l<m;l++)
    {
        if(grid[i][l] == "Q")
        return 0;
    }
    
    
    //diagonal attack
    
    for(int l=i,r=j;l>=0 && r>=0; l--,r--)
    {
        if(grid[l][r]=="Q")
        return 0;
    }
    
    for(int l=i,r=j;l>=0 && r<m; l--,r++)
    {
        if(grid[l][r]=="Q")
        return 0;
    }
    
  for(int l=i,r=j;l<n && r>=0; l++,r--)
    {
        if(grid[l][r]=="Q")
        return 0;
    }  
    
    for(int l=i,r=j;l<n && r<m; l++,r++)
    {
        if(grid[l][r]=="Q")
        return 0;
    }
    
    return 1;
}
void solve(vector<vector<string> > &ans ,vector<vector<string> > grid, int i)
{
    if(i == grid.size())
       {
           vector<string> temp;
           for(int i1=0;i1<grid.size();i1++)
           {
               string t="";
               for(int j=0;j<grid[i1].size();j++)
                  t=t+grid[i1][j];
                  
              temp.push_back(t);
           }
           
           ans.push_back(temp);
           return;
       }
       
       
     for(int p = 0;p<grid[i].size();p++)
     {
         if(isSafe(grid , i , p))
         {
             grid[i][p]="Q";
             solve(ans,grid, i+1);
             grid[i][p]=".";
         }
     }
}
vector<vector<string> > Solution::solveNQueens(int A) {
    vector <vector <string> > ans;
    vector<vector<string> > grid(A , vector <string> (A , "."));
    solve(ans,grid, 0);
    return ans;
}



_________________________________________________________________________________________________________________________________________________________________________________________________________________
bool isSafe(vector<vector<string>> &testBoard, int row, int col, int A)
{
    for(int j=0;j<col;j++)
    {
        if(testBoard[row][j]=="Q")
            return false;
    }
    for(int i=row,j=col;i>=0 && j>=0;i--,j--)
    {
        if(testBoard[i][j]=="Q")
            return false;
    }
    for(int i=row,j=col;i<A && j>=0;i++,j--)
    {
        if(testBoard[i][j]=="Q")
            return false;
    }
    return true;
}
bool backtrack(vector<vector<string>> &board, vector<vector<string>> &testBoard, int col, int A)
{
    if(col==A)
    {
        vector<string> emptyRow;
        board.push_back(emptyRow);
        int size=board.size();
        for(int i=0;i<A;i++)
        {
            string c="";
            for(int j=0;j<A;j++)
                c+=testBoard[i][j];
            board[size-1].push_back(c);
        }
        return false;
    }
    for(int i=0;i<A;i++)
    {
        if(isSafe(testBoard,i,col,A))
        {
            testBoard[i][col]="Q";
            if(!backtrack(board,testBoard,col+1,A))
                testBoard[i][col]=".";
            else
                return true;
        }
    }
    return false;
}
vector<vector<string>> Solution::solveNQueens(int A) 
{
    vector<vector<string>> testBoard;
    
    if(A==2 || A==3)
        return testBoard;
        
    vector<string> v(A,".");
    
    for(int i=0;i<A;i++)
        testBoard.push_back(v);
        
    vector<vector<string>> board;
    
    backtrack(board,testBoard,0,A);
    
    return board;
}

