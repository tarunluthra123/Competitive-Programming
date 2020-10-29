/* Program for performing various operations on matrices using pointer representation
   Made by Tarun Luthra
   Roll No. = 2018 CSC 1023   																	*/
#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int** getmatrix(int **p, int r, int c)								//function to allot memory dynammically and take input for matrix
{ p= new int* [r];
  for(int i=0;i<r;i++) 
  { *(p+i) = new int[c]; }
	for(int i=0;i<r;i++)
  { cout<<"Enter "<<c<<" elements for Row "<<i+1<<endl;
	for(int j=0;j<c;j++)
	{ cin>>*(*(p+i)+j); }
  }
  return p;
}
int** sumof2matrix(int **matrix1,int **matrix2,int r,int c)		//returns a third matrix having sum of 2 matrices
{   int **board;
	board=new int* [r];
	for(int i=0;i<r;i++)
	{ *(board+i) = new int[c]; } 
	for(int i=0;i<r;i++)
  {	for(int j=0;j<c;j++)
	{ *(*(board+i)+j)=*(*(matrix1+i)+j) + *(*(matrix2+i)+j); }
  }
  return board;
}


int** differenceof2matrix(int **matrix1,int **matrix2,int r,int c)	//returns a third matrix having difference of 2 matrices
{   int **board;
	board=new int* [r];
	for(int i=0;i<r;i++)
	{ *(board+i) = new int[c]; } 
	for(int i=0;i<r;i++)
  {	for(int j=0;j<c;j++)
	{ *(*(board+i)+j)=*(*(matrix1+i)+j) - *(*(matrix2+i)+j); }
  }
  return board;
}
float getcofactor(int **,int,int,int) ;
float determinant(int **p,int s)
{ 	int i,j;
	float det,term=0,sum=0;  
	int **q,w;
	if(s==1)
	{ det=**p; }
	else if(s==2)
	{ //det=(**p) * (*(*p+1)+1) - *(*p+1) * *(*(p+1));
	  det= p[0][0]*p[1][1]-p[0][1]*p[1][0];  }
	else 
	{ 	sum=0;
	 	for(j=0;j<s;j++)
	 	{ 	term=*(*p+j)*getcofactor(p,s,0,j);
	 		sum+=term;
		}
		det=sum;
	}
	return det;
}
float getcofactor(int **p,int n,int g=0,int h=0) 		//function to calculate cofactor of element (g,h)
{ 	float res=0,term,k=1;
	int **q,w,i,j,i1,j1,i2,j2;
    if(n==1)
  	{ res=**p;  }
  	
  	else if(n==2)
  	{ if(g==1)
  	  g=0;
  	  else if(g==0)
  	  g=1;
  	  if(h==0)
  	  h=1;
  	  else if(h==1)
  	  h=0;
  	  res=*(*(p+g)+h);
  	}
  	else
  	{ 	k=1;  res=0;  
  		q= new int*[n-1];				//Loop for alloting memory to q
  		for(i=0;i<n-1;i++) 
 		{ *(q+i) = new int[n-1]; }
 		
 		i=g+1;	i1=0; i2=0;
 		do
  	  	{	
			if(i==n)
  	  		i=0;
		 	j=h+1; j1=0;	j2=0;
		 	do
			{ 		
			  if(j==n)
			  j=0;
			  q[i1][j1]=p[i][j];
			  //cout<<"q["<<i1<<"]["<<j1<<"]="<<q[i1][j1]<<"   ";		//to check cofactor matrix
			  j1++;  j++;  j2++;
			}while(j2<n-1);
			//cout<<endl;								
			i1++;  i++;  i2++;
		}while(i2<n-1);
		res=determinant(q,n-1); 
	}
	return res;
}
int** productofmatrices(int **matrix1,int **matrix2,int r,int c,int x)    //returns a third matrix having product of 2 matrices
{  int** board,i,j,k,l,term=0;
   board=new int* [r];
   	for(i=0;i<r;i++)				//loop for memory allocation
	{ *(board+i) = new int[c]; } 
   
   for(k=0;k<r;k++)
   { for(l=0;l<c;l++)
     { 	 for(j=0;j<x;j++)
     	{ term+=*(*(matrix1+k)+j)**(*(matrix2+j)+l); }
    	*(*(board+k)+l)=term;
    	term=0;
 	 }
   }	
  return board;
}

void printmatrix(int **p,int r, int c)					//displays the matrix
{	for(int i=0;i<r;i++)
  {  for(int j=0;j<c;j++)
	  {cout<<setw(5)<<*(*(p+i)+j);}
	  cout<<endl;
  }
}	
int**transpose(int **p,int r,int c)
{ 	int **q,i,j,nr,nc;
	nr=c;	nc=r;
	q= new int* [nr];
    for(i=0;i<nr;i++) 
 	 { *(q+i) = new int[nc]; }
 	for(i=0;i<r;i++)
	{	for(j=0;j<c;j++)
		{ *(*(q+j)+i)=*(*(p+i)+j); }
	}
	return q;
}

int** adjoint(int **p,int s)
{ 	int **adj,i,j;
	adj= new int* [s];
 	 for(i=0;i<s;i++) 
 	 { *(adj+i) = new int[s]; }
 	 for(i=0;i<s;i++)
 	 {	for(j=0;j<s;j++)
 	 	{ *(*(adj+i)+j)=getcofactor(p,s,i,j); }
 	 }
 	 adj=transpose(adj,s,s);
 	 if(s==2)
 	 { *(*(adj+0)+1)*=-1; *(*(adj+1)+0)*=-1; } 
 	 return adj;
}	
float roundto3places(float x)
{ int n=(x*1000);
  float m=n;
  m/=1000;
  return m;
}
void showinverse(int **p,int s)
{ 	int **q,i,j;
	float term=0,det;
    q= new int* [s];
 	for(i=0;i<s;i++) 
 	{ *(q+i) = new int[s]; }	
 	q=adjoint(p,s);
 	det=determinant(p,s);
 	if(det==0)
 	{ cout<<"Since determinant is 0 , inverse does not exist"; }
 	else
 	{ 
	 	for(i=0;i<s;i++)
		{	for(j=0;j<s;j++)
	  		{ term=*(*(q+i)+j)/det;
	  		  term=roundto3places(term);
			  cout<<setw(7)<<term; }
			cout<<endl;  
		}
	}
}	  
int main()
{ int **matrix1=NULL,row1,col1,**matrix2=NULL,row2,col2;
  float det1,det2;
  int x,v;
  int choice=0;
  int **matrix3,row3,col3;
  while(choice!=12)
  {
  cout<<"\n\nChoose one of the following options to continue"<<endl;
  cout<<"\n1.Enter matrix 1 "; 
  if(matrix1!=NULL)
  cout<<"again";
  cout<<"\n2.Enter matrix 2 "; 
  if(matrix2!=NULL)
  cout<<"again";
  cout<<"\n3.View first matrix\n";
  cout<<"4.View second matrix\n";
  cout<<"5.Sum of the two matrices\n";
  cout<<"6.Difference of the two matrices\n";
  cout<<"7.Product of the two matrices\n";
  cout<<"8.Transpose of a matrix\n";
  cout<<"9.Get determinant of a matrix\n";
  cout<<"10.Adjoint of a matrix\n";
  cout<<"11.Inverse of a matrix\n";
  cout<<"12.Exit Program";
  cout<<"\nEnter choice=";
  cin>>choice;   cout<<endl;
  switch(choice)
  {   case 1:     cout<<"Input for first matrix\n";
 				  cout<<"Enter no. of rows=";
				  cin>>row1;
				  cout<<"Enter no. of columns=";
				  cin>>col1; 
				  matrix1= getmatrix(matrix1,row1,col1);
				  break;
	  case 2:	 cout<<"\nInput for second matrix\n";
  				 cout<<"Enter no. of rows=";
 				 cin>>row2;
 				 cout<<"Enter no. of columns=";
     		     cin>>col2;
 				 matrix2=getmatrix(matrix2,row2,col2);	
				  break;	
	  case 3: 	if(matrix1==NULL)
	   			{ cout<<"Matrix does not exist\nChoose option 1 to enter the matrix first"; }
				else
				{   cout<<"First matrix is \n\n";
	  				printmatrix(matrix1,row1,col1);   }
				break;
	  case 4: 	if(matrix2==NULL)
	   			{ cout<<"Matrix does not exist\nChoose option 2 to enter the matrix first"; }
				else
				{   cout<<"Second matrix is \n\n";
	  				printmatrix(matrix2,row2,col2);   }
				break;  
	  case 5:   if(matrix1==NULL||matrix2==NULL)
	  				{ cout<<"Insufficient input"; }
	   			else if(row1!=row2&&col1!=col2)
				{ cout<<"Entered matrices do not have the same no. of rows/columns\nSum function cannot be used";  }
				else 
				{ row3=row1; col3=col1;
				matrix3=sumof2matrix(matrix1,matrix2,row3,col3);
				cout<<"Sum matrix is \n";
				printmatrix(matrix3,row3,col3);    					}
				break;
      case 6:   if(matrix1==NULL||matrix2==NULL)
	  				{ cout<<"Insufficient input"; }
	   			else if(row1!=row2&&col1!=col2)
				{ cout<<"Entered matrices do not have the same no. of rows/columns\nDifference function cannot be used";  }
				else
				{ row3=row1; col3=col1;
				matrix3=differenceof2matrix(matrix1,matrix2,row3,col3);
				cout<<"Difference matrix is \n";
				printmatrix(matrix3,row3,col3);  		}
				break;
	  case 7:	if(matrix1==NULL||matrix2==NULL)
	  				{ cout<<"Insufficient input"; }
	   			else if(col1!=row2)
	  			{ cout<<"Product function cannot be used on entered matrices as the no. of rows and columns do not match"; }			
	  			else
				{ row3=row1; col3=col2;
	  			x=row2=col1;
	  			matrix3=productofmatrices(matrix1,matrix2,row3,col3,x);
	  			cout<<"Product matrix is \n";
				printmatrix(matrix3,row3,col3);  }
				break;
	  case 8:	cout<<"Enter 1 to get transpose of Matrix 1\n";
	  			cout<<"Enter 2 to get transpose of Matrix 2\n";
	  			cin>>v;
	  			if(v==1)
	  			{ if(matrix1==NULL)
				  cout<<"\nMatrix does not exist\nChoose option 1 to enter the matrix first";
				  else
				  { matrix3=transpose(matrix1,row1,col1) ; printmatrix(matrix3,row1,col1); 	}
				}
				else if(v==2)
				{ if(matrix2==NULL)
				   cout<<"\nMatrix does not exist\nChoose option 2 to enter the matrix first";
				  else
				  { matrix3=transpose(matrix2,row2,col2) ; printmatrix(matrix3,row2,col2); }
				}
				else
				cout<<"Invalid Input\nTry again";
	  case 9:	cout<<"Enter 1 to get determinant of Matrix 1\n";
	  			cout<<"Enter 2 to get determinant of Matrix 2\n";
	  			cin>>v;
	  			if(v==1)
	  			{ if(matrix1==NULL)
				  cout<<"\nMatrix does not exist\nChoose option 1 to enter the matrix first";
				  else if(row1!=col1)
				  { cout<<"\nMatrix 1 is not a square matrix hence determinant cannot be calculated"; }
				  else
				  { det1=determinant(matrix1,row1) ;  cout<<"\nDeterminant of matrix 1="<<det1;}
				}
				else if(v==2)
				{ if(matrix2==NULL)
				  cout<<"\nMatrix does not exist\nChoose option 2 to enter the matrix first";
				  else if(row2!=col2)
				  { cout<<"\nMatrix 2 is not a square matrix hence determinant cannot be calculated"; }
				  else
				  { det2=determinant(matrix2,row2);  cout<<"\nDeterminant of matrix 2="<<det2;}
				}
				else
				cout<<"Invalid Input\nTry again";
				break;
	  case 10: 		    cout<<"Enter 1 to get adjoint of Matrix 1\n";
	  					cout<<"Enter 2 to get adjoint of Matrix 2\n";
	  					cin>>v; cout<<endl;
	  					if(v==1)
	  					{ if(matrix1==NULL)
						  cout<<"Matrix does not exist\nChoose option 1 to enter the matrix first";
						  else if(row1!=col1)
						  { cout<<"Matrix 1 is not a square matrix hence adjoint cannot be determined"; }
						  else
						  { matrix3=adjoint(matrix1,row1); printmatrix(matrix3,row1,col1); }
						}
						else if(v==2)
						{ if(matrix2==NULL)
						  cout<<"Matrix does not exist\nChoose option 2 to enter the matrix first";
						  else if(row2!=col2)
						  { cout<<"Matrix 2 is not a square matrix hence adjoint cannot be determined"; }
						  else
						  { matrix3=adjoint(matrix2,row2); printmatrix(matrix3,row2,col2); }
						}
						else
						cout<<"Invalid Input\nTry again";
						break;
	  case 11:	    	cout<<"Enter 1 to get inverse of Matrix 1\n";
	  					cout<<"Enter 2 to get inverse of Matrix 2\n";
	  					cin>>v; cout<<endl;
	  					if(v==1)
	  					{ if(matrix1==NULL)
						  cout<<"Matrix does not exist\nChoose option 1 to enter the matrix first";
						  else if(row1!=col1)
						  { cout<<"Matrix 1 is not a square matrix hence inverse cannot be determined"; }
						  else
						  { showinverse(matrix1,row1) ; }
						}
						else if(v==2)
						{ if(matrix2==NULL)
						  cout<<"Matrix does not exist\nChoose option 2 to enter the matrix first";
						  else if(row2!=col2)
						  { cout<<"Matrix 2 is not a square matrix hence inverse cannot be determined"; }
						  else
						  { showinverse(matrix2,row2) ;}
						}
						else
						cout<<"Invalid Input\nTry again";
						break;
	  
	  case 12:	cout<<"Bye"; break;
	  default:  cout<<"Wrong input";
  }	//end of switch			
  } // end of while
 return 0;
}  
