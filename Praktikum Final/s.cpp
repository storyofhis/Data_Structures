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
int main(int argc, char const *argv[])
{
    ull t = 1;
    while (t--){
        ull n;
        cin >> n;
        ull x;
        set <ull> s;
        // set <ull> ::key_compare comp = s.key_comp();
        cin >> x;
        if (n == x)
            cout << "Y" << endl;
        else {
            if (n % 3 == 1 && x % 2 == 1){
                ull q;
                cin >> q;
                if (q % 2 == 0){
                    cout << "G" << endl;
                    return 0;
                }
                cout << "Y" << endl;
                return 0;
            }
            cout << "G" << endl;
        } 
    }
    return 0;
}
