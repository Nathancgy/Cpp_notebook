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
    ll maxn = 0;
    for(ll i = 1; i < n; i++){
        cout << "? " << maxn << " " << maxn << " " << i << " " << i << endl;
        char c;
        cin >> c;
        if(c=='<') maxn = i;
    }
    ll maxk = 0;
    vll temp;
    for(ll i = 0; i < n; i++){
        cout << "? " << maxn << " " << maxk << " " << maxn << " " << i << endl;
        char c;
        cin >> c;
        if(c=='=') temp.pb(i);
        if(c=='<'){
            temp.clear();
            maxk = i;
            temp.pb(i);
        }
    }
    ll minn = temp[0];
    for(ll i = 1;i<temp.size();i++){
        cout << "? " << minn << " " << minn << " " << temp[i] << " " << temp[i] << endl;
        char c;
        cin >> c;
        if(c=='>'){
            minn = temp[i];
        }
    }
    cout << "! " << minn << " " << maxn << endl;
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