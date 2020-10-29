#include <bits/stdc++.h>

using namespace std;

#define pb push_back

template <typename T>
class Graph {
private :
    map < T , list <T> > adjList ;
public :
    void addEdge(T u,T v,bool bidir = true){
        adjList[u].pb(v);
        if(bidir){
            adjList[v].pb(u);
        }
    }

    void printAdjList(){
        for(auto i: adjList){
            cout << i.first << " -> ";
            for(T entry : i.second){
                cout << entry << " ";
            }
            cout << endl ;
        }
    }
    
    //Only for undirected graphs
    bool isCyclicBFS(T src){
        map<T,bool> visited ;
        map<T,T> parent ; 
        queue<T> q ;

        q.push(src) ;
        visited[src] = true ; 
        parent[src] = src ;

        while(!q.empty()){
            T node = q.front() ;
            q.pop() ; 
            
            for(T neighbour : adjList[node]){
                
                if(visited[neighbour]){
                    if(parent[node] != neighbour){
                        return true ;
                    }
                }
                else {
                    visited[neighbour] = true ; 
                    parent[neighbour] = node ;
                    q.push(neighbour) ;
                }
            }
        }

        return false ; //Not presnet
    }
};
int main() {
    Graph<int> g ;
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(3,1);
    g.addEdge(3,2);

    g.printAdjList() ;

    cout << boolalpha << g.isCyclicBFS(0);
    return 0 ;
}
