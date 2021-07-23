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
#define pi 3.14159265
#define INF 0x3f3f3f3f
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define ff first
#define ss second
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define pq priority_queue
#define MAX 100005
#define s static
#define NIL -1
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
typedef l *adj;
#define fr(it,a,b) for (it = adj[].begin(); it != adj[].end(); ++it)

using namespace std;
class Graph
{   
    ll V;
    l *adj;
    void SCCUtil (ll u, ll disc[], ll low[], st *st, bool stackMember[]);
    public :
        Graph(ll V);
        void addEdge(ll v, ll w);
        void SCC();
};
Graph::Graph(ll V){
    this->V = V;
    adj = new l[V];
}
void Graph::addEdge(ll v, ll w){
    adj[v].pb(w);
}
void Graph::SCCUtil (ll u, ll disc[], ll low[], st *st, bool stackMember[]){
    s ll time = 0;
    disc[u] = low[u] = ++time;
    st->push(u);
    stackMember[u] = true;

    it i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i){
        ll v = *i;
        if (disc[v] == -1){
            SCCUtil(v, disc, low, st, stackMember);
            low[u] = min(low[u], low[v]);
        }
        else if (stackMember[v]) {
            low[u] = min(low[u], disc[v]);
        }
    }
    ll w = 0;
    if (low[u] == disc[u]){
        while (st->top() != u){
            w = (ll) st->top();
            cout << w << " ";
            stackMember[w] = false;
            st->pop();
        }
        w = (ll) st->top();
        cout << w << "\n";
        stackMember[w] = false;
        st->pop();
    }
}
void Graph::SCC(){
    ll *disc = new ll[V];
    ll *low = new ll[V];
    bool *stackMember = new bool[V];
    st *st = new stack<ll>();
    
    ll i;
    rep(i,0,V){
        disc[i] = -1;
        low[i] = -1;
        stackMember[i] = false;
    }
    rep(i, 0, V){
        if(disc[i] == -1){
            SCCUtil(i, disc, low, st, stackMember);
        }
    }
}
int main(int argc, char const *argv[])
{
    cout << "\nSCCs in first graph \n";
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.SCC();
  
    cout << "\nSCCs in second graph \n";
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.SCC();
  
    cout << "\nSCCs in third graph \n";
    Graph g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);
    g3.SCC();
  
    cout << "\nSCCs in fourth graph \n";
    Graph g4(11);
    g4.addEdge(0,1);g4.addEdge(0,3);
    g4.addEdge(1,2);g4.addEdge(1,4);
    g4.addEdge(2,0);g4.addEdge(2,6);
    g4.addEdge(3,2);
    g4.addEdge(4,5);g4.addEdge(4,6);
    g4.addEdge(5,6);g4.addEdge(5,7);g4.addEdge(5,8);g4.addEdge(5,9);
    g4.addEdge(6,4);
    g4.addEdge(7,9);
    g4.addEdge(8,9);
    g4.addEdge(9,8);
    g4.SCC();
  
    cout << "\nSCCs in fifth graph \n";
    Graph g5(5);
    g5.addEdge(0,1);
    g5.addEdge(1,2);
    g5.addEdge(2,3);
    g5.addEdge(2,4);
    g5.addEdge(3,0);
    g5.addEdge(4,2);
    g5.SCC();
  
    return 0;
}
