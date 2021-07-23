#include <iostream>
#include <map>
#include <list>
#include <queue>
#include <array>
#include <set>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <functional>

// This program shows off multiset STL Container implementation in C++
// By: Maula 
using std::cout;
using std::endl;
using std::list;
using std::vector; 

using namespace std;

class Person{
    public: 
        float age;
        string name;
    bool operator < (const Person& rhs) const { return age<rhs.age; }
    bool operator > (const Person& rhs) const { return age>rhs.age; }
};

int main(int argc, char const *argv[])
{
    std::multiset<Person, std::greater<Person> > multiSet;
    std::multiset<int> multiset;
    std::multiset<int>::iterator it1, it2;
    multiset.insert(5);
    multiset.insert(2);
    multiset.insert(4);
    multiset.insert(3);
    multiset.insert(2);
    multiset.insert(5);
    // std::reverse(multiset.begin(), multiset.end());
    for (it1 = multiset.begin(); it1 != multiset.end(); ++it1){
        cout << *it1 << " ";
    }
    cout << endl;
    std::multiset<int, std::greater<int> >MSet;

    MSet.insert(5);
    MSet.insert(2);
    MSet.insert(4);
    MSet.insert(3);
    MSet.insert(2);
    MSet.insert(5);
    for (it2 = MSet.begin(); it2 != MSet.end(); ++it2){
        cout << *it2 << " ";
    }
    return 0;
}
