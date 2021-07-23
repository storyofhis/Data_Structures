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

typedef struct node {
    int data;
    struct node *next,
                *prev;
}DListNode;

typedef struct deque{
    DListNode *head,
              *tail;  
    unsigned size;
}DeQue;

DListNode *createNode (int value);
void init (DeQue *deque);
bool isEmpty (DeQue *deque);
void pushFront (DeQue *deque);
void pushBack (DeQue *deque);
int front (DeQue *deque);
int back (DeQue *deque);
void popBack (DeQue *deque);
void popFront (DeQue *deque);

DListNode *createNode (int value){              // DListNode *newNode = createNode(value); klo ini dia buat node baru pake fungsi yang mengembalikan node yg sdh ada valuenya
    DListNode *newNode = (DListNode*)malloc(sizeof(DListNode));
    if (newNode){
        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = NULL;
    }else if(!newNode){
        return NULL;
    }
    return (DListNode *)newNode;
}
void init (DeQue *deque){
    deque->head = NULL;
    deque->tail = NULL;
    deque->size = (unsigned)0;
}
bool isEmpty (DeQue *deque){
    return (deque->head == NULL && deque->tail == NULL);
}
void pushFront (DeQue *deque, int value){               //  ini kukasih contoh aja ya, misal queue nya = 1 3 5
    DListNode *newNode = createNode (value);            //  pushfront(2)
    if (newNode){
        deque->size++;
        if(isEmpty(deque)){
            deque->head = deque->tail = newNode;
            return;
        }
        newNode->next = deque->head;                    //  next nya dari 2 nunjuk ke head(1)
        deque->head->prev = newNode;                    //  prev dari head(1) nunjuk ke 2
        deque->head = newNode;                          //  head(1) diupdate jadi head(2)
    }
}
void pushBack (DeQue *deque, int value)
{
    DListNode *newNode = createNode(value);
    if (newNode){
        deque->size++;
        if (isEmpty(deque)){
            deque->head = newNode;
            deque->tail = newNode;
            return;
        }
        deque->tail->next = newNode;                    // next dari tail = newNode;
        newNode->prev = deque->tail;                    // prev dari newNode = tail;
        deque->tail = newNode;                          // tail = newNode;
    }   
}
int front (DeQue *deque){
    if (!isEmpty(deque)){
        return deque->head->data;
    }
    return (int)0;
}
int back (DeQue *deque){
    if (!isEmpty(deque)){
        return deque->tail->data;
    }
    return (int)0;
}
// popFront 
    //  head(1) 3 5
    //  jadi
    //  1 head(3) 5

    // head nya itu 3 masih ada akses prev ke 1
    // karena 
    // deque->head = deque->head->next;

    // jadi prev nya di null in baru putus
    // karena 
    // deque->head->prev = NULL
void popFront (DeQue *deque){
    if (!isEmpty(deque)){                               // 1 3 5        head = 1
        DListNode *temp = deque->head;
        if (deque->head == deque->tail){                // ngechek Node nya cuman 1
            deque->tail = NULL;
            deque->head = NULL;
            free(temp);
        }else {
            deque->head = deque->head->next;            // head = 3
            deque->head->prev = NULL;                   // 1 3 5 prev nya head yaitu 1 dimana 1 udah = NULL
            free(temp);                                 // jadi head(3) 5;
        }
        deque->size--;                                  // size --;
    }
}
void popBack (DeQue *deque){
    if (!isEmpty(deque)){
        DListNode *temp;
        if(deque->head == deque->tail){
            temp = deque->head;
            deque->head = NULL;
            deque->tail = NULL;
            free(temp);
        }else {
            temp = deque->tail;
            deque->tail = deque->tail->prev;
            deque->tail->next = NULL;
            free(temp);
        }
        deque->size--;
    }
}
int main(int argc, char const *argv[])
{
    
    return 0;
}
