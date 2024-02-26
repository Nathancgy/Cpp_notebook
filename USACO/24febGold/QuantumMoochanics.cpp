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
#define N 200005
ll calc(ll x, ll y, const vector<ll>& p, const vector<ll>& s) {
    if (x%2 == 0) return (p[y]-p[x]+s[x]+s[y]-1)/(s[x]+s[y])*2-1;
    return (p[y]-p[x]+s[x]+s[y]-1)/(s[x]+s[y])*2;
}
void solve(){
    vll p(N), s(N), l(N), r(N), lst(N);
    ll n;
    cin >> n;
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> pq;
    rep(i, n) cin >> p[i];
    rep(i, n) cin >> s[i];
    rep(i, n) l[i] = i - 1, r[i] = i + 1;
    rep(i, n) if (i + 1 < n){
        pq.push(make_tuple(calc(i, i + 1, p, s),i,i + 1));
        //cout << calc(i, i + 1, p, s) << "\n";
    }
    while(true){
        if(pq.size() == 0) break;
        auto [time, x, y] = pq.top();
        pq.pop();
        if (lst[x] != 0 || lst[y] != 0) continue;
        lst[x] = time, lst[y] = time;
        if (l[x] != -1 && r[y] != n) pq.push(make_tuple(calc(l[x], r[y], p, s), l[x], r[y]));
        if (l[x] != -1) r[l[x]] = r[y];
        if (r[y] != n) l[r[y]] = l[x];
        //cout << x << " " << y << " " << time << " " << l[x] << " " << r[y] << "\n";
    }
    rep(i, n) cout << lst[i] << " \n"[i==n-1];
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