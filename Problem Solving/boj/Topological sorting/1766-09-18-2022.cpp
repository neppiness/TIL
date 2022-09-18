#include <bits/stdc++.h>
using namespace std;

int n, m;
int u, v;
int id[32002];
vector<int> adj[32002];
vector<int> lev[32002];

void tr(int cur) {

}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    cin >> u >> v;
    adj[v].push_back(u);
  }

  for(int i = 1; i <= n; i++) tr(i);
}