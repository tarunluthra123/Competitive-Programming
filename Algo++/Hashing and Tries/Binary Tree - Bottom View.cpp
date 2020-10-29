/*
TREE BOTTOM VIEW
Given a binary tree , print the nodes in left to right manner as visible from below the tree


Input Format:
Level order input for the binary tree will be given.

Constraints:
No of nodes in the tree can be less than or equal to 10^7

Output Format:
A single line containing space separated integers representing the bottom view of the tree

Sample Input:
1 2 3 4 5 6  -1 -1 -1 -1 -1 -1 -1
Sample Output:
4 2 6 3

Sample Input :
20 8 22 5 3 4 25 -1 -1 10 14 -1 -1 -1 -1 -1 -1 -1 -1
Sample Output :
5 10 4 14 25 
*/
#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

class node{
    public:
        long data;
        node*left;
        node*right;

        node(long d){
            data = d;
            left = NULL;
            right = NULL;
        }
};


node* buildTreeLevelWise(){

	long d;
	cin>>d;

	node*root = new node(d);
	queue<node*> q;
	q.push(root);

	while(!q.empty()){

		node*f = q.front();
		q.pop();
		long c1,c2;
		cin>>c1>>c2;

		if(c1!=-1){
			f->left = new node(c1);
			q.push(f->left);
		}
		if(c2!=-1){
			f->right = new node(c2);
			q.push(f->right);
		}
	}
	return root;
}

//Functor to sort the heap of numbers with same distance according to its level
class MyCompare{
public :
    bool operator ()(pair<long,int> a,pair<long,int> b){
        return a.second <= b.second ;
    }
};

#define maxHeap priority_queue<pair<long,int> ,vector<pair<long,int> > , MyCompare > 
//Create a max heap to store the numbers with same distance according to levels 
//pop the element with the maximum level out for each vertical line

void verticalOrderPrint(node*root,map<int,maxHeap > &m,int d,int level){
    if(root == NULL){
        return ;
    }
    //Store d for the vertical lines and level for the levels 
    m[d].push(make_pair(root->data,level));
    verticalOrderPrint(root->left,m,d-1,level+1);
    verticalOrderPrint(root->right,m,d+1,level+1);
}

int main(){
    node *root = buildTreeLevelWise() ;
    map<int,maxHeap > m;
    verticalOrderPrint(root,m,0,0);
    for(auto itr = m.begin();itr!=m.end() ; itr++){
        //itr is a pointer to a pair<int,maxHeap>
        //get the top of maxHeap
        //display its first element - number (second is level)
        cout<<itr->second.top().first<<" ";
    }

    return 0;
}
