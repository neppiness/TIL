#include <bits/stdc++.h>
using namespace std;

int score[102];
priority_queue<int> pq[102];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < m; j++) {
      int x; cin >> x;
      pq[i].push(x);
    }
  }

  for (int i = 0; i < m; i++) {
    int mx = 0;
    for (int j = 1; j <= n; j++) {
      mx = max(mx, pq[j].top());
    }
    for (int j = 1; j <= n; j++) {
      int x = pq[j].top(); pq[j].pop();
      score[j] += (x == mx);
    }
  }


  int mx = 0;
  for (int i = 1; i <= n; i++) {
    mx = max(mx, score[i]);
  }

  for (int i = 1; i <= n; i++) {
    if (mx != score[i]) continue;
    cout << i << ' ';
  }
}
