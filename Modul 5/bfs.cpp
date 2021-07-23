#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <array>
#include <cmath>
#include <list>
#include <string>
#include <stack>
#include <utility>
#define pi 3.14159265
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define ff first
#define ss second
#define rep(i,a,b) for(ll i=a;i<b;i++)
typedef long long int ll;
typedef std::vector<ll> vl;
typedef std::vector<vl> vvl;
typedef std::vector<bool> vb;
typedef std::pair<ll, ll> pl;
typedef std::list<ll> l;
typedef std::map <ll, ll> ml;
typedef std::list<ll>::iterator it;
typedef std::list< pl > lpl;
typedef std::stack<ll> st;
typedef std::set<pl> spl;
typedef l *adj;
#define fr(it,a,b) for (it = adj[].begin(); it != adj[].end(); ++it)
using namespace std;
class Graph {
    public: 
        ll V;
        void BFS(int);
        l *adj;
        void DFSUtil(ll v, bool visited[]);
        Graph(int V);
        void addEdge(ll v, ll w);
};
Graph::Graph(int V){
    this->V = V;
    // memory allocate
    adj = new l[V];
}
void Graph::addEdge(ll v, ll w){
    // undirected Graph
    adj[v].pb(w);
    adj[w].pb(v);
}
void Graph::BFS(int s){
    // Mark all the vertices as not visited;
    bool *visited = new bool[V];
    ll i;
    rep (i, 0, V){
        visited[i] = false;
    }
    // create a queue for BFS
    l queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.pb(s);

    // 'i' will be used to get all adjacent
    // vertices of a vertex
    l::iterator it;
    while (!queue.empty()){
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued 
        // vertex s. If an adjacent has not been visited,  
        // then mark it visited and enqueue it 
        for (it = adj[s].begin(); it != adj[s].end(); ++it) 
        { 
            if (!visited[*it]) 
            { 
                visited[*it] = true; 
                queue.pb(*it); 
            } 
        } 
    }
}

int main(int argc, const char** argv) {
    cout << "Logic Breadth First Search :)" ;
    //              0 
    //             / \
    //            1 - 2
    //             \  /
    //              3
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(1);
    cout << "\n";
    return 0;
}