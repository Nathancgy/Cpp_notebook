// Nathan4
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <chrono>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
unsigned long long random_seed=std::chrono::steady_clock::now().time_since_epoch().count();
 
using namespace std;
#define ll long long
#define pb push_back
#define pii pair<ll,ll>
#define rep(a,b) for(ll a=0;a<b;a++)
#define vll vector<long long>
template<typename _Size>
  inline _Size
  __lg(_Size __n)
  {
    _Size __k;
    for (__k = 0; __n != 0; __n >>= 1)
  ++__k;
    return __k - 1;
  }
// ------------------------------------------------------------
void solve(){
    ll n, a, b;
    cin >> n;
    if(__builtin_popcountll(n)%2){
        cout << "second" << endl;
        cin >> a >> b;
        if(!a && !b) return;
        if(__builtin_popcountll(a)%2) n=b;
        else n=a;
    }else{
        cout << "first" << endl;
    }
    while(true){
        ll k = (1ll<<__lg(n));
        cout << k << " " << (n^k) << endl;
        cin >> a >> b;
        if(!a && !b) return;
        if(__builtin_popcountll(a)%2) n=b;
        else n=a;
    }
    return;
}
int main(){
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}