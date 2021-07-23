// Max-Heap data structure in C++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}
void heapify(vector<int> &hT, int i)
{
    int size = hT.size();
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && hT[l] > hT[largest])
        largest = l;
    if (r < size && hT[r] > hT[largest])
        largest = r;

    if (largest != i)
    {
        swap(&hT[i], &hT[largest]);
        heapify(hT, largest);
    }
}
void insert(vector<int> &hT, int newNum)
{
    int size = hT.size();
    if (size == 0)
    {
        hT.push_back(newNum);
    }
    else
    {
        hT.push_back(newNum);
        for (int i = size / 2 - 1; i >= 0; i--)
            heapify(hT, i);
    }
}

void printArray(vector<int> &hT)
{
    for (int i = 0; i < hT.size(); ++i)
        cout << hT[i] << " ";
    cout << "\n";
}

int main(){
    vector<int> heapTree;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i){
        int a;
        cin >> a;
        insert(heapTree, a);
    }

    cout << "Max-Heap array: ";
    for (int i = 0; i < heapTree.size(); i++){
        cout << heapTree[i] << " ";
    }cout << endl;
    int deleteNum; 
    cin >> deleteNum;
    cout << "After deleting an element: ";
    for (int i = 0; i < heapTree.size(); i++){
        cout << heapTree[i] << " ";
    }cout << endl;
}