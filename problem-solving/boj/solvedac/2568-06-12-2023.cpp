#include <bits/stdc++.h>
using namespace std;

int n, mx;
vector<pair<int, int>> v;
unordered_map<int, int> ret;
unordered_map<int, bool> is_used;
pair<int, int> cache[100'002];

int find(int tar) {
  int st = 1, en = n;
  while (st < en) {
    int mid = (st + en) / 2;
    auto [a, b] = cache[mid];
    if (tar > b) st = mid + 1;
    else en = mid;
  }
  return st;
}

void trace(int st) {
  while (st) {
    is_used[st] = 1;
    st = ret[st];
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(cache, 0x7f, sizeof(cache));
  cache[0] = {0, 0};

  cin >> n;
  v.resize(n);

  for (int i = 0; i < n; i++) {
    int a, b; cin >> a >> b;
    v[i] = {a, b};
  }

  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    auto [a, b] = v[i];
    int idx = find(b);
    auto [c, d] = cache[idx];

    int len;
    if (b < d) len = idx;
    else len = idx + 1;
    cache[len] = {a, b};
    ret[a] = cache[len - 1].first; 
    mx = max(mx, len);
  }
  cout << n - mx << '\n';
  trace(cache[mx].first);

  for (int i = 0; i < n; i++) {
    auto [a, b] = v[i];
    if (is_used[a]) continue;
    cout << a << '\n';
  }
}