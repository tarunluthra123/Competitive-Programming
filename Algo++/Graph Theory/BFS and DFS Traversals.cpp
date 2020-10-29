#include <bits/stdc++.h>

using namespace std;

class Graph
{
private:
    int V;
    map<int, list<int>> adjList; // Stores adjList as <u, list< <v,w> > >

public:
    Graph(int v)
    {
        V = v;
    }

    void addEdge(int u, int v, bool bidir = true)
    {
        adjList[u].push_back(v);
        if (bidir)
        {
            adjList[v].push_back(u);
        }
    }

    void dfsHelper(int i, map<int, bool> &visited)
    {
        visited[i] = true;
        cout << i << " ";

        for (auto neighbour : adjList[i])
        {
            if (!visited[neighbour])
            {
                dfsHelper(neighbour, visited);
            }
        }
    }

    void dfs(int src)
    {
        map<int, bool> visited;
        cout << "DFS Traversal - ";

        dfsHelper(src, visited);

        for (auto it : adjList)
        {
            int i = it.first;
            if (visited[i] == false)
            {
                dfsHelper(i, visited);
            }
        }

        cout << endl;
    }

    void bfs(int src)
    {
        queue<int> q;
        q.push(src);
        map<int, bool> visited;

        cout << "BFS Traversal - ";

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            visited[node] = true;
            cout << node << " ";

            for (auto child : adjList[node])
            {
                if (!visited[child])
                {
                    q.push(child);
                }
            }
        }

        for (auto p : adjList)
        {
            int x = p.first;
            if (!visited[x])
            {
                q.push(x);
                while (!q.empty())
                {
                    int node = q.front();
                    q.pop();

                    visited[node] = true;
                    cout << node << " ";

                    for (auto child : adjList[node])
                    {
                        if (!visited[child])
                        {
                            q.push(child);
                        }
                    }
                }
            }
        }

        cout << endl;
    }
};

int main()
{
    int n, e;
    cin >> n >> e;
    Graph g(n);
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.dfs(0);
    g.bfs(0);

    return 0;
}

