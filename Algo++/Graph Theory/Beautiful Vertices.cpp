/*
BEAUTIFUL VERTICES
You are given a graph with N vertices and M edges. Master parent is the vertex which has no parent but may have 0 or more children. In any connected component of the graph, vertex with the lowest value in that component serves as the master parent. A vertex is called beautiful if it has more children than its parent. Count the number of beautiful vertices in the given graph. The graph has no cycles or self loops.


Input Format:
First line consists of two space separated integers denoting N and M and the following M lines consist of two space separated integers X and Y denoting there is an edge between vertices X and Y.

Constraints:
1 <= N <= 100000
0 <= M <= N-1
1 <= x,y <= N

Output Format:
Print the number of beautiful vertices in the graph.

Sample Input:
4 3
1 2
2 3
2 4
Sample Output:
1
Explanation:
In this graph, we have vertices 1,2,3 and 4. Since 1 is the lowest among these, so it becomes the master vertex. Now, 1 has only 1 child while 2 has two children.So, 2 is a beautiful vertex. There are no more beautiful vertices in the graph.

Time Limit: 2 sec
*/
#include <bits/stdc++.h>
using namespace std;

#define pb push_back

class Graph {
private :
    map<int, list<int> > adjList ;    //<node , neighbours > 
public  :
    void addEdge(int u,int v){
        adjList[u].pb(v);        
        adjList[v].pb(u);         
    }

   void printAdjList(){
        for(auto i : adjList){
            cout << i.first << " -> ";
            for(auto j : i.second){
                cout << j << "  ";
            }
            cout << endl ;
        }
    }

    void dfsHelper(int node,map<int,bool> &visited,map<int,int> &parent,map<int,int> &children){
        visited[node] = true;

        for(int neighbour : adjList[node]){
            if(!visited[neighbour]){
                children[node]++;
                parent[neighbour] = node;
                dfsHelper(neighbour,visited,parent,children);
            }
        }
    }

    void dfs(int src){
        map<int,bool> visited;
        map<int,int> parent;
        map<int,int> children;
        dfsHelper(src,visited,parent,children);
        for(auto i : adjList){
            int node = i.first;
            if(!visited[node]){
                dfsHelper(node,visited,parent,children);
            }
        }

        int answer = 0;
        int n = adjList.size();
        for(int i=1;i<=n;i++)
        {
            if(parent.find(i)!=parent.end() && children[parent[i]] < children[i])
            {
                //cout << "i="<<i<<endl;
                answer++;
            }
        }
        cout << answer << endl;
    }

};

int main() {
    int n,e;
    cin >> n >> e;
    Graph g;
    for(int i=0;i<e;i++){
        int u,v;
        cin >> u >> v;
        g.addEdge(u,v);
    }

   // g.printAdjList() ;

    g.dfs(1);

    return 0;
}

