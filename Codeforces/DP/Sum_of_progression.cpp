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
void solve(){
    ll n, m;
    cin >> n >> m;
    vll a(n);
    vector<vll> s1(201,vll(n+201));
    vector<vll> s2(201,vll(n+201));
    rep(i,n) cin >> a[i];
    a[0] = a[0];
    for(ll k = 1; k<=200; k++){
        for(ll i = 0; i < n; i ++){
            s1[k][i+k] = s1[k][i] + a[i];
            s2[k][i+k] = s2[k][i] + a[i] * (i/k + 1);
        }
    }
    rep(i,m){
        ll s,d,k;
        cin >> s >> d >> k;
        s--;
        if(d>200){
            ll cnt = 1, ans = 0;
            for(ll i = s; i <= s+d*(k-1); i+=d){
                ans = ans + a[i] * cnt;
                cnt++;
            }
            cout << ans << " ";
            continue;
        }
        cout << s2[d][s + d * k] - s2[d][s] - (s / d) * (s1[d][s + d * k] - s1[d][s]) << " ";
    }
    cout << "\n";
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


