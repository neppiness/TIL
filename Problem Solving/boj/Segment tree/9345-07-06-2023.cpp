#include <bits/stdc++.h>
using namespace std;

const int kRoot = 1;

int n, k;
int mn[400'002], mx[400'002];

int init(int st, int en, int cur, bool is_max) {
  if (st == en) {
    if (is_max) return mx[cur] = st;
    return mn[cur] = st;
  }

  int mid = (st + en) / 2;
  if (is_max) return mx[cur] = max(
      init(st, mid, cur*2, 1),
      init(mid + 1, en, cur*2 + 1, 1)
  );
  return mn[cur] = min(
      init(st, mid, cur*2, 0),
      init(mid + 1, en, cur*2 + 1, 0)
  );
}

int get(int st, int en, int cur, int x) {
  if (st == en) return mn[cur];
  int mid = (st + en) / 2;
  if (x <= mid) return get(st, mid, cur*2, x);
  return get(mid + 1, en, cur*2 + 1, x);
}

int get(int st, int en, int cur, int a, int b, bool is_max) {
  if (a <= st && en <= b) {
    if (is_max) return mx[cur];
    return mn[cur];
  }

  if (b < st || en < a) { // out of range process
    if (is_max) return -21e8;
    return 21e8;
  }

  int mid = (st + en) / 2;
  if (is_max) return max(
      get(st, mid, cur*2, a, b, 1),
      get(mid + 1, en, cur*2 + 1, a, b, 1)
  );
  return min(
      get(st, mid, cur*2, a, b, 0),
      get(mid + 1, en, cur*2 + 1, a, b, 0)
  );
}

int update(int st, int en, int cur, int taridx, int val, bool is_max) {
  if (st == en) {
    if (is_max) return mx[cur] = val;
    return mn[cur] = val;
  }

  if (taridx < st || en < taridx) { // out of range process
    if (is_max) return -21e8;
    return 21e8;
  }

  int mid = (st + en) / 2;
  if (is_max) return mx[cur] = max(
    update(st, mid, cur*2, taridx, val, 1),
    update(mid + 1, en, cur*2 + 1, taridx, val, 1)
  );
  return mn[cur] = min(
      update(st, mid, cur*2, taridx, val, 0),
      update(mid + 1, en, cur*2 + 1, taridx, val, 0)
  );
}

void swap(int a, int b) {
  int val_a = get(0, n - 1, kRoot, a);
  int val_b = get(0, n - 1, kRoot, b);
  update(0, n - 1, kRoot, a, val_b, 0);
  update(0, n - 1, kRoot, a, val_b, 1);
  update(0, n - 1, kRoot, b, val_a, 0);
  update(0, n - 1, kRoot, b, val_a, 1);
}

void chk(int a, int b) {
  int range_max = get(0, n - 1, kRoot, a, b, 1);
  int range_min = get(0, n - 1, kRoot, a, b, 0);
  if (range_min == a && range_max == b) cout << "YES\n";
  else cout << "NO\n";
}

void solve() {
  while (k--) {
    int code, a, b;
    cin >> code >> a >> b;
    if (!code) swap(a, b);
    else chk(a, b);
  }
}

void init() {
  init(0, n - 1, kRoot, 0);
  init(0, n - 1, kRoot, 1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    cin >> n >> k;
    init();
    solve();
  }
}