#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> a[1'002];

bool solve(int x) {
  priority_queue<pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>> pq;

  for (int i = 0; i < n; i++)
    pq.push(a[i]);

  while (!pq.empty()) {
    auto [st, du] = pq.top(); pq.pop();
    if (x > st) return 0;
    x++; st++; du--;
    if (du) pq.push({st, du});
  }
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    int t, s; cin >> t >> s;
    a[i] =  {(s - t), t};
  }
  sort(a, a + n);

  int st = 0, en = 1'000'000; 
  while (st < en) {
    int mid = (st + en) / 2 + 1;
    if (solve(mid)) st = mid;
    else en = mid - 1;
  }

  if (solve(st)) cout << st;
  else cout << -1;
}
