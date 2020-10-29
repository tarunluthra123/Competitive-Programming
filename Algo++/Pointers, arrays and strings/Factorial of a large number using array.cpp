#include <iostream>
using namespace std;
#define limit 500
void output(long int a[])
//ostream operator <<(ostream output,long int a[])
{	int i;
	//int check=0;
	for(i=limit -1 ;i>=0;i--)
	{	if(a[i]==0);
		//check=0;
		else
		{	//check=1; 
			break; }		
	}
	int size=i;
	for(i=size;i>=0;i--)
	{	cout<<a[i];	}
		//output<<a[i]; }
	//return output;
}
int main()
{
	long n,a[limit]={0};
	int carry,i;
	cin>>n;
	carry=0;
	a[0]=1;
	int j;
	for(i=1;i<=n;i++)
	{
		carry=0;
		for(j=0;j<limit;j++)
		{	
			a[j]=a[j]*i+carry;
			carry=a[j]/10;
			a[j]=a[j]%10;
		}
	}
	output(a);
	//cout<<a;
	return 0;
}
