/*
FUNKY CHESS BOARD
A knight is a piece used in the game of chess. The chessboard itself is square array of cells. Each time a knight moves, its resulting position is two rows and one column, or two columns and one row away from its starting position. Thus a knight starting on row r, column c – which we’ll denote as (r,c) – can move to any of the squares (r-2,c-1), (r-2,c+1), (r-1,c-2), (r-1,c+2), (r+1,c-2), (r+1,c+2), (r+2,c-1), or (r+2,c+1). Of course, the knight may not move to any square that is not on the board.

Suppose the chessboard is not square, but instead has rows with variable numbers of columns, and with each row offset zero or more columns to the right of the row above it. The figure to the left illustrates one possible configuration. How many of the squares in such a modified chessboard can a knight, starting in the upper left square (marked with an asterisk), not reach in any number of moves without resting in any square more than once? Minimize this number.

If necessary, the knight is permitted to pass over regions that are outside the borders of the modified chessboard, but as usual, it can only move to squares that are within the borders of the board.


Input Format:
First line contains an integer n, representing the side of square of chess board. The next n line contains n integers separated by single spaces in which jjth integer is 1 if that cell(i,j) is part of chessboard and 0 otherwise.

Constraints:
The maximum dimensions of the board will be 10 rows and 10 columns. That is, any modified chessboard specified by the input will fit completely on a 10 row, 10 column board. 

Output Format:
Print the minimum number of squares that the knight can not reach.

Sample Input:
3
1 1 1
1 1 1
1 1 1
Sample Output:
1
Time Limit: 1 sec
*/


//https://hack.codingblocks.com/contests/c/537/715
#include <iostream>
#include <climits>

using namespace std;

int res = INT_MAX ;             //Variable to store the final answer

//Cells marked 0 are not in the board
//Cells marked 1 are in the board but not visited
//Cells marked 2 are in the board and visited already
bool knight(int board[][15],int n,int r,int c,int count)
{
    //Base cases
    if(board[r][c]==2){
       //Already visited
       return false;   
    }

    if(r>=n || r<0 ||c<0 || c>=n || board[r][c] == 0){
        //Out of bounds
        return false;
    }

    if(board[r][c]==1){
        //Mark the cell has visited and reduce the count of unvisited cells
        count--;
        board[r][c] = 2;    
    }
    
    //Try to move the knight in all 8 possible ways
    bool x1 = knight(board,n,r-2,c-1,count);
    bool x2 = knight(board,n,r-2,c+1,count);
    bool x3 = knight(board,n,r-1,c-2,count);
    bool x4 = knight(board,n,r-1,c+2,count);
    bool x5 = knight(board,n,r+1,c-2,count);
    bool x6 = knight(board,n,r+1,c+2,count);
    bool x7 = knight(board,n,r+2,c-1,count);
    bool x8 = knight(board,n,r+2,c+1,count);

    //Backtrack
    board[r][c] = 1;
    count++;

    if(!(x1||x2||x3||x4||x5||x6||x7||x8)){
        //If all return false , knight is stuck 
        //Store the least number of unvisited cells in res
        res = min(res,count-1);
        return true;
    }

    return false;
}

int main() 
{
    int board[15][15];
    int n;
    int count = 0;		//Variable to store the number of unvisited cells
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){    
            cin>>board[i][j];
            if(board[i][j] == 1)
                count++;
        }
    }
    
    knight(board,n,0,0,count);

    cout<<res<<endl;

    return 0;
}

