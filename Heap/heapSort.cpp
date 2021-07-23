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
void swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
}
void heapify(int *arr, int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
    if (l < n and arr[l] > arr[largest])
        largest = l;
    if (r < n and arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(int *arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

// Driver code
int main(int argc, char const *argv[]){
    int a[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(a)/sizeof(a[0]);
    heapSort(a, n);
    cout << "Sorted array is \n";
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << "\n";
    return 0;
}