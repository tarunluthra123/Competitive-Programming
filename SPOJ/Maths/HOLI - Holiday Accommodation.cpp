//Holiday Accomodation Problem  - HOLI
/*
Nowadays, people have many ways to save money on accommodation when they are on vacation. One of these ways is exchanging houses with other people.

Here is a group of N people who want to travel around the world. They live in different cities, so they can travel to some other people's city and use someone's house temporary. Now they want to make a plan that choose a destination for each person. There are two rules should be satisfied:

All the people should go to one of the other people's city.
Two of them never go to the same city, because they are not willing to share a house.
They want to maximize the sum of all people's travel distance. The travel distance of a person is the distance between the city he lives in and the city he travels to. These N cities have N-1 highways connecting them. The travelers always choose the shortest path when traveling.

Given the highways' information, it is your job to find the best plan, that maximum the total travel distance of all people.

Input
The first line of input contains one integer T (1 = T = 10), indicating the number of test cases.

Each test case contains several lines. The first line contains an integer N (2 = N = 105), representing the number of cities. Then the following N-1 lines each contains three integers X, Y, Z (1 = X, Y = N, 1 = Z = 106), means that there is a highway between city X and city Y, and length of that highway.

You can assume all the cities are connected and the highways are bi-directional.

Output
For each test case in the input, print one line: "Case #X: Y", where X is the test case number (starting with 1) and Y represents the largest total travel distance of all people.

Example
Input:
2
4
1 2 3
2 3 2
4 3 2
6
1 2 3
2 3 4
2 4 1
4 5 8
5 6 5

Output:
Case #1: 18
Case #2: 62

*/

#include <iostream>
#include <list>
using namespace std;

#define ll long long int
#define sync                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

//Weighted Grapph
class Graph
{

    ll V;
    list<pair<ll, ll>> *l;

public:
    Graph(ll v)
    {
        V = v;
        l = new list<pair<ll, ll>>[V];
    }

    void addEdge(ll u, ll v, ll cost, bool bidir = true)
    {
        l[u].push_back(make_pair(v, cost));
        if (bidir)
        {
            l[v].push_back(make_pair(u, cost));
        }
    }
    //Return size of the subtree
    ll dfsHelper(ll node, bool *visited, ll *count, ll &ans)
    {

        visited[node] = true;
        count[node] = 1;

        //You to recursively find out the size of its children/neighbours
        for (auto neighbour : l[node])
        {
            ll v = neighbour.first;

            if (!visited[v])
            {
                count[node] += dfsHelper(v, visited, count, ans);
                //Cost -> Count
                ll s = count[v];
                ll N = V;
                ll edgeCost = neighbour.second;
                ans += 2 * min(s, N - s) * edgeCost;
            }
        }
        return count[node];
    }

    ll dfs()
    {
        bool *visited = new bool[V]{0};
        ll *count = new ll[V]{0};

        ll ans = 0;
        dfsHelper(0, visited, count, ans);

        /* for(ll i=0;i<V;i++){
            cout<<count[i]<<" ";
        }*/

        return ans;
    }
};

int main()
{
    sync;
    ll testCases;
    cin >> testCases;
    ll tcount = 1;
    while (testCases--)
    {
        ll V;
        cin >> V;
        Graph g(V);
        while (--V)
        {
            ll x, y, z;
            cin >> x >> y >> z;
            g.addEdge(x - 1, y - 1, z);
        }

        cout << "Case #" << tcount++ << ": " << g.dfs() << endl;
    }

    return 0;
}
