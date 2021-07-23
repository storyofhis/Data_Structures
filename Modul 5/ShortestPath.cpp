// Dijkstra’s shortest path algorithm
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <array>
#include <cmath>
#include <list>
#include <string>
#include <queue>
#include <cstdlib>
#include <stack>
#include <utility>
#include <limits.h>
#include <functional>
#define pi 3.14159265
#define INF 0x3f3f3f3f
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define ff first
#define ss second
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define pq priority_queue
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
    ll V;   // No. of Vertices 
    lpl *adj; // Pointer to adjacency list

    public : 
        Graph (ll V); // constructor
        void addEdge(ll u, ll v, ll w); // use to add an edge to the graph
        void shortestPath (ll s); // prints shortestPath from s;
};
// Allocates memory for adjacent list
Graph::Graph(ll V){
    this->V = V;
    adj = new lpl[V];
}

// Implementation  of method to add edges (Undirected  Graph)
void Graph::addEdge (ll u, ll v, ll weight){
    // u = src
    // v = dest
    // w = Distance 
    adj[u].pb(mp(v,weight));
    adj[v].pb(mp(u,weight));
}

// Prints shortest paths from src to all other vertices 
void Graph::shortestPath (ll src){
    // create a set to store vertices that are being processed
    spl setds;
    // Create a vector for distance 
    // initialize a ll as infinite (INF)
    vl dist(V, INF);
    // insert source itself in set 
    setds.insert(mp(0, src));
    // and initialize its distance as 0
    dist[src] = 0;
    // Looping till all shortest distance are finalized 
    // then setds will become empty
    while (!setds.empty()){
        // the 1st vertex in set is the minimum distance
        // vertex, extract it from set.
        pl tmp = *(setds.begin()); // setds.begin() di taruh di tmp
        setds.erase(setds.begin()); // setds.begin() di hapus dalam setds

        ll u = tmp.ss;
        lpl::iterator it;
        for (it = adj[u].begin() ; it != adj[u].end(); ++it){
            ll v = (*it).ff;
            ll weight = (*it).ss;

            if (dist[v] > dist[u] + weight){
                if (dist[v] != INF){
                    setds.erase(setds.find(mp(dist[v], v)));
                }
                dist[v] = dist[u] + weight;
                setds.insert(mp(dist[v], v));
            }
        }
    }
    printf("Vertex   Distance from Source\n");
    ll i;
    rep (i,0,V){
        printf("%lld \t\t %lld\n", i, dist[i]);
    }
}
int main(int argc, char const *argv[])
{
    ll V = 9;
    Graph g(V);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
  
    g.shortestPath(0);
    return 0;
}
