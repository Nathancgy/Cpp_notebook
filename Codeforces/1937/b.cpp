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
    ll n, k = 1, flag = 0, pot = 0;
    vector<char> ans;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    ans.pb(s1[0]);
    for(ll i = 0;i<n;i++){
        if(i==n-1){
            ans.pb(s2[i]);
            break;
        }
        if(flag){
            ans.pb(s2[i]);
            continue;
        }
        ll x = s1[i+1]-'0';
        ll y = s2[i]-'0';
        if(y<x){
            flag = 1;
            ans.pb(s2[i]);
            continue;
        }else if(x==y){
            k++;
            pot++;
            ans.pb(s2[i]);
        }else{
            k-=pot;
            pot = 0;
            ans.pb(s1[i+1]);
        }
    }
    rep(i,ans.size()) cout << ans[i];
    cout << "\n";
    cout << k << "\n";
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