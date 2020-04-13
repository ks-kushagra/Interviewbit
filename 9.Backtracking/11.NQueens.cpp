

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

