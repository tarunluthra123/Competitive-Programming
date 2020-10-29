/*
ARRAYS-SPIRAL PRINT ANTICLOCKWISE
Take as input a 2-d array. Print the 2-D array in spiral form anti-clockwise.

Input Format:
Two integers M(row) and N(colomn) and further M * N integers(2-d array numbers).

Constraints:
Both M and N are between 1 to 10.

Output Format
All M * N integers separated by commas with 'END' written in the end(as shown in example).

Sample Input
4 4
11 12 13 14
21 22 23 24
31 32 33 34
41 42 43 44
Sample Output
11, 21, 31, 41, 42, 43, 44, 34, 24, 14, 13, 12, 22, 32, 33, 23, END
*/
#include<iostream>
using namespace std;
int main() 
{ int a[11][11],m,n,i,j;
  cin>>m>>n;
  for(i=0;i<m;i++)
  { for(j=0;j<n;j++)
    { cin>>a[i][j]; }
  }
  
  int startRow=0,endRow=m-1,startCol=0,endCol=n-1;
  while(startRow<=endRow && startCol<=endCol)
  {

      for(i=startRow;i<=endRow;i++)
        { 
          cout<<a[i][startCol]<<", ";
        }
        startCol++;

      for(i=startCol;i<=endCol;i++)
        { 
          cout<<a[endRow][i]<<", ";
        }
        endRow--;

      
      if(startCol<=endCol)
      {
          for(i=endRow;i>=startRow;i--)
           {
              cout<<a[i][endCol]<<", "; 
           }
      endCol--;
      }
      if(startRow<=endRow)
      {
        for(i=endCol;i>=startCol;--i)
        {   
             cout<<a[startRow][i]<<", ";
        }
      startRow++;
      }
      
        
      
       
  }
  cout<<"END";
  
	return 0;
}

