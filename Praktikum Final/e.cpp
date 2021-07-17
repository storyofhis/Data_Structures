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

int func (st s, int i){
    return (s.empty() ? i : i - s.top() - 1);
}

int main()
{
    int arr[10000];
    int n;
    st s;
    while(scanf("%d", &n) != EOF){
        for (int i=0; i<n; i++){
            cin >> arr[i];
        }
        int max_area = 0;
        int tp; 
        int area_with_top;

        int i = 0;
        while (i < n) {
            if (s.empty() || arr[s.top()] <= arr[i]){
                s.push(i++);
            }
            else{
                tp = s.top(); 
                s.pop();
                area_with_top = arr[tp] * func(s, i);

                if (max_area < area_with_top){
                    max_area = area_with_top;
                }
            }
        }

        while (s.empty() == false){
            tp = s.top();
            s.pop();
            area_with_top = arr[tp] * func(s, i);

            if (max_area < area_with_top){
                max_area = area_with_top;
            }
        }
        cout << max_area << endl;
    } 
    
    
    return 0;
}