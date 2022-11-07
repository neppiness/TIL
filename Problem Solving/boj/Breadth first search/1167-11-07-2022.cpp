#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const int MX = 100'002;

int no, mx;
bool vis[MX];
vector<pair<int, int>> adj[MX];

void solve() {
  

}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> no;

  int u, v, cost;
  for(int i = 0; i < no; i++) {
    cin >> u >> v;
    while(v != -1) {
      cin >> cost;
      adj[u].push_back({v, cost});
      cin >> v;
    }
  }
  solve();
  cout << mx;
}