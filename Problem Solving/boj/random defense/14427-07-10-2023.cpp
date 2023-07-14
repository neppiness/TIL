#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

const int ROOT = 1;

int n, m, a[100'002];
pair<int, int> seq[400'002];

pair<int, int> init(int cur, pair<int, int> nr) {
  if (nr.X == nr.Y) return seq[cur] = {a[nr.X], nr.X};
  int nmid = (nr.X + nr.Y) / 2;
  return seq[cur] = min(
      init(cur*2, {nr.X, nmid}),
      init(cur*2 + 1, {nmid + 1, nr.Y})
  );
}

pair<int, int> update(int target, int cur, pair<int, int> nr) {
  if (nr.X == nr.Y) return seq[cur] = {a[nr.X], nr.X};
  if (target < nr.X || target > nr.Y) return seq[cur];
  int nmid = (nr.X + nr.Y) / 2;
  return seq[cur] = min(
      update(target, cur*2, {nr.X, nmid}),
      update(target, cur*2 + 1, {nmid + 1, nr.Y})
  );
}

void update() {
  int i; cin >> i >> a[i];
  update(i, ROOT, {1, n});
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  init(ROOT, {1, n});

  cin >> m;
  while (m--) {
    int code; cin >> code;
    if (code == 2) cout << seq[ROOT].Y << '\n';
    else update();
  }
}