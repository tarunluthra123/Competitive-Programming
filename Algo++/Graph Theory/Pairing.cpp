/*
PAIRING
There are N cities numbered from 0 to N-1. You have to choose 2 cities such that there is no path from first city to second city .
You are given information in the form of M pairs (X,Y) i.e there is an undirected road between city X and city Y.
Find out the number of ways in which cities can be chosen.


Input Format:
The first line contains two integers, N and M separated by a single space. M lines follow. Each line contains integers separated by a single space X and Y denoting road between X and Y.

Constraints:
1 <= N <= 100000
1 <= M <= 100000
0 <= X,Y <= N-1

Output Format:
An integer that denotes the number of permissible ways to choose a pair of cities.

Sample Input:
5 3
0 1
2 3
0 4
Sample Output:
6
Explanation:
0 1 4 cannot be reached by 2 hence (2,0) (2,1) (2,4) and also 0 1 4 cannot be reached by 3 so (3,0) (3,1) (3,4) hence 6 ways.
*/
//Same as Journey to moon problem ...only language is different 
#include <bits/stdc++.h>

using namespace std;


class Graph{
private :
    int V;
    list<int> *l;
    
public:
    Graph(int v){
        V = v;
        l = new list<int>[V];
        
    }
    
    void addEdge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void dfsHelper(int i,map<int,bool> &visited,int &noOfNodes){
        visited[i] = true;
        noOfNodes++;
        
        for(auto neighbour:l[i]){
            if(!visited[neighbour]){
                dfsHelper(neighbour,visited,noOfNodes);
            }
        }
        
    }
    
    int dfsPairing(){
        map<int,bool> visited ; 
        int totalPairs = V*(V-1)/2;
        
        for(int i=0;i<V;i++){
            if(visited[i]==false){
                int noOfNodes = 0;
                dfsHelper(i,visited,noOfNodes);
                totalPairs -= (noOfNodes)*(noOfNodes-1)/2;        //C(noOfNodes,2);
            }
        }
        
        return totalPairs;   
    }


};



int main() {
    int n,e;
    cin >> n >> e;
    Graph g(n);
    for(int i=0;i<e;i++){
        int u,v; 
        cin >> u >> v;
        g.addEdge(u,v);
    }

    cout << g.dfsPairing();

    return 0;
}

