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
const int N = 1e5 + 123;
vector <ll> Graph[N];
vector <bool> vis( N );
vector <ll> col( N );
bool flag = true;
void dfs(int node, int color) {
 if(vis[node]) return;///1
 vis[node] = true;///1 -> true
 col[node] = color;///1 -> 0
 for(auto u : Graph[node]) {///
  if(!vis[u]) dfs(u, color ^ 1);
  else if(col[u] == color) {
    flag = false;
    return;
  }
 }
 return;
}
int main( ) {
  startTime = clock( );
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, e; cin >> n >> e;
  for(int i = 1 ; i <= n ; i++) vis[i] = false;
  for(int i = 1 ; i <= e ; i++) {
    int x, y; cin >> x >> y;
    Graph[x].push_back( y );
    Graph[y].push_back( x );
  }
  dfs(1, 0);
  cout << (flag ? "Bipartite" : "Not Bipartite") << endl;
  return 0;
}
