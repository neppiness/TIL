#include <bits/stdc++.h>
using namespace std;

const int MX = 10;

int adj[MX + 2][MX + 2];
vector<int> comb;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, st; cin >> n >> st;
  for(int i = 0; i < n; i++)
    if(i != st) comb.push_back(i);

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin >> adj[i][j];

  for(int k = 0; k < n; k++)
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
  
  int ans = 0x7f7f7f7f;
  do {
    int tmp = adj[st][comb[0]];
    for(int i = 1; i < n - 1; i++)
      tmp += adj[comb[i - 1]][comb[i]];
    ans = min(tmp, ans);
  } while(next_permutation(comb.begin(), comb.end()));
  
  cout << ans;
}