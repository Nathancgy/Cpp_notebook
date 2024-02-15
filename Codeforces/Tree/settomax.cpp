// First Segment Tree Problem ^^
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
const int N = 2e5 + 5;
ll a[N],b[N],ans[N],las[N],maxn[N<<2],minn[N<<2],n;
void up(ll p){
    maxn[p]=max(maxn[p<<1],maxn[p<<1|1]);
    minn[p]=min(minn[p<<1],minn[p<<1|1]);
    return;
}
void build(ll node,ll l,ll r){
    if(l==r){
        maxn[node] = a[l];
        minn[node] = b[l];
        return;
    }
    ll mid = l + r >> 1;
    build(node << 1, l, mid);
    build(node << 1 | 1, mid + 1, r);
    up(node);
    return;
}
ll querymin(ll node, ll l, ll r, ll lx, ll rx){
    if(rx<l || lx>r) return n+1;
    if(lx<=l && rx>=r) return minn[node];
    ll mid = l + r >> 1;
    return min(querymin(node << 1, l, mid, lx, rx), querymin(node << 1 | 1, mid + 1, r, lx, rx));
}
ll querymax(ll node, ll l, ll r, ll lx, ll rx){
    if(rx<l || lx>r) return 0;
    if(lx<=l && rx>=r) return maxn[node];
    ll mid = l + r >> 1;
    return max(querymax(node << 1, l, mid, lx, rx), querymax(node << 1 | 1, mid + 1, r, lx, rx));
}
void solve(){
    cin >> n;
    for(ll i = 1; i <= n; i++){
        ans[i] = 0, las[i] = 0;
        cin >> a[i];
    }
    for(ll i = 1; i <= n; i++) cin >> b[i];
    build(1, 1, n);
    for(ll i = 1; i <= n; i++){
        las[a[i]] = i;
        if(!las[b[i]]) continue;
        //cout << i << " " << las[b[i]] << " " << querymin(1, 1, n, las[b[i]], i) << " " << querymax(1, 1, n, las[b[i]], i) << " " << b[i] << "\n";
        if((querymin(1, 1, n, las[b[i]], i) < b[i]) || (querymax(1, 1, n, las[b[i]], i) > b[i])) continue;
        ans[i] = 1;
    }
    for(ll i = 1; i <= n; i++) las[i] = 0;
    for(ll i = n; i >= 1; i--){
        las[a[i]] = i;
        if(!las[b[i]]) continue;
        if((querymin(1, 1, n, i, las[b[i]]) < b[i]) || (querymax(1, 1, n, i, las[b[i]]) > b[i])) continue;
        ans[i] = 1;
    }
    //for(ll i = 1; i <= n << 2; i++) cout << maxn[i] << " ";
    for(ll i = 1; i <= n; i++){
        if(ans[i]) continue;
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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
