// Maula Jago Deque

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
typedef long long int ll;
typedef unsigned long long llu;
typedef long double ld;
/* Struktur Node */

typedef struct dnode_t {
    int data;
    struct dnode_t      \
        *next,
        *prev;
} DListNode;

/* Struktur ADT Deque */
/* Implementasi didasarkan pada Doubly-Linked List */

typedef struct deque_t {
    DListNode           \
        *_head, 
        *_tail;
    unsigned _size;
} Deque;

/* DAFTAR FUNGSI YANG TERSEDIA */

DListNode* __dlist_createNode(int value);
void deq_init(Deque *deque);
bool deq_isEmpty(Deque *deque);
void deq_pushFront(Deque *deque, int value);
void deq_pushBack(Deque *deque, int value);
int  deq_front(Deque *deque);
int  deq_back(Deque *deque);
void deq_popFront(Deque *deque);
void deq_popBack(Deque *deque);

void insertAt (Deque *deque, int index, int value);

/* Definisi Fungsi */

DListNode* __dlist_createNode(int value)
{
    DListNode *newNode = \
        (DListNode*) malloc (sizeof(DListNode));
    
    if (!newNode) return NULL;
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    return (DListNode*) newNode;
}

void deq_init(Deque *deque)
{
    deque->_head = deque->_tail = NULL;
    deque->_size = (unsigned) 0;
}

bool deq_isEmpty(Deque *deque) {
    return (deque->_head == NULL && \
            deque->_tail == NULL);
}

void deq_pushFront(Deque *deque, int value)
{
    DListNode *newNode = __dlist_createNode(value);
    if (newNode) {
        deque->_size++;
        if (deq_isEmpty(deque)) {
            deque->_head = newNode;
            deque->_tail = newNode;
            return;
        }

        newNode->next = deque->_head;
        deque->_head->prev = newNode;
        deque->_head = newNode;
    }
}

void deq_pushBack(Deque *deque, int value)
{
    DListNode *newNode = __dlist_createNode(value);
    if (newNode) {
        deque->_size++;
        if (deq_isEmpty(deque)) {
            deque->_head = newNode;
            deque->_tail = newNode;
            return;
        }
        deque->_tail->next = newNode;
        newNode->prev = deque->_tail;
        deque->_tail = newNode;
    }
}

int deq_front(Deque *deque) {
    if (!deq_isEmpty(deque)) {
        return (deque->_head->data);
    }
    return 0;
}

int second_front (Deque *deque){
    if (!deq_isEmpty(deque)){
        return (deque->_head->next->data);
    }
    return 0;
}

int deq_back(Deque *deque) {
    if (!deq_isEmpty(deque)) {
        return (deque->_tail->data);
    }
    return 0;
}

void deq_popFront(Deque *deque)
{
    if (!deq_isEmpty(deque)) {
        DListNode *temp = deque->_head;
        if (deque->_head == deque->_tail) {
            deque->_head = NULL;
            deque->_tail = NULL;
            free(temp);
        }
        else {
            deque->_head = deque->_head->next;
            deque->_head->prev = NULL;
            free(temp);
        }
        deque->_size--;
    }
}

void deq_popBack(Deque *deque)
{
    if (!deq_isEmpty(deque)) {
        DListNode *temp;
        if (deque->_head == deque->_tail) {
            temp = deque->_head;
            deque->_head = NULL;
            deque->_tail = NULL;
            free(temp);
        }
        else {
            temp = deque->_tail;
            deque->_tail = deque->_tail->prev;
            deque->_tail->next = NULL;
            free(temp);
        }
        deque->_size--;
    }
}


void insertAt (Deque *deque, int index, int value){
    if (deq_isEmpty(deque) || index >= deque->_size){
        deq_pushBack(deque, value);
        return;
    }else if (index == 0 || index < 0){
        deq_pushFront(deque, value);
        return;
    }
    DListNode *newNode = (DListNode *)malloc(sizeof(DListNode));
    if (newNode){
        DListNode *temp = deque->_head;
        int i = 0;

        while (temp->next != NULL && i < index-1){
            temp = temp->next;
            i++;
        }
        newNode->data = value;
        newNode->next = temp->next;
        temp->next = newNode;
        deque->_size++;
    }
}
void takeAB (Deque *deque, int index, int value) {
    int a, b;
    if (!deq_isEmpty(deque))
}
int main(int argc, char const *argv[])
{
    Deque dque;
    int n, q;
    scanf("%d %d", &n, &q);
    int arr[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        insertAt(&dque, i, arr[i]);
    }
    int m[q];
    for (int i = 0; i < q; i++){
        scanf("%d", &m[i]);
        takeAB(&dque, i, m[i]);
    }


    return 0;
}