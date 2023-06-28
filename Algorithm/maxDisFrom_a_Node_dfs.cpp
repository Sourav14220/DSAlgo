#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> //Common file
#include <ext/pb_ds/tree_policy.hpp> //Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
typedef long long int ll;
typedef tree<ll, null_type,less<ll>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
//cout << *x.find_by_order(1) << endl; //iterator to the k-th largest element
//cout << x.order_of_key(-5) << endl; //number of items in a set that are strictly smaller than our item
clock_t startTime;
double getCurrentTime( ) {
 return (double)(clock( ) - startTime) / CLOCKS_PER_SEC;
}
const ll N = 1e5 + 123;
vector <ll> Graph[N];
bool vis[N];
vector <ll> path;
ll dis[N];
ll mx = 0;
void dfs(ll node, ll dist) {
 if(vis[node]) return;
 path.push_back(node);
 vis[node] = 1;
 dis[node] = dist;
 mx = max(mx, dist);
 for(auto u : Graph[node]) {
  dfs(u, dist + 1);
 }
 return;
}
int main( ) {
  startTime = clock( );
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int TC; cin >> TC;
  while( TC-- ) {
    ll n; cin >> n;
    for(int i = 1 ; i <= n ; i++) vis[i] = 0;
    for(int i = 1 ; i <= n - 1 ; i++) {
     ll x, y; cin >> x >> y;
     Graph[x].push_back( y );
     Graph[y].push_back( x );
    }
    dfs(1, 0);
    cout << mx << endl;
  }
  return 0;
}
