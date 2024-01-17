#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <queue>
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

using namespace std;

#define ll long long
#define pb push_back
#define sz(x) (long long)x.size()
#define mo 1000000007
#define ep() empty()
#define pii pair<ll,ll>
#define rep(a,b) for(long long a=0;a<b;a++)
#define rep1(a,b) for(long long a = 1; a<=b; a++)
#define forn(a,b,c) for(long long a=b;a<=c;a++)
#define vll vector<long long>

// ------------------------------------------------------------

ll n, k = 1000000, ans = 0;
vll a(200005);
vll prv(200005), nxt(200005), in(200005);

bool good(ll x){
    if(x<1 || x>n) return false;
    return a[x] - 1 == a[prv[x]] || a[x]-1 == a[nxt[x]];
}

void solve(){
    ans = 0, k = 1000000;
    cin >> n;
    rep1(i,n){
        cin >> a[i];
        in[i] = 0;
        prv[i] = i-1;
        nxt[i] = i+1;
    }
    a[n + 1] = a[0] = -2;
    priority_queue<pii> pq;
    rep1(i,n){
        if(good(i)){
            pq.push({a[i],i});
            in[i] = 1;
        }
    }
    while(!pq.empty()){
        auto [_,i] = pq.top(); pq.pop();
        prv[nxt[i]] = prv[i];
        nxt[prv[i]] = nxt[i];
        if(!in[prv[i]] && good(prv[i])){
            in[prv[i]] = 1;
            pq.push({a[prv[i]], prv[i]});
        }
        if(!in[nxt[i]] && good(nxt[i])){
            in[nxt[i]] = 1;
            pq.push({a[nxt[i]], nxt[i]});
        }
    }
    rep1(i, n){
        ans += !in[i];
        k = min(k,a[i]);
    }
    if(ans == 1 && k == 0) cout << "YES\n";
    else cout << "NO\n";
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}


