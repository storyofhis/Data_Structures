// Huffman Coding
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
#include <utility>
#include <limits.h>
#include <functional>
#define pi 3.14159265
#define INF 0x3f3f3f3f
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define ff first
#define ss second
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define pq priority_queue
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
struct MinHeapNode {
    char data;
    unsigned freq;
    MinHeapNode *left, *right;
    public :
        MinHeapNode (char data, unsigned freq){
            left = right = NULL;
            this->data = data;
            this->freq = freq;
        }
};
struct compare{
    bool operator()(MinHeapNode* l, MinHeapNode* r){
        return (l->freq > r->freq);
    }
};
void printCodes(struct MinHeapNode* root, string str)
{
 
    if (!root)
        return;
 
    if (root->data != '$')
        cout << root->data << ": " << str << "\n";
 
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}
void HuffmanCodes(char data[], int freq[], int size)
{
    struct MinHeapNode *left, *right, *top;
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
 
    for (int i = 0; i < size; ++i)
        minHeap.push(new MinHeapNode(data[i], freq[i]));
    while (minHeap.size() != 1) {
        left = minHeap.top();
        minHeap.pop();
 
        right = minHeap.top();
        minHeap.pop();
        top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
 
        minHeap.push(top);
    }
    printCodes(minHeap.top(), "");
}

int main(int argc, char const *argv[])
{
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
 
    int size = sizeof(arr) / sizeof(arr[0]);
 
    HuffmanCodes(arr, freq, size);
    
    return 0;
}
