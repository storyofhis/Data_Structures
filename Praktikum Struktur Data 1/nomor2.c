#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

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

// void SubArr_max (Deque *deque,unsigned long long arr[], unsigned long long n, unsigned long long k){
//     if (n > k){
//         for (unsigned long long i = 0; i < k; i++){
//             while (!deq_isEmpty(deque) && arr[deq_back(deque)] <= arr[i]){
//                 deq_popBack(deque);
//             }
//             deq_pushBack(deque,i) ;
//         }
//         for (unsigned long long i = k; i < n; i++){
//             printf("%llu ", arr[deq_front(deque)]);
//             if (i - deq_front(deque) == k){
//                 deq_popFront(deque);
//             }
//             while(!deq_isEmpty(deque) && arr[deq_back(deque)] <= arr[i]){
//                 deq_popBack(deque);
//             }
//             deq_pushBack(deque, i);
//         }
//         printf("%llu\n", arr[deq_front(deque)]);
//     }
// }

int main(int argc, char const *argv[])
{
    Deque dque;
    deq_init(&dque);
    long long int n;
    scanf("%lld", &n);
    unsigned long long arr[n];
    for(long long int i = 0; i < n; i++)
    {
        scanf("%llu",&arr[i]);
    }
    unsigned long long k;
    scanf("%llu", &k);
    
    if (n > k){
        for (long long int i = 0; i < k; i++){
            while (!deq_isEmpty(&dque) && arr[deq_back(&dque)] <= arr[i])
                deq_popBack(&dque);
            
            deq_pushBack(&dque,i) ;
        }
        for (long long int i = k; i < n; i++){
            printf("%llu ", arr[deq_front(&dque)]);
            if (i - deq_front(&dque) == k){
                deq_popFront(&dque);
            }
            while(!deq_isEmpty(&dque) && arr[deq_back(&dque)] <= arr[i])
                deq_popBack(&dque);
            
            deq_pushBack(&dque, i);
        }
        printf("%llu\n", arr[deq_front(&dque)]);
    }

    puts("\n");
    return 0;
}

// BY Maula



// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>

// typedef struct node {
//     long long data;
//     struct node *prev, *next;
// }DListNode;

// typedef struct deque {
//     DListNode *head, *tail;
//     unsigned size;
// }Deque;

// void init (Deque *deque){
//     deque->head = NULL;
//     deque->tail = NULL;
//     deque->size = 0;
// }
// bool isEmpty (Deque *deque){
//     return deque->head == NULL && deque->tail == NULL;
// }
// void pushFront (Deque *deque, int value){             
//     // DListNode *newNode = (DListNode *)malloc (sizeof(DListNode));           
//     // if (newNode){
//     //     DListNode *temp = deque->head;
//     //     deque->size++;
//     //     newNode->data = value;
//     //     newNode->next = NULL;
//     //     if(isEmpty(deque)){
//     //         deque->head = newNode;
//     //         return;
//     //     }
//     //     if (value > deque->head->data){
//     //         newNode->next = deque->head;
//     //         deque->head = newNode;
//     //     }
//     //     else {
//     //         while (temp->next != NULL && temp->next->data >value){
//     //             temp = temp->next;
//     //             newNode->next = temp->next;
//     //             temp->next = newNode;
//     //         }
//     //     }                         
//     // }
//     DListNode *newNode = (DListNode *)malloc(sizeof(DListNode));
//     if (newNode){
//         deque->size++;
//         if (isEmpty(deque))
//         {
//             deque->head = newNode;
//             deque->tail = newNode;
//             return; 
//         }
//         newNode->next = deque->head;
//         deque->head->prev = newNode;
//         deque->head = newNode;
//     }
// }
// void pushBack (Deque *deque, int value){
//     DListNode *newNode = (DListNode *)malloc (sizeof(DListNode));
//     if (newNode){
//         deque->size++;
//         if (isEmpty(deque)){
//             deque->head = newNode;
//             deque->tail = newNode;
//             return;
//         }
//         deque->tail->next = newNode;
//         newNode->prev = deque->tail;
//         deque->tail = newNode;
//     }
// }
// int getHead (Deque *deque) {
//     if (!isEmpty(deque)){
//         return deque->head->data;
//     }
//     return 0;
// }
// int getBack (Deque *deque) {
//     if (!isEmpty(deque)){
//         return deque->tail->data;
//     }
//     return 0;
// }
// void popFront (Deque *deque)
// {
//     if (!isEmpty(deque)){
//         DListNode *temp = deque->head;
//         if (deque->head == deque->tail){
//             deque->head = NULL;
//             deque->tail = NULL;
//             free(temp);
//         }else {
//             deque->head = deque->head->next;
//             deque->head->prev = NULL;
//             free(temp);
//         }
//         deque->size--;
//     }
// }
// void popBack (Deque *deque){
//     if(!isEmpty(deque)){
//         DListNode *temp;
//         if(deque->head == deque->tail){
//             temp = deque->head;
//             deque->head = NULL;
//             deque->tail = NULL;
//             free(temp);
//         }else {
//             temp = deque->tail;
//             deque->tail = deque->tail->prev;
//             deque->tail->next = NULL;
//             free(temp);
//         }
//         deque->size--;
//     }
// }
// void SubArr_max (Deque *deque,long long arr[], long long int n, long long int k){
//     // if (n > k){
//     //     int size_loop = (n - k) + 1;
//     //     int index;
//     //     for (index = 0; index < size_loop; index++){
//     //         for (int i = index; i < k; i++){
//     //             push(deque, arr[i]);
//     //         }
//     //         printf("%d ", getHead(deque));
//     //         k++;
//     //     }
//     // }
//     if (n > k){
//         for (int i = 0; i < k; i++){
//             while (!isEmpty(deque) && arr[getBack(deque)] <= arr[i]){
//                 popBack(deque);
//             }
//             pushBack(deque,i) ;
//         }
//         for (int i = k; i < n; i++){
//             printf("%lld ", arr[getHead(deque)]);
//             if (i - getHead(deque) == k){
//                 popFront(deque);
//             }
//             while(!isEmpty(deque) && arr[getBack(deque)] <= arr[i]){
//                 popBack(deque);
//             }
//             pushBack(deque, i);
//         }
//         printf("%lld\n", arr[getHead(deque)]);
//     }
//     // long long int i, j; 
//     // long long int max; 
//     // for (i = 0; i < (n-k) + 1; i++){
//     //     max = arr[i];
//     //     for (j = 1; j < k; j++){
//     //         if (arr[i + j] > max){
//     //             max = arr[i + j];
//     //         }
//     //     }
//     //     printf("%lld ", max); 
//     // }
// }
// int main(int argc, char const *argv[])
// {
//     Deque dque;
//     init(&dque);
//     long long int n;
//     scanf("%lld", &n);
//     long long int arr[n];
//     for(long long int i = 0; i < n; i++)
//     {
//         scanf("%lld",&arr[i]);
//     }
//     long long int k;
//     scanf("%lld", &k);
//     SubArr_max(&dque, arr, n, k);
//     // for (long long int i = 0; i < k; i++){
//     //     while(!isEmpty(dque) && arr[getBack(dque)] <= arr[i]){
//     //         popBack(dque);
//     //     }   
//     //     pushBack(i);
//     // }
//     // for (long long int i = k; i < n; i++){
//     //     printf("%lld", arr[getHead(dque)]);
//     //     if (i - getHead(dque) == k){
//     //         popFront(dque);
//     //     }
//     //     while (isEmpty(dque) && arr[getBack(dque)] <= arr[i]){
//     //         popBack(dque);
//     //     }
//     //     pushBack(i);
//     // }
//     // printf("%lld", arr[getHead(dque)]);
    
//     puts("\n");
//     return 0;
// }



// #include <algorithm>
// #include <iostream>
// #include <deque> 

// void printKMax(int arr[], int n, int k){
//     std::deque<int> queue;

//     for (int i = 0; i < k; i++) {
//         while (!queue.empty() && arr[queue.back()] <= arr[i]) {
//             queue.pop_back();
//         }

//         queue.push_back(i);
//     } 

//     for (int i = k; i < n; i++) {
//         std::cout << arr[queue.front()] << " ";

//         // an element with index queue.front() no longer belong to ths window
//         if (i - queue.front() == k) {
//             queue.pop_front();  
//         }

//         // pop all elements that don't exceed arr[i] as they're no longer useful
//         while (!queue.empty() && arr[queue.back()] <= arr[i]) {
//             queue.pop_back();
//         }  

//         queue.push_back(i);
//     }

//     std::cout << arr[queue.front()] << "\n";
// }



// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
 
// typedef struct dnode_t {
//     int data;
//     struct dnode_t      
//         *next,
//         *prev;
// } DListNode;
 
// /* Struktur ADT Deque */
// /* Implementasi didasarkan pada Doubly-Linked List */
 
// typedef struct deque_t {
//     DListNode           
//         *_head, 
//         *_tail;
//     unsigned _size;
// } Deque;
 
// /* DAFTAR FUNGSI YANG TERSEDIA */
 
// DListNode* __dlist_createNode(int value);
// void deq_init(Deque *deque);
// bool deq_isEmpty(Deque *deque);
// void deq_pushFront(Deque *deque, int value);
// void deq_pushBack(Deque *deque, int value);
// int  deq_front(Deque *deque);
// int  deq_back(Deque *deque);
// void deq_popFront(Deque *deque);
// void deq_popBack(Deque *deque);
// void printkMax(long arr[], int n, int k);
 
// /* Definisi Fungsi */
 
// DListNode* __dlist_createNode(int value)
// {
//     DListNode *newNode = \
//         (DListNode*) malloc (sizeof(DListNode));
 
//     if (!newNode) return NULL;
//     newNode->data = value;
//     newNode->next = NULL;
//     newNode->prev = NULL;
 
//     return (DListNode*) newNode;
// }
 
// void deq_init(Deque *deque)
// {
//     deque->_head = deque->_tail = NULL;
//     deque->_size = (unsigned) 0;
// }
 
// bool deq_isEmpty(Deque *deque) {
//     return (deque->_head == NULL && \
//             deque->_tail == NULL);
// }
 
// void deq_pushFront(Deque *deque, int value)
// {
//     DListNode *newNode = __dlist_createNode(value);
//     if (newNode) {
//         deque->_size++;
//         if (deq_isEmpty(deque)) {
//             deque->_head = newNode;
//             deque->_tail = newNode;
//             return;
//         }
 
//         newNode->next = deque->_head;
//         deque->_head->prev = newNode;
//         deque->_head = newNode;
//     }
// }
 
// void deq_pushBack(Deque *deque, int value)
// {
//     DListNode *newNode = __dlist_createNode(value);
//     if (newNode) {
//         deque->_size++;
//         if (deq_isEmpty(deque)) {
//             deque->_head = newNode;
//             deque->_tail = newNode;
//             return;
//         }
 
//         deque->_tail->next = newNode;
//         newNode->prev = deque->_tail;
//         deque->_tail = newNode;
//     }
// }
 
// int deq_front(Deque *deque) {
//     if (!deq_isEmpty(deque)) {
//         return (deque->_head->data);
//     }
//     return 0;
// }
 
// int deq_back(Deque *deque) {
//     if (!deq_isEmpty(deque)) {
//         return (deque->_tail->data);
//     }
//     return 0;
// }
 
// void deq_popFront(Deque *deque)
// {
//     if (!deq_isEmpty(deque)) {
//         DListNode *temp = deque->_head;
//         if (deque->_head == deque->_tail) {
//             deque->_head = NULL;
//             deque->_tail = NULL;
//             free(temp);
//         }
//         else {
//             deque->_head = deque->_head->next;
//             deque->_head->prev = NULL;
//             free(temp);
//         }
//         deque->_size--;
//     }
// }
 
// void deq_popBack(Deque *deque)
// {
//     if (!deq_isEmpty(deque)) {
//         DListNode *temp;
//         if (deque->_head == deque->_tail) {
//             temp = deque->_head;
//             deque->_head = NULL;
//             deque->_tail = NULL;
//             free(temp);
//         }
//         else {
//             temp = deque->_tail;
//             deque->_tail = deque->_tail->prev;
//             deque->_tail->next = NULL;
//             free(temp);
//         }
//         deque->_size--;
//     }
// }
 
// void printkMax(long arr[], int n, int k){
//     Deque mydeq;
//     deq_init(&mydeq);
 
//     int i;
//     for(i = 0; i < k; ++i){
//         while((!deq_isEmpty(&mydeq)) && arr[i] >=arr[deq_back(&mydeq)])
//             deq_popBack(&mydeq);
 
//         deq_pushBack(&mydeq, i);
//     }
 
//     for (; i < n; ++i){
//         printf("%ld ", arr[deq_front(&mydeq)]);
 
//         while ((deq_isEmpty(&mydeq)) && deq_front(&mydeq) <= i-k)
//             deq_popFront(&mydeq);
 
//         while (deq_isEmpty(&mydeq) && arr[i] >= arr[deq_back(&mydeq)])
//             deq_popBack(&mydeq);
 
//         deq_pushBack(&mydeq, i);
//     }
 
//     printf("%ld", arr[deq_front(&mydeq)]);
// }
 
// int main() {
 
//     int size, sub_size;
//     scanf("%d", &size);
 
//     long array[size];
 
//     for(int i = 0; i < size; i++){
//         scanf("%ld", &array[i]);
//     }
 
//     scanf("%d", &sub_size);
 
//     printkMax(array, size, sub_size);
// return 0;
// }