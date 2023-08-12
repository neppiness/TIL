#include <bits/stdc++.h>
using namespace std;

int n;

// 0: for all, 1 to N for each color ball
// first: size, second: cumulated sizes
vector<pair<int, int>> a[200'002];

// op: original pair, sp: sorted pair
vector<pair<int, int>> op, sp;

int find(vector<pair<int, int>> &x, int size) {
  int st = 0, en = x.size() - 1;
  while (st < en) {
    int mid = (st + en) / 2;
    auto [s, cs] = x[mid];
    if (s < size) st = mid + 1;
    else en = mid;
  }
  if (x[st].first != size) return -1;
  return st;
}

void update(int s, int c) {
  if (a[c].size() == 0) a[c].push_back({s, 0});
  int idx = find(a[c], s);
  if (idx == -1) a[c].push_back({s, 0});
  idx = find(a[c], s);
  a[c][idx].second += s;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  op.resize(n); sp.resize(n);
  for (int i = 0; i < n; i++) {
    int c, s; cin >> c >> s;
    op[i] = sp[i] = {s, c};
  }

  sort(sp.begin(), sp.end());

  for (auto [s, c] : sp) {
    update(s, 0); // 모든 색의 공에 대한 정보 저장
    update(s, c); // 확인된 색의 공에 대한 정보 저장
  }

  for (int c = 0; c <= 200'000; c++)
    for (int i = 1; i < a[c].size(); i++)
      a[c][i].second += a[c][i - 1].second;

  for (auto [s, c] : op) {
    int idx = find(a[0], s);
    if (idx == 0) { cout << 0 << '\n'; continue; }
    int ans = a[0][--idx].second;
    idx = find(a[c], s);
    if (idx == 0) { cout << ans << '\n'; continue; }
    ans -= a[c][--idx].second;
    cout << ans << '\n';
  }
}