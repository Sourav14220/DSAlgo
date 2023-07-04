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
const int N = 1e3 + 123;
bool vis[N];
vector <ll> Graph[N];
vector <ll> path;
void dfs(int node) {
 if(vis[node]) return;
 path.push_back(node);
 vis[node] = 1;
 for(auto u : Graph[node]) {
  dfs( u );
 }
 return;
}
int main( ) {
  startTime = clock( );
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m; cin >> n >> m;
  for(int i = 1 ; i <= n ; i++) vis[i] = 0;
  for(int i = 1 ; i <= m ; i++) {
    int x, y; cin >> y >> x;
    Graph[x].push_back( y );
    Graph[y].push_back( x );
  }
  dfs(3);
  for(auto u : path) {
    cout << u << " ";
  }
  return 0;
}
