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
}QueueNode;
typedef struct queue{
    QueueNode *front,
              *back;
    unsigned size;
}Queue;

void init (Queue *queue);
bool isEmpty (Queue *queue);
void push (Queue *queue, int value);
void pop (Queue *queue);
int front (Queue *queue);
int size (Queue *queue);

void init (Queue *queue){
    queue->front = NULL;
    queue->back = NULL;
    queue->size = 0;
}
bool isEmpty(Queue *queue){
    if (queue->front == NULL && queue->back == NULL){
        return true;
    }else {
        return false;
    }
}
void push (Queue *queue, int value){
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    if (newNode){
        queue->size++;
        newNode->data = value;
        newNode->next = NULL;
        if (isEmpty(queue) == true){
            queue->front = queue->back = newNode;
        }else {
            queue->back->next = newNode;
            queue->back = newNode;
        }
    }
}
void pop (Queue *queue){
    if (isEmpty(queue)==false){
        QueueNode *temp = queue->front;
        queue->front = queue->front->next;
        free(temp);

        if (queue->front == NULL){
            queue->back = NULL;
        } 
        queue->size--;
    }
}
int front (Queue *queue){
    if (isEmpty(queue)==false){
        return queue->front->data;
    }
    return (int)0;
}
int size (Queue *queue){
    return queue->size;
}

int main(int argc, char const *argv[])
{
    Queue myQueue;
    printf("Queue\n");
    printf("1. Push \n");
    printf("2. Pop \n");
    printf("3. Front \n");
    printf("4. Size \n");
    printf("5. Exit ");

    int pilih;
    int n;
    do
    {   
        printf("\n");
        scanf("%d", &pilih);
        switch (pilih)
        {
            case 1: 
                printf("Push : \n");
                scanf("%d", &n);
                push(&myQueue, n);
                break;
            case 2: 
                printf("Pop : \n");
                while (isEmpty(&myQueue) == false)
                {
                    printf("%d", front(&myQueue));
                    pop(&myQueue);   
                }
                break;
            case 3: 
                printf("Front : \n");   
                front(&myQueue);
                break;
            case 4: 
                printf("size : \n");
                size(&myQueue);
                break;  
            default:
                break;
        }   
        
    }while (pilih != 5);
    puts(" ");
    return 0;
}