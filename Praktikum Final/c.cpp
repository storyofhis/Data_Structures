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
#define s size_t
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


int main(int argc, char const *argv[])
{
    s t = 1;
    while (t--){
        s n; 
        cin >> n;
        s arr[n];
        for (s i = 0; i < t; i++){
            cin >> arr[i];
        }
        s result;
        for (s i = 0; i < t; i++){
            result = arr[i]^arr[i+1];
        }
        cout << result << endl;
    }
    return 0;
}
