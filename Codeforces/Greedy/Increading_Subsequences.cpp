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
    ll n;
    cin >> n;
    --n;
    vll ans;
    ll k = 1, cnt = 1;
    while(k<=n){
        n-=k;
        k*=2;
        ans.pb(cnt++);
    }
    for(ll i = 60; i >= 1; i--){
        if(n>=(1ll<<(i-1))){
            //cout << (1ll<<(i-1)) << "\n";
            n-=(1ll<<(i-1));
            ans.pb(i);
        }
    }
    cout << sz(ans) << "\n";
    rep(i,sz(ans)) cout << ans[i] << " ";
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