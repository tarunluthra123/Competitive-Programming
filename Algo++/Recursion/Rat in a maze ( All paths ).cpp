#include <iostream>
using namespace std;
bool ratInMaze(char maze[][10],int sol[][10],int i,int j,int m,int n)
{
    //Base case
    if(i==m && j==n)
    {
        sol[i][j] = 1;
        for(int row=0;row<=m;row++)
        {
            for(int col=0;col<=n;col++)
            {
                cout<<sol[row][col]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }

    //Rat should be inside the maze
    if(i>m || j>n)
        return false;

    //Should not encounter a blocked cell
    if(maze[i][j] == 'X')
        return false;

    //Recursive case
    //Assume solution exists through current cell
    sol[i][j] = 1;

    bool rightSuccess = ratInMaze(maze,sol,i,j+1,m,n);
    bool downSuccess  = ratInMaze(maze,sol,i+1,j,m,n);

    //Backtrack
    sol[i][j] = 0;

    if(rightSuccess || downSuccess)
        return true;

    return false;

}
int main() 
{
    char maze[10][10] = {
                            "0000",
                            "00X0",
                            "000X",
                            "0X00",
    };

    int sol[10][10]= {0};
    int m = 4;
    int n = 4;

    bool ans = ratInMaze(maze,sol,0,0,m-1,n-1);
    if(!ans)
        cout<<"path not found";


    return 0;
}

