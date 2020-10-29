//N Queen Problem using bitsets
//Returns the number of possible configurations for N-Queen board for a given N in a few lines 
#include <iostream>
#include <bitset>
using namespace std;

bitset<30> col,d1,d2;

void solveNQueen(int board[][10],int r,int n,int &ans)
{
    if(r == n )
    {   
		ans++;      
		for(int i=0;i<n;i++)
		{	for(int j=0;j<n;j++)
			{
				cout<<board[i][j]<<" ";
			}
			cout<<endl;
		}
		return ;
	}

    for(int c=0;c<n;c++)
    {
        if(!col[c] && !d1[r-c+n-1] && !d2[r+c] )
        {
            col[c] = d1[r-c+n-1]  = d2[r+c] = board[r][c] = 1;
            solveNQueen(r+1,n,ans);
            col[c] = d1[r-c+n-1]  = d2[r+c] = board[r][c] = 0;
        }
    }
}
int main() 
{
    int n;
    int board[10][10];
    cin>>n;
    int ans = 0;
    solveNQueen(board,0,n,ans);
    cout<<ans;
    return 0;
}

