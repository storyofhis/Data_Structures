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
}node, *nodePtr;
typedef struct sList{
    unsigned size;
    nodePtr head;
}sList, *sListPtr;
void init (sListPtr list)
{
    list->head = NULL;
    list->size = 0;
}
bool isEmpty (sListPtr list)
{
    if (list-> head == NULL){
        return true;
    }else {
        return false;
    }
}
void pushFront (sListPtr list, int value)
{
    nodePtr newNode = (nodePtr)malloc(sizeof(node));
    if (newNode){
        list->size++;
        newNode->num = value;
        if (isEmpty(list) == true){
            newNode->next = NULL;
        }else {
            newNode->next = list->head;     // ???
        }list->head = newNode;              // ???
    }
}
void popFront (sListPtr list){
    if (isEmpty(list) == false)
    {
        nodePtr temp = list->head;
        list->head = list->head->next;
        free(temp);
        list->size--;
    }
}
void pushBack (sListPtr list, int value){
    nodePtr newNode = (nodePtr)malloc(sizeof (node));
    if (newNode)
    {
        list->size++;
        newNode -> num = value;
        newNode -> next = NULL;
        if (isEmpty(list) == true){
            list->head = newNode;
        }else {
            nodePtr temp = list->head;
            while (temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}
void insertAt (sListPtr list, int index, int value){
    if(isEmpty(list) == true || index >= list->size){
        pushBack(list, value);
        return;
    }else {
        pushFront(list, value);
        return;
    }
    nodePtr newNode = (nodePtr)malloc(sizeof(node));
    if (newNode)
    {
        nodePtr temp = list->head;
        int i = 0;
        while (temp->next != NULL && i < index-1)
        {
            temp = temp->next;
            i++;
        }
        newNode -> data = value;
        newNode -> next = temp -> next;
        temp ->next = newNode;
        list -> size++;
    }
}
nodePtr makeNode (int n){
    nodePtr np = (nodePtr)malloc(sizeof(node));
    np->num = n;
    np->next = NULL;
    return np;
}
int main(int argc, char const *argv[])
{
    int n;
    nodePtr top, np, last;
    top = NULL;
    if (top == NULL){
        scanf("%d", &n);
        np = makeNode (n);
        top = np;   
    }

    
    return 0;
}
