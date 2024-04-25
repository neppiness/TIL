#include <bits/stdc++.h>
using namespace std;

int n; 
int a[100'002];
bool vis[100'002];

bool oob(int x) {
  return x < 1 || x > n;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  int x; cin >> x;
  queue<int> q;
  q.push(x);
  vis[x] = 1;  
  while (!q.empty()) {
    int cur = q.front(); q.pop();
    for (int nxt : {cur - a[cur], cur + a[cur]}) {
      if (oob(nxt)) continue;
      vis[nxt] = 1;
      q.push(nxt);
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; i++)
    ans += vis[i];
  cout << ans;
}
