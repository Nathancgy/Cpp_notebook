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
    vll a(n);
    for(ll i = 0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    cout << abs(a[n-1]-a[0]) + abs(a[n-2]-a[0]) + abs(a[n-1]-a[1]) + abs(a[n-2]-a[1]) << "\n";
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