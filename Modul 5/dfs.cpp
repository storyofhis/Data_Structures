#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <array>
#include <cmath>
#include <list>
#include <string>
#define pi 3.14159265
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define ff first
#define ss second
#define rep(i,a,b) for(ll i=a;i<b;i++)
typedef std::vector<long long> vl;
typedef std::pair<long long, long long> pl;
typedef std::list<long long> l;
typedef std::map <long long, long long> ml;
typedef std::list<long long>::iterator it;
typedef long long int ll;

using namespace std;

class Graph
{
    public:
        Graph(ll V);
        ll V;
        void DFSUtil(ll v, bool *visited);
        void DFS (ll v);
        l* adj;
        void addEdge (ll v, ll w);
};
Graph::Graph(ll V){
    this->V = V;
    adj = new list<ll>[V];
}
void Graph::DFSUtil (ll v, bool *visited){
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";

    // Recur for all the vertices adjacent
    // to this vertex.
    l::iterator it;
    for (it = adj[v].begin(); it != adj[v].end(); ++it){
        if (!visited[*it]){
            DFSUtil(*it, visited);
        }
    }
}

// DFS Traversal of the vertices reachable from v.
// It uses recursive DFSUtil()
void Graph::DFS(ll v){
    // Mark all the vertices as not visited
    bool *visited = new bool [V];
    for (ll i = 0; i < V; i++){
        visited[i] = false;
    }

    // Call the recursive helper function
    // to print DFS traversal
    DFSUtil(v, visited);
}
void Graph::addEdge(ll v, ll w){
    // undirected Graph
    adj[v].push_back(w);    
    adj[w].push_back(v);
}

int main(int argc, char const *argv[])
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 9);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(9, 3);
 
    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
    g.DFS(2);
    return 0;
}
