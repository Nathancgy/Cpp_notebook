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
#define pii pair<ll,ll>
#define rep(a,b) for(ll a=0;a<b;a++)
#define vll vector<long long>
 
// ------------------------------------------------------------
void solve(){
    ll n;
    cin >> n;
    ll k[10];
    k[1]=1,k[2]=3,k[3]=6,k[4]=10,k[5]=15;
    ll ans = 0;
    if(n>=30){
        ll p=n-30;
        p/=15;
        ans+=p;
        n=n-p*15;
    }
    vll a(n+1,0);
    for(ll i = 1; i<=n;i++){
        ll f = 0;
        for(ll j = 1;j<=5;j++){
            if(k[j]==i){
                a[i]++;
                f=1;
                break;
            }
        }
        if(f) continue;
        for(ll j = 1;j<=5;j++){
            if(i>k[j]){
                if(a[i]==0) a[i]=a[i-k[j]]+1;
                else a[i]=min(a[i],a[i-k[j]]+1);
            }
        }
    }
    cout << a[n]+ans << "\n";
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