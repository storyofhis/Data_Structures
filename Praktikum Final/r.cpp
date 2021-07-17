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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#define pi 3.14159265
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define ff first
#define ss second
#define rep(i,a,b) for(ll i=a;i<b;i++)
typedef long long int ll;
typedef unsigned int ui;
typedef unsigned long long int ull;
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

using namespace __gnu_pbds;

int func (int n){
    vl v;
    tree <int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> t;
    int j = n-1;
    ll ans = 1, factorial[n+5];
    factorial[0]=1;
    for (int i=1; i<=n; i++){
        factorial[i]=(factorial[i-1] * i) % mod;
    }
    for (int i=0;i<n;i++){
        ll in;
        cin >> in;
        t.insert(in);
        v.pb(in);
    }
    for (int i=0;i<n;i++){
        long long int order = t.order_of_key(v[i]);
        ans += (order * factorial[j--]);
        ans = ans % mod;
        t.erase(v[i]);
    }
    return ans;
}

int main(){ 
    int n;
    cin >> n;
    
    cout << func(n) << endl;
    return 0; 
}