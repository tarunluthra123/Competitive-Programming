//Topological sort - DFS
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

    void dfsHelper(T node,map<T,bool> &visited , list<T> & ordering){
        visited[node] = true; 

        for(T child : adjList[node]){
            if(!visited[child]){
                dfsHelper(child,visited,ordering);
            }
        }

        //Push this node at the head of the Linked List as all its neighbours have been  visited
        ordering.push_front(node);
    }

    void dfsTopologicalSort() {
        list <T> ordering;
        map<T,bool> visited ; 
        for(auto i : adjList){
            T node = i.first ;
            if(!visited[node]){
                dfsHelper(node,visited,ordering);
            }
        }

        //Print the elements
        for(T element : ordering){
            cout << element << " -> ";
        }
    }


    void bfsTopologicalSort(){
        queue<T> q;
        map<T,bool>visited ; 
        map<T,int> indegree ;
        for(auto i : adjList){
            T node = i.first ; 
            visited[node] = false  ;
            indegree[node] = 0;
        }

        //Get the indegrees of all the vertices
        for(auto i : adjList){
            T u = i.first ;
            for(T v : adjList[u]){
                indegree[v]++;
            }
        }

        //Find out all the nodes with 0 degree and push them in queue
        for(auto i : adjList){
            T node = i.first ;
            if(indegree[node] == 0){
                q.push(node);
            }
        }

        //Start with algorithm
        //Pop out 0 indegree nodes and remove them from the graph
        //Update the remaining degrees accordingly
        while(!q.empty()){
            T node = q.front() ; 
            q.pop() ; 
            cout << node <<" -> ";
            for(T neighbour : adjList[node]){
                indegree[neighbour]--;
                if(indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }
    }

};
int main() {

    Graph<string> g;
    g.addEdge("English","Programming Logic",false);
    g.addEdge("English","HTML",false);
    g.addEdge("Maths","Programming Logic",false);
    g.addEdge("Programming Logic","Java",false);
    g.addEdge("Programming Logic","HTML",false);
    g.addEdge("Programming Logic","JS",false);
    g.addEdge("Programming Logic","Python",false);
    g.addEdge("JS","Web D",false);
    g.addEdge("HTML","JS",false);
    g.addEdge("Python","Web D",false);
    g.addEdge("Java","Web D",false);

    //g.dfsTopologicalSort() ;
    g.bfsTopologicalSort() ;


    return 0;
}

