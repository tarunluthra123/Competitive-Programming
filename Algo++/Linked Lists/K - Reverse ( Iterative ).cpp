/*
K-REVERSE
Implement kReverse(int k) i.e. you reverse first K elements then reverse next K elements and join the linked list and so on. 3 ? 4 ? 5 ? 2 ? 6 ? 1 ? 9 for kreverse(3) becomes 5 ? 4 ? 3 ? 1 ? 6 ? 2 ? 9 ? 1. If k is greater than the size of rest linked list then reverse the rest part. Ex. For linked list 5 ? 4 ? 3 ? 1 and k =5. Output should be 1 ? 3 ? 4 ? 5
Do it for multiple testcases.

Input Format:
First Line of input will be no of testcases. Each testcase contains size N , N space separated elements and value of K ( no. of elements to be reversed)

Constraints:
None

Output Format:
Display the resulting Linked List for each testcase

Sample Input :
6
8
1 2 3 4 5 6 7 8
3
100
15 72 45 13 54 9 36 92 42 17 95 58 23 55 60 62 44 80 82 65 69 43 85 75 59 19 77 86 6 34 1 24 26 56 61 100 38 57 37 84 4 30 51 28 90 87 49 31 11 83 79 33 2 89 27 91 3 74 25 22 94 47 93 29 78 52 67 63 5 32 10 48 99 76 66 41 46 97 88 71 40 35 12 50 96 68 98 81 53 7 64 20 8 14 21 39 70 16 18 73 
4
100
1 87 60 16 85 34 55 36 52 5 74 9 57 50 38 73 13 31 99 26 32 28 79 66 84 46 77 44 43 45 71 23 82 40 4 67 89 93 3 70 48 47 64 21 22 83 41 96 20 98 19 12 24 68 61 25 80 78 97 33 58 94 53 49 59 90 35 11 92 54 65 69 95 62 76 14 18 17 86 7 42 29 6 88 81 75 15 37 27 100 63 10 51 39 30 91 2 56 8 72 
5
100
66 7 15 89 51 25 68 24 94 28 38 85 49 77 96 40 21 26 36 97 81 78 98 76 9 22 48 100 71 80 43 37 57 60 45 44 18 95 64 58 1 74 69 86 6 33 27 83 55 50 3 84 88 62 17 63 65 99 2 13 23 31 54 12 41 4 70 11 93 75 91 87 39 32 46 29 92 5 42 16 67 53 34 35 61 59 52 19 20 8 56 82 90 10 72 30 14 79 47 73 
6
100
51 3 73 64 39 28 60 61 77 95 12 48 57 71 49 6 67 96 5 52 66 80 99 55 1 68 54 100 25 70 65 79 36 2 8 19 90 72 44 91 22 30 10 15 34 82 63 93 62 37 13 88 16 41 45 27 43 75 38 86 83 50 14 59 46 89 21 18 76 11 74 85 9 78 31 33 24 35 32 69 42 7 40 17 29 4 92 23 87 53 26 47 98 81 94 20 58 84 56 97
7 
100
15 12 4 93 71 23 3 22 54 63 34 45 97 7 58 100 96 39 43 30 10 47 50 95 2 46 86 61 53 40 64 90 6 98 76 70 74 99 75 33 68 19 94 24 5 9 89 67 32 55 25 65 29 92 28 38 77 36 85 44 18 57 79 37 8 81 83 73 27 69 20 56 26 62 84 78 88 35 51 48 52 66 72 21 16 31 17 60 59 42 91 41 13 49 87 11 82 1 80 14 
8


Sample Output :
3 2 1 6 5 4 8 7 
13 45 72 15 92 36 9 54 58 95 17 42 62 60 55 23 65 82 80 44 75 85 43 69 86 77 19 59 24 1 34 6 100 61 56 26 84 37 57 38 28 51 30 4 31 49 87 90 33 79 83 11 91 27 89 2 22 25 74 3 29 93 47 94 63 67 52 78 48 10 32 5 41 66 76 99 71 88 97 46 50 12 35 40 81 98 68 96 20 64 7 53 39 21 14 8 73 18 16 70 
85 16 60 87 1 5 52 36 55 34 38 50 57 9 74 26 99 31 13 73 84 66 79 28 32 45 43 44 77 46 4 40 82 23 71 70 3 93 89 67 22 21 64 47 48 98 20 96 41 83 61 68 24 12 19 33 97 78 80 25 59 49 53 94 58 54 92 11 35 90 76 62 95 69 65 7 86 17 18 14 81 88 6 29 42 100 27 37 15 75 30 39 51 10 63 72 8 56 2 91 
25 51 89 15 7 66 85 38 28 94 24 68 26 21 40 96 77 49 76 98 78 81 97 36 80 71 100 48 22 9 44 45 60 57 37 43 74 1 58 64 95 18 83 27 33 6 86 69 62 88 84 3 50 55 13 2 99 65 63 17 4 41 12 54 31 23 87 91 75 93 11 70 5 92 29 46 32 39 35 34 53 67 16 42 8 20 19 52 59 61 30 72 10 90 82 56 73 47 79 14 
60 28 39 64 73 3 51 71 57 48 12 95 77 61 66 52 5 96 67 6 49 100 54 68 1 55 99 80 8 2 36 79 65 70 25 30 22 91 44 72 90 19 62 93 63 82 34 15 10 27 45 41 16 88 13 37 14 50 83 86 38 75 43 11 76 18 21 89 46 59 24 33 31 78 9 85 74 17 40 7 42 69 32 35 26 53 87 23 92 4 29 84 58 20 94 81 98 47 97 56 
22 3 23 71 93 4 12 15 100 58 7 97 45 34 63 54 95 50 47 10 30 43 39 96 90 64 40 53 61 86 46 2 33 75 99 74 70 76 98 6 67 89 9 5 24 94 19 68 38 28 92 29 65 25 55 32 37 79 57 18 44 85 36 77 56 20 69 27 73 83 81 8 48 51 35 88 78 84 62 26 60 17 31 16 21 72 66 52 11 87 49 13 41 91 42 59 14 80 1 82 

*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class node
{
	public:
	int data;
	node * next;
};
node* create_node(int d)
{
	node* np;
	np=new node();
	np->data=d;
	np->next=NULL;
	return np;
}
node* insertend(node* np,node*head)
{
	if(head==NULL)
	head=np;
	else
	{
		node* temp;
		temp=head;
		while(temp->next!=NULL)
		temp=temp->next;
		temp->next=np;
	}
	return head;
}
int length(node* head)
{
	node* temp=head;
	int i=0;
	while(temp!=NULL)
	{
		temp=temp->next;
		i++;
	}
	return i;
}
node* kreverse(node* head,int k)
{
	int l=length(head);
	node* current,*currentf,*nextnode;
	node* prevf=NULL;
	node* newhead=NULL;
	node* prev=NULL;
	int i=0,y=0;
	current=head;
	while(current!=NULL)
	{
		i=(i+1)%k;
		if(i==1)
		{
			currentf=current;
			prev=NULL;
		}
		nextnode=current->next;
		current->next=prev;
		prev=current;
		y++;
		if(i%k==0||y==l)
		{
			if(newhead==NULL)
			newhead=current;
			if(prevf!=NULL)
			{
				prevf->next=current;
				prevf=currentf;
			}
			else
			prevf=currentf;
		}
		current=nextnode;
	}
	return newhead;
}
void print(node * head)
{
	node* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
int main()
{
    int testCases ; 
    cin >> testCases ; 
    while(testCases--) {
        int n,d,k;
        cin>>n;
        node* head=NULL;
        node* np;
        for(int i=0;i<n;i++)
        {
            cin>>d;
            np=create_node(d);
            head=insertend(np,head);
        }
        cin>>k;
        head=kreverse(head,k);
        print(head);
        cout << endl;
    }

    return 0;
}
