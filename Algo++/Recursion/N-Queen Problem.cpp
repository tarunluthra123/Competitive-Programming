#include <iostream>
using namespace std;
bool isSafe(int board[][10],int i,int j,int n)
{
    //Check for column
    for(int row=0;row<i;row++)
    {
        if(board[row][j]==1)
            return false;
    }

    //Check for left diagonal
    int x = i;
    int y = j;
    while(x>=0 && y>=0)
    {
        if(board[x][y] == 1)
            return false;

        x--;
        y--;
    }

    //Check for right diagonal
    x = i;
    y = j;
    while(x>=0 && y<n)
    {
        if(board[x][y] == 1)
            return false;

        x--;
        y++;
    }

    //Position is safe
    return true;
}
bool solveNQueen(int board[][10],int i,int n)
{
    //Base case
    if(i==n)
    {
        //Successfully placed the queens in n rows (0...n-1)
        //Print the board
        for(int k=0;k<n;k++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[k][j] == 1)
                    cout<<"Q ";
                else
                    cout<<"_ ";
            }
            cout<<endl;
        }
        //cout<<endl<<endl;
        return true;
        //return false;
        //use false if you want to print all possible configurations
    }

    

    //Recursive case
    //Try to place the queen in the current row and call on the 
    //remaining part which  will be solved by recursion
    for(int j=0;j<n;j++)
    {
        //check if (i,j)th postion is safe
        if(isSafe(board,i,j,n))
        {
            //Place the queen - assuming that this is the right position
            board[i][j] = 1;

            //check for remaining part
            if(solveNQueen(board,i+1,n))
                return true;

            //(i,j) is not the right position
            //Our assumption was wrong
            board[i][j] = 0;    //Backtrack
        }
    }
    
    //We have tried all positions in current row but couldn't place a queen
    return false;


}//end of solveNQueen()


int main() 
{
    int board[10][10];
    int n;
    cin>>n;

    solveNQueen(board,0,n);

    return 0;
}

