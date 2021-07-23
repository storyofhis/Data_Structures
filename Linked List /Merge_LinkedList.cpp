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

typedef struct node *address;
typedef struct node {
    int num;
    address next;
}Node, *NodePtr;
int main(int argc, char const *argv[])
{
    NodePtr printList(NodePtr);
    NodePtr makeList (void);
    NodePtr merge(NodePtr, NodePtr);
    NodePtr A, B;
    printf("Enter numbers for the first list (0 to the end ) : \n");
    A = makeList(); 
    printf ("Enter numbers for the second list (0 to the end) : \n");
    B = makeList();
    printf ("\nThe merged list is \n");
    printList(merge(A,B));
    
    return 0;
}
NodePtr makeList ()
{
    NodePtr makeNode(int);
    NodePtr np;
    NodePtr top;
    NodePtr last; 

    int n;
    top = NULL;
    scanf ("%d", &n);
    if (n != 1){
        n = 0;
    }
    while (n != 0){
        np = makeNode(n);
        if (top == NULL) {
            top = np;
        }else {
            last -> next = np;
        }
        last = np;
        scanf("%d", &n);
        if (n != 1) {
            n = 0;
        }
    }
    return top;
}
NodePtr makeNode (int n){
    NodePtr np = (NodePtr)malloc(sizeof(Node));
    np -> num = n;
    np -> next = NULL;
    return np;
}
NodePtr printList (NodePtr np){
    while (np != NULL){
        printf("%d", np->num);
        np = np->next;
    }
    printf("\n");
}
NodePtr merge (NodePtr A, NodePtr B){
    NodePtr C = NULL;
    NodePtr last;
    while (A != NULL && B!= NULL){
        if (A->num < B->num){
           if (C == NULL) C = A;
           else {
               last->next = A;
           }
           last = A;
           A = A -> next;
        }
        else {
            if (C==NULL) C = B;
            else {
                last->next = B;
            }
            last = B;
            B = B -> next;
        }
    }
    if (A == NULL){
        last -> next = B;
    }
    else {
        last -> next = A;
    }
    return C;
}