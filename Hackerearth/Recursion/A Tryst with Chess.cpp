/*
https://www.hackerearth.com/practice/basic-programming/recursion/recursion-and-backtracking/practice-problems/algorithm/a-tryst-with-chess/

A Tryst With Chess
You are given a 10X10 chessboard with a knight on coordinate (I,J). You have to find the number of blocks on the chessboard that the knight can be at in exactly N moves.

NOTE: The knight can move from its positon in the diagram to all the coordinates marked by X in the following diagram in one move. For the 10X10 chessboard 
(1,1) is the top-left corner,(1,10) is the top-right corner and (10,10) is the bottom-right corner.  

INPUT

Input will consist of three space seperated integers I,J,N

N is less than 10.

OUTPUT

Print a single integer denoting the number of blocks on the chessboard that the knight can be at in exactly N moves.

Problem Setter - Sheldon

SAMPLE INPUT 
3 3 1
SAMPLE OUTPUT 
8
*/
 
 #include <iostream>
using namespace std;
int arr[10][10] = {0};
int knight(int i,int j,int n)
{
    //Base cases
    int temp=0; 
    if(n<0)
    return 0;

    if(i<0||i>9||j<0||j>9)
    return 0;

    if(arr[i][j]==1&&n==0)
    return 0;

    if(n==0)
    {
       temp=1;
       arr[i][j]=1;
    }


    //Recursive case
    int x1 = knight(i-2,j-1,n-1);
    int x2 = knight(i-2,j+1,n-1);
    int x3 = knight(i-1,j-2,n-1);
    int x4 = knight(i-1,j+2,n-1);

    int x5 = knight(i+1,j-2,n-1);
    int x6 = knight(i+1,j+2,n-1);
    int x7 = knight(i+2,j-1,n-1);
    int x8 = knight(i+2,j+1,n-1);

    return temp+x1+x2+x3+x4+x5+x6+x7+x8;
}
int main() 
{
    int i,j,n;
    cin>>i>>j>>n;
    cout<<knight(i-1,j-1,n);
    return 0;
}

