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
typedef struct QueueNode {
    char masuk[1001];
    int id;
    int urgensi;
    struct QueueNode *next;
}QueueNode;
typedef struct Queue{
    QueueNode *front;
    QueueNode *back;
    unsigned size;
}queue;
/* initialisasi */
void stack_init (Queue *queue)
{
    queue->size = 0;
    queue->top = NULL;
    queue->back = NULL;
}
bool isEmpty (Queue *queue)
{
    return queue->top == NULL && queue->back == NULL;
}
void queue_push (Queue *queue, char *Qmasuk, int ID, int urgent)
{
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    if (newNode){
        queue->size++;
        newNode->masuk = Qmasuk;
        newNode->id = ID;
        newNode->urgensi = urgent;
        newNode->next = NULL;
        if (isEmpty(queue)){
            queue->front = queue->back = newNode;
        }else {
            queue->back->next = newNode;
            queue->back = newNode;
        }
    }
}
void queue_pop (Queue *queue)
{
    if (!isEmpty(queue))
    {
        QueueNode *temp = queue->front;
        queue->front = queue->front->next;
        free(temp);

        if (queue->front == NULL){
            queue->back = NULL;
        }
        queue->size--;
    }
}
int queue_front (Queue *queue) {
    if (!isEmpty(queue)) {
        return queue->front->masuk && queue->front->id && queue->front->urgensi;
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    scanf("%d", &(Queue->size));

    return 0;
}
