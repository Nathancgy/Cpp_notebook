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
    ll n,m,k;
    cin >> n >> m;
    cout << "? 1 1" << endl;
    cin >> k;
    ll xl,yl,xr,yr;
    if(k>=n){
        xl=n,yl=k-n+2;
    }else{
        xl=k+1,yl=1;
    }
    if(k>=m){
        yr=m,xr=k-m+2;
    }else{
        xr=1,yr=k+1;
    }
    cout << "? " << xl << " " << yl << endl;
    cin >> k;
    k/=2;
    ll x1=xl-k,y1=yl+k;
    cout << "? " << xr << " " << yr << endl;
    cin >> k;
    k/=2;
    ll x2=xr+k,y2=yr-k;
    cout << "? " << x1 << " " << y1 << endl;
    cin >> k;
    if(k==0){
        cout << "! " << x1 << " " << y1 << endl;
    }else{
        cout << "! " << x2 << " " << y2 << endl;
    }
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