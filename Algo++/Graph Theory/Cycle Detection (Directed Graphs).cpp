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
    
    bool isCyclicHelper(T node, map <T,bool> &visited, map<T,bool> &inStack) {
        //Process the current node
        visited[node] = inStack[node] = true ;

        //Explore neighbours of node
        for(T child : adjList[node]) {
            //The current node is not visited but check if its further branch leads to a cycle 
            //OR  it is visited and is in inStack i.e. an ancestor node
            if((!visited[child] && isCyclicHelper(child,visited,inStack)) || inStack[child]) {
                return true ;
            }
        }

        //Backtrack
        inStack[node] = false ; 

        return false ;
    }

    bool isCyclicDFS(){
        map < T, bool > visited ;
        map < T, bool > inStack ;

        for(auto i : adjList) {
            T node = i.first ;
            if(!visited[node]){
                bool cyclePresent = isCyclicHelper(node,visited,inStack);
                if(cyclePresent){
                    return true ;
                }
            }
        }
        return false ;
    }


};
int main() {
    Graph<int> g ;
    g.addEdge(0,2,false);
    g.addEdge(0,1,false);
    g.addEdge(3,0,false);       //Back Edge
    g.addEdge(2,3,false);
    g.addEdge(2,4,false);
    g.addEdge(4,5,false);
    g.addEdge(1,5,false);

    g.printAdjList() ;

    if(g.isCyclicDFS()){
        cout << "Graph is cyclic";
    }
    else {
        cout <<"Graph is acyclic"; 
    }

    return 0 ;
}
