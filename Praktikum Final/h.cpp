#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <array>
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
typedef unsigned long long int ull;
typedef unsigned int ui;
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

using namespace std;

ll arr[1000000];

void func(int k){
    if(k == 0)
        arr[k] = 11;
    if(k == 1)
        arr[k] = 15;
    if(k>=2 && k<11) 
        arr[k] = ((arr[k-1]) + (arr[k-2])) % mod;
    if(k>=11 && k<15)
        arr[k] = ((arr[k-11])+ (arr[k-2])) % mod;
    else {
        arr[k] = ((arr[k-11]) + (arr[k-15]))% mod;
    }
}
int main(){
    for(int i = 0 ; i < 1000000;i++ ){ 
        func(i);
    }
    int t;
    scanf("%d",&t);
    for (int i=0; i<t; i++){
        int num;
        scanf("%d",&num);
        printf("%lli\n", arr[num]);
    }
    return 0;
}

// int func (ll x){
//     if (x == 0) return 11 % mod;
//     else if (x == 1) return 15 % mod;
//     else if (x >= 2 and x < 11) return (func (x-1) + func (x - 2)) % mod;
//     else if (x >= 11 and x < 15) return (func (x - 11) + func (x - 2)) % mod;
//     return func ( x - 11 ) + func (x - 15);
// }

// int main(int argc, char const *argv[])
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     ll t, x;
//     cin >> t;
//     for (ll i = 0; i < t; i++)
//     {
//         scanf ("%lld", &x);
//         printf("%lld", func(x));
//     }
//     return 0;
// }