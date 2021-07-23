// Using Kruskal Algorithm
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
class Edge {
    public : 
        ll src, dest, weight;
};
class Graph {
    public: 
        ll V, E;
        Edge *edge;
};  
Graph *createGraph (ll V, ll E){
    Graph *graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

class subset {
    public : 
        ll parent, rank;
};
ll find (subset subsets[], ll i){
    if (subsets[i].parent != i){
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}
void Union (subset subsets[], ll x, ll y){
    ll xroot = find(subsets, x);
    ll yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank){
        subsets[xroot].parent = yroot;
    }else if (subsets[xroot].rank > subsets[yroot].rank){
        subsets[yroot].parent = xroot;
    }
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
int myComp (const void *a, const void *b){
    Edge* a1 = (Edge*) a;
    Edge* b1 = (Edge*) b;

    return a1->weight > b1->weight;
}
void KruskalMST (Graph *graph){
    ll V = graph->V;
    Edge result[V];

    ll e = 0;
    ll i = 0;

    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);
    subset *subsets = new subset[(V * sizeof(subset))];
    ll v;
    rep (v, 0, V){
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    while (e < V-1 and i < graph->E){
        Edge next_edge = graph->edge[i++];
        
        ll x = find(subsets, next_edge.src);
        ll y = find(subsets, next_edge.dest);

        if (x != y){
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }
    cout << "Following are the edges in the constructed "
            "MST\n";
    ll minimumCost = 0;
    rep (i,0,e){
        cout << result[i].src << " -- " << result[i].dest
             << " == " << result[i].weight << endl;
        minimumCost = minimumCost + result[i].weight;
    }
    // return 
    cout << "Minimum Cost Spanning Tree: " << minimumCost
         << endl;
}
int main(int argc, char const *argv[])
{
    /* Let us create following weighted graph
            10
        0--------1
        | \ |
    6| 5\ |15
        | \ |
        2--------3
            4 */ 
    ll V = 4;
    ll E = 5;
    Graph *graph = createGraph (V, E);
    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 1;
    // add edge 0-2
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 3;
    // add edge 0-3
    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;
    // add edge 1-3
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 7;
    // add edge 2-3
    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 2;
    // Function call
    KruskalMST(graph);
    return 0;
}
