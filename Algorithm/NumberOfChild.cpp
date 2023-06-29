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
vector <int> Graph[N];
vector <int> vis;
int child = 0;
void dfs(int node) {
 vis[node] = 1;
 bool flag = true;
 for (auto i : Graph[node]) {
  if(!vis[i]) {
    flag = false;
    dfs(i);
  }
 }
 if(flag) child++;
 return;
}
int main( ) {
  startTime = clock( );
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n; cin >> n;
  memset(Graph, 0, sizeof(Graph));
  vis.resize(n, 0);
  for(int i = 0 ; i < n - 1 ; i++) {
    int x, y; cin >> x >> y;
    x--, y--;
    Graph[x].push_back( y );
    Graph[y].push_back( x );
  }
  dfs(0);
  cout << child << endl;
  return 0;
}
