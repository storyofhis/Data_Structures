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
#define MaxStack 1001
typedef long long int ll;
typedef long double ld;
using namespace std;
typedef struct node{
    int data;
    struct node *next;
}PQueueNode;
typedef struct pqueue{
    PQueueNode *top;
    unsigned size;
}PriorityQueue;

void init(PriorityQueue *pqueue);
bool isEmpty(PriorityQueue *pqueue);
void push(PriorityQueue *pqueue, int value);
void pop(PriorityQueue *pqueue);
int top (PriorityQueue *pqueue);

void init (PriorityQueue *pqueue){
    pqueue->top = NULL;
    pqueue->size = 0;
}
bool isEmpty(PriorityQueue *pqueue){
    return pqueue->top = NULL;
}
void push (PriorityQueue *pqueue, int value){
    PQueueNode *temp = pqueue->top;

    PQueueNode *newNode = (PQueueNode *)malloc(sizeof(PQueueNode));
    newNode->data = value;
    newNode->next = NULL;
    // Jika keadaan Kosong 
    if (isEmpty(pqueue)){
        pqueue->top = newNode; 
        return; 
    }
    // jika Value kurang dari nilai (top)
    if (value < pqueue->top->data){
        newNode->next = pqueue->top;
        pqueue->top = newNode;
    }else {
        while (temp->next != NULL && temp->next->data < value){
            temp = temp->next;  
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}
void pop (PriorityQueue *pqueue)
{
    if (!isEmpty(pqueue)){
        PQueueNode *temp = pqueue->top;
        pqueue->top = pqueue->top->next;
        free(temp);
    }
}
int top (PriorityQueue *pqueue)
{
    if(!isEmpty(pqueue)){
        return pqueue->top->data;
    }else {
        return (int)0;
    }
}
int main(int argc, char const *argv[])
{
    
    return 0;
}
