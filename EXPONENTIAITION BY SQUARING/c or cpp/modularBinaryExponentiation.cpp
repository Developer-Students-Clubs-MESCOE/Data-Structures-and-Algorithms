#include "bits/stdc++.h"
#define ll long long
#define lld long double
#define MOD 1000000007
#define inf 1000000000000000000ll
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

ll power(ll x,ll y, ll md=inf) {
    ll res = 1;x%=md;
    while(y){
        if(y&1)
            res = (res*x)%md;
        x *= x; 
        if(x>=md)
            x %= md; 
        y >>= 1;
    }
    return res;
}

int main(){
    assert(power(3,5)==243);
    assert(power(2,15)==32768);
}
