// TOPIC: std::vector<Type>

// NOTES: 
// 1. std::vector is a sequence container and also known as Dynamic Array or Array List.
// 2. Its size can grow and shrink Dynamically, and no need to provide size at compile time.

// ELEMENT ACCESS
// at(), [], front(), data()

// MODIFIERS:
// insert(), emplace(), push_back(), emplace_back(), pop_back(), resize(), swap(), erase(), clear()

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <list>
#include <array>
#include <map>
using namespace std;
using std::cout;
using std::endl;
using std::list;
using std::vector;

int main(int argc, char const *argv[])
{
    vector<int> angka;
    vector<int> arr(5, 20); // arr[5] = [20, 20, 20, 20, 20];
    vector<int> genap;
    genap.push_back(2);
    genap.push_back(4);
    genap.push_back(6);
    genap.push_back(8);
    vector<int> ganjil;
    ganjil.push_back(1);
    ganjil.push_back(3);
    ganjil.push_back(5);
    ganjil.push_back(7);

    vector<int> ::iterator i;

    angka.push_back(1);
    angka.push_back(2);
    angka.push_back(3);
    angka.push_back(4);

    cout << "Isi vector \"angka\":";
    for (i = angka.begin(); i != angka.end(); ++i)
        cout << ' ' << *i;
    cout << '\n';

    cout << "Jumlah elemen pada vector \"angka\": " << angka.size() << "\n";
    cout << "Jumlah maksimal elemen yang dapat ditampung oleh vector \"angka\": " << angka.max_size() << "\n";

    if (angka.empty())
        cout << "Vector \"angka\" kosong.\n";
    else
        cout << "Vector \"angka\" tidak kosong.\n";

    angka.pop_back();

    cout << "Isi vector \"angka\" setelah pop back:";
    for (i = angka.begin(); i != angka.end(); ++i)
        cout << ' ' << *i;
    cout << '\n';

    angka.resize(5, 100);

    cout << "Isi vector \"angka\" setelah resize:";
    for (i = angka.begin(); i != angka.end(); ++i)
        cout << ' ' << *i;
    cout << '\n';

    angka.assign(8, 10);

    cout << "Isi vector \"angka\" setelah assign:";
    for (i = angka.begin(); i != angka.end(); ++i)
        cout << ' ' << *i;
    cout << '\n';

    // memasukkan nilai 20 di posisi ke-2
    angka.insert(angka.begin() + 1, 20);

    // memasukkan nilai 30 di posisi ke-3 sebanyak 3
    angka.insert(angka.begin() + 2, 3, 30);

    cout << "Isi vector \"angka\" setelah insert:";
    for (i = angka.begin(); i != angka.end(); ++i)
        cout << ' ' << *i;
    cout << '\n';

    // menghapus elemen ke-2
    angka.erase(angka.begin() + 1);

    // menghapus elemen ke-2 hingga elemen ke-5
    angka.erase(angka.begin() + 1, angka.begin() + 4);

    cout << "Isi vector \"angka\" setelah erase:";
    for (i = angka.begin(); i != angka.end(); ++i)
        cout << ' ' << *i;
    cout << '\n';

    angka.clear();

    if (angka.empty())
        cout << "Vector \"angka\" kosong.\n";
    else
        cout << "Vector \"angka\" tidak kosong.\n";

    cout << "Isi vector \"genap\":";
    for (i = genap.begin(); i != genap.end(); ++i)
        cout << ' ' << *i;
    cout << '\n';

    cout << "Isi vector \"ganjil\":";
    for (i = ganjil.begin(); i != ganjil.end(); ++i)
        cout << ' ' << *i;
    cout << '\n';

    genap.swap(ganjil);
    // atau
    // ganjil.swap(genap);

    cout << "Isi vector \"genap\" setelah swap:";
    for (int i = 0; i < 4; i++)
        cout << ' ' << genap.at(i);
    cout << '\n';

    cout << "Isi vector \"ganjil\" setelah swap:";
    for (int i = 0; i < 4; i++)
        cout << ' ' << ganjil.at(i);
    cout << '\n';

    vector<int> toSort;
    toSort.push_back(5);
    toSort.push_back(3);
    toSort.push_back(2);
    toSort.push_back(4);
    toSort.push_back(1);
    vector<int>::iterator lo,hi;
    
    sort(toSort.begin(),toSort.end());

    for (int i = 0 ; i < 5 ; i++)
        cout << " "  << toSort[i];                  //1 2 3 4 5
    cout << endl;
    lo = lower_bound(toSort.begin(),toSort.end(),3);//    ^
    hi = upper_bound(toSort.begin(),toSort.end(),3);//      ^

    cout << "index lower_bound : " << (lo - toSort.begin()) << endl;
    cout << "index upper_bound : " << (hi - toSort.begin()) << endl;
    return 0;
}