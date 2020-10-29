/*
You are given an N*M grid. Each cell (i,j) in the grid is either blocked, or empty. The rat can move from a position towards left, right, up or down on the grid.
Initially rat is on the position (1,1). It wants to reach position (N,M) where it's cheese is waiting for. There exits a unique path in the grid . Find that path and help the rat reach its cheese.


Input Format:
First line contains 2 integers N and M denoting the rows and columns in the grid.
Next N line contains M characters each. An 'X' in position (i,j) denotes that the cell is blocked and ans 'O' denotes that the cell is empty.

Constraints:
1 <= N , M <= 10

Output Format:
Print N lines, containing M integers each. A 1 at a position (i,j) denotes that the (i,j)th cell is covered in the path and a 0 denotes that the cell is not covered in the path.
If a path does not exits then print "NO PATH FOUND"

Sample Input:
5 4
OXOO
OOOX
XOXO
XOOX
XXOO
Sample Output:
1 0 0 0 
1 1 0 0 
0 1 0 0 
0 1 1 0 
0 0 1 1 
Time Limit: 2 sec
*/
//https://hack.codingblocks.com/contests/c/537/570
#include <iostream>
using namespace std;

bool ratCheese(char grid[][15],int sol[][15],int r,int c,int i,int j){
    //Base case - rat reached the cheese
    if(i==r-1 && j==c-1){
        sol[i][j] = 1;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cout<<sol[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }

    //already visited
    if(sol[i][j]==1){
        return false;
    }

    //out of bounds condition
    if(i>=r || j>=c ||i<0 ||j<0){
        return false;
    }

    //encountered a blocked cell
    if(grid[i][j] =='X'){
        return false;
    }

    //Rec case
    //Assume solution exists through current cell
    sol[i][j] = 1;

    bool rightSuccess = ratCheese(grid,sol,r,c,i,j+1);
    if(rightSuccess)
        return true;
    bool downSuccess = ratCheese(grid,sol,r,c,i+1,j);
    if(downSuccess)
        return true;
    bool leftSuccess = ratCheese(grid,sol,r,c,i,j-1);
    if(leftSuccess)
        return true;
    bool upSuccess = ratCheese(grid,sol,r,c,i-1,j);
    if(upSuccess)
        return true;

    //Backtrack
    sol[i][j] = 0;

    return false;    
}

int main() {
    int row,col;
    char grid[15][15];
    cin>>row>>col;
    for(int i=0;i<row;i++){
        cin>>grid[i];
    }
    int sol[15][15]= {0};
    bool ans = ratCheese(grid,sol,row,col,0,0);
    if(!ans){
        cout<<"NO PATH FOUND";
    }

    return 0;
}

