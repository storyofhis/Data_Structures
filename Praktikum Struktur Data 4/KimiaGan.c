#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef long long int ll;
typedef long double ld;
#define max 1500000

int main(int argc, char const *argv[])
{
    ll t;
    scanf("%lld", &t);
    // kulit atom (Ki)
    ll k[max] = {0};
    for (ll i = 1; i < max; i++){
        k[i] = k[i - 1] + (2*i*i);
    }
    for (ll i = 1; i < max; i++){
        ll n;
        scanf("%lld", &n);
        ll first = 0, result = 0, last = t, middle; 
        while (first <= last){
            middle = (first + last) / 2;
            if (k[middle] >= n){
                result = middle;
                last = middle - 1;
            }else {
                first = middle + 1;
            } 
        }
        printf("%lld\n", result);
    }
    return 0;
}
