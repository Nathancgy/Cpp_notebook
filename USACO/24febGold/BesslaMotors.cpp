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
#define N 100007
#define M 200007
struct node
{
    ll st, d, cur;
};
bool operator<(const node& a, const node& b) {
    return a.d > b.d;
}
unordered_map<ll, unordered_map<ll, ll>> graph1;
unordered_map<ll, vector<pii>> graph2;
unordered_map<ll, unordered_map<ll, ll>> visited;
priority_queue<node> pq;
ll n, m, s, u, v, w, cnt, dis, c, r, k;
vll books(N), ans;
void build(){
    forn(i, 1, n){
        for(auto o : graph1[i]){
            graph2[i].push_back({o.second, o.first});
        }
        sort(graph2[i].begin(), graph2[i].end());
    }
}
void solve(){
    cin >> n >> m >> c >> r >> k;
    rep(i,m){
        cin >> u >> v >> w;
        graph1[u][v] = w;
        graph1[v][u] = w;
    }
    build();
    forn(i, 1, c){
        pq.push({i, 0, i});
    }
    while (!pq.empty()){
        node tmp = pq.top();
        pq.pop();
        u = tmp.st;
        dis = tmp.d;
        ll cur = tmp.cur;
        if (books[u] < k && !visited[cur][u]){
            visited[cur][u] = 1;
            ++books[u];
        }
        else continue;
        for (pii p1: graph2[u]){
            ll x = p1.first, y = p1.second;
            if(!visited[cur][y] && books[y] < k && x + dis <= r) pq.push({y, x + dis, cur});
        }
    }
    forn(i, c+1, n){
        if (books[i] >= k) ans.pb(i);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    rep(i, ans.size()) cout << ans[i] << "\n";
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