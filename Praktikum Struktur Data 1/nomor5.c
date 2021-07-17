#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
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

void descen (int arr[], int n){
    int temp;
    int i, j;
    for ( i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++){
            if (arr[i] < arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for ( i = 0; i < n; i++)
    {
        if (arr[i] % 2 != 0){
            printf("%d\n", arr[i]);
        }
    }
    
}
void selectionSort(int arr[], int n)
{
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++) {
        if (arr[i] % 2 == 0){
            min_idx = i;
            for (j = i + 1; j < n; j++){
                if (arr[j] < arr[min_idx]){
                    min_idx = j;
                }
            }
            temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
    for (i = 0; i < n; i++){
        if (arr[i] % 2 == 0){
            printf("%d\n", arr[i]);
        }
    }
}
int main(int argc, char const *argv[])
{
    int n;  
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    selectionSort(arr, n);
    descen(arr, n);
    return 0;
}

// By Maula












// Soal no 2



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
//     long long int i, j; 
//     long long int max; 
//     for (i = 0; i < (n-k) + 1; i++){
//         max = arr[i];
//         for (j = 1; j < k; j++){
//             if (arr[i + j] > max){
//                 max = arr[i + j];
//             }
//         }
//         printf("%lld ", max); 
//     }
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
//     puts("");
//     return 0;
// }
