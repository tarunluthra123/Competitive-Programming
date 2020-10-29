/* Program for solving Towers of Hanoi problem with recursion
   Created by Tarun Luthra
   Roll No. = 2018 CSC 1023   																	*/
   
#include <iostream>

using namespace std;

int count = 1;							//to count the total moves

void towersOfHanoi(int n, char source, char dest)
{	
	if(n==0)
		return ;		
							
    char temp = ('A'+'B'+'C') - source - dest;
    
    //Move N-1 disks from source to temp
    towersOfHanoi(n-1, source, temp);
    
    //Move Nth disk from source to dest
    cout<<"\nStep "<<count++<<" : Move disk "<<n<<" from rod "<<source<<" to rod "<<dest;
    
    //Move N-1 disks from temp to dest
    towersOfHanoi(n- 1, temp, dest);
}
int main()
{
    int n;
    cout<<"TOWERS OF HANOI\n";
    cout<<"Enter the number of disks to be moved from rod A to C: ";
    cin>>n;
    cout<<"The sequence of moves involved in the Tower of Hanoi are :\n";
    towersOfHanoi(n, 'A', 'C');					//move n disks from A to C
    cout<<"\nTotal number of moves = "<<count-1;
    return 0;
}
