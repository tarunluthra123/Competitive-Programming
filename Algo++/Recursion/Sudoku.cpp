#include <iostream>
using namespace std;
bool isSafe(int a[][10],int n,int i,int j,int value)
{
    //Check horizontally and vertically 
    for(int x=0;x<n;x++)
    {
        if(a[i][x] == value ||a[x][j] == value)
            return false;
    }
    
    //Check in 3*3 square
    //First find the square
    int x = i/3;
    int y = j/3;
    for(int row=(x*3);row<((x*3)+3);row++)
    {    for(int col=(y*3);col<((y*3)+3);col++)
         {   
             if(a[row][col] == value)
                return false;
         }
    }
    //position is safe
    return true;
}

bool sudoku(int a[][10],int n,int currentNumber,int currentRow)
{
    //Base case
    if(currentRow>=n && currentNumber>=n)
        return true;

    //Recursive case
    if(currentRow>=n)
    {
        //currentNumber placed in the sudoku ...try for the next number
        //return false and backtrack in case this is not correct
        return sudoku(a,n,currentNumber+1,0);
    }
    
    //Check if currentNumber is already present in the row
    bool present = false;
    for(int j=0;j<n;j++)
    {
        if(a[currentRow][j] == currentNumber)
        {
            present = true;    break;
        }
    }
    if(present)
    {
        //Number is already present in this row as input ...move to next row
        if(sudoku(a,n,currentNumber,currentRow+1))
            return true;
    }

    //Number is not present in this row
    else
    {
        //find an empty position
        for(int j=0;j<n;j++)
        {
            if(a[currentRow][j] == 0)
            {
                //Check if this position is safe to place the number
                if(isSafe(a,n,currentRow,j,currentNumber))
                {
                    //cout<<"placed at ("<<currentRow<<","<<j<<")\n";
                    //Place the number at (currentRow,j) ...assuming it is the right position
                    a[currentRow][j] = currentNumber;

                    //Check for the remaining part
                    if(sudoku(a,n,currentNumber,currentRow+1))
                        return true;

                    //(currentRow,j) is not the riht position ...assumption was wrong
                    a[currentRow][j] = 0;   //Backtrack
                    //cout<<"backtracked at ("<<currentRow<<","<<j<<")\n";
                }
            }
        }
    }

    //could not place this number in this entire row
    return false;
}


int main()
{
    int n;
    cin>>n;
    int a[10][10];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    
    sudoku(a,n,1,0);
    
    for(int i=0;i<n;i++)
    {   for(int j=0;j<n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
      
    return 0;
}
