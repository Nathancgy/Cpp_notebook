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
void solve() {
   int n, m, x, y;
   cin >> n >> m;
   x = n; y = m;
   int bitA[65] = {0}, bitB[65] = {0}, msbA = 0, msbB = 0;
   int i = 0;
   while(n) {
    if(n&1) bitA[i] = 1;
    n /= 2;
    i++;
   }
   i = 0;
   while(m) {
     if(m&1) bitB[i] = 1;
     m /= 2;
     i++;
   }
   for(int i = 0; i <= 63; i++) {
    if(bitA[i]) msbA = i;
    if(bitB[i]) msbB = i;
   }
   if(bitA[msbB]) {
    cout << "1\n";
    cout << x << " " << y << endl;
    return;
   } 
   for(int i = msbB+1; i < msbA; i++) {
    if(bitA[i] == 1) {
        cout << 2 << endl;
        int mid = (1LL<<msbA) + (1LL<<msbB);
        cout << x << " " << mid << " " << y << endl;
        return;
    }
   }
   cout << "-1\n";
}
 
signed main() {
    // freopen("input.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}