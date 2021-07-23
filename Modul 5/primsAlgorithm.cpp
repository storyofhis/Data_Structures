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
#define pi 3.14159265
#define INF 0x3f3f3f3f
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define ff first
#define ss second
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define pq priority_queue
typedef std::vector<long long> vl;
typedef std::vector<bool> vb;
typedef std::pair<long long, long long> pl;
typedef std::list<long long> l;
typedef std::map <long long, long long> ml;
typedef std::list<long long>::iterator it;
typedef std::list< pl > lpl;
typedef long long int ll;
using namespace std;
class Graph{
    ll V;
    lpl *adj;
    public :
        Graph(ll V);
        void addEdge(ll u, ll v, ll w);
        void primMST();
};

Graph::Graph(ll V){
    this->V = V;
    adj = new lpl [V];
}
void Graph::addEdge(ll u, ll v, ll w){
    adj[u].pb(mp(v,w));
    adj[v].pb(mp(u,w));
}

void Graph::primMST(){
    priority_queue <pl, vector<pl>, greater<pl> > pq;
    ll src = 0;
    vl key (V, INF);
    vl parent (V, -1);
    vb inMST(V, false);
    pq.push(mp(0,src));
    key[src] = 0;

    while(!pq.empty()){
        ll u = pq.top().ss;
        pq.pop();

        if (inMST[u] == true){
            continue;
        }
        inMST[u] = true;

        lpl::iterator it;

        for (it = adj[u].begin(); it != adj[u].end(); ++it){
            ll v = (*it).ff;
            ll weight = (*it).ss;

            if (!inMST[v] and key[v] > weight){
                key[v] = weight;
                pq.push(mp(key[v], v));
                parent[v] = u;
            }
        }
    }
    for (ll i = 1; i < V; ++i){
        cout << parent[i] - i << endl;
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

    g.primMST();
    return 0;
}

// Time complexity : O(E Log V))