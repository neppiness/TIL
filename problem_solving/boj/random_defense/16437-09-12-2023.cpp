#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MX = 123'456;

int n;
ll val[MX + 2][2]; // val[cur][is_wolf] = no
vector<int> ch[MX + 2];

ll solve(int cur) {
  for (int nxt : ch[cur]) 
    val[cur][0] += solve(nxt);
  val[cur][0] -= val[cur][1];
  return max((ll) 0, val[cur][0]);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 2; i <= n; i++) {
    char sw; ll no; int par;
    cin >> sw >> no >> par;
    val[i][sw == 'W'] = no;
    ch[par].push_back(i);
  }
  cout << solve(1);
}
