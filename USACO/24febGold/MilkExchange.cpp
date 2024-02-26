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
#define sz(x) (ll)x.size()
#define mo 1000000007
#define ep() empty()
#define pii pair<ll,ll>
#define rep(a,b) for(ll a=0;a<b;a++)
#define rep1(a,b) for(ll a = 1; a<=b; a++)
#define forn(a,b,c) for(ll a=b;a<=c;a++)
#define vll vector<long long>

// ------------------------------------------------------------
void solve(){
    ll n, cnt = 0, mn = 1e9 + 5;
    deque<ll> pos;
    cin >> n;
    vll a(2*n+5), k(n+5);
    rep(i, n){
        cin >> a[i];
        //b[i] = a[i];
        a[i+n] = a[i];
        cnt += a[i];
        //mn = min(mn, a[i]);
    }
    rep(i, n){
        while(pos.size()>0 && a[pos.back()]>=a[i]){
            pos.pop_back();
        }
        pos.pb(i);
    }
    forn(i, n, 2*n-1){
        while(pos.size()>0){
            if(pos.front() < i - n) pos.pop_front();
            else break;
        }
        if(a[i]>a[i-1]){
            pos.pb(i);
            continue;
        }
        while(pos.size()>0){
            if(a[pos.back()] <= a[i]) break;
            k[i-pos.back()] += a[pos.back()] - a[i];
            ll temp = a[pos.back()] - a[i];
            pos.pop_back();
            if(pos.size()>0) k[i-pos.back()] -= temp;
        }
        pos.pb(i);
    }
    forn(i, 1, n){
        k[i] += k[i-1];
        cnt -= k[i];
        cout << cnt << "\n";
    }
    return;
}
int main(){
    ll t=1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}