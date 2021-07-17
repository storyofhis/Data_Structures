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
class node {
    public:
        int key;
        node *left, *right;
};
class bst {
    public:
        node *_root;
        ui _size;
};
class c{
    public :
        int count;
};
node *__bst__createNode (int value){
    node *newNode = new node();
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
node *__bst__insert(node *root, int value){
    if (root == NULL)
        return __bst__createNode(value);
    if (value < root->key){
        root->left = __bst__insert(root->left, value);
    }else if (value > root->key){
        root->right = __bst__insert(root->right, value);
    }
    return root;
}
node *__bst__search (node *root, int value){
    while (root != NULL){
        if (value < root->key)
            root = root->left;
        else if (value > root->key)
            root = root->right;
        else 
            return root;
    }
    return root;
}
node *__bst__findMinNode (node *n){
    node *currNode = n;
    if (currNode){
        while (currNode->left != NULL){
            currNode = currNode->left;
        }
        return currNode;
    }
    return currNode;
}
void init (bst *bst){
    bst->_root = NULL;
    bst->_size = 0;
}
bool isEmpty (bst *bst){
    return bst->_root == NULL;
}
bool find (bst *bst, int value){
    node *temp = __bst__search(bst->_root, value);
    if (temp == NULL) return false;
    if (temp->key == value) return true;
    return false;
}
void insert (bst *bst, int value){
    if (!find(bst, value)){
        bst->_root = __bst__insert(bst->_root, value);
        bst->_size++;
    }
}

void maximum (node *root, int k, c *co){
    if (root == NULL || co->count >= k) return;
    maximum (root->right, k, co);
    co->count++;
    if (co->count == k){
        cout << root->key << endl;
        return;
    }
    maximum (root->left, k, co);
}
int main(int argc, char const *argv[])
{
    bst set;
    init (&set);
    int t = 1;
    c c;
    c.count = 0;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        for (int i = 0; i < n; i++){
            int num;
            cin >> num;
            insert(&set,num);
        }
        maximum(set._root, x, &c);
    }
    return 0;
}
