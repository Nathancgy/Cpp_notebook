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
#define sz(x) (int)x.size()
#define mo 1000000007
#define ep() empty()
#define pii pair<ll,ll>
#define rep(a,b) for(int a=0;a<b;a++)
#define forn(a,b,c) for(int a=b;a<=c;a++)
#define vll vector<long long>

// ------------------------------------------------------------
vector<vector<ll> > routes(755, vector<ll>(755));
vector<vector<ll> > dir(755, vector<ll>(755));

ll f(ll l, ll r){
    ll temp = 0;
    for(ll i = l; i < r; i++) temp ^= routes[l][i] * dir[i][r];
    return temp;
}

void solve(){
    ll n, ans = 0;
    cin >> n;
    rep(i,n-1){
        string s;
        cin >> s;
        for(ll j = i+1; j < n; j++) routes[i][j] = s[j-i-1] - '0';
    }
    for(ll i = n-1; i>=0;i--){
        for(ll j = i+1;j<n;j++){
            dir[i][j] = f(i,j) ^ routes[i][j];
            ans += dir[i][j];
        }
    }
    cout << ans << "\n";
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}


