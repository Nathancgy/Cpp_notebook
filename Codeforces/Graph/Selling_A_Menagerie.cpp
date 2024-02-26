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
    ll n;
    cin >> n;
    vll adj(n+1);
    vll radj(n+1);
    priority_queue<pii, vector<pii>, greater<>> pq;
    vector<bool> visited(n+1, false);
    rep(i,n){
        ll x;
        cin >> x;
        adj[i+1] = x;
        radj[x]++;
    }
    rep(i, n){
        ll x;
        cin >> x;
        pq.push({x, i+1});
    }
    vll ans, k;
    for(ll i = 1; i <= n; i++){
        if(radj[i] == 0){
            k.pb(i);
        }
    }
    while(k.size()){
        vll temp;
        rep(i, k.size()){
            radj[adj[k[i]]]--;
            ans.pb(k[i]);
            visited[k[i]] = true;
            if(radj[adj[k[i]]]==0) temp.pb(adj[k[i]]);
        }
        k = temp;
    }
    while(pq.size()){
        auto [val, x] = pq.top();
        pq.pop();
        if(visited[x]) continue;
        visited[x] = true;
        ll k = x;
        while(adj[k]!=x){
            ans.pb(adj[k]);
            visited[adj[k]] = true;
            k = adj[k];
        }
        ans.pb(x);
    }
    rep(i,n) cout << ans[i] << " \n"[i==n-1];
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
