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
  while(startRow<endRow && startCol<endCol)
  {
      for(i=startCol;i<=endCol;i++)
      {   
        cout<<a[startRow][i]<<", ";
      }
      startRow++;
      
      for(i=startRow;i<=endRow;i++)
      {
       cout<<a[i][endCol]<<", "; 
      }
      endCol--;
      if(startRow<=endRow)
      {
        for(i=endCol;i>=startCol;i--)
        { 
          cout<<a[endRow][i]<<", ";
        }
        endRow--;
      }
      if(startCol<=endCol)
      {
        for(i=endRow;i>=startRow;i--)
        { 
          cout<<a[i][startCol]<<", ";
        }
        startCol++;
      }
       
  }
  cout<<"END";
  
	return 0;
}

