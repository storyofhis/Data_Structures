#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <stddef.h>
#include <map>
#include <set>
#include <vector>
#include <cassert>
#include <sstream>
#include <queue>
#include <limits>
#include <ctime>
#include <stack>
#include <string>
#include <cstdlib>
#include <typeinfo>
#include <ctype.h>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define REP(i,a,b) for(ll i=a;i<=b;i++)
#define F first
#define S second
#define mp make_pair
#define sortb(a) sort(a,a+n)
#define sortr(a) sort(a,a+n,greater<int>())
#define inf LLONG_MAX
#define RogueValue -9999
#define MaxStack 10
typedef long long int ll;
typedef long double ld;
using namespace std;
typedef struct node {
    int num;
    struct node *next;
}Node, *NodePtr;
NodePtr makeNode (int n){
    NodePtr np = (NodePtr)malloc(sizeof(Node));
    np->num = n;
    np->next = NULL;
    return np;
}
void printList (NodePtr np){
    while (np->next != NULL)
    {
        printf("%d \n", np->num);
        np = np->next;
    }
}
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    NodePtr top, np, last;
    top = NULL;
    if (n!=1){
        n=0;
    }
    while (n!=0){
        np = makeNode(n);
        if (top == NULL){
            top = np;
        }else last->next = np;
        last = np;
        if (n!=1){
            n=0;
        }
        printList(top);
    }
    return 0;
}
