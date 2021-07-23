#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <array>
#include <cmath>
#include <list>
#include <string>
#include <cstdlib>
#define pi 3.14159265
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define ff first
#define ss second
#define q qsort
#define rep(i,a,b) for(ll i=a;i<b;++i)
typedef std::vector<long long> vl;
typedef std::vector<bool> vb;
typedef std::pair<long long, long long> pl;
typedef std::list<long long> l;
typedef std::map <long long, long long> ml;
typedef std::list<long long>::iterator it;
typedef std::list< pl > lpl;
typedef long long int ll;
typedef long double ld;
using namespace std;

// structure of Edge in Graph 
class Edge {
    public :
        ll src, dest;
};
// Representation of Graph;
class Graph{
    public :
        ll V, E;
        Edge *edge;
};
// Create a Graph 
// V = vertices/vertex/node
// E = edge;
Graph *createGraph (ll V, ll E){
    // allocate Memory
    Graph *graph = new Graph();
    graph->V = V;
    graph->E = E;

    graph->edge = new Edge[graph->E * sizeof(Edge)];
    return graph;
}
// A Utility function to find the subset of an element i;
ll find (ll *parent, ll i){
    if (parent[i] == -1) return i;
    return find(parent, parent[i]);
}
// A utility function to do union of two subsets;
void Union (ll parent[], ll x, ll y){
    parent[x] = y;
}
// cycle or not
ll isCycle (Graph *graph){
    ll *parent = new ll [graph->V * sizeof(ll)];

    // initialize all element in parent by -1
    // 0   1   2
    // -1 -1  -1
    memset (parent, -1, sizeof(ll) * graph->V);
    ll i;
    rep (i, 0, graph->E){
        ll x = find(parent, graph->edge[i].src);
        ll y = find(parent, graph->edge[i].dest);

        if (x == y) return 1;

        Union (parent,x, y);
    }
    return 0;
}


int main(int argc, char const *argv[])
{
    /* Let us create the following graph
        0
        | \
        |  \
        1---2 */

    ll E = 3;
    ll V = 3;

    Graph* graph = createGraph(V, E);
 
    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
 
    // add edge 1-2
    graph->edge[1].src = 1;
    graph->edge[1].dest = 2;
 
    // add edge 0-2
    graph->edge[2].src = 0;
    graph->edge[2].dest = 2;
 
    if (isCycle(graph) == 1)
        cout << "graph contains cycle\n";
    else
        cout << "graph doesn't contain cycle\n";
    
    return 0;
}
// 0->1->2 // 1 is parent of 0 and 2 is parent of 1 
// https://www.geeksforgeeks.org/union-find/