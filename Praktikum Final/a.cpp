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
int min(int a, int b) {
    return (a < b) ? a : b;
}
int main(){
    int N, K;
    int ans, v;
    cin >> N;
    vl store;
    store.push_back(0);
    for(int i = 1; i <= N; i++){
        cin >> v;
        store.push_back(v);
    }
    cin >> K;
    vl key;
    key.pb(0);
    for (int i = 1; i <= K; i++){
        int prim = 50000;
        for (int j = 1; j <= N; j++)
            if (store[j] <= i)  
                prim = (prim < key[i-store[j]] + 1) ? prim : key[i-store[j]] + 1;
        key.pb(prim);
    }
    if (key[K] < 50000) 
        cout << key[K] << endl;
    else 
        cout << -1 << endl;
    return 0;
}