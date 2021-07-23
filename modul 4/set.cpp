// TOPIC : std::set<T>

// SYNTAX : std::set<T> objectName;

// 1. Does not allowed Duplicate 
// 2. Sort Element

#include <iostream>
#include <map>
#include <queue>
#include <array>
#include <set>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iterator>
#include <functional>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "Does not allowed Duplicate : ";
    set<int> Set;
    for (int i = 1; i <= 10; i++){
        for (int j = 1; j <= 10; j++){
            Set.insert(j);
        }
        Set.insert(i);
    }
    for (const auto &e : Set){
        cout << e << " ";
    }

    cout<<"\n";
    cout << "set<int, std::greater<int> > SetKu : ";
    set <int, std::greater<int> > SetKu;
    SetKu.insert(9);
    SetKu.insert(7);
    SetKu.insert(5);
    SetKu.insert(2);
    SetKu.insert(8);
    SetKu.insert(1);
    SetKu.insert(4);c
    SetKu.insert(6);
    SetKu.insert(0);
    SetKu.insert(3);
    for (const auto &e : SetKu){
        cout << e << " ";
    }


    cout<<"\n";

    set<int> mySet;
    for (int i = 1 ; i <= 10 ; i++)
    {
        for (int j = 1 ; j <= 10 ; j++)
            mySet.insert(i);
    }

    cout << "ukuran set sekarang : " << mySet.size() << endl;
    cout << "elemen - elemen di dalam set : ";
    for (set<int>::iterator it = mySet.begin() ; it != mySet.end() ; ++it)
    {
        cout << *it << " "; //coba tebak kenapa harus pakai asterisk?
    }
    cout << endl;

    for (int i = 7 ; i <= 12 ; i++)
    {
        if (mySet.count(i))
            cout << i << " ada di dalam set" << endl;
        else
            cout << i << " tidak ada di dalam set" << endl;
    }

    set<int>::iterator lo,hi;
    mySet.erase(5);                 //1 2 3 4 6 7 8 9 10
    lo = mySet.lower_bound(4);      //      ^
    hi = mySet.upper_bound(4);      //        ^

    return 0;   
}