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
int main(){
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);
    ll n, m, c, ans = 0;
    cin >> n >> m >> c;
    vll value(n);
    rep(i,n) cin >> value[i];
    vector<pii> edge(m);
    rep(i,m) cin >> edge[i].first >> edge[i].second;
    vector<vll> dp(3,vll(n+100));
    for(auto &row : dp) {
        fill(row.begin(), row.end(), -1LL);
    }

    dp[0][1] = 0;
    for(ll i = 1; i <= 1000; i++){
        ll x = i%2;
        fill(dp[x].begin(), dp[x].end(), -1LL);
        for(auto [a,b]: edge){
            if(dp[1-x][a]>=0){
                dp[x][b] = max(dp[x][b], dp[1-x][a] + value[b-1]);
            }
        }
        ans = max(ans, dp[x][1]-c*i*i);
    }
    cout << ans << "\n";
    return 0;
}


